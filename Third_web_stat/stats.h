#pragma once

#include "http_request.h"
#include <string_view>
#include <string>
#include <set>
#include <map>
using namespace std;

class Stats {
public:
    Stats();
    void AddMethod(string_view method);
    void AddUri(string_view uri);
    const map<string_view, int>& GetMethodStats() const;
    const map<string_view, int>& GetUriStats() const;

private:
    map<string_view, int> methods_;
    map<string_view, int> uris_;
    set<string> methods{"GET","POST","PUT","DELETE","UNKNOWN"};
    set<string> uris{"/","/order","/product","/basket","/help","unknown"};

};

HttpRequest ParseRequest(string_view line);
