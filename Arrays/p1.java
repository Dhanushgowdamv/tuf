public class p1 {

    public static int removeDuplicates(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        int uniqueIndex = 0; // Points to the last unique element
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[uniqueIndex]) {
                uniqueIndex++;
                nums[uniqueIndex] = nums[i];
            }
        }
        return uniqueIndex + 1; // Length of the unique elements array
    }

    public static void main(String[] args) {
        // Example input array
        int[] nums = {1, 1, 2, 3, 3, 4, 5, 5};

        // Removing duplicates
        int length = removeDuplicates(nums);

        // Printing the unique elements
        System.out.println("Length of array with unique elements: " + length);
        System.out.print("Array with unique elements: ");
        for (int i = 0; i < length; i++) {
            System.out.print(nums[i] + " ");
        }
    }
}
