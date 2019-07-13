#include <iostream>
#include "stats.h"
Stats::Stats() {
    for(auto& x:methods){
        methods_[x]=0;
    }
    for(auto& x:uris){
        uris_[x]=0;
    }
}
void Stats::AddMethod(string_view method){
    auto result=methods.find(string(method));
    if(result!=methods.end()){
    }
    if(result==methods.end())
        methods_["UNKNOWN"]+=1;
    else{
        methods_[*result]+=1;
    }
}

void Stats::AddUri(string_view uri) {
    auto result = uris.find(string(uri));
    if (result == uris.end())
        uris_["unknown"] += 1;
    else {
        uris_[*result] += 1;
    }
}

const map<string_view, int> &Stats::GetMethodStats() const {
    return  methods_;
}

const map<string_view, int> &Stats::GetUriStats() const {
    return uris_;
}

HttpRequest ParseRequest(string_view line) {
    HttpRequest req;
    size_t point;
    std::array<std::string_view, 3> stringview_arr;

    for (int i = 0; i < 3; ++i) {
        line.remove_prefix(line.find_first_not_of(' '));

        point = line.find(' ');
        if (point == line.npos) {
            stringview_arr[i] = line.substr(0, line.npos);
            continue;
        }
        stringview_arr[i] = line.substr(0, point);

        line.remove_prefix(point + 1);
    }

    point = 0;

    req.method   = stringview_arr[point++];
    req.uri      = stringview_arr[point++];
    req.protocol = stringview_arr[point++];
//    int begin=0;
//    HttpRequest rq;
//    for (int i = 0; i <line.size() ; ++i) {
//        if(isalpha(line[i]) && i!=' '){
//            begin=i;
//            break;
//        }
//    }
//    line.remove_prefix(begin);
//    size_t tmp=line.find(" /");
//    rq.method=line.substr(0,tmp);
//    line.remove_prefix(tmp+1);
//    tmp=line.find(' ');
//    rq.uri=line.substr(0,tmp);
//    tmp=line.find(' ');
//    line.remove_prefix(tmp+1);
//    rq.protocol=line;
//    cout<<rq.method<<"::"<<rq.uri<<"::"<<rq.protocol<<endl;
    return req;
}
