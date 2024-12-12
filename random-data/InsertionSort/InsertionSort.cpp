#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    ifstream inputFile("random_data.txt");
    vector<int> arr;
    int num;
    while (inputFile >> num) {
        arr.push_back(num);
    }
    inputFile.close();
    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Insertion Sort Execution Time: " << fixed << setprecision(4) << elapsed.count() * 1000 << " milliseconds" << endl;
    return 0;
}