import time
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]
        merge_sort(left_half)
        merge_sort(right_half)
        i = j = k = 0
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1
        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1
def main():
    try:
        with open("descending_data.txt", "r") as file:
            arr = list(map(int, file.read().split()))
    except FileNotFoundError:
        print("Error: descending_data.txt file not found!")
        return
    start_time = time.time()
    merge_sort(arr)
    end_time = time.time()
    execution_time = end_time - start_time
    print(f"Merge Sort Execution Time: {execution_time * 1000:.4f} milliseconds")
if __name__ == "__main__":
    main()