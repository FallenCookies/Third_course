#include<iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct Template{
public:
    string Country_Code;
    string Operator_Code;
    string Personal_Number;
    string Operator;

};
map<string,map<string,pair<string,string>>> base;
string Compare_number(string raw_numb){
    for(auto x:base){
        if(raw_numb.substr(0,x.first.length())==x.first){
            for(auto Operator_code:x.second){
                if (raw_numb.substr(x.first.length(),
                                    Operator_code.first.length())==Operator_code.first)
                {
                    if (raw_numb.length()-(x.first.length()+Operator_code.first.length())
                        ==Operator_code.second.first.length()){
                        bool is_ok=true;
                        size_t begin_index=x.first.length()+Operator_code.first.length();
                        for(size_t i=begin_index;i<Operator_code.second.first.length();i++){
                            if(!(Operator_code.second.first[i]=='X' ||
                                 Operator_code.second.first[i]==raw_numb[i])){
                                is_ok= false;

                            }
                        }
                        if(is_ok){
                            return "+"+x.first
                                   + " ("+Operator_code.first
                                   +") "+raw_numb.substr(begin_index,raw_numb.length()-begin_index)+" - "
                                   +Operator_code.second.second;
                        }
                    }

                }
            }
        }
    }
    return "";

}
int main(){

    vector<string> raw_numbers;
    int N;
    cin>>N;
    cin.ignore();
    string curr_raw_numb;
    for (int i=0;i<N;i++){
        getline(cin,curr_raw_numb);
        string tmp;
        for (auto x:curr_raw_numb){
            if(isdigit(x))
                tmp+=x;
        }
        raw_numbers.push_back(tmp);
        tmp.clear();

    }
    int M;
    cin>>M;
    cin.ignore();
    string curr_template;
    for (int i=0;i<M;i++){
        string tmp,oper1,oper2,Country_Code,Operator_Code,Personal_Number,Operator;
        Template t;
        cin>>Country_Code;
        Country_Code=Country_Code.substr(1,Country_Code.length());
        cin>>Operator_Code;
        Operator_Code=Operator_Code.substr(1,Operator_Code.length()-2);
        cin>>Personal_Number;
        cin.ignore(3);
        cin>>oper1;
        cin>>oper2;
        Operator=oper1+" "+oper2;

        base[Country_Code][Operator_Code]=make_pair(Personal_Number,Operator);

    }


    for(auto x:raw_numbers){
        cout<<Compare_number(x)<<endl;
    }
    return 0;
}
