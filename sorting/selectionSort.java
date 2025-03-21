public class selectionSort {

    // Method to perform Selection Sort
    public static void SelectionSort(int[] arr) {
        int n = arr.length;

        // Iterate over the array
        for (int i = 0; i < n - 1; i++) {
            // Find the index of the minimum element in the unsorted part of the array
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j; // Update minIndex if a smaller element is found
                }
            }

            // Swap the found minimum element with the first element of the unsorted part
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
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
        int[] arr = {64, 25, 12, 22, 11}; // Example array
        System.out.println("Original array:");
        printArray(arr);

        SelectionSort(arr); // Sort the array

        System.out.println("Sorted array:");
        printArray(arr);
    }
}
