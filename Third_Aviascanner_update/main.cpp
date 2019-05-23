#include "airline_ticket.h"
#include "test_runner.h"
#include <iostream>
#include <string>
using namespace std;

bool operator < (const Date& lhs, const Date& rhs) {
  return tie(lhs.year, lhs.month, lhs.day) < tie(rhs.year, rhs.month, rhs.day);
}

bool operator == (const Date& lhs, const Date& rhs) {
  return tie(lhs.year, lhs.month, lhs.day) == tie(rhs.year, rhs.month, rhs.day);
}

bool operator < (const Time& lhs, const Time& rhs) {
  return tie(lhs.hours, lhs.minutes) < tie(rhs.hours, rhs.minutes);
}

bool operator == (const Time& lhs, const Time& rhs) {
  return tie(lhs.hours, lhs.minutes) == tie(rhs.hours, rhs.minutes);
}

ostream& operator<<(ostream& os, const Date& d) {
  return os << d.year << '-' << d.month << '-' << d.day;
}
istringstream& operator>>(istringstream& is, Date& dt){
    string unparsed_date;
    is>>unparsed_date;
    string tmp;
    enum class DataType {
        MONTH,
        YEAR,

    };
    DataType tk=DataType::YEAR;
    for (uint32_t i=0;i<unparsed_date.length();i++){

        if(unparsed_date[i]!='-' && i!=unparsed_date.length()) {
            tmp += unparsed_date[i];
        }else{
            switch(tk){
                case (DataType::YEAR):{
                    dt.year=stoi(tmp);
                    tk=DataType ::MONTH;
                    break;
                }
                case (DataType ::MONTH):{
                    dt.month=stoi(tmp);
                    dt.day=stoi(unparsed_date.substr(i+1,unparsed_date.length()-1));
                    break;
                }

            }
            tmp="";
        }

    }

    return is;
}
ostream& operator<<(ostream& os, const Time& t) {
    return os << t.hours << ':' << t.minutes;
}
istringstream& operator>>(istringstream& is, Time& tm){
    string unparsed_time;
    bool is_hour=true;
    is>>unparsed_time;
    string tmp_hour,tmp_min;
    for (uint32_t i=0;i<unparsed_time.length();i++){
        if(unparsed_time[i]!=':'){
            if(is_hour){
                tmp_hour+=unparsed_time[i];
            }else{
                tmp_min+=unparsed_time[i];
            }
        }else{
            is_hour=false;
        };
    }
    tm.hours=stoi(tmp_hour);
    tm.minutes=stoi(tmp_min);
    return is;
}

#define UPDATE_FIELD(ticket, field, values){        \
      auto it = (values.find(#field));              \
      if (it != values.end()) {                     \
            istringstream is(it->second);            \
            is >> ticket.field;                      \
      }                                             \
}

void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}
