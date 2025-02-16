import java.util.Scanner;

public class pascaletriangle {
    public static void printPascalsTriangle(int n) {
        int[][] triangle = new int[n][n];

        // Generate Pascal's Triangle
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    triangle[i][j] = 1;  // First and last elements are 1
                } else {
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
                }
                System.out.print(triangle[i][j] + " ");
            }
            System.out.println(); // New line for each row
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of rows: ");
        int numRows = scanner.nextInt();
        scanner.close();

        printPascalsTriangle(numRows);
    }
}
