import java.util.HashSet;

public class ArrayOperations {

    // Function to find the union of two arrays
    public static void findUnion(int[] array1, int[] array2) {
        HashSet<Integer> unionSet = new HashSet<>();

        // Add elements from the first array
        for (int num : array1) {
            unionSet.add(num);
        }

        // Add elements from the second array
        for (int num : array2) {
            unionSet.add(num);
        }

        // Display the union of the two arrays
        System.out.println("Union of the two arrays: " + unionSet);
    }

    // Function to find the missing number in an array from 1 to n
    public static int findMissingNumber(int[] arr, int n) {
        int expectedSum = n * (n + 1) / 2; // Sum formula
        int actualSum = 0;

        for (int num : arr) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }

    public static void main(String[] args) {
        // Union of two arrays
        int[] array1 = {1, 2, 3, 4, 5};
        int[] array2 = {3, 4, 5, 6, 7};
        findUnion(array1, array2);

        // Finding the missing number
        int[] array = {1, 2, 4, 5, 6}; // Missing number is 3
        int n = 6; // The last number in the sequence
        System.out.println("Missing number: " + findMissingNumber(array, n));
    }
}
