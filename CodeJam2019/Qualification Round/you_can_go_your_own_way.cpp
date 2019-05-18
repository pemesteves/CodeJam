#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <random>
#include <sstream>
#include <time.h>

using namespace std;

vector<string> results;

void func_threads(unsigned i, unsigned N, string P){
    string result;
    for(unsigned j = 0; j < P.length(); j++){
        if(P[j] == 'E')
            result.push_back('S');
        else
            result.push_back('E');
    }
    results[i] = result;
}

int main(){
    srand(time(NULL));
    unsigned T, N;
    cin >> T;
    results.resize(T);
    string P;
    
    vector<thread> threads;
    
    for(unsigned  i = 0; i < T; i++){
        cin >> N;
        cin >> P;
        threads.push_back(thread(func_threads, i, N, P));
        P.resize(0);
    }
    
    for(unsigned i = 0; i < threads.size(); i++){
        threads[i].join();
    }
    
    for(unsigned i = 0; i < T; i++){
        cout << "Case #" << i+1 << ": " << results[i] << endl;
    }
    
    return 0;
}