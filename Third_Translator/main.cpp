#include "test_runner.h"
#include <string>
#include <vector>
#include <set>
#include <string_view>
using namespace std;

class Translator {
public:
    void Add(string_view source, string_view target){
        auto result=Test.insert(string(source));
        auto result2=Test.insert(string(target));
        dbForward[string_view(*result.first)] = string_view(*result2.first);
        dbBackward[string_view(*result2.first)]=string_view(*result.first);



    }
    string_view TranslateForward(string_view source) const{
        try {
            return dbForward.at(source);
        }catch(exception& e){
            return "";
        }
    }
    string_view TranslateBackward(string_view target) const{
        try {
            return dbBackward.at(target);
        }catch(exception& e){
            return "";
        }
    }
    void ShowForward(){
        for(auto x:dbForward){
            cout<<x.first<<"::"<<x.second<<endl;
        }
    }
    void ShowBacward(){
        for(auto x:dbBackward){
            cout<<x.first<<"::"<<x.second<<endl;
        }
    }

private:
    map<string_view,string_view> dbForward;
    map<string_view,string_view> dbBackward;
    set<string> Test;
};

void TestSimple() {
    Translator translator;
    translator.Add(string("okno"), string("window"));
    translator.Add(string("kek"), string("lol"));
    translator.Add(string("kek"), string("1"));
    translator.Add(string("stol"), string("table"));
//    translator.ShowBacward();

    ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
    ASSERT_EQUAL(translator.TranslateForward("stol"), "table");
    ASSERT_EQUAL(translator.TranslateForward("kek"), "1");
    ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
    ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSimple);

    return 0;
}