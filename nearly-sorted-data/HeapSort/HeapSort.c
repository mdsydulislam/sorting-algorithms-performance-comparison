#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void heapify(int arr[], int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}
int main() {
    FILE *file = fopen("nearly_sorted_data.txt", "r");
    if (!file) {
        printf("Error: Cannot open nearly_sorted_data.txt\n");
        return 1;
    }
    int n = 25000;
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < n; i++) fscanf(file, "%d", &arr[i]);
    fclose(file);
    clock_t start = clock();
    heapSort(arr, n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Heap Sort Execution Time: %.4f milliseconds\n", time_taken * 1000);
    free(arr);
    return 0;
}