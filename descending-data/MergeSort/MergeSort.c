#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Dynamically allocate memory for temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    if (!L || !R) {
        printf("Memory allocation failed\n");
        exit(1); // Exit if memory allocation fails
    }

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    // Copy remaining elements of L[], if any
    while (i < n1) arr[k++] = L[i++];

    // Copy remaining elements of R[], if any
    while (j < n2) arr[k++] = R[j++];

    // Free the dynamically allocated memory
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    FILE *file = fopen("descending_data.txt", "r");
    if (!file) {
        printf("Error: Cannot open descending_data.txt\n");
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
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort Execution Time: %.6f seconds\n", time_taken);

    free(arr);
    return 0;
}
