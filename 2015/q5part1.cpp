#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//counting the vowels
int vowelCount(string s){
    string vowels = {'a','e','i','o','u'};
    int count = 0;
    for(int i = 0 ; i<s.size() ; i++){
        for(int j = 0; j<5 ; j++){
            if(s[i]==vowels[j]){
                count++;
                break;
            }
        }
    }
    return count;
}

// checking if 2 consecutive characters are same or not
bool doubleChar(string s){
    for(int i = 0 ; i<s.size()-1 ; i++){
        if(s[i]==s[i+1]){
            return 1;
        }
    }
    return 0;
}

//checking if the given string contain ab or cd or pq or xy consecutively in a string or not
bool notContain(string s){

    for(int i = 0; i<s.size()-1 ; i++){
        if((s[i]=='a' && s[i+1]=='b') 
        || 
        (s[i]=='c' && s[i+1]=='d') 
        || 
        (s[i]=='p' && s[i+1]=='q') 
        || 
        (s[i]=='x' && s[i+1]=='y')){
            return 0;
        }
    }
    return 1;
}

//checking if the string satify all the 3 functions above, hence making a nice string
bool niceString(string s){
    if(vowelCount(s)>=3 && doubleChar(s) && notContain(s)){
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

        // checking if the string is nice or not
        if(niceString(s)) count++;
    }
    cout<<count;

}