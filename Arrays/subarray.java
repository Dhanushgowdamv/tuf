import java.util.Arrays;

public class subarray {

    public static void printAllSubArrays(int[] arr) {
        int n = arr.length;

        System.out.println("All subarrays:");
        for (int start = 0; start < n; start++) {
            for (int end = start; end < n; end++) {
                // Print subarray from start to end
                System.out.print("[");
                for (int k = start; k <= end; k++) {
                    System.out.print(arr[k]);
                    if (k != end) System.out.print(", ");
                }
                System.out.println("]");
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3};
        printAllSubArrays(arr);
    }
}
