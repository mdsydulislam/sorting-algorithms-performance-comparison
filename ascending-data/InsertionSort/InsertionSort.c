#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    FILE *file = fopen("ascending_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    int arr[25000], n = 0;
    while (fscanf(file, "%d", &arr[n]) != EOF) {
        n++;
    }
    fclose(file);
    clock_t start, end;
    start = clock();
    insertionSort(arr, n);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort Execution Time: %.4f milliseconds\n", time_taken * 1000);
    return 0;
}