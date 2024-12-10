package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"time"
)

func bubbleSort(arr []int) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		for j := 0; j < n-i-1; j++ {
			if arr[j] > arr[j+1] {
				arr[j], arr[j+1] = arr[j+1], arr[j]
			}
		}
	}
}

func main() {
	data := readData("descending_data.txt")
	start := time.Now()
	bubbleSort(data)
	elapsed := time.Since(start)
	fmt.Printf("Bubble Sort Execution Time: %.6f seconds\n", elapsed.Seconds())
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