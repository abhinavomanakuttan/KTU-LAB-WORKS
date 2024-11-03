 
import java.io.*;

public class  File_Exception_Handling {
    public static void main(String[] args) {
        File inputFile = new File("input.txt");
        File outputFile = new File("output.txt");

        // File reading and writing
        try (FileReader reader = new FileReader(inputFile);
             FileWriter writer = new FileWriter(outputFile)) {

            int character;
            while ((character = reader.read()) != -1) {
                writer.write(character);
            }
            System.out.println("File copied successfully from input.txt to output.txt");

        } catch (FileNotFoundException e) {
            System.err.println("Error: The file was not found: " + e.getMessage());
        } catch (IOException e) {
            System.err.println("Error: An I/O error occurred: " + e.getMessage());
        } catch (Exception e) {
            System.err.println("An unexpected error occurred: " + e.getMessage());
        }
    }
}
