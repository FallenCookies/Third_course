#pragma once


#include <array>
#include <stdexcept>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
    explicit StackVector(size_t a_size = 0):size(a_size){
        if(a_size>capacity){
            throw invalid_argument("");
        }
        size=a_size;
        begin_=stack_vector.begin();
        end_=stack_vector.begin();
    }

    T& operator[](size_t index){
        return stack_vector.at(index);
    }
    const T& operator[](size_t index) const{
        return stack_vector.at(index);
    }

    typename std::array<T,N>::iterator begin(){
        return begin_;
    };
    typename std::array<T,N>::iterator end(){
        return end_;
    };
    typename std::array<T,N>::iterator begin() const{
        return begin_;
    };
    typename std::array<T,N>::iterator end() const{
        return end_;
    };

    size_t Size() const{
        return size;
    }
    size_t Capacity() const{
        return capacity;
    }

    void PushBack(const T& value){
        if(capacity==size){
            throw overflow_error("");
        }
        stack_vector[size]=value;
        size+=1;
        end_++;


    }
    T PopBack(){
        if(size==0)
            throw underflow_error("");
        auto tmp=stack_vector[size-1];
        end_--;
        size--;
        return tmp;
    }

private:
    array<T,N> stack_vector;
    typename std::array<T,N>::iterator begin_;
    typename std::array<T,N>::iterator end_;
    size_t size;
    size_t capacity=N;
};
