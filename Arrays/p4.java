import java.util.HashSet;

public class UnionExample {
    public static void main(String[] args) {
        int[] array1 = {1, 2, 3, 4, 5};
        int[] array2 = {3, 4, 5, 6, 7};

        HashSet<Integer> unionSet = new HashSet<>();

        // Add elements from the first array
        for (int num : array1) {
            unionSet.add(num);
        }

        // Add elements from the second array
        for (int num : array2) {
            unionSet.add(num);
        }

        // Display the union of the two arrays
        System.out.println("Union of the two arrays: " + unionSet);
    }
}
