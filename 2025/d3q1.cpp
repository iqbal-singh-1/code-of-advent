#include <iostream>
#include <string>


using namespace std;

int main(){
    string str;
    int p1 = 0,p2 = 0;
    long long countyy=0;
    while(getline(cin,str)){

        //Find first maximum digit and its index
        int max1 = 0;
        int idx = -1;
        for(int i = 0; i<str.size(); i++){
            int d = str[i] - '0';
            if(d > max1) {
                max1 = d;
                idx = i;
            }
        }

        //if the max number is at end index, find 2nd max in front part.
        if(idx == str.size() - 1){
            int max2 = 0;
            for(int i = 0; i<idx; i++){
                int d = str[i] - '0';
                if(d > max2) {
                    max2 = d;
                }
            }
            countyy+= max2*10 + max1;
        }
        //if the max is at any other index, find 2nd max in the back part.
        else{
            int max2 = 0;
            for(int i = idx+1; i<str.size(); i++){
                int d = str[i] - '0';
                if(d > max2) {
                    max2 = d;
                }
            }
            countyy+= max1*10 + max2;
        }

    }
    cout<<countyy<<endl;
}