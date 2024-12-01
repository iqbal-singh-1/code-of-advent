#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    char c;

    ifstream myfile;
    myfile.open("q12input");

    while(myfile>>c){
        cout<<c<<endl;
    }

}