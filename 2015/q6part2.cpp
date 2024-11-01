#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//calculate no of lights on
int calcLightsOn(vector<vector< int>> & v){
    int count = 0;
    for(int i = 0;i<v.size() ; i++){
        for(int j = 0; j<v[0].size() ; j++){
            if(v[i][j]>=1){
                count+=v[i][j];
            }
        }
    }
    return count;
}

//increase brightness by 1
void turnOn(vector<vector< int>> & v,int startx,int starty,int endx,int endy ){
    for(int i = startx; i<=endx; i++){
        for(int j = starty; j<=endy ; j++){
            v[i][j]+=1;
        }
    }
}

//decrease brightness by 1
void turnOff(vector<vector< int>> & v,int startx,int starty,int endx,int endy ){
    for(int i = startx; i<=endx; i++){
        for(int j = starty; j<=endy ; j++){
            if(v[i][j]>=1) v[i][j] -= 1;
        }
    }
}

//increase brightness by 2
void toggle(vector<vector< int>> & v,int startx,int starty,int endx,int endy ){
    for(int i = startx; i<=endx; i++){
        for(int j = starty; j<=endy ; j++){
            v[i][j] += 2;
        }
    }
}

int main() {
    ifstream myfile("q6input.txt");
    vector<vector< int>> v(1000, vector< int>(1000, false)); 
    string s;

    if (myfile.is_open()) {
        while (myfile >> s) {
            cout << s<<endl;
            int x1,x2,y1,y2;
            myfile>>x1;
            myfile>>y1;
            myfile>>x2;
            myfile>>y2;

            // Call appropriate function based on the command
            if (s[0] == 'O') turnOn(v, x1, y1, x2, y2);
            if (s[0] == 'N') turnOff(v, x1, y1, x2, y2);
            if (s[0] == 'T') toggle(v, x1, y1, x2, y2);
        }
        myfile.close(); // Always good to close the file
    } else {
        cout << "Unable to open file." << endl;
    }

    //printing the answer
    cout << calcLightsOn(v) << endl;

    return 0;
}