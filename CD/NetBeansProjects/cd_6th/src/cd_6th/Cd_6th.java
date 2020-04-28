
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

class Input
{
    public String result; 
    public String op1; 
    char operator; 
    public String op2; 
            
}
public class Cd_6th {

 
    public static void main(String[] args) {
        
        //Input i = new Input();
        int line=0;
        Input inobj[]=new Input[15];
        int number=0;
       int[] itr = new int[15];
       int[] jtr = new int[15];
        for(int i =0;i<15;i++)
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
            System.out.println("32 Error");
        }
        for(int i=0;i<line;i++)
        {
            System.out.println(inobj[i].result+"\t"+inobj[i].op1+"\t"+inobj[i].operator+"\t"+inobj[i].op2+"\n");
            
        }
        System.out.println("-----------------");
        int flag =0,keep=0;
        for(int i=0;i<line;i++)
        {
            for(int j=i+1;j<line;j++)
            {
                
              if(inobj[i].operator == '-' || inobj[i].operator == '/')
              {
                if(inobj[i].op1.equals( inobj[j].op1)  && inobj[i].operator == inobj[j].operator && inobj[i].op2.equals(inobj[j].op2))
                {
                    flag=0;
                    for(int k =i; k<j;k++)
                    {
                        if(inobj[i].op1.equals(inobj[k].result) ||inobj[i].op2.equals(inobj[k].result))
                        {
                            flag=1;
                        }
                    }
                    if(flag!=1)
                    {
                        System.out.println(inobj[i].op1 + "\t" + inobj[i].operator +"\t" + inobj[i].op2);
                        itr[number]=i;
                        jtr[number]=j;
                        number++;
                    }
                }
                else{//System.out.println("Next plz");
                    
                    }
                }
              else
              {
                  if(inobj[i].operator == inobj[j].operator)
                    if(inobj[i].op1.equals(inobj[j].op1)  && inobj[i].op2.equals(inobj[j].op2) || inobj[i].op1.equals(inobj[j].op2)  && inobj[i].op2.equals(inobj[j].op1))
                      {
                          flag=0;
                          for(int k =i; k<j;k++)
                          {
                              if(inobj[i].op1.equals(inobj[k].result) ||inobj[i].op2.equals(inobj[k].result))
                              {
                                  flag=1;
                              }
                          }
                          if(flag!=1)
                          {
                              System.out.println(inobj[i].op1 + "\t" + inobj[i].operator +"\t" + inobj[i].op2);
                              itr[number]=i;
                              jtr[number]=j;
                              number++;
                          }
                      }
                  else{//System.out.println("Next plz");

                       }
                }
            }
            }
            System.out.println("------");
            try
            {
                BufferedWriter input = new BufferedWriter(new FileWriter("output.txt"));
                int j=0;
                int f=0;
                for(int i=0;i<line;i++)
                {
	      f=0;
                    for(int k=0;k<number;k++)
                    {
                        if(i==jtr[k])
                        {
                            f=1;
                            System.out.println(inobj[i].result + "\t"+inobj[itr[k]].result);
                            input.write(inobj[i].result + "\t"+inobj[itr[k]].result+"\n");    
                                
                        }
                    }
                    if(f!=1)
                    {
                        System.out.println(inobj[i].result + "\t"+inobj[i].op1+"\t"+inobj[i].operator+"\t"+inobj[i].op2);
                        input.write(inobj[i].result + "\t"+inobj[i].op1+"\t"+inobj[i].operator+"\t"+inobj[i].op2+"\n");
                    }
                    
                }
                input.close();
            }
            catch(Exception e)
            {
                
            }
        }
    
    }
    

