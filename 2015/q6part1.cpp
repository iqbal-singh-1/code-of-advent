#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//calculate the number og total lights on
int calcLightsOn(vector<vector<bool>> & v){
    int count = 0;
    for(int i = 0;i<v.size() ; i++){
        for(int j = 0; j<v[0].size() ; j++){
            if(v[i][j]==1){
                count++;
            }
        }
    }
    return count;
}

//turning lights on
void turnOn(vector<vector<bool>> & v,int startx,int starty,int endx,int endy ){
    for(int i = startx; i<=endx; i++){
        for(int j = starty; j<=endy ; j++){
            v[i][j]=1;
        }
    }
}

//turning lights off
void turnOff(vector<vector<bool>> & v,int startx,int starty,int endx,int endy ){
    for(int i = startx; i<=endx; i++){
        for(int j = starty; j<=endy ; j++){
            v[i][j]=0;
        }
    }
}

//change the state of light from off to on or vice-versa
void toggle(vector<vector<bool>> & v,int startx,int starty,int endx,int endy ){
    for(int i = startx; i<=endx; i++){
        for(int j = starty; j<=endy ; j++){
            if(v[i][j]==1) {
                v[i][j]=0;
            }
            else {
                v[i][j]=1;
            }
        }
    }
}

int main() {
    ifstream myfile("q6input.txt");
    vector<vector<bool>> v(1000, vector<bool>(1000, false)); 
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

    //printing the output
    cout << calcLightsOn(v) << endl;

    return 0;
}