#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//checking if the entered string is hexadecimal or not
bool checkHex(char c){
    if((c>='0' && c<='9') || (c>='a' && c<='f') || (c>='A' && c<='F')){
        return 1;
    }
    return 0;
}

//counting all the characters escaped
int charactersEscaped(string str){
    int count = 0;
    int i = 0;
    while(i<str.size()-1){

        if(str[i]=='\\' && (str[i+1]=='\\' || str[i+1] == '"')){
            
            //checking if the given string contains " \\ " or " \" "

            count++;
            i++;
        }
        else if(str.size()-i<4){

            //if size-i<4, it cannot be hexadecimal, so skip it

            i++;
            continue;
        }
        else if(str[i]=='\\' && str[i+1]=='x' && checkHex(str[i+2]) && checkHex(str[i+3])){

            //if the given string is hexadecimal, 3 characters are escaped

            count+=3;
            i+=3;
        }
        i++;
    }
    return count;
}

int main(){

    string s;
    int totalCount = 0;
    int newCount = 0;
    ifstream myfile;
    myfile.open("q8input.txt");

    //taking file input
    while(myfile>>s){

        //total words = size of string
        totalCount += s.size();

        //characters left after skipping escape characters and double qoutes at starting and end
        newCount += s.size() - 2 - charactersEscaped(s);
        cout<<newCount<<endl;
    }
    myfile.close();
    cout<<totalCount-newCount;

}