import java.io.*;
import java.util.*;
public class InsertionSort {
    public static void insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("repeated10x_10kRandomData_total100k.txt"));
            List<Integer> dataList = new ArrayList<>();
            String line;
            while ((line = br.readLine()) != null) {
                dataList.add(Integer.parseInt(line));
            }
            br.close();
            int[] arr = dataList.stream().mapToInt(i -> i).toArray();
            long startTime = System.nanoTime();
            insertionSort(arr);
            long endTime = System.nanoTime();
            double timeTaken = (endTime - startTime) / 1e9;
            System.out.println(String.format("Insertion Sort Execution Time: %.4f milliseconds", timeTaken * 1000));

        } catch (IOException e) {
            System.out.println("Error reading the file: " + e.getMessage());
        }
    }
}