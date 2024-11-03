 
import java.io.*;
import java.util.Scanner;

public class  File_Reader_Writer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Creating and writing to "sample.txt"
        try (FileWriter writer = new FileWriter("sample.txt")) {
            System.out.println("Enter text to write to sample.txt (type 'exit' to finish):");

            while (true) {
                String input = scanner.nextLine();
                if (input.equalsIgnoreCase("exit")) {
                    break;
                }
                writer.write(input + System.lineSeparator());
            }

            System.out.println("Data written to sample.txt successfully.");
        } catch (IOException e) {
            System.out.println("An error occurred while writing to sample.txt: " + e.getMessage());
        }

        // Reading from "sample.txt" and writing to "new-sample.txt"
        try (FileReader reader = new FileReader("sample.txt");
             FileWriter newWriter = new FileWriter("new-sample.txt")) {

            int character;
            while ((character = reader.read()) != -1) {
                newWriter.write(character);
            }

            System.out.println("Data copied from sample.txt to new-sample.txt successfully.");
        } catch (IOException e) {
            System.out.println("An error occurred while handling the files: " + e.getMessage());
        }

        scanner.close();
    }
}
