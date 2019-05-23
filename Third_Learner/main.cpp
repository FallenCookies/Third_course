#include <iostream>
#include "learner.h"
#include "test_runner.h"
#include "profile.h"
int main() {
    Learner learner;
    string line;

    vector<string> words;

    for(int i=0;i<100000;i++){
        words.push_back(to_string(i));
    }
    cout << learner.Learn(words) << "\n";

    cout << "=== known words ===\n";
    for (auto word : learner.KnownWords()) {
        cout << word << "\n";
    }
    return 0;
}