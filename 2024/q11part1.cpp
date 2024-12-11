#include <bits/stdc++.h>
using namespace std;

int calculateSize(  long long number) {
    if (number == 0) return 1;
    return log10(number) + 1; // Calculates number of digits in the number
}

unsigned long long splitNumber(unsigned long long num,deque<unsigned long long>& newArr) {
    std::string numStr = std::to_string(num);  // Convert the number to a string

    int length = numStr.length();
    int mid = length / 2;

    std::string part1 = numStr.substr(0, mid);
    std::string part2 = numStr.substr(mid);

    // Convert parts back to unsigned long long for displaying
    unsigned long long part1Num = std::stoull(part1);
    unsigned long long part2Num = std::stoull(part2);
    newArr.push_back(part2Num);  // Push the right part
        
    return part1Num;
}

void perform(deque<unsigned long long>& arr) {
    deque<unsigned  long long> newArr;

    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            arr[i] = 1;  // Replace 0 with 1 to avoid multiplication issues
        } else if (calculateSize(arr[i]) % 2 == 0) {
            arr[i]=splitNumber(arr[i], newArr);
            
        } else {
            arr[i] = arr[i] * 2024;  // For odd-sized numbers, multiply by 2024
        }
    }

    // Efficiently append newArr to arr by pushing each element
    for (const auto& elem : newArr) {
        arr.push_back(elem);
    }
}

int main() {
    // Starting with an initial deque of numbers
    deque<unsigned  long long> arr = {0 ,7, 6618216, 26481, 885, 42, 202642, 8791};

    // Perform the operations for a specified number of iterations
    for (int i = 0; i < 25; i++) {
    perform(arr);
}


    // Display the final size of the array
    cout << "Final size: " << arr.size() << endl;
    return 0;
}
