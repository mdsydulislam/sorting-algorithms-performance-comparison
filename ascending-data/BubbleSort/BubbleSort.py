import time
def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
def main():
    try:
        with open("ascending_data.txt", "r") as file:
            arr = list(map(int, file.read().split()))
    except FileNotFoundError:
        print("Error: ascending_data.txt file not found!")
        return
    start_time = time.time()
    bubble_sort(arr)
    end_time = time.time()
    execution_time = end_time - start_time
    print(f"Bubble Sort Execution Time: {execution_time * 1000:.4f} milliseconds")
if __name__ == "__main__":
    main()