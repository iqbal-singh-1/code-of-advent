#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool repeat(string s){
    for(int i = 0; i<s.size()-2; i++){
        if(s[i]==s[i+2]) return 1;
    }
    return 0;
}

bool includeCopy(string s){

    for(int i = 0; i<s.size()-3 ; i++){
        for(int j = i+2; j<s.size()-1 ; j++){
            if(s[i]==s[j] && s[i+1]==s[j+1]){
                return 1;
            }
        }
    }
    return 0;
}

bool niceString(string s){
    if(repeat(s) && includeCopy(s)){
        return 1;
    }
    return 0;
}

int main(){

    ifstream myfile;
    myfile.open("q5input.txt");
    string s;
    int count = 0;
    if(myfile.is_open()) while(myfile.good()){
        myfile>>s;
        if(niceString(s)) count++;
        // cout<<s<<endl;
    }
    // if(niceString(s)) count++;
    cout<<count;

}