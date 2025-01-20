public class practice {
        public static void selectionSort(int[] arr){
            int n = arr.length;
            for(int i =0 ;i<n-1;i++){
                int minIndex = i;
                for(int j=i+1;j<n;j++){
                    if(arr[j] < arr[minIndex]){
                        minIndex = j;
                    }
                }
                 int temp = arr[minIndex];
                 arr[minIndex] = arr[i];
                 arr[i] = temp;
            }
        }
   public static void bubblesort(int []arr){
    int n= arr.length;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
   }
        public static void printArr(int []arr){
           for(int num:arr){
            System.out.println( num);
           }
        }
        public static void main(String[] args) {
            int[] arr = {64, 25, 12, 22, 11};
            System.out.println("print original arr");
            printArr(arr);
             
            bubblesort(arr);
            System.out.println("the sorted array");
            printArr(arr);
        }
}
