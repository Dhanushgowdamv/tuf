package patterns;

public class pattern1 {

    public void pattern(int n) {
        // Using 'n' for the grid size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
    public static void pattern2(int n) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
    public static void pattern3(int n) {
        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(j+" ");
            }
            System.out.println();
        }
    }
    public static void pattern4(int n) {
        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(i+" ");
            }
            System.out.println();
        }
    }
    public static void pattern5(int n) {
        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <n-i+1; j++) {
                System.out.print(j+" ");
            }
            System.out.println();
        }
    }
    public static void pattern6(int n) {
        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <n-i+1; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
    public static void pattern7(int n){
        //outer loops
        for(int i=0;i<n;i++){
            //prit the space
            for(int j=0;j<n-i-1;j++){
                System.out.print(" ");
            }
            //print the stars
            for(int j=0;j<2*i+1;j++){
                System.out.print("*");
            }
            for(int j=0;j<n-i-1;j++){
                System.out.print(" ");
            }
            System.out.println();
        }
        
    }
    public static void pattern8(int n){
        
        
        //outer loops
        for(int i=0;i<n;i++){
            //prit the space
            for(int j=0;j<i;j++){
                System.out.print(" ");
            }
            //print the stars
            for(int j=0;j<(2*n-(2*i +1));j++){
                System.out.print("*");
            }
            for(int j=0;j<i;j++){
                System.out.print(" ");
            }
            System.out.println();
        }
        
    }
    public static void pattern9(int n){
        for(int i=0;i<n;i++){
            //prit the space
            for(int j=0;j<n-i-1;j++){
                System.out.print(" ");
            }
            //print the stars
            for(int j=0;j<2*i+1;j++){
                System.out.print("*");
            }
            for(int j=0;j<n-i-1;j++){
                System.out.print(" ");
            }
            System.out.println();
        }
        for(int i=0;i<n;i++){
            //prit the space
            for(int j=0;j<i;j++){
                System.out.print(" ");
            }
            //print the stars
            for(int j=0;j<(2*n-(2*i +1));j++){
                System.out.print("*");
            }
            for(int j=0;j<i;j++){
                System.out.print(" ");
            }
            System.out.println();
        }
    }
    public static void pattern10(int n){
        for(int i=1 ;i< n;i++){
            for(int j=1;j< i ;j++){
                System.out.print("* ");
            }
            System.out.println();
        }
        for( int i= n-1;i >=1;i--){
            for(int j=1;j<=i;j++){
                System.out.print("* ");
            }
            System.out.println();
        }
    }
    public static void pattern11(int n){
        int start = 1;
        for(int i=0;i<n;i++){
            if(i %2 == 0) start = 1;
            else start=0;
            for(int j =0 ;j<=i;j++){
                System.out.print(start);
                start = 1- start;
            }
            System.out.println();
        }
    }
    public static void pattern12(int n){

        int space = 2*(n-1);
        for(int i=1;i<=n;i++){
            
            //number
            for(int j = 1;j<=i;j++){
                System.out.print(j);
            }
            //space = 2*(n-1) for reducing by two
            for(int j=1;j<=space;j++){
                System.out.print(" ");
            }
            //number
            for(int j = i;j>=1;j--){
                System.out.print(j);
            }
            System.out.println();
            space -=2;
        }

    }
    public static void pattern13(int n){
        int num = 1;
        for(int i=0;i<=n;i++){
            for(int j=1;j<=i;j++){
                System.out.print(num);
                num= num+1;
            }
            System.out.println();
        }
    }
    public static void pattern14(int n){
        for(int i=0;i<=n;i++){
            for(char ch='A';ch<='A'+i;ch++){
                System.out.print(ch+" ");
            }
            System.out.println();
        }
    }
    public static void pattern15(int n){

        for(int i=0;i<n;i++){
            for(char j='A';j<='A'+(n-i-1);j++){
                System.out.print(j);
            }
            System.out.println();
        }
    }
    public static void pattern16(int n){
        for(int i=0;i<n;i++){
            char ch =(char) ('A' + i);
            for(int j=0;j<=i;j++){
                System.out.print(ch);
            }
            System.out.println();
        }
    }
    public static void pattern17(int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                System.out.print(" ");
            }
            for(int j=0;j<2*i-1;j++){
                System.out.print("* ");
            }
            for(int j=0;j<n-i-1;j++){
                System.out.print(" ");
            }
            System.out.println();
        }
    }
    public static void pattern18(int n){
        for(int i=0;i<n;i++){
            for(char j=(char) ('E'-i);j<='E';j++){
                System.out.print(j+" ");
            }
            System.out.println();
        }
    }
    public static void pattern19(int N){
        for (int i = 0; i < N; i++) {
            // Print left stars
            for (int j = 0; j < N - i; j++) {
                System.out.print("* ");
            }

            // Print spaces
            for (int j = 0; j < 2 * i; j++) {
                System.out.print("  ");
            }

            // Print right stars
            for (int j = 0; j < N - i; j++) {
                System.out.print("* ");
            }

            // Move to the next row
            System.out.println();
        }

        // Generate the bottom half of the pattern
        for (int i = N - 1; i >= 0; i--) {
            // Print left stars
            for (int j = 0; j < N - i; j++) {
                System.out.print("* ");
            }

            // Print spaces
            for (int j = 0; j < 2 * i; j++) {
                System.out.print("  ");
            }

            // Print right stars
            for (int j = 0; j < N - i; j++) {
                System.out.print("* ");
            }

            // Move to the next row
            System.out.println();
        }
    }


    public static void main(String[] args) {
        int N = 5;

        // Create an instance of Pattern1 and call the pattern method
        pattern1 obj = new pattern1();
        
        obj.pattern19(N);
    }
}
   