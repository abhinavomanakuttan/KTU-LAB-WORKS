/*
Write a Java program that works as a simple 
calculator. Arrange Buttons for digits and the
 + - * % 
operations properly. Add a text field to display 
the result. Handle any possible exceptions like 
divide by zero. Use Java Swing.
 */
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class  Calculator extends JFrame implements ActionListener {
    private JTextField display;
    private String operator;
    private double firstOperand;
    
    public  Calculator() {
        // Set up the frame
        setTitle("Simple Calculator");
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Create the display field
        display = new JTextField();
        display.setEditable(false);
        display.setFont(new Font("Arial", Font.BOLD, 24));
        add(display, BorderLayout.NORTH);

        // Create buttons
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4));

        String[] buttons = {
                "7", "8", "9", "/",
                "4", "5", "6", "*",
                "1", "2", "3", "-",
                "0", "C", "=", "+"
        };

        for (String text : buttons) {
            JButton button = new JButton(text);
            button.addActionListener(this);
            buttonPanel.add(button);
        }

        add(buttonPanel, BorderLayout.CENTER);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        switch (command) {
            case "C":
                display.setText("");
                firstOperand = 0;
                operator = "";
                break;
            case "=":
                try {
                    double secondOperand = Double.parseDouble(display.getText());
                    double result = performOperation(secondOperand);
                    display.setText(String.valueOf(result));
                } catch (ArithmeticException ex) {
                    display.setText("Error: " + ex.getMessage());
                } catch (NumberFormatException ex) {
                    display.setText("Error: Invalid Input");
                }
                break;
            default:
                if ("+-*/".contains(command)) {
                    firstOperand = Double.parseDouble(display.getText());
                    operator = command;
                    display.setText("");
                } else {
                    display.setText(display.getText() + command);
                }
                break;
        }
    }

    private double performOperation(double secondOperand) {
        switch (operator) {
            case "+":
                return firstOperand + secondOperand;
            case "-":
                return firstOperand - secondOperand;
            case "*":
                return firstOperand * secondOperand;
            case "/":
                if (secondOperand == 0) {
                    throw new ArithmeticException("Cannot divide by zero");
                }
                return firstOperand / secondOperand;
            default:
                return secondOperand;  // If no operator, return the second operand
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            Calculator calculator = new  Calculator();
            calculator.setVisible(true);
        });
    }
}
