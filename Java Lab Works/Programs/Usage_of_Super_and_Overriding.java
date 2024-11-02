/*
 Write two Java classes Employee and Engineer. 
Engineer should inherit from Employee class. 
Employee class to have two methods display() and 
calcSalary(). Write a program to display the 
engineer salary and to display from Employee class 
using a single object instantiation (i.e., only one 
object creation is allowed).  

 ● display() only prints the name of the class and 
does not return any value. Ex. “....... 
Employee.......” 

 ● calcSalary() in Employee displays “Salary of 
employee is 10000” and calcSalary() in Engineer 
displays “Salary of Engineer is 20000.” 
 */

class Employee {
    // Method to display the class name
    void display() {
        System.out.println("....... Employee .......");
    }

    // Method to calculate and display the salary of an employee
    void calcSalary() {
        System.out.println("Salary of employee is 10000");
    }
}

class Engineer extends Employee {
    // Method to display the class name
    @Override
    void display() {
        System.out.println("....... Engineer .......");
    }

    // Method to calculate and display the salary of an engineer
    @Override
    void calcSalary() {
        System.out.println("Salary of Engineer is 20000");
    }
}

public class  Usage_of_Super_and_Overriding {
    public static void main(String[] args) {
        // Single object instantiation of Engineer
        Employee emp = new Engineer();
        
        // Display and calculate salary using the Engineer object
        emp.display();
        emp.calcSalary();
    }
}

 

