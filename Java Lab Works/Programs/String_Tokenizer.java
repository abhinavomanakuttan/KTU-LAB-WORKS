 /*
Write a Java program that reads a line of integers, 
and then displays each integer, and the sum of all 
the integers (Use String Tokenizer class of 
java.util). 
  */ 
import java.util.Scanner;
import java.util.StringTokenizer;

public class  String_Tokenizer  {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a line of integers separated by spaces: ");
        String inputLine = scanner.nextLine();
        
        // Using StringTokenizer to parse the input line
        StringTokenizer tokenizer = new StringTokenizer(inputLine);
        int sum = 0;

        System.out.println("The integers entered are:");
        while (tokenizer.hasMoreTokens()) {
            // Convert each token to an integer
            int number = Integer.parseInt(tokenizer.nextToken());
            System.out.print(number + " ");
            sum += number;
        }
        
        System.out.println("\nThe sum of all integers is: " + sum);
        scanner.close();
    }
}
