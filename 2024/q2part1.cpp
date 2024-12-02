#include <bits/stdc++.h>
using namespace std;

string extractWord(string str, int count) {
    string temp;
    int wordIndex = 0;
    bool inWord = false;

    for (char c : str) {
        if (c != ' ') {
            if (!inWord) {
                wordIndex++;
                inWord = true;
            }
            if (wordIndex == count) {
                temp += c;
            }
        } else {
            inWord = false;
        }
    }

    return temp;
}

int countWords(string str) {
    int count = 0;
    bool inWord = false;

    for (char ch : str) {
        if (ch == ' ') {
            if (inWord) {
                count++;
                inWord = false;
            }
        } else {
            inWord = true;
        }
    }

    if (inWord) {
        count++;
    }

    return count;
}

int main() {
    int count = 0;
    string str;
    ifstream myfile;
    myfile.open("q2input.txt");
    
    while (getline(myfile, str)) {
        vector<int> arr;
        int size = countWords(str);
        
        // Populate the vector with integers from the extracted words
        for (int i = 1; i <= size; i++) {
            int num = stoi(extractWord(str, i));  // Convert string to integer
            arr.push_back(num);
        }
        
        int inc = 0, positive = 0, unSafe = 0;
        
        for (int i = 0; i < size - 1; i++) {
            inc = arr[i + 1] - arr[i];
            if(abs(inc)>3 || inc==0){
                unSafe = 1;
                break;
            }
            if (inc >= 0 && positive == 0) {
                positive = 1;
            }
            else if (inc <= 0 && positive == 0) {
                positive = -1;
            }
            if (positive == 1 && inc >= 0) {
                continue;
            }
            else if (positive == -1 && inc <= 0) {
                continue;
            }
            else {
                unSafe = 1;
            }
        }

        if (!unSafe) {
            count++;
        }
        
    }

    myfile.close();
    cout << count << endl;

    return 0;
}
