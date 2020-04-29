#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>
#include <graphics.h>

typedef struct coordinate
{
	int x,y;
	char code[4];
}point;

void drawwindow();
void drawline(point p1,point p2);
point setcode(point p);
int AND_output(point p1,point p2);
int x1,x2,y1,y2;

void printwindow()
{
	setcolor(RED);
	line(x1,y1,x2,y1);
	line(x2,y1,x2,y2);
	line(x2,y2,x1,y2);
	line(x1,y2,x1,y1);
}


void acceptwindow()
{
	setcolor(RED);

	printf("Draw Window:-\n");
	printf("Enter Upper-Left Coordinates:-\n");
	printf("X:");
	scanf("%d",&x1);
	printf("Y:");
	scanf("%d",&y1);
	printf("Enter Lower-Right Coordinates:-\n");
	printf("X:");
	scanf("%d",&x2);
	printf("Y:");
	scanf("%d",&y2);
	printwindow(x1,y1,x2,y2);
	getch();
}

void main()
{
	int gd=DETECT, gm,logical_AND;
	point p1,p2,temp;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	cleardevice();
	printf("\t\t\t** MIDPOINT CLIPPING **\n");
	acceptwindow();
	printf("END-POINT 1 (Line):\n");
	printf("X:");
	scanf("%d",&p1.x);
	printf("Y:");
	scanf("%d",&p1.y);
	printf("\nEND-POINT 2 (Line):\n");
	printf("X:");
	scanf("%d",&p2.x);
	printf("Y:");
	scanf("%d",&p2.y);
	cleardevice();
	setcolor(WHITE);
	outtextxy(10,20,"Before Clipping...");
	printwindow();
	setcolor(WHITE);
	drawline(p1,p2);
	getch();
	cleardevice();
	outtextxy(10,20,"After Clipping...");
	printwindow();
	setcolor(WHITE);
	midsub(p1,p2);
	getch();
	closegraph();
}

midsub(point p1,point p2)
{
	point mid;
	int logical_AND;
	p1=setcode(p1);
	p2=setcode(p2);
	logical_AND=AND_output(p1,p2);
	switch(logical_AND)
	{
	case 0:
		drawline(p1,p2);
		break;
	case 1:
		break;
	case 2:
		mid.x=p1.x+(p2.x-p1.x)/2;
		mid.y=p1.y+(p2.y-p1.y)/2;
		midsub(p1,mid);
		mid.x=mid.x+1;
		mid.y=mid.y+1;
		midsub(mid,p2);
		break;
	}
	return 0;
}


void drawline(point p1,point p2)
{
	line(p1.x,p1.y,p2.x,p2.y);
}

point setcode(point p)
{
	point temp;
	if(p.y<=y1)
	   temp.code[0]='1';
	else temp.code[0]='0';
	if(p.y>=y2)
	   temp.code[1]='1';
	else
	   temp.code[1]='0';
	if (p.x>=x2)
	   temp.code[2]='1';
	else
	   temp.code[2]='0';
	if (p.x<=x1)
	   temp.code[3]='1';
	else
	   temp.code[3]='0';
	temp.x=p.x;
	temp.y=p.y;
	return(temp);
}

int AND_output(point p1,point p2)
{
	int i,flag=0;
	for(i=0;i<4;i++)
	{
		if((p1.code[i]!='0')||(p2.code[i]!='0'))
		flag=1;
	}
	if(flag==0)
		return(0);

	for(i=0;i<4;i++)
	{
		if((p1.code[i]==p2.code[i]) &&(p1.code[i]=='1'))
		flag=0;
	}
	if(flag==0)
		return(1);

return(2);
}