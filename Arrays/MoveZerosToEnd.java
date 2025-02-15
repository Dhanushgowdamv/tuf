import java.util.Arrays;
import java.util.Scanner;

public class MoveZerosToEnd {
    // move the zeroes to the end of the arr in brute way
    public static void moveZerosBrute(LIst<Integer> arr) {
        List<Integer> temp = new ArrayList<>();

        for(int num : arr){
            if(num !=0){
                temp.add(num);
            }
        }

        int i=0;
        for(;i < temp.size();i++){
            arr.set(i,temp.get(i));
        }

        for(;i<arr.size();i++){
            arr.set(i,0);
        }

       
    }

    // better way to solve the question
    public static void moveZeroBetter(List<Integer> arr){
        int count =0 ;
        for(int i=0;i<n;i++){
            if(arr.get(i) !=0){
                arr.set(count++ , arr.get(i));
            }


        }
        while(count < arr.size()){
            arr.set(count++ ,0);
        }
    }
   
    public static void moveZeroOptmail(List<Integer> arr){
        int j=0;
        for(int i=0;i<arr.size();i++){
            if(arr.get(i) != 0){
                if(i!=j){
                    int temp = arr.get(i);
                    arr.set(i,arr.get(j));
                    arr.set(j,temp);
                }
                j++;
            }
        }
    }

    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<>(Arrays.asList(0,1,0,3,12,6,0,4,0,88));
        moveZerosBrute(arr);
        System.out.println(arr);
}
}
