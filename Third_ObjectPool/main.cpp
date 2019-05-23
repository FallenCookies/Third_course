#include "test_runner.h"
#include "profile.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
    T* Allocate(){
        if(!free.empty()) {
            auto move=free.front();
            in_use.insert(move);
            free.pop_front();
            return move;
        }
        else{
            T* to_push=new T;
            in_use.insert(to_push);
            return to_push;
        }
    }
    T* TryAllocate(){
        if(!free.empty()) {
            auto move=free.front();
            in_use.insert(move);
            free.pop_front();
            return move;
        }
        else{
            return nullptr;
        }
    }

    void Deallocate(T* object){
        auto result=in_use.find(object);
        if(result == in_use.end())
            throw invalid_argument("");
        else{
            in_use.erase(result);
            free.push_back(object);
        }
    }

    ~ObjectPool(){
        for(auto it=in_use.begin();it!=in_use.end();it++){
            delete *it;
        }
        for(auto it=free.begin();it!=free.end();it++){
            delete *it;
        }
    }

private:
    set<T*> in_use;
    deque<T*> free;
};

void TestObjectPool() {
        ObjectPool<string> pool;

        auto p1 = pool.Allocate();
        auto p2 = pool.Allocate();
        auto p3 = pool.Allocate();

        *p1 = "first";
        *p2 = "second";
        *p3 = "third";

        pool.Deallocate(p2);
        ASSERT_EQUAL(*pool.Allocate(), "second");

        pool.Deallocate(p3);
        pool.Deallocate(p1);
        ASSERT_EQUAL(*pool.Allocate(), "third");
        ASSERT_EQUAL(*pool.Allocate(), "first");

        pool.Deallocate(p1);

}

int main() {
//    LOG_DURATION("all")
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;

}
