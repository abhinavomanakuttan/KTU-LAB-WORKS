 /*
  * Write a Java program that shows thread 
    synchronization 
  */ 
  
import java.util.Random;

class NumberGenerator extends Thread {
    public static int number;

    public void run() {
        Random random = new Random();
        while (true) {
            number = random.nextInt(100);  // Generates a random integer between 0 and 99
            System.out.println("Generated number: " + number);
            try {
                Thread.sleep(1000);  // Pauses for 1 second
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}

class SquareCalculator extends Thread {
    public void run() {
        while (true) {
            if (NumberGenerator.number % 2 == 0) {  // Checks if the number is even
                System.out.println("Square of " + NumberGenerator.number + " is: " + (NumberGenerator.number * NumberGenerator.number));
                try {
                    Thread.sleep(1000);  // Pauses to synchronize with the number generator
                } catch (InterruptedException e) {
                    System.out.println(e.getMessage());
                }
            }
        }
    }
}

class CubeCalculator extends Thread {
    public void run() {
        while (true) {
            if (NumberGenerator.number % 2 != 0) {  // Checks if the number is odd
                System.out.println("Cube of " + NumberGenerator.number + " is: " + (NumberGenerator.number * NumberGenerator.number * NumberGenerator.number));
                try {
                    Thread.sleep(1000);  // Pauses to synchronize with the number generator
                } catch (InterruptedException e) {
                    System.out.println(e.getMessage());
                }
            }
        }
    }
}

public class  Thread_Synchronization {
    public static void main(String[] args) {
        NumberGenerator generator = new NumberGenerator();
        SquareCalculator squareCalculator = new SquareCalculator();
        CubeCalculator cubeCalculator = new CubeCalculator();

        generator.start();
        squareCalculator.start();
        cubeCalculator.start();
    }
}
