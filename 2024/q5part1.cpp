#include <bits/stdc++.h>
using namespace std;

string extractWord(string str, int count, char delimiter) {
    stringstream ss(str);
    string word;
    int wordIndex = 0;

    while (getline(ss, word, delimiter)) {
        wordIndex++;
        if (wordIndex == count) {
            return word;
        }
    }
    return "";
}

int countWords(const string& str) {
    stringstream ss(str);
    string word;
    int count = 0;

    while (getline(ss, word, ',')) {
        count++;
    }

    return count;
}

int main() {
    ifstream myfile("q5input.txt");
    if (!myfile.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    unordered_map<int, vector<int>> dataMap;
    string str;
    int lineCount = 0;

    // First part: Process the first 1176 lines (| separated)
    while (lineCount < 1176 && getline(myfile, str)) {
        lineCount++;
        try {
            int num1 = stoi(extractWord(str, 1, '|'));
            int num2 = stoi(extractWord(str, 2, '|'));
            dataMap[num1].push_back(num2);
        } catch (const invalid_argument&) {
            cerr << "Error: Invalid input format on line " << lineCount << endl;
            continue;
        }
    }

    int sum = 0;

    // Second part: Process the remaining lines (, separated)
    while (getline(myfile, str)) {
        vector<int> arr3;
        int totalSize = countWords(str);

        // Parse the array
        for (int i = 1; i <= totalSize; i++) {
            try {
                arr3.push_back(stoi(extractWord(str, i, ',')));
            } catch (const invalid_argument&) {
                cerr << "Error: Invalid number format in array" << endl;
                arr3.clear();
                break;
            }
        }

        // Validate the array
        bool isValidArr = true;
        for (int i = 0; i < arr3.size(); i++) {
            for (int j = 0; j < i; j++) {
                int key = arr3[i];
                auto it = dataMap.find(key);

                if (it != dataMap.end()) {
                    const vector<int>& values = it->second;

                    if (find(values.begin(), values.end(), arr3[j]) != values.end()) {
                        isValidArr = false;
                        break;
                    }
                }
            }
            if (!isValidArr) break;
        }

        if (isValidArr && !arr3.empty()) {
            sum += arr3[(arr3.size() - 1) / 2];
        }
    }

    myfile.close();

    // Output final sum
    cout << "Final Sum: " << sum << endl;

    return 0;
}
