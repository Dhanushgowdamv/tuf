public class p2 {
    public static void leftRotateByOne(int[] arr) {
        int n = arr.length;
        if (n == 0) return;

        int first = arr[0]; // Store the first element
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1]; // Shift elements left
        }
        arr[n - 1] = first; // Move the first element to the last position
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        System.out.println("Original Array:");
        printArray(arr);

        leftRotateByOne(arr);
        
        System.out.println("Array after Left Rotation by One:");
        printArray(arr);
    }

    private static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
