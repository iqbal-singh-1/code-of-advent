#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(){
    //Take file input
    ifstream inputFile("d1q1i1.txt");
    string line;

    //Counter for number of times we cross 0
    long long countyy=0;

    //Direction flag
    bool left = 1;

    //Starting position
    int start = 50;

    //While the input is not empty
    while(getline(inputFile,line)){
        string temp;
        for(char c: line){
            if(isalpha(c)) continue;
            temp+=c;
        }

        //Shift direction based on input
        if(line[0]=='R') left = 0;

        int num = stoi(temp);

        //left rotation logic
        if(left){
            start -= num;
            start = start%100;
            if(start==0) countyy++;
        }
        //right rotation logic
        else{
            start += num;
            start = start%100;
            if(start==0) countyy++;
        }
        left = 1;
    }
    cout<<countyy<<endl;
    return 0;
}