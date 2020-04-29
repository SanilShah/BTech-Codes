#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

float x1,x2,y1,y2,slope,dx,dy,x,y,G,temp_x,temp_y;

int round(float previous_number)
{
 int converted_number;
 converted_number=previous_number+0.5;
 return converted_number;
}

void swap(float x1,float y1,float x2,float y2)
{
 int t1,t2;

  t1=x1;
  x1=x2;
  x2=t1;
  t2=y1;
  y1=y2;
  y2=t2;
}

void DDA(float x1,float y1,float x2,float y2)
{
 if(x1>x2||y1>y2)
   {
       int temp1,temp2;

        temp1=x1;
        x1=x2;
        x2=temp1;

        temp2=y1;
        y1=y2;
        y2=temp2;
   }
   //swap(x1,y1,x2,y2)
 dx=abs(x2-x1);
 dy=abs(y2-y1);

 slope=(float)dy/dx;
 x=x1;
 y=y1;
 putpixel(round(x1),round(y1),RED);
 while(x!=x2||y!=y2)
 {
  if(dx>dy)
  {
    if(x1<x2)
      {
       x++;
      }
    else
      {
       x--;
      }
    if(y1<y2)
      {
       y=y+slope;
      }
    else
      {
       y=y-slope;
      }
    temp_y=round(y);
    putpixel(round(x),temp_y,RED);
  }
 else if(dx<dy)
  {
    if(y1<y2)
     {
      y++;
     }
    else
     {
      y--;
     }

    if(x1<x2)
     {
      x=x+1/slope;
     }
    else
     {
      x=x-1/slope;
     }
    temp_x=round(x);
    putpixel(temp_x,round(y),RED);
  }
  else if(dx==0)
  {
    y++;
    putpixel(round(x),round(y),RED);
  }
 else if(dx==dy)
  {
   if(x1<x2)
    {
     x++;
    }
   else
    {
      x--;
    }

   if(y1<y2)
    {
      y++;
    }
   else
    {
      y--;
    }
    putpixel(round(x),round(y),RED);
  }
 else
  {
     y++;
    putpixel(round(x),round(y),RED);
  }
 }
putpixel(round(x2),round(y2),RED);
}


void Bresenham(float x1,float y1,float x2,float y2)
{
  if(x1>x2||y1>y2)
 {
  int temp1,temp2;
  temp1=x1;
  x1=x2;
  x2=temp1;
  temp2=y1;
  y1=y2;
  y2=temp2;
 }
 x=x1;
 y=y1;

 dx=abs(x2-x1);
 dy=abs(y2-y1);

 putpixel(x,y,WHITE);
  if(dx>=dy)
  {
     G=2*(dy)-dx;
   while(x!=x2||y!=y2)
   {
    if(G>=0)
    {
      if(y1<y2)
      {
       y++;
      }
      else
      {
       y--;
      }
      x++;
      G=G+2*(dy)-2*(dx);
      putpixel(x,y,WHITE);
     }
    else
     {
      x++;
      G=G+2*(dy);
      putpixel(x,y,WHITE);
     }
    }
   }
 else
 {
    G=2*(dx)-dy;
   while(x!=x2||y!=y2)
   {
    if(G>=0)
    {
      if(x1<x2)
      {
       x++;
      }
     else
      {
	x--;
      }
      y++;
      G=G+2*(dx)-2*(dy);
      putpixel(x,y,WHITE);

    }
    else
    {
     y++;
     G=G+2*(dx);
     putpixel(x,y,WHITE);
    }
   }
  }
  putpixel(x,y,WHITE);
}

void showobject()
{
    DDA(100,100,200,200);
}

int main()
{
    int gdriver=DETECT,gmode,choice,x1,x2,y1,y2;

    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
    printf("======= Line Drawing Algorithms ======== \n");
    printf("1.DDA Algorithm.\n2.Bresenham Algorithm.\nChoice : ");
    scanf("%d",&choice);
    printf("Enter Coordinates:-\n");
    printf(" X1=");
    scanf("%d",&x1);
    printf(" Y1=");
    scanf("%d",&y1);
    printf(" X2=");
    scanf("%d",&x2);
    printf(" Y2=");
    scanf("%d",&y2);
    printf("======================================== \n");

    switch(choice)
    {
       case 1 : DDA(x1,x2,y1,y2);
		break;
       case 2 : Bresenham(x1,x2,y1,y2);
		break;
       case 3: showobject();
        break;
    }
    getch();
    closegraph();
    return 0;
}


