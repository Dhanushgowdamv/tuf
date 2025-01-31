import java.util.Arrays;

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

    public static void main(String[] args) {
        int[] arr = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
        System.out.println("Before: " + Arrays.toString(arr));

        moveZeros(arr);

        System.out.println("After: " + Arrays.toString(arr));
    }
}
