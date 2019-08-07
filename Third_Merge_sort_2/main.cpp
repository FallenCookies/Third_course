#include <iostream>
#include <vector>
#include <algorithm>
#include "test_runner.h"
using namespace std;
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin > 1) {
        vector<typename RandomIt::value_type> main(make_move_iterator(range_begin),
                make_move_iterator(range_end));
        auto it_middle_first = main.begin() + (range_end - range_begin) / 3;
        auto it_middle_second = it_middle_first+(range_end - range_begin) / 3;
        MergeSort(main.begin(), it_middle_first);
        MergeSort(it_middle_first, it_middle_second);
        MergeSort(it_middle_second,main.end());
        vector<typename RandomIt::value_type> tmp;

        merge(make_move_iterator(main.begin()),
                make_move_iterator(it_middle_first),make_move_iterator(it_middle_first),
              make_move_iterator(it_middle_second),
              move(back_inserter(tmp)));

        merge(make_move_iterator(tmp.begin()),
                make_move_iterator(tmp.end()),
                make_move_iterator(it_middle_second),
                make_move_iterator(main.end()),
                range_begin);
    } else {
        return;
    }

}

void TestIntVector() {
    vector<int> numbers = {6, 1, 3, 9, 1, 9, 8, 12, 1};
    MergeSort(begin(numbers), end(numbers));
    ASSERT(is_sorted(begin(numbers), end(numbers)));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestIntVector);
    return 0;
}