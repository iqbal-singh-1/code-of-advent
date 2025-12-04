#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string line;
    vector<vector<bool>> grid;
    while(getline(cin, line)){
        vector<bool> row;
        for(char c : line) row.push_back(c == '@');
        grid.push_back(row);
    }

    long long ans = 0;

    while(true){
        bool changed = false;
        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){
                if(!grid[i][j]) continue;
                int neighbours = 0;
                if((j-1) >= 0 ) neighbours += grid[i][j-1];
                if((j+1) < grid[i].size()) neighbours += grid[i][j+1];
                if((i-1) >= 0){
                    if((j-1) >= 0 ) neighbours += grid[i-1][j-1];
                    neighbours += grid[i-1][j];
                    if((j+1) < grid[i].size()) neighbours += grid[i-1][j+1];
                }
                if((i+1) < grid.size()){
                    if((j-1) >= 0 ) neighbours += grid[i+1][j-1];
                    neighbours += grid[i+1][j];
                    if((j+1) < grid[i].size()) neighbours += grid[i+1][j+1];
                }
                if(neighbours < 4){
                    ans++;
                    grid[i][j] = false;
                    changed = true;
                }
            }
        }
        if(!changed) break;
    }
    cout << ans;
}