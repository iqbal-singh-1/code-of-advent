#include <iostream>
#include <string>
using namespace std;
int main() {
    int l[1001];
    int w[1001];
    int h[1001];
    int i = 0,area=0,total=0;
    while(i<1000){
        cin>>l[i]>>w[i]>>h[i];
        i++;
    }
    i = 0;
    while(i<1000){
        //finding minimum 2 out of l, w and h
        int min1 = 0,min2 = 0;
        if( l[i] <= h[i] && w[i]<=h[i]){
            min1 = l[i];
            min2 = w[i];
        }
        else if(w[i]<=l[i] && h[i]<=l[i] ) {
            min1 = w[i];
            min2 = h[i];
        }
        else{
            min1 = l[i];
            min2 = h[i];
        }

        //calculating the volume + minimum perimeter
        area = 2*(min1+min2) + l[i]*w[i]*h[i];
        total+=area;
        i++;
    }
    cout<<total;

}