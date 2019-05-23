#include "test_runner.h"
#include <sstream>
#include <string>
#include <algorithm>
#include <string>
using namespace std;

class Logger {
public:
    explicit Logger(ostream& output_stream) : os(output_stream) {
    }

    void SetLogLine(bool value) { log_line = value; }
    void SetLogFile(bool value) { log_file= value; }

    void Log(const string& message) {
//        string file=__FILE__;
//        string file_only;
//        for(auto it=file.end()-1;*it!='\\';it--){
//            file_only+=*it;
//        }
//        reverse(file_only.begin(),file_only.end());
        if ((log_file) && !(log_line)) {
            os << curr_file<< " " << (message)<<endl;
        } else if (!(log_file) && (log_line)) {
            os << "Line " << curr_line << " " << (message) <<endl;
        } else if ((log_file) && (log_line)) {
            os << curr_file << ":" << curr_line << " " << (message) << endl;
        } else if (!(log_file) && !(log_line)){
            os<<message<<endl;
        }
    }
    void Set_line(int line){
        curr_line=line;
    }
    void Set_file(string file){
        curr_file=file;
    }
private:
    ostream& os;
    int curr_line;
    string curr_file;
    bool log_line = false;
    bool log_file = false;

};

#define LOG(logger, message) {                               \
    logger.Set_line((__LINE__));                             \
    logger.Set_file((__FILE__));                             \
    logger.Log((message));                                   \
}

void TestLog() {
/* Для написания юнит-тестов в этой задаче нам нужно фиксировать конкретные
 * номера строк в ожидаемом значении (см. переменную expected ниже). Если
 * мы добавляем какой-то код выше функции TestLog, то эти номера строк меняются,
 * и наш тест начинает падать. Это неудобно.
 *
 * Чтобы этого избежать, мы используем специальный макрос #line
 * (http://en.cppreference.com/w/cpp/preprocessor/line), который позволяет
 * переопределить номер строки, а также имя файла. Благодаря ему, номера
 * строк внутри функции TestLog будут фиксированы независимо от того, какой
 * код мы добавляем перед ней*/
#line 1 "logger.cpp"

    ostringstream logs;
    Logger l(logs);
    LOG(l, "hello");

    l.SetLogFile(true);
    LOG(l, "hello");

    l.SetLogLine(true);
    LOG(l, "hello");

    l.SetLogFile(false);
    LOG(l, "hello");
    string expected = "hello\n";
    expected += "logger.cpp hello\n";
    expected += "logger.cpp:10 hello\n";
    expected += "Line 13 hello\n";
    ASSERT_EQUAL(logs.str(), expected);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestLog);
}
