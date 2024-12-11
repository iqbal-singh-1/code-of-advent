#include <bits/stdc++.h>

using namespace std;

void dottedPattern(string &str,int num){
    string temp;
    for(int i = 0; i<num; i++){
        temp+=".";
    }
    str.append(temp);
}

void idPattern(string &str,int id,int num) {
    string temp;
    for(int i = 0; i<num ; i++) {
        temp+=to_string(id);
    }
    str.append(temp);
}

bool isNumeric(char ch) {
    return ch >= '0' && ch <= '9';
}

int main() {

    ifstream myfile("q9input.txt");
    string str;
    string temp;

    while(getline(myfile,temp)){
        str += temp;
    }
    // cout<<str<<endl;
    myfile.close();
    
    int id = 0;
    string newStr;
    int i = 0;
    for(char c: str) {
        int num = c - '0';
        if(i%2==0) {
            idPattern(newStr,id,num);
            id++;
        }
        else{
            dottedPattern(newStr,num);
        }
        i++;
    }

    int start = 0;
    int end = newStr.size() - 1;

    while (start <= end) {
        if (newStr[start] == '.' && isNumeric(newStr[end])) {
            swap(newStr[start], newStr[end]);
            start++;
            end--;
        } else if (newStr[start] != '.') {
            start++;
        } else if (!isNumeric(newStr[end])) {
            end--;
        }
    }

    unsigned long long ans = 0;

    for(int i = 0; i<newStr.size() ; i++) {
        if(newStr[i]=='.') continue;
        int num = newStr[i] - '0';
        unsigned long long  product = num*i;
        ans+=product;
    }

    cout<<ans;



}