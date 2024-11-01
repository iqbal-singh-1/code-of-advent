#include <iostream>
#include <string>
using namespace std;
int main(){
    char a[7002];
    cin>>a;
    int count = 0;
    int countup = 0;
    for(int i = 0; i<7000 ; i++){
        if(a[i]=='('){
            //if parethesis is "(", move one floor up
            count++;
            countup++;
        }
        else if(a[i]==')'){
            //if parethesis is ")", move one floor down
            count--;
        }

        //when you are on -1 floor, break the code
        if(count<0) break;
    }
    cout<<endl<<countup + 1;

}