import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;

public class StringSortExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a line of text:");

        // Read the input line
        String input = scanner.nextLine();

        // Use StringTokenizer to split the line into words
        StringTokenizer tokenizer = new StringTokenizer(input);
        ArrayList<String> words = new ArrayList<>();

        // Display each token and add it to the list
        System.out.println("Individual words:");
        while (tokenizer.hasMoreTokens()) {
            String word = tokenizer.nextToken();
            System.out.println(word);
            words.add(word);
        }

        // Sort the list of words
        Collections.sort(words);

        // Display the sorted words
        System.out.println("\nSorted words:");
        for (String word : words) {
            System.out.println(word);
        }

        scanner.close();
    }
}