#include <bits\stdc++.h>
using namespace std;

vector<vector<char>> maze(130,vector<char>(130,'.'));
int startX = 0,startY=0;

int uniquePath = 1;
void processGraph(string &line,int col) {
    for(int i = 0; i<line.size(); i++){
        int x = i;
        int y = col;
        vector<int> arr = {x,y};
        maze[i][col] = line[i];

        if(line[i]=='^') {
            startX = x, startY = y;
        }
    }
    return ;
}

void move(int &x,int &y,int direction) {

    if(direction==1) y--;
    else if(direction==2) x++;
    else if(direction==3) y++;
    else if(direction==4) x--;
    return;
}

void changeDirection(int &direction) {
    if(direction==4) direction = 1;
    else direction++;
}

bool checkObstacle(int x, int y) {
    if(maze[x][y]=='#') return 1;
    return 0;
}

void path(int &x, int&y, int& direction) {
    int tempx = x;
    int tempy = y;
    
    move(tempx,tempy,direction);
    while(checkObstacle(tempx, tempy)) {
        tempx = x;
        tempy = y;
        changeDirection(direction);
        move(tempx,tempy,direction);
    }
    move(x,y,direction);
    if(maze[x][y]=='^') return;
    maze[x][y] = '^';
    uniquePath++;
}

int main() {
    string str;
    ifstream myfile("q6input.txt");
    int count = 0;
    int length = 0;
    int width = 0;
    while(getline(myfile,str)) {
        processGraph(str,count);
        width = str.size();
        count++;
    }
    myfile.close();
    length = count;
    int endpoint1 = length - 1;
    int endpoint2 = width - 1;
    int direction = 1;
    int countObstacles = 0;
    vector<pair<int,int>> arr;
    int count1 =0;
    while( startX!=endpoint2 && startY!=endpoint1 && startX!=0 && startY!=0) {
        int previous = direction;
        int tempx = startX;
        int tempy = startY;

        path(startX,startY,direction);

        if(previous!=direction) {
            move(tempx,tempy,previous);
            pair<int,int> p = {tempx,tempy};
            if(arr.size() < 3) { 
                arr.push_back(p);
            }
            else {
                bool isLoop = true;
                if(direction==1) {
                    if(p.first>=arr[0].first) {
                        isLoop = false;
                    }
                    else{
                        int temp = arr[0].first;
                        int y = p.second;
                        while(y>arr[0].second){
                            if(checkObstacle(temp,y)){
                                isLoop = false;
                                break;
                            }
                            move(temp,y,direction);
                        }
                    }
                
                }
                else if(direction==2) {
                    if(p.second>=arr[0].second) {
                        isLoop = false;
                    }
                    else{
                        int temp = arr[0].second;
                        int x = p.first;
                        while(x<arr[0].first) {
                            if(checkObstacle(x,temp)) {
                                isLoop = false;
                                break;
                            }
                            move(x,temp,direction);
                        }
                    }
                }
                else if(direction==3) {
                    if(p.first<=arr[0].first) {
                        isLoop = false;
                    }
                    else {
                        int temp = arr[0].first;
                        int y = p.second;
                        while(y<arr[0].second){
                            if(checkObstacle(temp,y)) {
                                isLoop = false;
                                break;
                            }
                            move(temp,y,direction);
                        }
                    }
                }
                else if(direction==4) {
                    if(p.second<=arr[0].second) {
                        isLoop = false;
                    }
                    else{
                        int temp = arr[0].second;
                        int x = p.first;
                        while(x>arr[0].first){
                            if(checkObstacle(x,temp)){
                                isLoop = false;
                            }
                            move(x,temp,direction);
                        }
                    }
                }
                if(isLoop) count1++;
                arr.erase(arr.begin());
                arr.push_back(p);
            }

        }
    }
    cout<<endl;
    cout<<uniquePath<<endl;
    cout<<count1<<endl;
}

