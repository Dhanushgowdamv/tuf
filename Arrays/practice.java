import java.util.*;
public class practice {

    public static int large(int n, int[] arr) {
        int largest = arr[0];  // Assume the first element is the largest
        
        for (int i = 1; i < n; i++) {  // Start loop from 1 as 0th index is already considered
            if (arr[i] > largest) {
                largest = arr[i];  // Update largest if a bigger number is found
            }
        }
        return largest;  // Return the largest number
    }


    // time comlpicaty is O(n)
    public static int secondlargest(int [] a,int n){
        int largest = a[0];
        int slargest = -1;
         for(int i=0;i<n;i++){
            if(a[i] > largest){
                slargest = largest;
                largest = a[i];

            }else if(a[i]< largest && a[i]>slargest ){
                slargest = a[i]; 
            }
         }
         return slargest;

    }

    public static int secondsmallest(int []a ,int n){
          int smallest = a[0];
          int ssmallest = Integer.MAX_VALUE;
          for(int i=1;i<n;i++){
            if(a[i] <smallest){
                ssmallest = smallest;
                smallest = a[i];
            }else if(a[i] != smallest && a[i] < ssmallest){
                ssmallest = a[i];
            }
          }
          return ssmallest;
    }

    //check if the array is sorted or not
public static boolean isSorted(int n , int[] a){
    for(int i=1;i<n;i++){
    if(a[i] < a[i-1]){

    }
    else {
        return false;
    }
    
}
return true;
}

//remove the duplicates in the sorted array

public static List<Integer> removedup(int[] arr){
    Set<Integer> set = new LinkedHashSet<>();
    for(int num : arr){
        set.add(num);
    }
    return new ArrayList<>(set);

}

//left rotate the array by one 
static void solve(int[] arr, int n){
    int temp[] = new int[n];
    for(int i=0;i<n;i++){
        temp[i=1] = arr[i];
    }
    temp[n-1]= arr[0];
    for(int i=0;i<n;i++){
        System.out.println(temp[i]+" ");
    }
}


    public static void main(String[] args) {
        int[] numbers = {10, 25, 35, 42, 5, 19};  // Sample array
        int largestNumber = large(numbers.length, numbers);  // Calling the method
        System.out.println("Largest number is: " + largestNumber);  // Output the result
        int[] a= {1,2,4,7,2,9,3};
        int[] arr = {1,1,2,2,2,3,4,4,5};
        int n = a.length;
        int slargest = secondlargest(a,n);
        int ssmallest= secondsmallest(a,n);
        boolean isSort = isSorted(n,a);
       System.out.println("second Largest "+slargest);
        System.out.println("second smallest"+ssmallest);
      System.out.println("is array sorted"+isSort);
      System.out.println("remove the duplicate number"+removedup(arr));
    }

}
