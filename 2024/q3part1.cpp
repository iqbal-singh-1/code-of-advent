#include <bits/stdc++.h>
using namespace std;

void multiplyNumbersInPattern(const string &text, const regex &pattern, vector<int> &products) {
    auto matchesBegin = sregex_iterator(text.begin(), text.end(), pattern);
    auto matchesEnd = sregex_iterator();

    for (auto it = matchesBegin; it != matchesEnd; ++it) {
        string match = it->str(); // Full match: "mul(num,num)"
        smatch numMatch;
        regex numPattern("\\d+"); // Regex to extract numbers within "mul"

        vector<int> numbers;
        auto numBegin = sregex_iterator(match.begin(), match.end(), numPattern);
        auto numEnd = sregex_iterator();

        for (auto numIt = numBegin; numIt != numEnd; ++numIt) {
            numbers.push_back(stoi(numIt->str())); // Convert number strings to integers
        }

        if (numbers.size() == 2) {
            products.push_back(numbers[0] * numbers[1]); // Multiply the two numbers
        }
    }
}

int main() {
    ifstream myfile("q3input.txt");
    if (!myfile.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    string str;
    regex pattern(R"(mul\(\d+,\d+\))"); // Regex to match "mul(num,num)"
    vector<int> products;

    while (getline(myfile, str)) {
        multiplyNumbersInPattern(str, pattern, products);
    }

    myfile.close();

    long long sum = 0;

    for (int product : products) {
        cout << product << " ";
        sum+=product;
    }
    cout << endl;
    cout<<sum<<endl;
    return 0;
}
