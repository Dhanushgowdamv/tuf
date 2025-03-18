import java.util.HashMap;

public class longestArray {

    public static int longestSubarrayWithSumK(int[] arr, int K) {
        // Map to store (cumulative_sum, index)
        HashMap<Integer, Integer> sumMap = new HashMap<>();
        int maxLength = 0;
        int currentSum = 0;

        for (int i = 0; i < arr.length; i++) {
            currentSum += arr[i];

            // Case 1: Subarray from 0 to i has sum K
            if (currentSum == K) {
                maxLength = i + 1;
            }

            // Case 2: Check if there is a prefix sum that makes current sum - K
            if (sumMap.containsKey(currentSum - K)) {
                int prevIndex = sumMap.get(currentSum - K);
                maxLength = Math.max(maxLength, i - prevIndex);
            }

            // Store currentSum if not already present
            if (!sumMap.containsKey(currentSum)) {
                sumMap.put(currentSum, i);
            }
        }

        return maxLength;
    }

    public static void main(String[] args) {
        int[] arr = {10, 5, 2, 7, 1, 9, 7};
        int K = 15;

        int length = longestSubarrayWithSumK(arr, K);
        System.out.println("Length of Longest Subarray with sum " + K + ": " + length);
    }
}
