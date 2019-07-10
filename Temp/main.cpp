#include <iostream>
#include <map>
using namespace std;
int main()
{
 map<int,int> a;
 a[1]=2;
 a[3]=4;
 a[5]=6;
 auto Items=make_pair(a.begin(),a.end());
 for(auto item:Items){

 }

}
