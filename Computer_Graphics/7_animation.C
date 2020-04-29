    #include<graphics.h>
    #include<conio.h>
    #include<dos.h>
    #include<process.h>
    #include"myline.h"


    int cx=300,cy=100,r=300;
    int x=0,y,p;
    //int x1,y1;
    int count=6;
    int flag=0;
    int delay_speed[10]={1,2,3,4,5,6,7,8,9,10};
    int i=0;


    int path(int direction)
     {

	 int x1,y1,d;
	 line(200,100,400,100);
	count--;


	//if(i==10)
		d=9;
	//else if(i>0)
	       //	d=delay_speed[i];
	//else if(i>10)
	       //	d=10;
	setcolor(WHITE);
	if(x>=y)
	{
		return 0;
	}
	cleardevice();
	if(direction==1)
	{
	    setcolor(CYAN);
		circle(cx+x,cy+y,20);
		setcolor(YELLOW);
		line(200,100,400,100);
		      setcolor(WHITE);
		line(cx,cy,cx+x,cy+y-20);
	} else
	{
	    setcolor(CYAN);
		circle(cx-x,cy+y,20);
			setcolor(YELLOW);
		line(200,100,400,100);
		setcolor(YELLOW);
			setcolor(WHITE);
		line(cx,cy,cx-x,cy+y-20);
	}

	delay(d);
	if(kbhit())
		exit(0);
	x++;
	if(p<0)
		p+=2*x+1;
	else

	{
		y--;
		p+=2*(x-y)+1;
	}
	x1=x;
	y1=y;
	if(flag==0)
		flag=1;
	else if(flag==1)
		flag=0;

	path(direction);
	cleardevice();
	if(direction==1)
	{
	    setcolor(CYAN);
		circle(cx+x1,cy+y1,20);
		setcolor(WHITE);
		line(cx,cy,cx+x1,cy+y1-20);
		setcolor(YELLOW);
		line(200,100,400,100);
	}
	 else
	{
	    setcolor(CYAN);
		circle(cx-x1,cy+y1,20);
		setcolor(WHITE);
		line(cx,cy,cx-x1,cy+y1-20);
		setcolor(YELLOW);
		line(200,100,400,100);
	}
	delay(d);
	if(kbhit())
		exit(0);
	return(0);
    }
    void main()
     {
	int gd=DETECT,gm=DETECT;
	initgraph(&gd,&gm,"C:/TURBOC3/BGI");
	cleardevice();
	setcolor(WHITE);
	line(200,100,400,100);
	putpixel(300,100,4);
	while(1)
	{
		x=0;
		y=r;
		p=1-r;
		path(1);
		x=0;
    		y=r;
    		p=1-r;
    		path(0);
    	}
    }
