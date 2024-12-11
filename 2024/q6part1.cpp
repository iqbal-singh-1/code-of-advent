#include <bits/stdc++.h>
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
    while( startX!=endpoint2 && startY!=endpoint1 && startX!=0 && startY!=0) {
        path(startX,startY,direction);
        cout<<startX<<","<<startY<<" ";
    }
    cout<<endl;
    cout<<uniquePath<<endl;
}

