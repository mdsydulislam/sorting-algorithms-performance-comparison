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
    FILE *file = fopen("descending_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int arr[25000], n = 0;

    // Read integers from the file
    while (fscanf(file, "%d", &arr[n]) != EOF) {
        n++;
    }
    fclose(file);

    // Measure sorting time
    clock_t start, end;
    start = clock();
    insertionSort(arr, n);
    end = clock();

    // Calculate time taken
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    

    printf("Execution Time: %f seconds\n", time_taken);
    return 0;
}
