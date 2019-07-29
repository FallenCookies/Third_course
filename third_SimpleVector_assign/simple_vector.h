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
    SimpleVector(const SimpleVector& other):
    data(new T[other.capacity]),
    size_(other.size_),
    end_(data+other.size_),
    capacity(other.capacity)
    {
    copy(other.begin(),other.end(),begin());
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
    void operator=(const SimpleVector& rhs){
        if (rhs.size_<= capacity) {
            // У нас достаточно памяти - просто копируем элементы
            copy(rhs.begin(), rhs.end(), begin());
            size_ = rhs.size_;
        } else {
            // Это так называемая идиома copy-and-swap.
            // Мы создаём временный вектор с помощью
            // конструктора копирования, а затем обмениваем его поля со своими.
            // Так мы достигаем двух целей:
            //  - избегаем дублирования кода в конструкторе копирования
            //    и операторе присваивания
            //  - обеспечиваем согласованное поведение конструктора копирования
            //    и оператора присваивания
            SimpleVector<T> tmp(rhs);
            swap(tmp.data, data);
            swap(tmp.size_, size_);
            swap(tmp.capacity, capacity);
            end_=data+capacity;
        }
    }

private:
    T* data;
    T* end_;
    size_t capacity;
    size_t size_;

};
