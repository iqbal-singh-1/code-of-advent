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

        //Accounts for 0s if number of rotations are greater than 100
        if(num>=100){
            countyy += num/100;
            num = num%100;
        }

        //Left rotation logic is that if start - num <=0 we cross 0
        //Right rotation logic is that if start + num >=100 we cross 0
        if(left){
            if((start - num)<=0 && start!=0) countyy++;
            start -= num;
            if(start<0) start+=100;
            start = start%100;
        }
        else{
            if((start + num)>=100) countyy++;
            start += num;
            start = start%100;
        }
        left = 1;
    }
    cout<<countyy<<endl;
    return 0;
}