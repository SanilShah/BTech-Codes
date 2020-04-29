#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int choice;

void octantpoint(int x1,int y1,int Xc,int Yc)
{

 putpixel(Xc+x1,Yc+y1,RED);
 putpixel(Xc-x1,Yc+y1,RED);
 putpixel(Xc+x1,Yc-y1,RED);
 putpixel(Xc-x1,Yc-y1,RED);
 putpixel(Xc+y1,Yc+x1,RED);
 putpixel(Xc-y1,Yc+x1,RED);
 putpixel(Xc+y1,Yc-x1,RED);
 putpixel(Xc-y1,Yc-x1,RED);
}



void disObj(int x1,int y1,int Xc,int Yc)
{

 putpixel(Xc+x1,Yc+y1,WHITE);
 putpixel(Xc-x1,Yc+y1,WHITE);
 putpixel(Xc+x1,Yc-y1,WHITE);
 putpixel(Xc-x1,Yc-y1,WHITE);
 putpixel(Xc+y1,Yc+x1,WHITE);
 putpixel(Xc-y1,Yc+x1,WHITE);
 putpixel(Xc+y1,Yc-x1,WHITE);
 putpixel(Xc-y1,Yc-x1,WHITE);
}


void midpoint(int r,int Xc,int Yc)
{
 int p,x=0,y=r;
 p=1-r;

 while(x<=y)
 {
  if(choice!=3)
     octantpoint(x,y,Xc,Yc);
  else
     disObj(x,y,Xc,Yc);
   if(p<=0)
    {
      x++;
      p=p+2*(x)+3;
    }
   else
    {
      x++;
      y--;
      p=p+2*(x)-2*(y)+5;
    }

  }

}


void BresenhamCircle(int r,int Xc,int Yc)
{
 int s,x=0,y=r;
 s=3-2*(r);

 while(x<=y)
 {
	if(choice!=3)
		 octantpoint(x,y,Xc,Yc);
	else
		 disObj(x,y,Xc,Yc);
	 if(s<=0)
		{
			x++;
			s=s+4*(x)+6;
		}
	 else
		{
			x++;
			y--;
			s=s+4*(x)-4*(y)+10;
		}

	}
}

void objectC()
{


}



void main()
{
 int gd=DETECT,gm;
 int r,Xc,Yc;
 initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
 printf("\n");
 printf("\tCircle Drawing Algorithms.\n");
 printf("===================================\n");
 printf("1.Mid-point Algorithm\n2.Bresenham Algorithm\n3.Object Creation\n4.Exit\n");
 printf("===================================\n");
 printf("Enter choice:-");
 scanf("%d",&choice);
 switch(choice)
 {
     case 1:
	   printf("Enter X-co-ordinates of Centre of Circle:-");
	   scanf("%d",&Xc);
	   printf("Enter Y-co-ordinates of Centre of Circle:-");
	   scanf("%d",&Yc);
	   printf("Enter length of Radius:-");
	   scanf("%d",&r);
	   midpoint(r,Xc,Yc);
	   break;

     case 2:
	  printf("Enter X-co-ordinates of Centre of Circle:-");
	  scanf("%d",&Xc);
	  printf("Enter Y-co-ordinates of Centre of Circle:-");
	  scanf("%d",&Yc);
	  printf("Enter length of Radius:-");
	  scanf("%d",&r);
	  BresenhamCircle(r,Xc,Yc);
	  break;

     case 3:
	  objectC();
	  break;

     case 4:
	  exit(0);

     default:
	  printf("Invalid Choice");
 }
 getch();

 closegraph();

}
