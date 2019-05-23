#pragma once

#include <cstdlib>
#include <algorithm>
using namespace std;
// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
    SimpleVector(){
        data= nullptr;
        end_=nullptr;
        capacity=0;
        size_=0;
    }
    explicit SimpleVector(size_t size){
        data=new T[size];
        end_=data+size;
        capacity=size;
        size_=size;
    }
    ~SimpleVector(){
        delete[] data;
    }

    T& operator[](size_t index){
        return data[index];
    }

    T* begin(){
        return data;
    }
    T* end(){
        return end_;
    }
    const T* begin() const {
        return data;
    }
    const T* end() const{
        return end_;
    }

    size_t Size() const{
        return size_;
    }
    size_t Capacity() const{
        return capacity;
    }
    void PushBack(const T& value){
        if(capacity==size_){
            if (capacity==0)
                capacity=1;
            T* New_data=new T[capacity*2];
            copy_n(data,size_,New_data);
            capacity=capacity*2;
            delete[] data;
            data=New_data;
            end_=data+size_+1;
            auto& tmp = *(data+size_);
            tmp=value;
            size_+=1;
        }else{
            *(end_)=value;
            end_+=1;
            size_+=1;
        }
    }

private:
    T* data;
    T* end_;
    size_t capacity;
    size_t size_;

};
