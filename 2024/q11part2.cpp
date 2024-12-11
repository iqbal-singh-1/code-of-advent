#include <bits/stdc++.h>
using namespace std;

int calculateSize(long long number) {
    if (number == 0) return 1;
    return log10(number) + 1;  // Calculates number of digits in the number
}

void splitNumber(unsigned long long num, map<unsigned long long, unsigned long long>& newArr, unsigned long long count) {
    std::string numStr = std::to_string(num);  // Convert the number to a string
    int length = numStr.length();
    int mid = length / 2;

    std::string part1 = numStr.substr(0, mid);
    std::string part2 = numStr.substr(mid);

    // Convert parts back to unsigned long long for processing
    unsigned long long part1Num = std::stoull(part1);
    unsigned long long part2Num = std::stoull(part2);
    
    newArr[part1Num] += count ;
    newArr[part2Num] += count ;
}

void perform(map<unsigned long long, unsigned long long>& arr) {
    map<unsigned long long, unsigned long long> newArr;

    // Iterate over the original map (arr) and perform operations
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        if (it->first == 0) {
            if(newArr.find(1) != newArr.end()) {
                newArr[1] += 1;
            }
            else{
                newArr[1] = arr[it->first];
            }
        }
        else if (calculateSize(it->first) % 2 == 0) {
            splitNumber(it->first, newArr, it->second);
        }
        else {
            newArr[it->first * 2024] += it->second ;
        }
    }

    
    arr.clear();
    for (auto it = newArr.begin(); it != newArr.end(); ++it) {
        arr[it->first] = it->second;
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    // Starting with an initial map of numbers
    map<unsigned long long, unsigned long long> arr = {
        {{0,1}, {7,1}, {6618216,1}, {26481,1}, {885,1}, {42,1}, {202642,1}, {8791,1}}
    };

    // Perform the operations for a specified number of iterations
    for (int i = 0; i < 75; i++) {
        perform(arr);
    }

    // Count the sum of all values in the final map
    unsigned long long count = 0;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        count += it->second;
    }

    cout << "Final sum: " << count << endl;
    cout<<arr.size()<<endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;
    return 0;
}
