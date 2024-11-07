#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Generates the next string in the look-and-say sequence
string calNewString(string s) {
    string temp;
    int i = 0, start = 0, end = 0, count = 1;

    // Loop through the string to process each sequence of consecutive identical characters
    while (i < s.size() - 1) {
        if (s[i] != s[i + 1]) {
            start = end;
            end = i + 1;
            count = end - start;
            temp += to_string(count) + s[i];  // Add the count and character to result
        }
        i++;
    }

    // Handle the last character group
    start = end;
    end = i + 1;
    count = end - start;
    temp += to_string(count) + s[i];

    return temp;
}

int main() {
    string n = "1113222113";  // Starting string
    for (int i = 0; i < 50; i++) {
        n = calNewString(n);  // Generate next sequence term
    }

    cout << n.size() << endl;  // Output the length of the final string
    return 0;
}
