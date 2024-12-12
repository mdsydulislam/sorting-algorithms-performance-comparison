import time
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)
def main():
    try:
        with open("nearly_sorted_data.txt", "r") as file:
            arr = list(map(int, file.read().split()))
    except FileNotFoundError:
        print("Error: nearly_sorted_data.txt file not found!")
        return
    start_time = time.time()
    sorted_arr = quick_sort(arr)
    end_time = time.time()
    execution_time = end_time - start_time
    print(f"Quick Sort Execution Time: {execution_time * 1000:.4f} milliseconds")
if __name__ == "__main__":
    main()