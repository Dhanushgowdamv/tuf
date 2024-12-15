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

    public static void main(String[] args) {
        int n = 5;

        // Create an instance of Pattern1 and call the pattern method
        pattern1 obj = new pattern1();
        obj.pattern(n);
        obj.pattern2(n);
        obj.pattern3(n);
    }
}
