package main
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"time"
)
func heapify(arr []int, n, i int) {
	largest := i
	left := 2*i + 1
	right := 2*i + 2
	if left < n && arr[left] > arr[largest] {
		largest = left
	}
	if right < n && arr[right] > arr[largest] {
		largest = right
	}
	if largest != i {
		arr[i], arr[largest] = arr[largest], arr[i]
		heapify(arr, n, largest)
	}
}
func heapSort(arr []int) {
	n := len(arr)
	for i := n/2 - 1; i >= 0; i-- {
		heapify(arr, n, i)
	}
	for i := n - 1; i > 0; i-- {
		arr[0], arr[i] = arr[i], arr[0]
		heapify(arr, i, 0)
	}
}
func main() {
	data := readData("random_data.txt")
	start := time.Now()
	heapSort(data)
	elapsed := time.Since(start)
	fmt.Printf("Heap Sort Execution Time: %.4f milliseconds\n", elapsed.Seconds()*1000)
}
func readData(filename string) []int {
	file, err := os.Open(filename)
	if err != nil {
		panic(err)
	}
	defer file.Close()
	var data []int
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		num, _ := strconv.Atoi(scanner.Text())
		data = append(data, num)
	}
	if err := scanner.Err(); err != nil {
		panic(err)
	}
	return data
}