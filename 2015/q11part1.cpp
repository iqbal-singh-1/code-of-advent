#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Increment string by one lexicographically
string incrementStringByOne(string &s) {
    vector<int> ascii;
    for (int i = 0; i < s.size(); i++) {
        ascii.push_back(int(s[i]) - 97);  // Convert char to 0-based index
    }

    int i = ascii.size() - 1;
    while (ascii[i] + 1 == 26) {  // If 'z', wrap around
        ascii[i] = 0;
        i--;
    }
    ascii[i] += 1;  // Increment the current character

    string temp;
    for (int i = 0; i < ascii.size(); i++) {
        temp += (ascii[i] + 97);  // Convert back to char
    }
    return temp;
}

// Check if the string is valid
bool checkValid(string s) {
    bool valid1 = 0;
    for (int i = 0; i < s.size() - 2; i++) {
        if (s[i] == s[i + 1] - 1 && s[i] == s[i + 2] - 2) {
            valid1 = 1;  // Found consecutive sequence
            break;
        }
    }
    if (!valid1) return 0;

    bool valid2 = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1]) {
            for (int j = i + 2; j < s.size() - 1; j++) {
                if (s[j] == s[j + 1]) {
                    valid2 = 1;  // Found second pair
                    break;
                }
            }
            break;
        }
    }
    if (!valid2) return 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'i' || s[i] == 'o' || s[i] == 'l') {
            return 0;  // Invalid characters found
        }
    }
    return 1;  // Valid string
}

int main() {
    string a = "hepxcrrq";

    while (true) {
        a = incrementStringByOne(a);  // Increment the string
        cout << a << endl;
        if (checkValid(a)) break;  // Check if valid
    }

    return 0;
}
