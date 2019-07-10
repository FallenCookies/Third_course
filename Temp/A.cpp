#include<iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main() {
    map<pair<string,string>,int>graph;
    vector<string> nums;
    int T;
    cin >>T;
    string tmp;
    for (int i=0;i<T;i++){
        cin>>tmp;
        nums.push_back(tmp);
    }
    for(auto& x:nums){
        for(size_t i=0;i<x.length()-3;i++) {
            pair<string, string> Pair = make_pair(x.substr(i, 3), x.substr(i + 1,3));
            graph[Pair] += 1;
        }
    }
    set<string> peaks;
    for(auto x:graph){
        peaks.insert(x.first.first);
    }
    cout<<peaks.size()<<endl;
    cout<<graph.size()<<endl;
    for(auto x:graph){
        cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
    }
    return 0;
}
