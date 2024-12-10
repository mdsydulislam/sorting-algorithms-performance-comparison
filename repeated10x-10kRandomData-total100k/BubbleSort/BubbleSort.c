#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *file = fopen("repeated10x_10kRandomData_total100k.txt", "r");
    if (!file) {
        printf("Error: Cannot open repeated10x_10kRandomData_total100k.txt\n");
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
    bubbleSort(arr, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Execution Time: %.6f seconds\n", time_taken);

    free(arr);
    return 0;
}
