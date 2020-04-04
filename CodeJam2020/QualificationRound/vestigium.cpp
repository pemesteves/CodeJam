#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++){
        int N, Mi;
        vector<vector<int>> matrix;
        int rows_repeated = 0;
        cin >> N;
        for(int j = 0; j < N; j++){
            vector<int> line;
            unordered_set<int> nums;
            bool rep_val = false;
            for(int k = 0; k < N; k++){
                cin >> Mi;
                line.push_back(Mi);
                if(!rep_val){
                    auto it = nums.insert(Mi);
                    if(!it.second){
                        rep_val = true;
                    }
                }
            }
            if(rep_val)
                rows_repeated++;
            matrix.push_back(line);
        }
        
        int trace = 0;
        for(int j = 0; j < N; j++){
            trace += matrix[j][j];
        }
        
        int cols_repeated = 0;
        for(int j = 0; j < N; j++){
            unordered_set<int> nums;
            for(int k = 0; k < N; k++){
                auto it = nums.insert(matrix[k][j]);
                if(!it.second){
                    cols_repeated++;
                    break;
                }
            }   
            
        }
        cout << "Case #" << (i+1) << ": " << trace << " " << rows_repeated << " " << cols_repeated << endl;
    }
    
    return 0;
}