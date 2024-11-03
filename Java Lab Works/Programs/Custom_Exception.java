/*
Create a mini-application for a banking system in 
Java. In this program, we will add some basic 
functionalities of a bank account like a deposit of 
amount, withdrawal of amount, etc.Initially, the 
program accepts the number of customers (Array of 
Objects)we need to add and adds the customer and 
account details accordingly. Further, it displays the 
series of menus to operate over the accounts. 
1.Display all account details 
2.Search by account number 
3.Deposit the amount 
4.Withdraw the amount 
5.Exit  
Create Custom Exception and perform the 
following action: 
Customers are not allowed to deposit amount <= 0 ( 
In this case throw InvalidAmountException). 
Customers are not allowed to withdraw amount <= 
0 (throw InvalidAmountException). 
 
Customers are also not allowed to withdraw an 
amount greater than (>) the available amount 
(throw InsufficientFundsException) 

 */
import java.util.Scanner;

// Custom Exception for Invalid Amount
class InvalidAmountException extends Exception {
    public InvalidAmountException(String message) {
        super(message);
    }
}

// Custom Exception for Insufficient Funds
class InsufficientFundsException extends Exception {
    public InsufficientFundsException(String message) {
        super(message);
    }
}

// Bank Account class
class BankAccount {
    private String accountNumber;
    private String customerName;
    private double balance;

    // Constructor to initialize account details
    public BankAccount(String accountNumber, String customerName, double initialBalance) {
        this.accountNumber = accountNumber;
        this.customerName = customerName;
        this.balance = initialBalance;
    }

    // Getters for account details
    public String getAccountNumber() {
        return accountNumber;
    }

    public String getCustomerName() {
        return customerName;
    }

    public double getBalance() {
        return balance;
    }

    // Method to deposit amount
    public void deposit(double amount) throws InvalidAmountException {
        if (amount <= 0) {
            throw new InvalidAmountException("Invalid deposit amount. Amount must be greater than zero.");
        }
        balance += amount;
        System.out.println("Successfully deposited " + amount + ". New balance: " + balance);
    }

    // Method to withdraw amount
    public void withdraw(double amount) throws InvalidAmountException, InsufficientFundsException {
        if (amount <= 0) {
            throw new InvalidAmountException("Invalid withdrawal amount. Amount must be greater than zero.");
        }
        if (amount > balance) {
            throw new InsufficientFundsException("Insufficient funds. Available balance: " + balance);
        }
        balance -= amount;
        System.out.println("Successfully withdrew " + amount + ". New balance: " + balance);
    }

    // Method to display account details
    public void displayAccountDetails() {
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Customer Name: " + customerName);
        System.out.println("Balance: " + balance);
    }
}

// Main class for Bank Application
public class  Custom_Exception {
    private static Scanner scanner = new Scanner(System.in);
    private static BankAccount[] accounts;

    public static void main(String[] args) {
        System.out.print("Enter the number of customers: ");
        int numCustomers = scanner.nextInt();
        accounts = new BankAccount[numCustomers];

        // Add customers
        for (int i = 0; i < numCustomers; i++) {
            System.out.print("Enter account number: ");
            String accountNumber = scanner.next();
            System.out.print("Enter customer name: ");
            String customerName = scanner.next();
            System.out.print("Enter initial balance: ");
            double initialBalance = scanner.nextDouble();
            accounts[i] = new BankAccount(accountNumber, customerName, initialBalance);
        }

        // Menu-driven interface
        int choice;
        do {
            System.out.println("\nMenu:");
            System.out.println("1. Display all account details");
            System.out.println("2. Search by account number");
            System.out.println("3. Deposit amount");
            System.out.println("4. Withdraw amount");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    displayAllAccounts();
                    break;
                case 2:
                    searchByAccountNumber();
                    break;
                case 3:
                    depositAmount();
                    break;
                case 4:
                    withdrawAmount();
                    break;
                case 5:
                    System.out.println("Exiting program.");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 5);
    }

    // Display all accounts
    public static void displayAllAccounts() {
        for (BankAccount account : accounts) {
            account.displayAccountDetails();
            System.out.println("---------------");
        }
    }

    // Search for an account by account number
    public static void searchByAccountNumber() {
        System.out.print("Enter account number to search: ");
        String accountNumber = scanner.next();
        BankAccount account = findAccount(accountNumber);
        if (account != null) {
            account.displayAccountDetails();
        } else {
            System.out.println("Account not found.");
        }
    }

    // Deposit amount into account
    public static void depositAmount() {
        System.out.print("Enter account number for deposit: ");
        String accountNumber = scanner.next();
        BankAccount account = findAccount(accountNumber);
        if (account != null) {
            System.out.print("Enter amount to deposit: ");
            double amount = scanner.nextDouble();
            try {
                account.deposit(amount);
            } catch (InvalidAmountException e) {
                System.out.println(e.getMessage());
            }
        } else {
            System.out.println("Account not found.");
        }
    }

    // Withdraw amount from account
    public static void withdrawAmount() {
        System.out.print("Enter account number for withdrawal: ");
        String accountNumber = scanner.next();
        BankAccount account = findAccount(accountNumber);
        if (account != null) {
            System.out.print("Enter amount to withdraw: ");
            double amount = scanner.nextDouble();
            try {
                account.withdraw(amount);
            } catch (InvalidAmountException | InsufficientFundsException e) {
                System.out.println(e.getMessage());
            }
        } else {
            System.out.println("Account not found.");
        }
    }

    // Find account by account number
    public static BankAccount findAccount(String accountNumber) {
        for (BankAccount account : accounts) {
            if (account.getAccountNumber().equals(accountNumber)) {
                return account;
            }
        }
        return null;
    }
}
