import java.io.*;
import java.util.*;
public class HeapSort {
    public static void heapify(int[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            heapify(arr, n, largest);
        }
    }
    public static void heapSort(int[] arr) {
        int n = arr.length;
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }
    }
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("descending_data.txt"));
            List<Integer> dataList = new ArrayList<>();
            String line;
            while ((line = br.readLine()) != null) {
                dataList.add(Integer.parseInt(line));
            }
            br.close();
            int[] arr = dataList.stream().mapToInt(i -> i).toArray();
            long startTime = System.nanoTime();
            heapSort(arr);
            long endTime = System.nanoTime();
            double timeTaken = (endTime - startTime) / 1e9;
            System.out.println(String.format("Heap Sort Execution Time: %.4f milliseconds", timeTaken * 1000));
        } catch (IOException e) {
            System.out.println("Error reading the file: " + e.getMessage());
        }
    }
}