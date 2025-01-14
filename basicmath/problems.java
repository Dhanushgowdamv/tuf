package basicmath;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Problems {

    // Count the number of digits
    public static int countdigits(int n) {
        int cn = 0;
        while (n > 0) {
            n = n / 10;
            cn = cn + 1;
        }
        return cn;
    }

    // Reverse the number
    public static int reversenum(int n) {
        int rev = 0;
        while (n > 0) {
            int last = n % 10;
            n = n / 10;
            rev = (rev * 10) + last;
        }
        return rev;
    }

    // Palindrome
    public static void palindrome(int n) {
        int revnum = 0;
        int dup = n;

        while (n > 0) {
            int id = n % 10;
            revnum = (revnum * 10) + id;
            n = n / 10;
        }

        if (dup == revnum) {
            System.out.println(dup + " is a Palindrome");
        } else {
            System.out.println(dup + " is not a Palindrome");
        }
    }

    // Armstrong number
    public static void amstrong(int n) {
        int sum = 0;
        int dup = n;
        while (n > 0) {
            int lst = n % 10;
            sum = sum + (lst * lst * lst);
            n = n / 10;
        }
        if (sum == dup) {
            System.out.println(dup + " is an Armstrong number");
        } else {
            System.out.println(dup + " is not an Armstrong number");
        }
    }

    // Print all divisors of a number
    public static void printAllDivisor(int n) {
        System.out.print("The divisors of the number " + n + ": ");
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }

    // Print all divisors using a list
    public static void printAll(int n) {
        List<Integer> ls = new ArrayList<>();

        // Find divisors up to the square root of n
        for (int i = 1; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                ls.add(i); // Add the divisor
                if (i != n / i) { // Avoid duplicate divisor when n is a perfect square
                    ls.add(n / i);
                }
            }
        }

        // Sort the divisors in ascending order
        Collections.sort(ls);

        // Print the divisors
        System.out.println("Divisors of " + n + ": " + ls);
    }

    public static void main(String[] args) {
        // Example usage of the methods
        int result = countdigits(3455667);
        int result1 = reversenum(1234);
        System.out.println("Reversed number: " + result1);
        System.out.println("Number of digits: " + result);

        amstrong(153);
        amstrong(123);

        palindrome(121);
        palindrome(123);

        printAllDivisor(24);
        printAll(36);
    }
}
