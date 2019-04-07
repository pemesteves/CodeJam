#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <random>
#include <sstream>
#include <time.h>

using namespace std;

vector<string> results;

bool insert_character(vector<vector<char>> &v, string &s, unsigned i, unsigned j){
    if(i == v.size()-1 && j == v.size()-1)
        return true;
    if(i >= v.size() || j >= v.size())
        return false;
    
    if(v[i][j] == '\0'){
        v[i][j] = 'S';
        s.push_back('S');
        if(insert_character(v, s, i+1, j))
            return true;
        s.pop_back();
        v[i][j] = '\0';
        v[i][j] = 'E';
        s.push_back('E');
        if(insert_character(v, s, i, j+1))
            return true;
        s.pop_back();
        return false;
    }
    
    if(v[i][j] == 'e'){
        v[i][j] = 'S';
        s.push_back('S');
        if(insert_character(v, s, i+1, j))
            return true;
        s.pop_back();
        v[i][j] = 'e';
        return false;
    }
    
    if(v[i][j] == 's'){
        v[i][j] = 'E';
        s.push_back('E');
        if(insert_character(v, s, i, j+1))
            return true;
        s.pop_back();
        v[i][j] = 's';
        return false;
    }
    
    return false;
}
    

void func_threads(unsigned i, unsigned N, string P){
    vector<vector<char>> v(N, vector<char>(N, '\0'));
    int j = 0, k = 0;
    for(unsigned i = 0; i < 2*N-2; i++){
        v[j][k] = tolower(P[i]);
        if(P[i] == 'E')
            k++;
        else if(P[i] == 'S')
            j++;
    }
    
    string result;
    insert_character(v, result, 0, 0);
    
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