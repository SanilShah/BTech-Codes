#include<stdio.h>
#include<conio.h>
#include<time.h>
#define max 10


char block[max],compVar,userVar;

/*void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
*/

void go(int move,char moveVar)
{
 block[move]=moveVar;
}

int makeMove()
{
   if(block[2]=='b')
    {
      return 2;
    }
   else if(block[4]=='b')
   {
       return 4;
   }
   else if(block[6]=='b')
   {
       return 6;
   }
   else if(block[8]=='b')
   {
       return 8;
   }
}

int passwin(char moveVar)
{
    int i,j,k,arr[max];
    int cnt,count=0,temp,index=0;
    int sumRow=0,sumDiagonal=0,sumColumn=0;
    int flag=0,f=0;

    for(i=1; i<=9; i++)
    {

	index=0;
	f=0;

	if(i<=6)                                /*Column-wise check*/
	{
	    k=0;
	    count=0;
	    for(j=i; j<=9; j=j+3)
	    {
            if(block[j]==moveVar)
            {
                arr[k]=j;
                count++;
                k++;
            }
	    }
	    sumColumn=arr[0]+arr[1];

	    if(count==2 && (sumColumn==8 || sumColumn==10 || sumColumn==12))
	    {
            temp=arr[1];
            index=temp-3;

	    }
	    else if(count==2)
	    {
            temp=arr[1];
            index=temp+3;

	    }
	    if(index<=9 && block[index]=='b')
		    break;
        index=0;
	}

	if(i>=7 && i<=9)                       /*Column-wise check*/
	{
	    k=0;
	    count=0;

	    for(j=i; j>=1; j=j-3)
	    {
            if(block[j]==moveVar)
            {
                arr[k]=j;
                count++;
                k++;
            }
	    }
	    sumColumn=arr[0]+arr[1];

	    if(count==2 && (sumColumn==8 || sumColumn==10 || sumColumn==12))
	    {
            temp=arr[1];
            index=temp+3;

	    }
	    else if(count==2)
	    {
            temp=arr[1];
            index=temp-3;

	    }
	    if(index<=9 && block[index]=='b')
		    break;
        index=0;
	}

	if(i==1)                     /* Diagonal-wise check */
	{
	    k=0;
	    count=0;

	    for(j=i; j<=9; j=j+4)
	    {
            if(block[j]==moveVar)
            {
                arr[k]=j;
                count++;
                k++;
            }
	    }
	    if(count==2 && sumDiagonal==10)
        {
            temp=arr[1];
            index=temp-4;
        }
	    else if(count==2)
	    {
            temp=arr[1];
            index=temp+4;

	    }
	    if(index<=9 && block[index]=='b')
            break;
        index=0;
	}

	if(i==3)                                    /* Diagonal-wise check */
	{
	    k=0;
	    count=0;

	    for(j=i; j<=9; j=j+2)
	    {
		if(block[j]==moveVar)
		{
		    arr[k]=j;
		    count++;
		    k++;
		}
	    }
	    if(count==2 && sumDiagonal==10)
        {
            temp=arr[1];
            index=temp-2;
        }
	    else if(count==2)
	    {
            temp=arr[1];
            index=temp+2;
	    }
	    if(index<=9 && block[index]=='b')
		{
		  sumDiagonal=arr[0]+arr[1]+index;
		  if(sumDiagonal==15)
		  {
		   flag=1;
		  }
		}
		if(flag==1)
		    break;
        index=0;


	}

    if(i==7)                        /* Diagonal-wise check */
    {
        k=0;
	    count=0;

	    for(j=i; j>=1; j=j-2)
	    {
		if(block[j]==moveVar)
		{
		    arr[k]=j;
		    count++;
		    k++;
		}
	    }
	    if(count==2 && sumDiagonal==10)
        {
            temp=arr[1];
            index=temp+2;
        }
	    else if(count==2)
	    {
            temp=arr[1];
            index=temp-2;

	    }
	    if(index<=9 && block[index]=='b')
            break;
        index=0;

    }

	if(i==9)                    /* Diagonal-wise check */
	{
	    k=0;
	    count=0;

	    for(j=i; j>=1; j=j-4)
	    {
		if(block[j]==moveVar)
		{
		    arr[k]=j;
		    count++;
		    k++;
		}
	    }
	    if(count==2 && sumDiagonal==10)
        {
            temp=arr[1];
            index=temp+4;
        }
	    else if(count==2)
	    {
            temp=arr[1];
            index=temp-4;

	    }
	    if(index<=9 && block[index]=='b')
            break;
        index=0;
	}

	if(i%3==0)                                   /* Row-wise check */
	{
	    k=0;
	    count=0;
	    //index=0;
	    for(j=i; j>=2; j--)
	    {
            if(block[j]==moveVar && block[j-1]==moveVar)
            {
                arr[k]=j;
                k++;
                arr[k]=j-1;
                k++;
                count=2;

            }
            else if(block[j]==moveVar && block[j-2]==moveVar)
            {
                arr[k]=j;
                k++;
                arr[k]=j-2;
                k++;
                count=2;
                f=1;

            }
	     }
         if(count==2 && f==1)
         {
            temp=arr[1];
            index=temp+1;
         }
         else if(count==2)
		 {
            temp=arr[1];
            index=temp-1;

		 }
		 if(index<=9 && block[index]=='b')
                    break;
        index=0;
	}

	if(i%3!=0)                             /* Row-wise check */
	{
		 k=0;
		 count=0;
		 //index=0;
		 for(j=i; j<=8; j++)
		 {
				if(block[j]==moveVar && block[j+1]==moveVar)
				{
					 arr[k]=j;
					 k++;
					 arr[k]=j+1;
					 k++;
					 count=2;

				}
				else if(block[j]==moveVar && block[j+2]==moveVar)
				{
					 arr[k]=j;
					 k++;
					 arr[k]=j+2;
					 k++;
					 count=2;
					 f=1;

				}
		 }
		 if(count==2 && f==1)
         {
                temp=arr[1];
				index=temp-1;
         }
		 else if(count==2)
		 {
				temp=arr[1];
				index=temp+1;

		 }
		 if(index<=9 && block[index]=='b')
				{
				 sumRow=arr[0]+arr[1]+index ;
				 if(sumRow==6 || sumRow==15 || sumRow==24)
				 {
					 flag=1;
				 }
				}
				if(flag==1)
					 break;
                index=0;
    }

   }
	return index;
}

void displayBlock()
{
	 int i;
	 for(i=1; i<=9; i++)
	 {
	if(i%3==1)
	 {
		 printf("\n");
	 }
	 printf("%4c",block[i]);
	 }

}

int main()
{
	 int i,j,blockNo=0,move,flag=1;
	 int userMove,index,cnt=1;
	 //clrscr();

     printf("\n------------------------------------------------------\n");
	 printf("\t\tTic");
	 delay(200);
	 printf(" Tac");
	 delay(200);
	 printf(" Toe");
	 delay(200);
	 printf("\n------------------------------------------------------\n");


	 printf("\nEnter your Move( X / O ):");
	 scanf("%c",&userVar);

	 for(i=1; i<=9; i++)       /* Initial Block State */
	 {
	 block[i]='b';
	 }

     displayBlock();

	 if(userVar=='X')
	 {
		  compVar='O';
		  printf("\n\n\tUser Plays 1st...");
		  printf("\n\nYour Move:");
		  scanf("%d",&userMove);
		  go(userMove,userVar);
		  printf("\n\nStep-1");
		  displayBlock();
		  flag=2;
	 }
	 else
	 {
		  compVar='X';
		  printf("Computer Plays 1st...");
		  go(5,compVar);
		  printf("\n\nStep-1");
		  displayBlock();
		  flag=1;
	 }

	 for(i=2; i<=9; i++)
	 {
        cnt++;
		  if(flag==2)                               /* Computer Moves */
		  {
                printf("\n\n\tComputer is playing");
                printf(".");
                delay(100);                         /* Total Delay 1.7 sec */
                printf(".");
                delay(100);
                printf(".");
                delay(100);
                printf(".");
                delay(100);
                printf(".");
                delay(100);

                delay(400);
				if(passwin(compVar)!=0)
				{
					 index=passwin(compVar);
					 go(index,compVar);
					 printf("\n\nStep-%d",i);
					 displayBlock();
					 printf("\n\n\tComputer Wins !");
					 flag=0;
					 break;
				}
				else if(passwin(userVar)!=0)
				{
					 go(passwin(userVar),compVar);
				}
				else if(block[5]=='b')
				{
					 go(5,compVar);
				}

				else if(block[1]=='b')
				{
					 go(1,compVar);
				}
				else if(block[3]=='b')
				{
					 go(3,compVar);
				}
				else if(block[7]=='b')
				{
					 go(7,compVar);
				}
				else if(block[9]=='b')
				{
					 go(9,compVar);
				}

				else
				{
					 move=makeMove();
					 go(move,compVar);
				}
				flag=1;
		  }
		  else                                      /* User Moves */
           {

				printf("\n\nEnter your move:");
				scanf("%d",&userMove);

				if(block[userMove]!='b')
                {
                    printf("\n!! Invalid Move !!");
                    printf("\nEnter your move again:");
                    scanf("%d",&userMove);
                }

				if(passwin(userVar)!=0)
                {
                    index=passwin(userVar);
                    if(index==userMove)
                    {
                        go(userMove,userVar);
                        printf("\n\nStep-%d",i);
                        displayBlock();
                        printf("\n\n\tUser Wins !");
                        flag=0;
                        break;
                    }

                }

				go(userMove,userVar);
				flag=2;
		  }

		  printf("\n\nStep-%d",i);
		  displayBlock();
		  if(cnt>=9)
                break;

	 }

	if(flag!=0)
		printf("\n\n\tMatch Draw...");

     //printf("Cnt-%d",cnt);
	 getch();
	 return 0;

}
