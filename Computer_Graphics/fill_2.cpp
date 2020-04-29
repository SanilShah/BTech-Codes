#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include"myline.h"

typedef struct node
{
  int x,y;
  struct node *next;
} node;

node *front=NULL,*rear=NULL;
int point_x[10],point_y[10];

void enqueue(int x,int y)
{
    node* newnode;

    if(rear==NULL && front==NULL)
    {
	newnode=(node*)malloc(sizeof(node));
	newnode->x=x;
	newnode->y=y;
	newnode->next=NULL;
	rear=newnode;
	front=rear;
    }
    else
    {
	newnode=(node*)malloc(sizeof(node));
	newnode->x=x;
	newnode->y=y;
	rear->next=newnode;
	rear=newnode;

    }
}

void edgefill(int f_point,int s_point,int f_color)
{
    float x1,y1,x2,y2,m;
    int x;
    {
	if(point_y[f_point]<point_y[s_point])
	{
	    y1=point_y[f_point];
	    x1=point_x[f_point];
	    y2=point_y[s_point];
	    x2=point_x[s_point];
	}
	else
	{
	    y1=point_y[s_point];
	    x1=point_x[s_point];
	    y2=point_y[f_point];
	    x2=point_x[f_point];
	}
	putpixel(point_x[f_point],point_y[f_point],f_color);
	putpixel(point_x[s_point],point_y[s_point],f_color);
	m=(float)(y2-y1)/(x2-x1);

	while(y1<y2)
	{
	    y1++;
	    x1=x1+(1/m);
	    x=x1;
	    while(x<=639)
	    {
		if(getpixel(x,y1)==0)
		    putpixel(x,y1,f_color);
		else
		    putpixel(x,y1,0);
		x++;
		delay(0.1);
	    }
	}
    }
}

void boundaryfill(int seed_x,int seed_y,int f_color,int boundary_color)
{
    int x=seed_x;
    int y=seed_y;
    node* temp;
   // push(x,y);
   enqueue(x,y);
    temp=front;
	while(temp)
	{
	    x=temp->x;
	    y=temp->y;

	    putpixel(x,y,f_color);
	if(getpixel(x,y+1)!=boundary_color&&getpixel(x,y+1)!=f_color)
	{
	    putpixel(x,y+1,f_color);
	   // push(x+1,y);'
	   enqueue(x,y+1);
	}
	if(getpixel(x,y-1)!=boundary_color&&getpixel(x,y-1)!=f_color)
	{
	    putpixel(x,y-1,f_color);
	    //push(x,y+1);
	    enqueue(x,y-1);
	}

	if(getpixel(x+1,y)!=boundary_color&&getpixel(x+1,y)!=f_color)
	{
	    putpixel(x+1,y,f_color);
	   // push(x,y-1);
	   enqueue(x+1,y);
	}
	if(getpixel(x-1,y)!=boundary_color&&getpixel(x-1,y)!=f_color)
	{
	    putpixel(x-1,y,f_color);
	   // push(x-1,y);
	   enqueue(x-1,y);
	}


       /*	if(getpixel(x+1,y+1)!=boundary_color&&getpixel(x+1,y+1)!=f_color)
	{
	    putpixel(x+1,y+1,f_color);
	   // push(x,y-1);
	   enqueue(x+1,y+1);
	}
	if(getpixel(x+1,y-1)!=boundary_color&&getpixel(x+1,y-1)!=f_color)
	{
	    putpixel(x+1,y-1,f_color);
	   // push(x,y-1);
	   enqueue(x+1,y-1);
	}
	if(getpixel(x-1,y-1)!=boundary_color&&getpixel(x-1,y-1)!=f_color)
	{
	    putpixel(x-1,y-1,f_color);
	   // push(x,y-1);
	   enqueue(x-1,y-1);
	}
	if(getpixel(x-1,y+1)!=boundary_color&&getpixel(x-1,y+1)!=f_color)
	{
	    putpixel(x-1,y+1,f_color);
	   // push(x,y-1);
	   enqueue(x-1,y+1);
	} */
	node* temp1=temp;
	temp=temp->next;
	free(temp1);


	delay(0.1);
      }
}

void boundaryfill_recursive(int x,int y,int f_color,int b_color)
{
	if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
	{
		putpixel(x,y,f_color);
		boundaryfill(x+1,y,f_color,b_color);
		boundaryfill(x,y+1,f_color,b_color);
		boundaryfill(x-1,y,f_color,b_color);
		boundaryfill(x,y-1,f_color,b_color);
	}
}




int main()
{

	int gm,gd=DETECT;
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	int x,y,x1,y1,x2,y2,vertices,i=1;
	int white=15,fill_color,choice;

	printf("*** FILL ALGORITHMS ***\n\n");
	printf(" 1>Edge Fill\n 2>Boundary Fill \n");
	printf("***********************\n\n\n");
	printf("Press Enter...\n");
	getch();
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");

	printf("Enter no.of Vertices:");
	scanf("%d",&vertices);
	printf("Enter Vertex Coordinates:-\n");
	while(i<=vertices)
	{
		printf("X%d:",i);
		scanf("%d",&point_x[i]);
		printf("Y%d:",i);
		scanf("%d",&point_y[i]);
		printf("\n");
		i++;
	}
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	i=1;
	while(i<=vertices)
	{
		if(i==vertices)
		{
			DDA(point_x[i],point_y[i],point_x[1],point_y[1]);
		}
		else
		{
			DDA(point_x[i],point_y[i],point_x[i+1],point_y[i+1]);
		}
		i++;
	}
       /*	while(i<=vertices)
	{
		printf("Line %d:-\nEnter X1:",i);
		scanf("%d",&x1);
		printf("      Y1:");
		scanf("%d",&y1);
		printf("Enter X2:");
		scanf("%d",&x2);
		printf("      Y2:");
		scanf("%d",&y2);
		printf("\n");
		line(x1,y1,x2,y2);
		i++;
	}*/
	printf("1)Edge Fill.\n2)Boundary Fill.\n3)Exit\n\nEnter Choice:");
	scanf("%d",&choice);
	if(choice==1)
	{
		int i=1;
		int j;
		for(j=0;j<vertices-1;j++)
		{
			edgefill(i,i+1,4);
			i++;
		}
		edgefill(1,vertices,4);
		getch();
	}
	else if(choice==2)
	{
		printf("Seed Point:-\nEnter X:");
		scanf("%d",&x);
		printf("      Y:");
		scanf("%d",&y);
		printf("Enter Color:");
		scanf("%d",&fill_color);
		i=1;
		initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
		while(i<=vertices)
		{
			if(i==vertices)
			{
				DDA(point_x[i],point_y[i],point_x[1],point_y[1]);
			}
			else
			{
				DDA(point_x[i],point_y[i],point_x[i+1],point_y[i+1]);
			}
			i++;
		}
		boundaryfill(x,y,fill_color,white);
		delay(1);
	}
	else
	closegraph();
	return 0;
}
