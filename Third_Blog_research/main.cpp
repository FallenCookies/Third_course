#include "test_runner.h"
#include "profile.h"

#include <map>
#include <string>
#include <set>
#include <future>
#include <functional>
#include <deque>
using namespace std;
template <typename Iterator>
class IteratorRange {
public:
    IteratorRange(Iterator begin, Iterator end)
            : first(begin)
            , last(end)
            , size_(distance(first, last))
    {
    }

    Iterator begin() const {
        return first;
    }

    Iterator end() const {
        return last;
    }

    size_t size() const {
        return size_;
    }

private:
    Iterator first, last;
    size_t size_;
};

template <typename Iterator>
class Paginator {
private:
    vector<IteratorRange<Iterator>> pages;

public:
    Paginator(Iterator begin, Iterator end, size_t page_size) {
        for (size_t left = distance(begin, end); left > 0; ) {
            size_t current_page_size = min(page_size, left);
            Iterator current_page_end = next(begin, current_page_size);
            pages.push_back({begin, current_page_end});

            left -= current_page_size;
            begin = current_page_end;
        }
    }

    auto begin() const {
        return pages.begin();
    }

    auto end() const {
        return pages.end();
    }

    size_t size() const {
        return pages.size();
    }
};

template <typename C>
auto Paginate(C& c, size_t page_size) {
    return Paginator(begin(c), end(c), page_size);
}
 struct Stats {
    map<string, int> word_frequences;

    void operator += (const Stats& other){
        for(auto& item:other.word_frequences){
            word_frequences[item.first]+=item.second;
        }
    }
};

Stats ExploreLine(const set<string>& key_words, const string& line) {
    string tmp;
    Stats line_result;
    for(auto x:line){
        if(x!=' ')
            tmp+=x;
        else{
            auto it=key_words.find(tmp);
            if(it!=key_words.end()) {
                line_result.word_frequences[tmp]+=1;
            }
            tmp.clear();
        }
    }
    auto it=key_words.find(tmp);
    if(it!=key_words.end()) {
        line_result.word_frequences[tmp] += 1;
    }
    return line_result;
}
template <typename T>
Stats ExploreKeyWordsSingleThread(

        const set<string>& key_words, IteratorRange<T> page
) {
    LOG_DURATION("ExploreKeyWordSingle");
    Stats result;
        for(auto& line:page){
            result+=ExploreLine(key_words,line);
        }
    return result;
}

Stats ExploreKeyWords(const set<string>& key_words, istream& input) {
    LOG_DURATION("ExploreKeyWord");
    Stats stats;
    vector<string> all_data;
    size_t index=0;
    for (string line; getline(input, line); ) {
        all_data.push_back(move(line));
    }
    size_t page_size=all_data.size()/4;
    vector<future<Stats>> to_sum;
    for(auto& page:Paginate(all_data,page_size)){
                to_sum.push_back(async([key_words,page]{
                    return ExploreKeyWordsSingleThread(key_words,page);
                }));

    }
    for (auto& item:to_sum){
        stats+=item.get();
    }
    return stats;
}

void TestBasic() {
    const set<string> key_words = {"yangle", "rocks", "sucks", "all"};

    stringstream ss;
    ss << "this new yangle service really rocks\n";
    ss << "It sucks when yangle isn't available\n";
    ss << "10 reasons why yangle is the best IT company\n";
    ss << "yangle rocks others suck\n";
    ss << "Goondex really sucks, but yangle rocks. Use yangle\n";

    const auto stats = ExploreKeyWords(key_words, ss);
    const map<string, int> expected = {
            {"yangle", 6},
            {"rocks", 2},
            {"sucks", 1}
    };
    ASSERT_EQUAL(stats.word_frequences, expected);
}
void TestHuge() {
     set<string> key_words;
    for (int k = 0; k <50000 ; ++k) {
        key_words.insert(to_string(k));
    }
    stringstream ss;
    for (int i = 0; i <50000 ; ++i) {
        string word;
        for (int j = 0; j <20 ; ++j) {
            word+=" ";
            word+=char(j);
            word+=" ";
        }
        word+="\n";
        ss<<word;
    }
    const auto stats = ExploreKeyWords(key_words, ss);
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, TestBasic);
    {
        LOG_DURATION("all");
        TestHuge();
    }
}
