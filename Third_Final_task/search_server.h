#pragma once

#include <istream>
#include <ostream>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <future>
using namespace std;
template <typename T>
class Synchronized {
public:
    explicit Synchronized(T initial = T()):value(move(initial)){

    }
    struct Access {
        T& ref_to_value;
        lock_guard<mutex> lock;
    };

    Access GetAccess(){

        return {value,lock_guard(m)};
    };
private:
    T value;
    mutex m;
};

class InvertedIndex {
public:
  void Add(const string& document);
  list<size_t> Lookup(const string& word) const;

  const string& GetDocument(size_t id) const {
    return docs[id];
  }
  using hits=int;
  using word_index=int;
private:
  Synchronized<map<string_view , map<hits,word_index>>>index;
  vector<string> docs;
};

template <typename T>

class SearchServer {
public:
  SearchServer() = default;
  explicit SearchServer(istream& document_input);
  void UpdateDocumentBase(istream& document_input);
  void AddQueriesStream(istream& query_input, ostream& search_results_output);

private:
  InvertedIndex index;
};