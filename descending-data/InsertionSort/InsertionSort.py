import time
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
file_name = "descending_data.txt"
try:
    with open(file_name, "r") as file:
        data = file.read()
        arr = list(map(int, data.split()))
except FileNotFoundError:
    print("Error: descending_data.txt file not found!")
    exit()
start_time = time.time()
insertion_sort(arr)
end_time = time.time()
execution_time = end_time - start_time
print(f"Insertion Sort Execution Time: {execution_time * 1000:.4f} milliseconds")