#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include "profile.h"
#include "test_runner.h"
using namespace std;
class Request{
public:
    Request(int64_t time_,int client_id_,int room_count_):
            time(time_),client_id(client_id_),room_count(room_count_){

    }
    int Get_id(){
        return client_id;
    }
    int64_t Get_time() {
        return time;
    }
    int Get_room_count(){
        return room_count;
    }

private:
    int client_id;
    int64_t time;
    int room_count;
};
class BookingManager{
public:
    BookingManager(){

    }
    void Book(int64_t time,string hotel_name,int client_id,int room_count){
        time_line.push_back(time);
        Base[hotel_name].push_back(Request(time,client_id,room_count));
        rooms[hotel_name]+=room_count;
        clients[hotel_name][client_id]+=room_count;
        Update(hotel_name);



    }
    int Clients(const string& hotel_name) {
        Update(hotel_name);
        return clients[hotel_name].size();

    }
    int Rooms(const string& hotel_name) {
        Update(hotel_name);
        return rooms[hotel_name];
    }
    void Update(const string& hotel_name){
        if (!(time_line.size()>1 && time_line.back()-time_line.front()>=86400)){
            return;
        }
        deque<Request>& cur_deq =Base[hotel_name];
            if (!cur_deq.empty()) {
                auto& cur_rooms=rooms[hotel_name];
                auto& cur_clients=clients[hotel_name];
                int64_t border=time_line.back()-86400;
                while(cur_deq.front().Get_time()<=border && !(cur_deq.empty())){
                        time_line.pop_front();
                        cur_rooms-=cur_deq.front().Get_room_count();
                        cur_clients[cur_deq.front().Get_id()]-=cur_deq.front().Get_room_count();
                        if(cur_clients[cur_deq.front().Get_id()]==0)
                            cur_clients.erase(cur_deq.front().Get_id());
                        cur_deq.pop_front();
                }
            }

    }

private:
    map<string,deque<Request>> Base;
    map<string,map<int,int>> clients;
    map<string,int> rooms;
    deque<int64_t> time_line;
};
void TestAll() {
    {
        BookingManager bk;
        bk.Book(10, "Hotel1", 1, 10);
        ASSERT_EQUAL(bk.Rooms("Hotel1"), 10);
        ASSERT_EQUAL(bk.Clients("Hotel1"), 1);

        bk.Book(11, "Hotel1", 2, 20);
        ASSERT_EQUAL(bk.Rooms("Hotel1"), 30);
        ASSERT_EQUAL(bk.Clients("Hotel1"), 2);

        bk.Book(10, "Hotel2", 1, 10);
        ASSERT_EQUAL(bk.Rooms("Hotel2"), 10);
        ASSERT_EQUAL(bk.Clients("Hotel2"), 1);

        bk.Book(11, "Hotel2", 2, 20);
        ASSERT_EQUAL(bk.Rooms("Hotel2"), 30);
        ASSERT_EQUAL(bk.Clients("Hotel2"), 2);

        bk.Book(86410, "Hotel1", 1, 10);
        ASSERT_EQUAL(bk.Rooms("Hotel1"), 30);
        ASSERT_EQUAL(bk.Clients("Hotel1"), 2);
    }
    {
        BookingManager bk;
        bk.Book(0,"Hotel1",1,1);
        bk.Book(86400,"Hotel1",1,1);
        bk.Book(172800,"Hotel1",1,1);
        bk.Book(259200,"Hotel1",1,1);
        bk.Book(345600,"Hotel1",1,1);
        ASSERT_EQUAL(bk.Clients("Hotel1"),1);
        ASSERT_EQUAL(bk.Rooms("Hotel1"),1);
    }
    {
        BookingManager bk;
        bk.Book(0,"Hotel1",1,1);
        bk.Book(1,"Hotel1",1,1);
        bk.Book(2,"Hotel1",1,1);
        bk.Book(3,"Hotel1",1,1);
        bk.Book(4,"Hotel1",1,1);
        bk.Book(5,"Hotel1",1,1);
        ASSERT_EQUAL(bk.Clients("Hotel1"),1);
        ASSERT_EQUAL(bk.Rooms("Hotel1"),6);

    }

}
int main() {
    TestRunner tr;
    RUN_TEST(tr,TestAll);
    {
        BookingManager bk;
        {
            LOG_DURATION("BOOK")
            for (int i = 0; i < 20000; i++) {
                bk.Book(i, to_string(i), i + 1, i + 2);
            }
        }
        {
            LOG_DURATION("Rooms")
            for (int i = 0; i <20000; i++) {
                bk.Rooms(to_string(i));

            }
        }
        {
            LOG_DURATION("Clients")
            for (int i = 0; i <20000; i++) {
                bk.Clients(to_string(i));
            }
        }
    }

    int query_count;
    cin >> query_count;
    BookingManager bk;
    for (int query_id = 0; query_id < query_count; ++query_id) {
        string command;
        cin >> command;
        string hotel_name;
        if (command == "BOOK") {
            int64_t time;
            int client_id,room_count;
            cin>>time;
            cin>>hotel_name;
            cin>>client_id>>room_count;
            bk.Book(time, hotel_name,client_id,room_count);
        } else if (command == "CLIENTS") {
            cin>>hotel_name;
            cout<<bk.Clients(hotel_name)<<"\n";
        } else if (command == "ROOMS"){
            cin>> hotel_name;
            cout<<bk.Rooms(hotel_name)<<"\n";
        }
    }
    return 0;
}