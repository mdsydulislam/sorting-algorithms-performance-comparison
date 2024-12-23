#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main() {
    ifstream inputFile("duplicate_data.txt");
    vector<int> arr;
    int num;
    while (inputFile >> num) {
        arr.push_back(num);
    }
    inputFile.close();
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Bubble Sort Execution Time: " << fixed << setprecision(4) << elapsed.count() * 1000 << " milliseconds" << endl;
    return 0;
}