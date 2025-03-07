import java.util.*;

public class p1 {
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
        moveZeroOptmail(arr);
        System.out.println(arr);
}
}

    

