#include "test_runner.h"

using namespace std;

template <typename Type>
class Table{
public:
    Table(size_t columns_,size_t rows_){
       Resize(columns_,rows_);
    }
    vector<Type>& operator[](const size_t index){
        return table[index];
    }
    vector<Type>& operator[](size_t index)const {
        return table[index];
    }
    void Resize(size_t columns_,size_t rows_){
        table.resize(columns_);
        for(auto& x:table){
            x.resize(rows_);
        }
    }
    pair<size_t,size_t> Size() const{
        return {table.size(), (table.empty() ? 0 : table[0].size())};
    };
private:
    vector<vector<Type>> table;

};
void TestTable() {
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
    Table<string> t2(5,5);
    t2[0][0]="hello";
    ASSERT_EQUAL(t2[0][0],"hello")

}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}