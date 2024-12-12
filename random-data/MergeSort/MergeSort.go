package main
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"time"
)
func merge(left, right []int) []int {
	var result []int
	i, j := 0, 0
	for i < len(left) && j < len(right) {
		if left[i] <= right[j] {
			result = append(result, left[i])
			i++
		} else {
			result = append(result, right[j])
			j++
		}
	}
	result = append(result, left[i:]...)
	result = append(result, right[j:]...)
	return result
}
func mergeSort(arr []int) []int {
	if len(arr) <= 1 {
		return arr
	}
	mid := len(arr) / 2
	left := mergeSort(arr[:mid])
	right := mergeSort(arr[mid:])
	return merge(left, right)
}
func main() {
	data := readData("random_data.txt")
	start := time.Now()
	data = mergeSort(data)
	elapsed := time.Since(start)
	fmt.Printf("Merge Sort Execution Time: %.4f milliseconds\n", elapsed.Seconds()*1000)
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