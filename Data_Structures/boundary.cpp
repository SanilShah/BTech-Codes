#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>

typedef struct node
{
    int x,y;
    node *next;
}node;

node *rear=NULL,*front=NULL;

node *createnode(int x,int y)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->x=x;
    temp->y=y;
    temp->next=NULL;

    return temp;
}

void enqueue(node *x)
{
    if(front==NULL and rear==NULL)
    {
        rear=x;
        front=x;
    }
    else
    {
        rear=x;
        rear=rear->next();
    }
}

node *dequeue()
{
    return front();
}

void drawpolygon()
{
    setcolor(15);
    line(100,100,100,200);
    line(100,200,200,200);
    line(200,200,200,100);
    line(200,100,100,100);
}

b_fill(int x,int y)
{
    node *temp=createnode(x,y);
    node *p;
    front=NULL;
    rear=NULL;
    int x,y;
    int bcolor=15;
    int fcolor=4;
    enqueue(temp)
    {
        while(front!=NULL)
        {
            p=dequeue();
            x=p->x;
            y=p->y;

            putpixel(x,y,fcolor);

            if(getpixel(x,y+1)!=bcolor and getpixel(x,y+1)!=fcolor)
            {
                putpixel(x,y+1,fcolor);
                p=createnode(x,y+1);
                enqueue(p);
            }
            if(getpixel(x,y-1)!=bcolor and getpixel(x,y-1)!=fcolor)
            {
                putpixel(x,y-1,fcolor);
                p=createnode(x,y-1);
                enqueue(p);
            }
            if(getpixel(x+1,y)!=bcolor and getpixel(x+1,y)!=fcolor)
            {
                putpixel(x+1,y,fcolor);
                p=createnode(x+1,y);
                enqueue(p);
            }
            if(getpixel(x-1,y)!=bcolor and getpixel(x-1,y)!=fcolor)
            {
                putpixel(x-1,y,fcolor);
                p=createnode(x-1,y);
                enqueue(p);
            }

            front=front->next;
            p->next=NULL;
            free(p);
        }
    }

}

int main()
{

    int gd=DETECT,gm;
    int x,y;

    initgraph(&gd,&gm,"C:/TURBOC3/BGI);
    printf("Seed point:-"\n);
    printf("X:");
    scanf("%d",&x);
    printf("Y:");
    scanf("%d",&y)

    drawpolygon();

    b_fill(x,y);

    getch();

}


