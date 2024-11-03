 /*
Write a menu driven Java program that shows the 
usage of the following BuiltinException using try, 
catch, throws and finally. 
 1. AritmeticException  
2. ArrayIndexOutOfBoundsException. 
  */
import java.util.Scanner;

public class Exception_Handling {

    // Method to demonstrate ArithmeticException
    public static void arithmeticExceptionDemo() throws ArithmeticException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter two numbers to divide: ");
        int num1 = scanner.nextInt();
        int num2 = scanner.nextInt();

        try {
            int result = num1 / num2;
            System.out.println("Result: " + result);
        } catch (ArithmeticException e) {
            System.out.println("Error: Cannot divide by zero!");
            throw e; // Re-throwing the exception to demonstrate `throws`
        } finally {
            System.out.println("Arithmetic operation complete.");
        }
    }

    // Method to demonstrate ArrayIndexOutOfBoundsException
    public static void arrayIndexOutOfBoundsExceptionDemo() {
        int[] numbers = {1, 2, 3, 4, 5};
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an index to access the array element: ");
        int index = scanner.nextInt();

        try {
            System.out.println("Element at index " + index + ": " + numbers[index]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Index is out of bounds!");
        } finally {
            System.out.println("Array access operation complete.");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\nMenu:");
            System.out.println("1. Arithmetic Exception Demo");
            System.out.println("2. Array Index Out Of Bounds Exception Demo");
            System.out.println("3. Exit");
            System.out.print("Choose an option: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    try {
                        arithmeticExceptionDemo();
                    } catch (ArithmeticException e) {
                        System.out.println("Caught in main: " + e.getMessage());
                    }
                    break;
                case 2:
                    arrayIndexOutOfBoundsExceptionDemo();
                    break;
                case 3:
                    System.out.println("Exiting program...");
                    break;
                default:
                    System.out.println("Invalid choice! Please try again.");
            }
        } while (choice != 3);

        scanner.close();
    }
}
