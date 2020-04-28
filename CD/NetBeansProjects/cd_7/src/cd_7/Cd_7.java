/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cd_7;

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
public class Cd_7 {
    
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
    public static void main(String[] args) {
       int line=0;
        Input inobj[]=new Input[100];
        int number=0;
       int[] itr = new int[30];
       int[] jtr = new int[30];
        for(int i =0;i<100;i++)
        {
            inobj[i]=new Input();
        }
        try
        {
                BufferedReader input = new BufferedReader(new FileReader("H:\\Sem 6\\CD\\Assi\\7th\\input.txt"));
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
        for(int i=0;i<line;i++)
        {
            System.out.println(inobj[i].result+"\t"+inobj[i].op1+"\t"+inobj[i].operator+"\t"+inobj[i].op2+"\n");
            
        }
        System.out.println("-----------------");
        
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
                         System.out.println("operand 1 " + inobj[j].result + i + j);
                        
                    }
                    if(inobj[j].op2.equals(inobj[i].result) && inobj[i].op2.equals("null"))
                    {
                        inobj[j].op2=inobj[i].op1;
                    }
                    else if(inobj[j].result.equals(inobj[i].result))
                     {
                         flag=1;
                         System.out.println("hey got the result" + i + j);
                         break;
                     }
                }
            }
        }
        
        
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
        
        for(int i=0; i<line; i++)
        {
            if(isNumber(inobj[i].op1))
            {
                for(int j =i+1;j<line;j++)
                {
                     
                    if(inobj[j].op1.equals(inobj[i].result) && inobj[i].op2.equals("null"))
                    {
                        inobj[j].op1=inobj[i].op1;
                         System.out.println("operand 1 " + inobj[j].result + i + j);
                        
                    }
                    if(inobj[j].op2.equals(inobj[i].result) && inobj[i].op2.equals("null"))
                    {
                        inobj[j].op2=inobj[i].op1;
                    }
                    else if(inobj[j].result.equals(inobj[i].result))
                     {
                         flag=1;
                         System.out.println("hey got the result" + i + j);
                         break;
                     }
                }
            }
        }
        
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
        System.out.println("**_________________________**");
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
                BufferedWriter input = new BufferedWriter(new FileWriter("H:\\Sem 6\\CD\\Assi\\7th\\output.txt"));
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
