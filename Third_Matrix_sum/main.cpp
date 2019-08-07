#include "test_runner.h"
#include <vector>
#include <future>
#include <algorithm>
#include <numeric>
#include "profile.h"
using namespace std;
template <typename Type>
class IteratorRange{
private:
    Type first,last;
public:
    IteratorRange(Type f,Type l):first(f),last(l){
    }
    size_t size()const {
        return last-first;
    }
    Type begin()const{
        return first;
    }
    Type end()const{
        return last;
    }
};
template <typename Iterator>
class Paginator {
private:

    Iterator first,last;
    size_t page_size;
    vector <IteratorRange<Iterator>> pages;

public:
    Paginator(Iterator begin_,Iterator end_, size_t page_size_):first(begin_),last(end_),
                                                                page_size(page_size_){
        int count=0;
        auto last_it=begin_;
        if(begin_!=end_) {
            for (auto cur_it = begin_; cur_it <= end_; cur_it++) {
                if (count == page_size_ || cur_it == end_) {
                    pages.push_back(IteratorRange(last_it, cur_it));
                    count = 1;
                    last_it = cur_it;
                } else {
                    count++;
                }


            }
        }



    }
    auto begin() const{
        return pages.begin();
    }
    auto end() const{
        return pages.end();
    }
    size_t size() const{
        return pages.size();
    }

};
template <typename C>
auto Paginate(C& c, size_t page_size) {
    return Paginator{c.begin(),c.end(),page_size};
}
template <typename T>
int64_t to_sum(IteratorRange<T> page){
    int64_t sum=0;
    for(auto& row:page){
        for(auto item:row){
            sum+=item;
        }
    }
    return sum;
}
int64_t CalculateMatrixSum(const vector<vector<int>>& matrix) {
    size_t page_size=matrix.size()/4;
    vector<future<int64_t>> sums;
   for(auto page:Paginate(matrix,page_size)){
       sums.push_back(async([page]{
           return to_sum(page);
       }));
   }
   int64_t result=0;
    for(auto& x:sums){
        result+=x.get();
    }
    return result;
}

void TestCalculateMatrixSum() {
  const vector<vector<int>> matrix = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };
  ASSERT_EQUAL(CalculateMatrixSum(matrix), 136);
}


int main() {
  TestRunner tr;
  RUN_TEST(tr, TestCalculateMatrixSum);


}
