package main
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"time"
)
func insertionSort(arr []int) {
	for i := 1; i < len(arr); i++ {
		key := arr[i]
		j := i - 1
		for j >= 0 && arr[j] > key {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = key
	}
}
func main() {
	data := readData("repeated10x_10kRandomData_total100k.txt")
	start := time.Now()
	insertionSort(data)
	elapsed := time.Since(start)
	fmt.Printf("Insertion Sort Execution Time: %.4f milliseconds\n", elapsed.Seconds()*1000)
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