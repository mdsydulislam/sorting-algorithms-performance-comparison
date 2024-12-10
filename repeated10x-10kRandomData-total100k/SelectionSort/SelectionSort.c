#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
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
    selectionSort(arr, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort Execution Time: %.6f seconds\n", time_taken);

    free(arr);
    return 0;
}
