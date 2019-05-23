#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y)       \
            (out) << (x) << endl<<(y)<<endl  \



int main() {
  TestRunner tr;
  tr.RunTest([] {
    ostringstream output;
    ostringstream output1;
    if(true)
     PRINT_VALUES(output, 5, "red belt");
    if(true){
        PRINT_VALUES(output, 5, "red belt");
    }
    if(true){
        PRINT_VALUES(output, 5, "red belt");
    }else{
        PRINT_VALUES(output, 5, "red belt");
    }
    if (!true)
        PRINT_VALUES(output, 5, "red belt");
    else
        PRINT_VALUES(output, 5, "red belt");

  }, "PRINT_VALUES usage example");
}