#include <iostream>
#include <string>
#include <thread>
#include <utility>
#include <sstream>
#include <vector>

using namespace std;

vector<pair<unsigned, unsigned>> v;

void calc_values(int j, string N){
   string B;
   B.resize(N.length());
   for(int i = 0; i < N.length(); i++){
        if(N[i] != '4')
            B[i] = '0';
        else{
            B[i] = '1';
            N[i] = '3';
        }
   }
   
   v[j] = make_pair(stoi(N), stoi(B));
}

int main(){
    unsigned T;
    cin >> T;
    v.resize(T);
    vector<thread> v1;
    
    unsigned N;
    string argument;
    
    for(unsigned i = 0; i < T; i++){
        cin >> N;
        ostringstream oss;
        oss << N;
        argument = oss.str();
        v1.push_back(thread(calc_values, i, argument));
        oss.str(std::string());
    }
    
    for(unsigned i = 0; i < v1.size(); i++){
        v1[i].join();
    }
    
    for(unsigned i = 0; i < v.size(); i++){
        cout << "Case #"  << i+1 << ": " << v[i].first << " " << v[i].second << endl;
    }
    
    return 0;
}