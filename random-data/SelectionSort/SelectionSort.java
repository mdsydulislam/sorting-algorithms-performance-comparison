import java.io.*;
import java.util.*;
public class SelectionSort {
    public static void selectionSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("random_data.txt"));
            List<Integer> dataList = new ArrayList<>();
            String line;
            while ((line = br.readLine()) != null) {
                dataList.add(Integer.parseInt(line));
            }
            br.close();
            int[] arr = dataList.stream().mapToInt(i -> i).toArray();
            long startTime = System.nanoTime();
            selectionSort(arr);
            long endTime = System.nanoTime();
            double timeTaken = (endTime - startTime) / 1e9;
            System.out.println(String.format("Selection Sort Execution Time: %.4f milliseconds", timeTaken * 1000));
        } catch (IOException e) {
            System.out.println("Error reading the file: " + e.getMessage());
        }
    }
}
