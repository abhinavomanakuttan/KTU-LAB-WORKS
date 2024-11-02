/*
 \Java program to create an abstract class named 
Shape that contains an empty method named 
printArea( ). Provide three classes named 
Rectangle, Triangle and Hexagon such that each 
one of the classes extends the class Shape. Each 
one of the classes contains only the method 
printArea( ) that shows the area of in the given 
geometrical structures. Also find the area of each 
shape when the side is given. 
 */

abstract class Shape{
    abstract void printArea();
}

class Rectangle extends Shape{
    int lenght ;
    int width;

    public Rectangle(int lenght,int width){
        this.lenght=lenght;
        this.width=width;
    }

    @Override
    void printArea() {
        int area =lenght*width;
        System.out.println("Area: "+area);
    }

}
class Triangle extends Shape {
    double base;
    double height;

    // Constructor to initialize dimensions
    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    // Calculate and print area of the triangle
    @Override
    void printArea() {
        double area = 0.5 * (base * height);
        System.out.println("Area of Triangle: " + area);
    }
}

class Hexagon extends Shape {
    double side;
    

    // Constructor to initialize dimensions
    public Hexagon(double side) {
        this.side = side;
        
    }

    // Calculate and print area of the triangle
    @Override
    void printArea() {
        double area = (3 * Math.sqrt(3) / 2) * side * side;
        System.out.println("Area of Hexagon: " + area);
    }
}


public class Abstract_class {
    public static void main(String[] args) {
        // Create Rectangle object with given length and width
        Rectangle rectangle = new Rectangle(5, 10);
        rectangle.printArea();
        //create Trinagle object with give base and height
        Triangle t =new Triangle(10, 14);
        t.printArea();

        // Create Hexagon object with given side length
        Hexagon hexagon = new Hexagon(7);
        hexagon.printArea();
    
    }
}
