#include <iostream>
#include <vector>
//#include "test_runner.h"
using namespace std;
template <typename Type>
class Deque{
private:
    vector<Type> for_front;
    vector<Type> for_back;
public:
    Deque(){

    }
    bool Empty()const{
        return (for_back.size()+for_front.size())==0;
    }
    size_t Size()const{
        return (for_back.size()+for_front.size());
    }
    const Type&operator[](size_t index)const{

        return At(index);
    }
    Type&operator[](size_t index){
        return At(index);
    }
    Type& Front(){
        if(!for_front.empty())
            return for_front.back();
        else
            return for_back.front();
    }
    Type& Back(){
        if(!for_back.empty())
            return for_back.back();
        else
            return for_front.front();
    }
    const Type& Front()const{
        if(!for_front.empty())
            return for_front.back();
        else
            return for_back.front();
    }
    const Type& Back()const {
        if(!for_back.empty())
            return for_back.back();
        else
            return for_front.front();
    }
    Type& At(size_t index){
        if(for_back.size()+for_front.size()>index){
            if(index>=for_front.size()){
                return for_back[index-for_front.size()];
            }else{
                return for_front[for_front.size()-1-index];
            }
        }else{
            throw out_of_range("");
        }
    }
    const Type& At(size_t index) const{
        if(for_back.size()+for_front.size()>index){
            if(index>=for_front.size()){
                return for_back[index-for_front.size()];
            }else{
                return for_front[index];
            }
        }else{
            throw out_of_range("");
        }
    }
    void PushFront(Type value){
        for_front.push_back(value);
    }
    void PushBack(Type value){
        for_back.push_back(value);
    }
};
//void TestAll(){
//    Deque<int> deq1;
//    ASSERT_EQUAL(deq1.Empty(), true);
//
//    deq1.PushBack(1);
//    ASSERT_EQUAL(deq1.Empty(),false);
//    deq1.PushBack(2);
//    deq1.PushBack(3);
//    deq1.PushBack(4);
//    deq1.PushFront(5);
//    ASSERT_EQUAL(deq1[4],4);
//    ASSERT_EQUAL(deq1.Front(),5);
//    ASSERT_EQUAL(deq1.Back(),4);
//    ASSERT_EQUAL(deq1.Size(),5);
//
//
//}
int main() {
//    TestRunner tr;
//    RUN_TEST(tr,TestAll);
//    Deque <int>dq;
//    dq.PushFront(0);
//    dq.PushFront(1);
//    dq.PushFront(2);
//    dq.PushFront(3);
//    dq.PushFront(4);
//    dq.PushFront(5);
//    dq.PushBack(6);
//    dq.PushBack(7);
//    dq.PushBack(8);
//    dq.PushBack(9);
//    dq.PushBack(10);
//    cout<<dq.Front()<<endl;
//    cout<<dq.Back()<<endl;
//    for(int i=0;i<dq.Size();i++){
//        cout<<dq[i]<<" ";
//    }
    return 0;
}