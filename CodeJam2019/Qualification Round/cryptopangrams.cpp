#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <algorithm>

using namespace std;

vector<string> results;

void func_threads(unsigned i, vector<unsigned> nums, vector<unsigned> primes){
    vector<unsigned> pos_res;
    for(unsigned j = 0; j < primes.size(); j++){
        if(nums[0] % primes[j] == 0 && nums[1] % primes[j] == 0){
            pos_res.push_back(nums[0]/primes[j]);
            pos_res.push_back(primes[j]);
            pos_res.push_back(nums[1]/primes[j]);
            break;
        }
    }
    
    for(unsigned j = 2; j < nums.size(); j++){
        pos_res.push_back(nums[j]/pos_res[pos_res.size()-1]);   
    }
    
    vector<unsigned> order_v(pos_res);
    sort(order_v.begin(), order_v.end());
    order_v.erase( unique(order_v.begin(), order_v.end() ), order_v.end() );
    string result = "";
    char c;
    for(unsigned j = 0; j < pos_res.size(); j++){
        for(unsigned k = 0; k < order_v.size(); k++){
            if(order_v[k] == pos_res[j]){
                c = 'A' + k;
                break;
            }
        }
        result.push_back(c);
    }
    
    results[i] = result;
}

void calc_primes(vector<unsigned> &primes, unsigned N){
    unsigned i = 3;
    primes.push_back(2);
    bool isPrime;
    while(i <= N){
        isPrime = true;
        for(unsigned j = 2; j <= i / 2; j++)
        {
            if(i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
            primes.push_back(i);
        i += 2;
    }
}

int main(){
    unsigned T, N, L, value;
    cin >> T;
    results.resize(T);
    
    vector<unsigned> nums;
    vector<unsigned> primes;
    vector<thread> threads;
    
    for(unsigned  i = 0; i < T; i++){
        nums.clear();
        primes.clear();
        cin >> N >> L;
        thread t (calc_primes, ref(primes), N);
        while(L > 0){
            cin >> value;
            nums.push_back(value);
            L--;
        }
        t.join();
        threads.push_back(thread(func_threads, i, nums, primes));
    }
    
    for(unsigned i = 0; i < threads.size(); i++){
        threads[i].join();
    }
    
    for(unsigned i = 0; i < T; i++){
        cout << "Case #" << i+1 << ": " << results[i] << endl;
    }
    
    return 0;
}