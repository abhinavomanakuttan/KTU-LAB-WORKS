/*
Write a Java program that implements a 
multithreaded program which has three threads. 
First thread generates a random integer every 1 
second. If the value is even, second thread 
computes the square of the number and prints. If 
the value is odd the third thread will print the value 
of cube of the number 
 */

import java.util.Random;

class NumberGenerator extends Thread {
    public static int number;

    public void run() {
        Random random = new Random();
        int i=0;
        while (i<=4) {
            number = random.nextInt(100);  // Generates a random integer between 0 and 99
            System.out.println("Generated number: " + number);
            try {
                Thread.sleep(1000);  // Pauses for 1 second
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
            i++;
        }
    }
}

class SquareCalculator extends Thread {
    public void run() {
        int i=0;
        while (i<=4) {
            if (NumberGenerator.number % 2 == 0) {  // Checks if the number is even
                System.out.println("Square of " + NumberGenerator.number + " is: " + (NumberGenerator.number * NumberGenerator.number));
                try {
                    Thread.sleep(1000);  // Pauses to synchronize with the number generator
                } catch (InterruptedException e) {
                    System.out.println(e.getMessage());
                }
            }
            i++;
        }
    }
}

class CubeCalculator extends Thread {
    public void run() {
        int i=0;
        while (i<=4) {
            if (NumberGenerator.number % 2 != 0) {  // Checks if the number is odd
                System.out.println("Cube of " + NumberGenerator.number + " is: " + (NumberGenerator.number * NumberGenerator.number * NumberGenerator.number));
                try {
                    Thread.sleep(1000);  // Pauses to synchronize with the number generator
                } catch (InterruptedException e) {
                    System.out.println(e.getMessage());
                }
            }
            i++;
        }
    }
}

public class Exp14_Multi_threading {
    public static void main(String[] args) {
        NumberGenerator generator = new NumberGenerator();
        SquareCalculator squareCalculator = new SquareCalculator();
        CubeCalculator cubeCalculator = new CubeCalculator();

        generator.start();
        squareCalculator.start();
        cubeCalculator.start();
    }
}
