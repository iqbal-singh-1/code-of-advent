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
        if(line.size()==0) continue;
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
            ids.push_back(stoll(w1));
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

    for(long long x : ids){
        int l = 0, r = merged.size() - 1;
        bool ok = 0;
        while(l <= r){
            int m = (l+r)/2;
            long long a = merged[m].first;
            long long b = merged[m].second;
            if(x < a) r = m - 1;
            else if(x > b) l = m + 1;
            else { ok = 1; break; }
        }
        if(ok) countValid++;
    }

    cout << countValid;
}
