#include<stdio.h>
#include<graphics.h>
#include<dos.h>

typedef struct node
{
  int x,y;
  struct node *next;
} node;

node* head=NULL;

void push(int x,int y)
{
    node* newnode;
    if(head==NULL)
    {
        newnode=(node*)malloc(sizeof(node));
        newnode->x=x;
        newnode->y=y;
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        newnode=(node*)malloc(sizeof(node));
        newnode->x=x;
        newnode->y=y;
        head->next=newnode;
        head=newnode;
    }
}

void boundaryfill(int seed_x,int seed_y,int f_color,int boundary_color)
{
    int x=seed_x;
    int y=seed_y;
    node* temp;
    temp=head;
    push(x,y);
	while(temp)
	{
	    x=temp->x;
	    y=temp->y;
	    putpixel(x,y,);
	    if(getpixel(x,y+1)!=boundary_color&&getpixel(x,y+1)!=f_color)
        {
            putpixel(x,y+1,f_color);
            push(x,y+1);
        }
        else if(getpixel(x,y-1)!=boundary_color&&getpixel(x,y-1)!=f_color)
        {
            putpixel(x,y-1,f_color);
            push(x,y-1);
        }
        else if(getpixel(x+1,y)!=boundary_color&&getpixel(x+1,y)!=f_color)
        {
            putpixel(x+1,y,f_color);
            push(x+1,y);
        }
        if(getpixel(x-1,y)!=boundary_color&&getpixel(x-1,y)!=f_color)
        {
            putpixel(x-1,y,f_color);
            push(x-1,y);
        }
        temp=temp->next;
	}
	getch();
}




int main()
{
	int gm,gd=DETECT,radius;
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	int x,y;
    int white=15,fill_color;
	printf("Enter x and y positions for circle\n");
	scanf("%d%d",&x,&y);
	printf("Enter radius of circle\n");
	scanf("%d",&radius);
    printf("Enter color to fill.\n");
    scanf("%d",&fill_color);
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	circle(x,y,radius);
	boundaryfill(x,y,fill_color,white);
	delay(10);
	closegraph();

	return 0;
}
