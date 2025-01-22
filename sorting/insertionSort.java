public class insertionSort {

    // Method to perform insertion sort
    public static void insertion(int[] arr, int n) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            // Move elements that are greater than key to one position ahead
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // Method to print the array
    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90}; // Example array
        int n = arr.length; // Length of the array

        System.out.println("Original array:");
        printArray(arr);

        insertion(arr, n); // Perform insertion sort

        System.out.println("Sorted array:");
        printArray(arr);
    }
}
