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
    int x = 0, y = 0;
    int t = 1;
    while(true) {

    if(!t) break;
    // Read the entire line of directions
    cin >> directions;

    for (char move : directions) {
        
        walk(move,x,y);

        // Check for uniqueness
        bool duplicate = false;
        for (const auto& pos : positions) {
            if (pos[0] == x && pos[1] == y) {
                duplicate = true;
                break;
            }
        }
        
        // Add to positions if unique
        if (!duplicate) {
            positions.push_back({x, y});
        }
    }

    cout << positions.size() << endl;
    
    cout <<"proceed further????";
    cin>>t;
    cout<<endl;
    cout<<x<<" "<<y;
    }
    return 0;
}



