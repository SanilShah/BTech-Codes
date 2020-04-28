/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.*;

class Input
{
    public String result; 
    public String op1; 
    char operator; 
    public String op2; 
            
}
public class Cd_7_Copy {
    
     static boolean isNumber(String s) 
    { 
        for (int i = 0; i < s.length(); i++) 
        if (Character.isDigit(s.charAt(i))  
            == false) 
            return false; 
  
        return true; 
    } 
  

    /**
     * @param args the command line arguments
     */

    static int line=0;
    static Input inobj[]=new Input[100];
    static int number=0;
    static int[] itr = new int[30];
    static int[] jtr = new int[30];


    public static void CF()
    {
        for(int i=0; i<line; i++)
        {   
            if(isNumber(inobj[i].op1) && isNumber(inobj[i].op2))
            {
                if(inobj[i].operator=='+')
                {
                    int temp = Integer.parseInt(inobj[i].op1)+Integer.parseInt(inobj[i].op2);
                    inobj[i].op1 = Integer.toString(temp);
                    inobj[i].op2 = "null";
                    inobj[i].operator = 'n';
                }
                else if(inobj[i].operator=='-')
                {
                    int temp = Integer.parseInt(inobj[i].op1)-Integer.parseInt(inobj[i].op2);
                    inobj[i].op1 = Integer.toString(temp);
                    inobj[i].op2 = "null";
                    inobj[i].operator = 'n';
                }
                else if(inobj[i].operator=='*')
                {
                    int temp = Integer.parseInt(inobj[i].op1)*Integer.parseInt(inobj[i].op2);
                    inobj[i].op1 = Integer.toString(temp);
                    inobj[i].op2 = "null";
                    inobj[i].operator = 'n';
                }
                
                else if(inobj[i].operator=='/')
                {
                    int temp = Integer.parseInt(inobj[i].op1)/Integer.parseInt(inobj[i].op2);
                    inobj[i].op1 = Integer.toString(temp);
                    inobj[i].op2 = "null";
                    inobj[i].operator = 'n';
                }
                
            }
        }

    }

    public static void CP()
    {
        int flag=0;
        int inflag=0;
        
        for(int i=0; i<line; i++)
        {
            if(isNumber(inobj[i].op1))
            {
                for(int j =i+1;j<line;j++)
                {
                     
                    if(inobj[j].op1.equals(inobj[i].result) && inobj[i].op2.equals("null"))
                    {
                        inobj[j].op1=inobj[i].op1;
                        // System.out.println("operand 1 " + inobj[j].result + i + j);
                        
                    }
                    if(inobj[j].op2.equals(inobj[i].result) && inobj[i].op2.equals("null"))
                    {
                        inobj[j].op2=inobj[i].op1;
                    }
                    else if(inobj[j].result.equals(inobj[i].result))
                     {
                         flag=1;
                         //System.out.println("hey got the result" + i + j);
                         break;
                     }
                }
            }
        }
    }

    public static void main(String[] args) {

        for(int i =0;i<100;i++)
        {
            inobj[i]=new Input();
        }
        try
        {
                BufferedReader input = new BufferedReader(new FileReader("input.txt"));
                String s;
                int j=0;
                while((s=input.readLine())!=null)
                {
                    String ss[] = s.split("\t");

                    inobj[j].result=ss[0];
                        inobj[j].op1=ss[1];
                        inobj[j].operator=ss[2].charAt(0);
                        inobj[j].op2=ss[3];
                    j++;
                    line++;
                }
        }
        catch(Exception e)
        {
            System.out.println("32 Error"+e);
        }
        System.out.println("\n");
        for(int i=0;i<line;i++)
        {
            System.out.println(inobj[i].result+"\t"+inobj[i].op1+"\t"+inobj[i].operator+"\t"+inobj[i].op2);
            
        }
        System.out.println("-----------------------------");
        
        //Replace
       CF();
        //Replace 2
        CP();
        
        CF();
        
        CP();
        CF();
        //System.out.println("--------------------------");
        for(int i=0;i<line;i++)
        {
            System.out.print(inobj[i].result+"\t"+inobj[i].op1);
            if(!(inobj[i].op2.equals("null")))
            {
                System.out.print("\t"+inobj[i].operator+"\t"+inobj[i].op2);
            }
            System.out.println();
        }
        
         try
            {
                BufferedWriter input = new BufferedWriter(new FileWriter("output.txt"));
                 for(int i=0;i<line;i++)
                {
                    input.write(inobj[i].result+"\t"+inobj[i].op1);  
                    if(!(inobj[i].op2.equals("null")))
                    {
                        input.write("\t"+inobj[i].operator+"\t"+inobj[i].op2);
                    }
                    input.write("\n");
                }
                 input.close();
            }
         catch(Exception e)
         {
             System.out.println("Exception e at 277");
         }
        
    }
   
    //isNumber(inobj[i].op1)
}
