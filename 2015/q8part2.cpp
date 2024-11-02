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
int encodeCharactersEscaped(string str){
    int count = 0;
    int i = 0;
    while(i<str.size()-1){

        if(str[i]=='\\' && (str[i+1]=='\\' || str[i+1] == '"')){
            
            //increase count by 2 if escape charater is " \\ or \" "

            count+=2;
            i++;
        }
        else if(str.size()-i<4){

            //if size-i<4, it cannot be hexadecimal, so skip it

            i++;
            continue;
        }
        else if(str[i]=='\\' && str[i+1]=='x' && checkHex(str[i+2]) && checkHex(str[i+3])){

            //if the given string is hexadecimal, increase count by 1

            count++;
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

        //encoding escaped characters " \" " fixed 2 times at start and end of each line
        //and encoding each encoded character according to the requirement
        newCount += s.size() + encodeCharactersEscaped(s) + 4;
        cout<<newCount<<endl;
    }
    myfile.close();
    cout<<newCount-totalCount;

}