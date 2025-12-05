#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string line;
    vector<pair<long long,long long>> validRanges;
    vector<long long> ids;

    while(getline(cin,line)){
        if(line.size()==0) break;
        string w1,w3;
        bool found = 0;
        for(char c : line){
            if(c=='-'){
                found = 1;
                continue;
            }
            if(c==' '||c=='\t'||c=='\r') continue;
            if(found) w3.push_back(c);
            else w1.push_back(c);
        }
        if(w1.size()==0) continue;

        if(!found){
            break;
        }
        else{
            long long start = stoll(w1);
            long long end = stoll(w3);
            validRanges.push_back({start,end});
        }
    }

    sort(validRanges.begin(), validRanges.end());

    vector<pair<long long,long long>> merged;
    for(auto &p : validRanges){
        if(merged.empty() || p.first > merged.back().second){
            merged.push_back(p);
        } else {
            merged.back().second = max(merged.back().second, p.second);
        }
    }

    long long countValid = 0;

    for(int i = 0; i < merged.size(); ++i){
        countValid += merged[i].second - merged[i].first + 1;
    }

    cout << countValid;
}
