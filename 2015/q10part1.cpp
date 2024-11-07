#include <iostream>
#include <vector>
using namespace std;
int main(){

    int n = 1113222113;
    int duplicate = n;
    vector<int> digits;
    int count = 1;
    int ans = 1;
    while(duplicate!=0){
        int a = duplicate%10;
        if(digits.size()==0){ 
            digits.push_back(a);
        }
        else if(digits.back()==a){
            count++;
        }
        else{
            cout<<count<<endl;
            count = 1;
            digits.push_back(a);
        }
        if(duplicate<10){
            cout<<count<<endl;
            count = 1;
            digits.push_back(a);
        }
        duplicate = duplicate/10;
    }
}