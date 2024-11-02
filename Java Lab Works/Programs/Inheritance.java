
/*
Java program which creates a class named 'Employee' having the following members: Name,Age,
Phone number, Address, Salary. It also has a method named 'printSalary( )' which prints the 
salary of the Employee. Two classes 'Officer' and 'Manager' inherits the 'Employee' class. 
The 'Officer' and 'Manager' classes have data members 'specialization' and 'department' respectively. 
Now, assign name, age, phone number, address and salary to an officer and a manager by making an 
object of both of these classes and print the same. 
 */
class Employee{
    String name;
    int age;
    String phoneNO;
    String Address;
    double salary;

    // Constructer to initialze Employee details 
    public Employee(String name,int age, String phoneNO,String Address,double salary){
        this.name =name;
        this.age =age;
        this.phoneNO= phoneNO;
        this.Address =  Address;
        this.salary=salary;

    } 

    public void printSalary(){
        System.out.println("Salary: "+salary);
    }

    public void printDetails(){
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Phone Number: " + phoneNO);
        System.out.println("Address: " + Address);
        printSalary();
    }
}

class officer extends Employee{
    String specialization;

    public officer(String name,int age, String phoneNO,String Address,double salary,String specialization){
        super(name, age, phoneNO, Address, salary);
        this.specialization=specialization;
    }
   public void printDetails(){
    super.printDetails();
    System.out.println("Specialization: " + specialization);
   }
        
    
}
class Manager extends Employee{

    String department;
    public Manager(String name,int age, String phoneNO,String Address,double salary,String department){
        super(name,age,phoneNO,Address,salary);
        this.department=department;

    }
    public void printDetalis(){
        super.printDetails();
        System.out.println("Department: " + department);
       }
    

}





public class Inheritance {
    public static void main(String[] args) {
        officer f =new officer("Abhinav", 20, "12304455", "abcvfjb", 250000 , "B-tech");
        System.out.println("Officer Details :");
        f.printDetails();

        Manager m = new Manager("Bob", 40, "0987654321", "456 Maple Ave", 75000, "HR");
        System.out.println("Manager Details:");
        m.printDetails();
    }
    
}
