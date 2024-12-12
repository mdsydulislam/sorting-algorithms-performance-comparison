#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}
int main() {
    ifstream inputFile("repeated10x_10kRandomData_total100k.txt");
    vector<int> arr;
    int num;
    while (inputFile >> num) {
        arr.push_back(num);
    }
    inputFile.close();
    auto start = chrono::high_resolution_clock::now();
    selectionSort(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Selection Sort Execution Time: " << fixed << setprecision(4) << elapsed.count() * 1000 << " milliseconds" << endl;
    return 0;
}