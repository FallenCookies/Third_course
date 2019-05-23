#include "student.h"
#include "test_runner.h"
#include "profile.h"
#include <algorithm>

using namespace std;

//Оптимизируйте эту функцию
bool Compare(const  Student& first,const  Student& second) {
    return first.Less(second);
}

void TestComparison() {
    Student newbie {
            "Ivan", "Ivanov", {
                    {"c++", 1.0},
                    {"algorithms", 3.0}
            },
            2.0
    };

    Student cpp_expert {
            "Petr", "Petrov", {
                    {"c++", 9.5},
                    {"algorithms", 6.0}
            },
            7.75
    };

    Student guru {
            "Sidor", "Sidorov", {
                    {"c++", 10.0},
                    {"algorithms", 10.0}
            },
            10.0
    };
    {
        LOG_DURATION("CMP1")
        ASSERT(Compare(guru, newbie));
    }
    {
        LOG_DURATION("CMP2")
        ASSERT(Compare(guru, cpp_expert));
    }
    {
        LOG_DURATION("CMP3")
        ASSERT(!Compare(newbie, cpp_expert));
    }
}

void TestSorting() {
    vector<Student> stud;
    for (int i =0; i<100000;i++){
        stud.push_back(Student{to_string(i),to_string(i+1),{{to_string(i+2),i+3}},i+4.});
    }
    {
        LOG_DURATION("Sort")
        sort(stud.begin(), stud.end(), Compare);
    }
    vector<Student> students {
            {"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
            {"Semen", "Semenov", {{"maths", 4.}}, 4.},
            {"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
            {"Petr", "Petrov", {{"maths", 3.}}, 3.},
            {"Alexander", "Alexandrov", {{"maths", 1.}}, 1.}
    };
    {

        sort(students.begin(), students.end(), Compare);
    }
    ASSERT(is_sorted(students.begin(), students.end(),
                     [](Student first, Student second) {
                         return first.Less(second);
                     })
    );
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestComparison);
    RUN_TEST(tr, TestSorting);
    return 0;
}