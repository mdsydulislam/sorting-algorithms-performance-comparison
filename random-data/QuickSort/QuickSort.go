package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"time"
)

func quickSort(arr []int) []int {
	if len(arr) < 2 {
		return arr
	}

	pivot := arr[0]
	var left, right []int
	for _, v := range arr[1:] {
		if v <= pivot {
			left = append(left, v)
		} else {
			right = append(right, v)
		}
	}

	return append(append(quickSort(left), pivot), quickSort(right)...)
}

func main() {
	data := readData("random_data.txt")
	start := time.Now()
	data = quickSort(data)
	elapsed := time.Since(start)
	fmt.Printf("Quick Sort Execution Time: %.6f seconds\n", elapsed.Seconds())
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
