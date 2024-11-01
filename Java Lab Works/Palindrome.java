
import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {
        int flag=0;
        Scanner in =new Scanner(System.in);
        System.out.print("Enter the string :");
        String str1=in.nextLine();
        int len=str1.length();// length of the string 

        for(int i=0;i<len/2;i++){ 
            if(str1.charAt(i)==str1.charAt(len-1-1)){ 
                //to check first == last of the string 
                flag=1;
                break;
            }
        }
        if(flag==1){
            System.out.println(str1+" is a palindrome");
        }else {
            System.out.println(str1+" is not a palindrome");
        }
    }
}
