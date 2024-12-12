import time
def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
def main():
    try:
        with open("duplicate_data.txt", "r") as file:
            arr = list(map(int, file.read().split()))
    except FileNotFoundError:
        print("Error: duplicate_data.txt file not found!")
        return
    start_time = time.time()
    selection_sort(arr)
    end_time = time.time()
    execution_time = end_time - start_time
    print(f"Selection Sort Execution Time: {execution_time * 1000:.4f} milliseconds")
if __name__ == "__main__":
    main()