import java.io.*;
import java.util.*;

public class InsertionSort {

    // Insertion Sort function
    public static void insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int j = i - 1;
            
            // Move elements of arr[0..i-1] that are greater than key
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    public static void main(String[] args) {
        try {
            // Read data from file
            BufferedReader br = new BufferedReader(new FileReader("nearly_sorted_data.txt"));
            List<Integer> dataList = new ArrayList<>();
            String line;
            while ((line = br.readLine()) != null) {
                dataList.add(Integer.parseInt(line));
            }
            br.close();

            // Convert data to an array
            int[] arr = dataList.stream().mapToInt(i -> i).toArray();

            // Start measuring time
            long startTime = System.nanoTime();

            // Call the insertionSort function
            insertionSort(arr);

            // End measuring time
            long endTime = System.nanoTime();

            // Calculate the time taken in seconds
            double timeTaken = (endTime - startTime) / 1e9;
            System.out.println("Insertion Sort Execution Time: " + timeTaken + " seconds");

        } catch (IOException e) {
            System.out.println("Error reading the file: " + e.getMessage());
        }
    }
}
