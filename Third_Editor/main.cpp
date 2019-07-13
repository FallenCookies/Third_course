#include <string>
#include <string_view>
#include "test_runner.h"
#include "profile.h"
#include <list>
#include <deque>
#include <algorithm>


using namespace std;

class Editor {
public:
    // Реализуйте конструктор по умолчанию и объявленные методы
    Editor():cursor(0){
    }
    void Left(){
        if(left_.size()>0){
            right_.push_front(left_.back());
            left_.pop_back();
        }
    }
    void Right(){
        if(right_.size()>0) {
            left_.push_back(right_.front());
            right_.pop_front();
        }
    }
    void Insert(char token){
        left_.push_back(token);
        cursor+=1;

//        cout<<distance(cursor,main_str.begin())<<endl;

    }
    void Cut(size_t tokens = 1){
        buffer.clear();
        if(tokens==0)
            return;
        if (tokens>right_.size()){
            buffer={right_.begin(),right_.end()};
            right_.clear();
        }else {
            buffer={right_.begin(),right_.begin()+tokens};
            right_.erase(right_.begin(),right_.begin()+tokens);
        }


    }
    void Copy(size_t tokens = 1){
        buffer.clear();
        if(tokens==0)
            return;
        if (tokens>right_.size()){
            buffer=right_;
        }else {
            buffer={right_.begin(),right_.begin()+tokens};
        }

    }
    void Paste(){
//        for(auto x:buffer){
//            cout<<x;
//        }
//        cout<<endl;
//        for(auto x:left_){
//            cout<<x;
//        }
//        cout<<endl;
//        for(auto x:right_){
//            cout<<x;
//        }
//        cout<<endl;
        left_.insert(left_.end(),buffer.begin(),buffer.end());

    }
    string GetText() const{
        string tmp={left_.begin(),left_.end()};
        tmp+={right_.begin(),right_.end()};
        return tmp;
    }
//    size_t GetCursor(){
//        return distance(cursor,main_str.begin());
//    }
    size_t GetIndex(){
        return cursor;
    }
    string GetBuffer(){
        return {buffer.begin(),buffer.end()};
    }
//    char GetSymbol(){
//        return *(main_str.begin()+cursor);
//    }


private:
    deque<char> left_={};
    size_t cursor;
    deque<char> right_={};
    deque<char> buffer;
};

void TypeText(Editor& editor, const string& text) {
    for(char c : text) {
        editor.Insert(c);
    }
}

void TestEditing() {
    {
        Editor editor;

        const size_t text_len = 12;
        const size_t first_part_len = 7;
        TypeText(editor, "hello, world");
        for(size_t i = 0; i < text_len; ++i) {
            editor.Left();
        }
        editor.Cut(first_part_len);
        for(size_t i = 0; i < text_len - first_part_len; ++i) {
            editor.Right();
        }
        TypeText(editor, ", ");
        editor.Paste();
        editor.Left();
        editor.Left();
        editor.Cut(3);

        ASSERT_EQUAL(editor.GetText(), "world, hello");
    }
    {
        Editor editor;

        TypeText(editor, "misprnit");
        editor.Left();
        editor.Left();
        editor.Left();
        editor.Cut(1);
        editor.Right();
        editor.Paste();

        ASSERT_EQUAL(editor.GetText(), "misprint");
    }
}

void TestReverse() {
    Editor editor;

    const string text = "esreveR";
    for(char c : text) {
        editor.Insert(c);
        editor.Left();
    }

    ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
    Editor editor;
    ASSERT_EQUAL(editor.GetText(), "");

    editor.Left();
    editor.Left();
    editor.Right();
    editor.Right();
    editor.Copy(0);
    editor.Cut(0);
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "");
}
void TestManyInserts() {
    Editor editor;
   for(int i=0;i<1'000'000;i++){
       editor.Insert(i);
   }
}
void TestManyPaste() {
    Editor editor;
    TypeText(editor,"Hello ");
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Copy(6);
    for(int i=0;i<1'000'000;i++){
        editor.Paste();
    }

}

void TestEmptyBuffer() {
    Editor editor;
    editor.Paste();
    TypeText(editor, "example");
    editor.Left();
    editor.Left();
    editor.Paste();
    editor.Right();
    editor.Paste();
    editor.Copy(0);
    editor.Paste();
    editor.Left();
    editor.Cut(0);
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "example");
}

int main() {
    LOG_DURATION("TEST ALL")
    TestRunner tr;
    RUN_TEST(tr, TestEditing);
    RUN_TEST(tr, TestReverse);
    RUN_TEST(tr, TestNoText);
    RUN_TEST(tr, TestEmptyBuffer);
    RUN_TEST(tr, TestManyInserts);
    RUN_TEST(tr, TestManyPaste);



//    Editor ed;
//    TypeText(ed,"kekes");
//    cout<<ed.GetText()<<endl;
//    ed.Left();
//    ed.Left();
//    ed.GetIndex();
//    ed.Cut(3);
//    cout<<ed.GetBuffer()<<endl;
//    cout<<ed.GetText()<<endl;
//    deque<int>src={1,2,3};
//    deque<int>dst={};
//    remove_copy(src.begin()+1,src.end(),dst.begin(),true);

//    list<char> string={'a','b','c','d','e','f'};
//    list<char>::iterator iter=string.begin();
//    cout<<distance(string.begin(),iter)<<endl;
//    auto it=string.begin();
//    advance(it,2);
//    buffer.splice(buffer.begin(),string,string.begin(),it);
//    for(auto x:string){
//        cout<<x;
//    }
//    cout<<endl;
//    for(auto x:buffer){
//        cout<<x;
//    }
//    cout<<endl;
    return 0;
}