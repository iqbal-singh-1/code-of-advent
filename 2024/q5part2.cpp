#include <bits/stdc++.h>
using namespace std;

string extractWord(string str, int count, char delimiter) {
    stringstream ss(str);
    string word;
    int wordIndex = 0;

    while (getline(ss, word, delimiter)) { // Split using the given delimiter
        wordIndex++;
        if (wordIndex == count) {
            return word; // Return the required word
        }
    }
    return ""; // Return empty if count exceeds number of words
}

int countWords(const string& str) {
    stringstream ss(str);
    string word;
    int count = 0;

    while (getline(ss, word, ',')) { // Split using ',' as the delimiter
        count++;
    }

    return count;
}

bool isValidArray(const vector<int>& arr, const unordered_map<int, vector<int>>& dataMap) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < i; j++) {
            int key = arr[i];
            auto it = dataMap.find(key);
            if (it != dataMap.end()) {
                const vector<int>& values = it->second;

                if (find(values.begin(), values.end(), arr[j]) != values.end()) {
                    return false; // Invalid if we find a pair that contradicts the order
                }
            }
        }
    }
    return true; // Array is valid
}

vector<int> correctArray(const vector<int>& arr, const unordered_map<int, vector<int>>& dataMap) {
    vector<int> correctedArr = arr;
    bool swapped;
    
    // Perform a simple bubble sort-like approach to ensure that all elements are ordered correctly
    do {
        swapped = false;
        for (int i = 0; i < correctedArr.size() - 1; i++) {
            int key = correctedArr[i];
            auto it = dataMap.find(key);
            if (it != dataMap.end()) {
                const vector<int>& values = it->second;

                if (find(values.begin(), values.end(), correctedArr[i + 1]) != values.end()) {
                    // Swap elements to correct the order
                    swap(correctedArr[i], correctedArr[i + 1]);
                    swapped = true;
                }
            }
        }
    } while (swapped);

    return correctedArr;
}

int main() {
    string str;
    ifstream myfile("q5input.txt");

    if (!myfile.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    unordered_map<int, vector<int>> dataMap;
    int count = 0;

    // Read the first part of the file and create the map
    while (getline(myfile, str)) {
        count++;
        try {
            int num1 = stoi(extractWord(str, 1, '|')); // Extract first number
            int num2 = stoi(extractWord(str, 2, '|')); // Extract second number
            dataMap[num1].push_back(num2);
        } catch (const invalid_argument&) {
            cerr << "Error: Invalid input format on line " << count << endl;
            continue;
        }
        if (count == 1176) break; // Limit the reading up to 1176 lines
    }

    int sum = 0;
    // Read the second part of the file with ',' separated arrays
    while (getline(myfile, str)) {
        vector<int> arr3;
        int totalSize = countWords(str);
        
        // Split the string and populate the array
        for (int i = 1; i <= totalSize; i++) {
            arr3.push_back(stoi(extractWord(str, i, ',')));
        }

        // Check if the array is valid
        if (!isValidArray(arr3, dataMap)) {
            // Correct the array if invalid
            arr3 = correctArray(arr3, dataMap);
        sum += arr3[(arr3.size() - 1) / 2]; 
        }

        // Add the middle element of the corrected or valid array
    }

    cout << "Final sum: " << sum  << endl;
    return 0;
}
