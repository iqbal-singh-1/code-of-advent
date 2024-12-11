#include <bits/stdc++.h>
using namespace std;

int calculateSize(  long long number) {
    if (number == 0) return 1;
    return log10(number) + 1; // Calculates number of digits in the number
}

unsigned long long splitNumber(unsigned long long num,deque<unsigned long long>& newArr, unsigned long long count) {
    std::string numStr = std::to_string(num);  // Convert the number to a string

    int length = numStr.length();
    int mid = length / 2;

    std::string part1 = numStr.substr(0, mid);
    std::string part2 = numStr.substr(mid);

    // Convert parts back to unsigned long long for displaying
    unsigned long long part1Num = std::stoull(part1);
    unsigned long long part2Num = std::stoull(part2);
    newArr[part1Num] = newArr[part1Num] + count + 1;
    newArr[part2Num] = newArr[part2Num] + count + 1;
}

void perform(map<unsigned long long ,unsigned long long>& arr) {
    map<unsigned long long ,unsigned long long> newArr;

    for (auto it = newArr.begin(); it != newArr.end(); ++it) {
        if(it->first==0) {
            newArr[it->first] = newArr[it->first] + it->second + 1;
        }
        else if(calculateSize(it->first) % 2 == 0) {
            splitNumber(it->first,newArr,it->second);
        }
        else{
            newArr[it->first * 2024] = newArr[it->first] + it->second + 1;
        }
    }
    for (auto it = newArr.begin(); it != newArr.end(); ++it) {
        if(arr.find(it->first) != arr.end()) {
            arr[it->first] = arr[it->first] + newArr[it->first];
        }
        else{
            arr[it->first] = newArr[it->first];
        }
    }

    
}

int main() {
    // Starting with an initial deque of numbers
    map<unsigned long long, unsigned long long> arr = {{0,1} ,{7,1} , {6618216,1} , {26481,1} , {885,1} , {42,1} , {202642,1} , {8791,1} };

    // Perform the operations for a specified number of iterations
    for (int i = 0; i < 25; i++) {
    perform(arr);
    cout<<i<<endl;
}
unsigned long long count = 0;

    for (auto it = arr.begin(); it != arr.end(); ++it) {
        count += it->second;
    }
    // Display the final size of the array
    cout<<count<<endl;
    return 0;
}