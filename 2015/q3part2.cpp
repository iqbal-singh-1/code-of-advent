#include <iostream>
#include <vector>
#include <string>

using namespace std;

//moving according to the need
void walk(char move,int &x,int &y){
    if (move == '^') y++;
    else if (move == 'v') y--;
    else if (move == '>') x++;
    else if (move == '<') x--;
}


int main() {
    string directions;
    vector<vector<int>> positions = {{0,0}};
    int x1 = 0, y1 = 0,x2 = 0, y2 = 0;
    int t = 1;
    int count = 0;
    while(true) {

    if(!t) break;
    // Read the entire line of directions
    cin >> directions;

    for (char move : directions) {
        if(count%2==0) {
            walk(move,x1,y1);
        }
        else if(count%2==1) {
            walk(move,x2,y2);
        }

        // Check for uniqueness
        bool duplicate = false;
        for (const auto& pos : positions) {
            if (count%2==0 && (pos[0] == x1 && pos[1] == y1)) {
                duplicate = true;
                break;
            }
            else if(count%2==1 && (pos[0] == x2 && pos[1] == y2)){
                duplicate = true;
                break;
            }
        }
        
        // Add to positions if unique
        if (!duplicate) {
            if(count%2==0) positions.push_back({x1, y1});
            else positions.push_back({x2,y2});
        }
        count++;
    }

    cout << positions.size() << endl;
    
    cout <<"proceed further????";
    cin>>t;
    cout<<endl;
    cout<<x1<<" "<<y1<<" and "<<x2<<" "<<y2;
    }
    return 0;
}



