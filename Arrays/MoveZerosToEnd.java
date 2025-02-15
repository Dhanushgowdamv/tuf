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
   

    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<>(Arrays.asList(0,1,0,3,12,6,0,4,0,88));
        moveZerosBrute(arr);
        System.out.println(arr);
}
}
