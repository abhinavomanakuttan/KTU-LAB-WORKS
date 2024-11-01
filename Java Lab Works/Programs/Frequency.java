
import java.util.Scanner;

public class  Frequency{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Enter the Stirng ");
        String str =in.nextLine();

        System.out.println("Enter the character you want to find out: ");
        char ch =in.next().charAt(0);

        int len =  str.length();

        int count=0;
        for (int i=0;i<len;i++){
            if (str.charAt(i) == ch) {
                count++;
            }
        }
        System.out.print("The count of "+ch+" is "+count);
    }
}