import java.util.Arrays;
import java.util.Scanner;

public class MoveZerosToEnd {
    public static void moveZeros(int[] arr) {
        int index = 0; // Position for non-zero elements

        // Move non-zero elements forward
        for (int num : arr) {
            if (num != 0) {
                arr[index++] = num;
            }
        }

        // Fill remaining spaces with zeros
        while (index < arr.length) {
            arr[index++] = 0;
        }
    }

    public static int search(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i; // Return the index where the target is found
            }
        }
        return -1; // Return -1 if the element is not found
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Scanner object created

        int[] arr = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
        System.out.println("Before: " + Arrays.toString(arr));

        moveZeros(arr);

        System.out.println("After: " + Arrays.toString(arr));

        System.out.print("Enter the number to search: ");
        int target = scanner.nextInt();

        int result = search(arr, target);

        if (result != -1) {
            System.out.println("Element found at index: " + result);
        } else {
            System.out.println("Element not found in the array.");
        }

        scanner.close(); // Close the scanner
    }
}
