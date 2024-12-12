import java.io.*;
import java.util.*;
public class QuickSort {
    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) { 
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }
    public static void quickSort(int[] arr, int low, int high) {
        int[] stack = new int[high - low + 1];
        int top = -1;
        stack[++top] = low;
        stack[++top] = high;
        while (top >= 0) {
            high = stack[top--];
            low = stack[top--];
            int pi = partition(arr, low, high);
            if (pi - 1 > low) {
                stack[++top] = low;
                stack[++top] = pi - 1;
            }
            if (pi + 1 < high) {
                stack[++top] = pi + 1;
                stack[++top] = high;
            }
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
            quickSort(arr, 0, arr.length - 1);
            long endTime = System.nanoTime();
            double timeTaken = (endTime - startTime) / 1e9;
            System.out.println(String.format("Quick Sort Execution Time: %.4f milliseconds", timeTaken * 1000));
        } catch (IOException e) {
            System.out.println("Error reading the file: " + e.getMessage());
        }
    }
}