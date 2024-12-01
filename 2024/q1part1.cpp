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

int calPivotIndex(vector<int>& arr, int start, int end) {
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }
    int pivotIndex = count + start;
    swap(arr[start], arr[pivotIndex]);
    return pivotIndex;
}

void partition(vector<int>& arr, int start, int end, int pivotIndex) {
    int i = start, j = end;
    int pivot = arr[pivotIndex];
    while (i < pivotIndex && j > pivotIndex) {
        if (arr[i] > pivot && arr[j] <= pivot && j != pivotIndex) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        } else if (arr[j] > pivot) {
            j--;
        } else {
            i++;
        }
    }
}

void quickSort(vector<int>& arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivotIndex = calPivotIndex(arr, start, end);
    partition(arr, start, end, pivotIndex);
    quickSort(arr, start, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, end);
}

int main() {
    int size = 1000, i = 0;
    string str;
    ifstream myfile;
    myfile.open("q1input.txt");
    vector<int> arr1(size), arr2(size);
    while (getline(myfile, str)) {
        arr1[i] = stoi(extractWord(str, 1));
        arr2[i] = stoi(extractWord(str, 2));
        i++;
    }
    myfile.close();
    quickSort(arr1, 0, size - 1);
    quickSort(arr2, 0, size - 1);
    long long total = 0;
    for (int i = 0; i < size; i++) {
        total += abs(arr1[i] - arr2[i]);
        cout << arr1[i] << " " << arr2[i] << endl;
    }
    cout << "total is " << total << endl;
}
