public class Practice {

    public static int large(int n, int[] arr) {
        int largest = arr[0];  // Assume the first element is the largest
        
        for (int i = 1; i < n; i++) {  // Start loop from 1 as 0th index is already considered
            if (arr[i] > largest) {
                largest = arr[i];  // Update largest if a bigger number is found
            }
        }
        return largest;  // Return the largest number
    }

    public static void seclarge(int [] arr,int n){
        
    }
    public static void main(String[] args) {
        int[] numbers = {10, 25, 35, 42, 5, 19};  // Sample array
        int largestNumber = large(numbers.length, numbers);  // Calling the method
        System.out.println("Largest number is: " + largestNumber);  // Output the result
    }
}
