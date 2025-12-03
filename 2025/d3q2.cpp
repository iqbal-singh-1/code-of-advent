#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string str;
    long long countyy=0;
    while(getline(cin,str)){
        vector<int> digits;
        int canRemove = str.size() - 12;
        for(char c:str){
            int d = c - '0';
            if(digits.size()<1){
                digits.push_back(d);
                continue;
            }
            //The solution is simple, if we encounter a digit greter then the previous digits, then we pop the older digits if we haven't removed numbers such that the number is atleast 12 digits
            if(digits.back()<d){
                while(digits.size()!=0 && digits.back()<d && canRemove>0){
                    digits.pop_back();
                    canRemove--;
                }
            }
            digits.push_back(d);
        }
        long long num = -1;
        for(int i = 0; i<12; i++){
            if(num==-1) num = digits[i];
            else num = num*10 + digits[i];
        }
        cout<<num<<endl;
        countyy+=num;
    }
    cout<<countyy<<endl;

}