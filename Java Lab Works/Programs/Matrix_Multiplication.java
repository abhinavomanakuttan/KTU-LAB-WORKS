/*
  
    Java program to multiply two given matrices  
 
    */

import java.util.Scanner;

public class Matrix_Multiplication {
    public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);

        // Input for the first matrix
        System.out.println("Enter dimensions of the first matrix (rows and columns): ");
        int rows1 = sc.nextInt();
        int cols1 = sc.nextInt();
        int[][] matrix1 = new int[rows1][cols1];

        System.out.println("Enter elements of the first matrix:");
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols1; j++) {
                System.out.print("(" + (i+1)+" " + (j+1) + ") =");
                matrix1[i][j] = sc.nextInt();
            }
        }

        // Input for the second matrix
        System.out.println("Enter dimensions of the second matrix (rows and columns): ");
        int rows2 = sc.nextInt();
        int cols2 = sc.nextInt();
        int[][] matrix2 = new int[rows2][cols2];

        // Ensure that matrix multiplication is possible
        if (cols1 != rows2) {
            System.out.println("Matrix multiplication not possible: columns of the first matrix must equal rows of the second matrix.");
            return;
        }

        System.out.println("Enter elements of the second matrix:");
        for (int i = 0; i < rows2; i++) {
            for (int j = 0; j < cols2; j++) {
                System.out.print("(" + (i+1)+" " + (j+1) + ") =");
                matrix2[i][j] = sc.nextInt();
            }
        }

        // Result matrix
        int[][] result = new int[rows1][cols2];

        // Matrix multiplication
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                for (int k = 0; k < cols1; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        // Display the result
        System.out.println("Product of the matrices:");
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }   
}
