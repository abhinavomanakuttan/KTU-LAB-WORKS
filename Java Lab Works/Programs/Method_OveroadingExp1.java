
import java.util.Scanner;

class Method_OveroadingExp1 {
    //Method to calculate the area of a circle
    
    public double calArea(double radius){
        return Math.PI*radius*radius;
    }

    public double calArea(double lenght ,double breath){
        return lenght*breath;
    }

    public double calArea(float  base,float  height){
        return 0.5*(base*height);
    
    }

    public static void main(String[] args) {

        Method_OveroadingExp1  c=new Method_OveroadingExp1();

        Scanner in =new Scanner(System.in);
        System.out.println("Enter the radius of the circle: ");
        double r = in.nextDouble();

        System.out.println("Enter the lenght of the rectangel ");
        double l = in.nextDouble();  
        double b =in.nextDouble();

        System.out.println("Enter the height and base of the tirangle : ");
        double height = in.nextDouble();
        double base =in.nextDouble();

        System.out.println("Area of the cricle ="+c.calArea(r));
        System.out.println("Area of the rectangle ="+c.calArea(l,b));
        System.out.println("Area of the triangle ="+c.calArea(base,height));
    }
}
