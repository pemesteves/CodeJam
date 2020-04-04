#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int ctoi(char c){
    return (int)c-48;
}

int main(){
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        string S;
        cin >> S;
        ostringstream oss;

        int depth = 0;
        for(int j = 0; j < S.length(); j++){
            if(ctoi(S[j]) > depth){
                while(ctoi(S[j]) > depth){
                    oss << '(';
                    depth++;
                }
            }else if(ctoi(S[j]) < depth){
                while(ctoi(S[j]) < depth){
                    oss << ')';
                    depth--;
                }
            }
            oss << S[j];
        }
        while(depth > 0){
            oss << ')';
            depth--;
        }
        cout << "Case #" << (i+1) << ": " << oss.str() << endl;
    }

    return 0;
}