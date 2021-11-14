//
// Created by Master on 2021/11/13.
//
#include <iostream>
#include <string>
using namespace std;
bool detectCapitalUse(string word) {
    int flag = 1;
    if(islower(word[0])){
        for(int i=1; i<word.length(); i++){
            if(isupper(word[i])){
                cout<<islower(word[i])<<endl;
                flag = 0;
                break;
            }
        }

    }
    else if(isupper(word[0]) && isupper(word[1])){
        for(int i=2; i<word.length(); i++){
            if(islower(word[i])){
                flag = 0;
                break;
            }
        }

    }
    else if(isupper(word[0]) && islower(word[1])){
        for(int i=2; i<word.length(); i++){
            if(isupper(word[i])){
                flag = 0;
                break;
            }
        }

    }
    return flag != 0;
}

int main(){
    string word("ggg");
    bool t = detectCapitalUse(word);
    bool q = islower(word[1]);
    cout<<t<<endl<<q;
    return 0;
}
