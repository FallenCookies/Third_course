#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include "profile.h"
using namespace std;

class ReadingManager {
public:
    ReadingManager(vector<int> index_=vector<int>(1000)):index(index_){

    }

    void Read(int user_id, int page_count) {
        if(user_base.size()<MAX_USER_COUNT_) {
            if (user_base.count(user_id) == 0) {
                user_base[user_id]=page_count;
                index[page_count] += 1;

            } else {
                index[user_base[user_id]] -= 1;
                user_base[user_id] = page_count;
                index[page_count] += 1;
            }
        }


    }

    double Cheer(int user_id)  {
        if (user_base.count(user_id) == 0) {
            return 0;
        }
        if (user_base.size() == 1) {
            return 1;
        }
        int sum=0;
        int id=user_base[user_id];
        for(int i=0;i<id;i++){
            sum+=index[i];
        }

        return sum * 1.0 / (user_base.size() - 1);
    }

private:
    // Статическое поле не принадлежит какому-то конкретному
    // объекту класса. По сути это глобальная переменная,
    // в данном случае константная.
    // Будь она публичной, к ней можно было бы обратиться снаружи
    // следующим образом: ReadingManager::MAX_USER_COUNT.
    static const int MAX_USER_COUNT_ = 100'000;

    map<int,int> user_base;
    vector<int> index;

};


int main() {
    // Для ускорения чтения данных отключается синхронизация
    // cin и cout с stdio,
    // а также выполняется отвязка cin от cout
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ReadingManager manager;
//    {
//        LOG_DURATION("Read")
//        int page=0;
//        for (int i = 0; i < 500000; i++) {
//            if (page==999)
//                page=0;
//            page++;
//            manager.Read(i, page);
//        }
//    }
//    {
//        LOG_DURATION("Cheer")
//        for (int i = 0; i < 500000; i++) {
//            manager.Cheer(i);
//        }
//    }


    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int user_id;
        cin >> user_id;

        if (query_type == "READ") {
            int page_count;
            cin >> page_count;
            manager.Read(user_id, page_count);
        } else if (query_type == "CHEER") {
            cout << setprecision(6) << manager.Cheer(user_id) << "\n";
        }
    }

    return 0;
}