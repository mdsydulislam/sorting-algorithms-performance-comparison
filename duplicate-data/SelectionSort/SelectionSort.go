package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"time"
)

func selectionSort(arr []int) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		minIdx := i
		for j := i + 1; j < n; j++ {
			if arr[j] < arr[minIdx] {
				minIdx = j
			}
		}
		arr[i], arr[minIdx] = arr[minIdx], arr[i]
	}
}

func main() {
	data := readData("duplicate_data.txt")
	start := time.Now()
	selectionSort(data)
	elapsed := time.Since(start)
	fmt.Printf("Selection Sort Execution Time: %.6f seconds\n", elapsed.Seconds())
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
