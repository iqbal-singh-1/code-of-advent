#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<string> myvec;
vector<vector<int>> happiness(10,vector<int>(10,0));
vector<int> totalHappiness;
vector<int>seated(10,0);

string extractWord(string str,int count){
    string temp;
    count--;
    for(char c: str){
        if(c==' '){
            count--;
            continue;
        }
        if(c=='.') continue;
        if(count==0) temp+=c;
    }
    return temp;
}

bool checkPresence(vector<string> myvec, string &Name){
    for(int i = 0; i<myvec.size() ; i++) {
        if(myvec[i] == Name){
            return 1;
        }
    }
    return 0;
}

void addName(vector<string>& myvec, string &name){
    myvec.push_back(name);
}

int findIndex(string &name){

    for(int i = 0 ; i<myvec.size() ; i++) {
        if(myvec[i]==name) return i;
    }

    return -1;
}

void calHappiness(string startName ,string nextName,int& total) {

    int index1 = findIndex(nextName);
    seated[index1] = 1;

    int maxi = INT32_MIN;
    int index2 = -1;
    
    for(int i = 0; i<myvec.size(); i++) {
        if(seated[i]==1) continue;
        if( maxi< (happiness[index1][i] + happiness[i][index1]) ) {
            maxi = max( maxi, happiness[index1][i] + happiness[i][index1] );
            index2 = i;
        }
    }

    if(index2==-1){
        for(int i = 0; i<myvec.size() ; i++) {
            seated[i]=0;
        }
        int startIndex = findIndex(startName);
        total+= happiness[index1][startIndex] + happiness[startIndex][index1];
        totalHappiness.push_back(total);
        return;
    }
    total+=maxi;
    calHappiness(startName,myvec[index2],total);


}

int main(){
    ifstream myfile;
    myfile.open("q13input.txt");
    string str;
    int i = 0;
    while(getline(myfile,str)){
        string name1 = extractWord(str,1);
        string name2 = extractWord(str,11);
        int happy = stoi(extractWord(str,4));

        if(!checkPresence(myvec,name1)) {
            addName(myvec,name1);
        }

        if(!checkPresence(myvec,name2)) {
            addName(myvec,name2);
        }

        string word = extractWord(str,3);
        int index1 = findIndex(name1);
        int index2 = findIndex(name2);

        if(word=="gain") happiness[index1][index2] = happy;
        else happiness[index1][index2] = -happy;
        
    }

    myfile.close();

    for(int i = 0; i<myvec.size() ; i++) {
        int total = 0;
        calHappiness(myvec[i],myvec[i],total);
    }

    int maxi = INT32_MIN;
    for(int i = 0; i<totalHappiness.size() ; i++) {
        maxi = max(maxi,totalHappiness[i]);
    }
    cout<<maxi;
}