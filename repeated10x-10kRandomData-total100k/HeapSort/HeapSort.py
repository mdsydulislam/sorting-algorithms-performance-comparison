import time
def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and arr[left] > arr[largest]:
        largest = left
    if right < n and arr[right] > arr[largest]:
        largest = right
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)
def heap_sort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)
def main():
    try:
        with open("repeated10x_10kRandomData_total100k.txt", "r") as file:
            arr = list(map(int, file.read().split()))
    except FileNotFoundError:
        print("Error: repeated10x_10kRandomData_total100k.txt file not found!")
        return
    start_time = time.time()
    heap_sort(arr)
    end_time = time.time()
    execution_time = end_time - start_time
    print(f"Heap Sort Execution Time: {execution_time * 1000:.4f} milliseconds")
if __name__ == "__main__":
    main()