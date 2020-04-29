//#include<iostream.h>
#include<dos.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>

int gd=DETECT,gm;
double x1,x2,y1,y2;


void draw_cube(double edge[20][3])
	{
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	int i;
	cleardevice();
	setcolor(RED);
	for(i=0;i<19;i++)
		{
		x1=edge[i][0]+edge[i][2]*(cos(2.3562)); //x=x+z*cos(135)
		y1=edge[i][1]-edge[i][2]*(sin(2.3562)); // y=y-z*sin(135)
		x2=edge[i+1][0]+edge[i+1][2]*(cos(2.3562));
		y2=edge[i+1][1]-edge[i+1][2]*(sin(2.3562));
		line(x1+320,240-y1,x2+320,240-y2);
		}
    setcolor(WHITE);
    line(320,0,320,480);
    line(0,240,640,240);
    line(60,479,585,0);

	getch();
	closegraph();
	}

void scale(double edge[20][3])
	{
	double a,b,c;
	int i;
	//cleardevice();
	cout<<" Enter The Scaling Factors :\n";
	cout<<"\nX:";
	cin>>a;
	cout<<"Y:";
	cin>>b;
	cout<<"Z:";
	cin>>c;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	clearviewport();
	for(i=0;i<20;i++)
		{
		edge[i][0]=edge[i][0]*a;
		edge[i][1]=edge[i][1]*b;
		edge[i][2]=edge[i][2]*c;
		}
	draw_cube(edge);
	closegraph();
	}

void translate(double edge[20][3])
	{
	int a,b,c;
	int i;
	//cleardevice();
	cout<<"Enter The Translation Factors :";
	cout<<"\nX:";
	cin>>a;
	cout<<"Y:";
	cin>>b;
	cout<<"Z:";
	cin>>c;

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	clearviewport();
	for(i=0;i<20;i++)
		{
		edge[i][0]+=a;
		edge[i][1]+=b;
		edge[i][2]+=c;
		}
	draw_cube(edge);
	closegraph();
	}

void rotate(double edge[20][3])
	{
	int ch;
	int i;
	double temp,theta,temp1;
	//cleardevice();

	cout<<" Rotation About:- \n\n";
	cout<<"1)X-Axis ";
	cout<<"\n2)Y-Axis ";
	cout<<"\n3)Z-Axis \n\n";
	cout<<"Choice :";
	cin>>ch;
	switch(ch)
		{
		case 1:
			cout<<"Angle :";
			cin>>theta;
			theta=(theta*3.14)/180;
			for(i=0;i<20;i++)
				{
				edge[i][0]=edge[i][0];
				temp=edge[i][1];
				temp1=edge[i][2];
				edge[i][1]=temp*cos(theta)-temp1*sin(theta);
				edge[i][2]=temp*sin(theta)+temp1*cos(theta);
				}
			draw_cube(edge);
			break;

		case 2:
			cout<<"Angle :";
			cin>>theta;
			theta=(theta*3.14)/180;
			for(i=0;i<20;i++)
				{
				edge[i][1]=edge[i][1];
				temp=edge[i][0];
				temp1=edge[i][2];
				edge[i][0]=temp*cos(theta)+temp1*sin(theta);
				edge[i][2]=-temp*sin(theta)+temp1*cos(theta);
				}
			draw_cube(edge);
			break;

		case 3:
			cout<<" Angle :";
			cin>>theta;
			theta=(theta*3.14)/180;
			for(i=0;i<20;i++)
				{
				edge[i][2]=edge[i][2];
				temp=edge[i][0];
				temp1=edge[i][1];
				edge[i][0]=temp*cos(theta)-temp1*sin(theta);
				edge[i][1]=temp*sin(theta)+temp1*cos(theta);
				}
			draw_cube(edge);
			break;
		}
	}


void main()
	{
	int choice;
	double edge[20][3]=
			{
			50,0,0,
			50,50,0,
			0,50,0,
			0,50,60,
			0,0,60,
			0,0,0,
			50,0,0,
			50,0,60,
			50,50,60,
			50,50,60,
			50,50,50,
			50,50,0,
			50,50,60,
			50,50,60,
			50,50,60,
			0,50,60,
			0,50,0,
			0,0,0,
			0,0,60,
			50,0,60
			};


	while(1)
		{
        cout<<"\n\n--- 3D Transformations ---\n\n";
		cout<<"1)Draw Cube\n";
            cout<<"2)Scaling \n";
            cout<<"3)Rotation \n";
		cout<<"4)Translation \n";

		cout<<"5)Exit \n\n ";
		cout<<"Enter Your Choice:";
		cin>>choice;
		switch(choice)
			 {
			 case 1:
				draw_cube(edge);
				break;

			 case 2:
				scale(edge);
				break;

			 case 3:
				rotate(edge);
				break;

			 case 4:
				translate(edge);
				break;

			 case 5:
				exit(0);

			 default:
				cout<<"\n Wrong choice. Re-enter... ";
				getch();
				break;
			 }

		getch();
		closegraph();

		}
	}
