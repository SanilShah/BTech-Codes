#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <time.h>

#define MAX_POINTS 30

typedef struct p {
    int x, y;
} Point;

void DrawCurve(Point controlPoints[], int numberOfPoints)
{
    for(int i = 0 ; i < numberOfPoints ; i++)
    {
	line(controlPoints[i].x, controlPoints[i].y, controlPoints[i+1].x, controlPoints[i+1].y);
    }
}

void Bezier(Point controlPoints[], int numberOfPoints, int iterations)
{
    Point m[MAX_POINTS];
    int k = 1;
    if(iterations > 0)
    {
	for(int i = 0; i < numberOfPoints; i++)
	{
	    m[k].x = (int) ((controlPoints[i].x + controlPoints[i + 1].x)/2);
	    m[k].y = (int) ((controlPoints[i].y + controlPoints[i + 1].y)/2);
	    k++;
	}
	m[0].x = controlPoints[0].x;
	m[0].y = controlPoints[0].y;
	m[k].x = controlPoints[numberOfPoints].x;
	m[k].y = controlPoints[numberOfPoints].y;
	cleardevice();
	setcolor(YELLOW);
	DrawCurve(m, k);
	getch();
	Bezier(m, k, iterations - 1);
    }
}

void acceptControlPolygon(Point controlPoints[])
{
    for(int i = 0; i < 4; i++)
    {
	printf("\n\t Enter X: ");
	scanf("%d", &controlPoints[i].x);
	printf("\t Enter Y: ");
	scanf("%d", &controlPoints[i].y);
    }
}

void kochCurve(int x1, int y1, int x2, int y2, int iterations)
{
    int theta = 60;
    float thetaRadian = theta * M_PI / 180;
    int fmidx = (2 * x1 + x2)/3;
    int fmidy = (2 * y1 + y2)/3;
    int smidx = (x1 + 2 * x2)/3;
    int smidy = (y1 + 2 * y2)/3;
    int topX = fmidx + (smidx - fmidx) * cos(thetaRadian) + (smidy - fmidy) * sin(thetaRadian);
    int topY = fmidy - (smidx - fmidx) * sin(thetaRadian) + (smidy - fmidy) * cos(thetaRadian);
    if(iterations > 0)
    {
	kochCurve(x1, y1, fmidx, fmidy, iterations - 1);
	kochCurve(fmidx, fmidy, topX, topY, iterations - 1);
	kochCurve(topX, topY, smidx, smidy, iterations - 1);
	kochCurve(smidx, smidy, x2, y2, iterations - 1);
    }
    else
    {
	line(x1, y1, fmidx, fmidy);
	line(fmidx, fmidy, topX, topY);
	line(topX, topY, smidx, smidy);
	line(smidx, smidy, x2, y2);
    }
}
void simulateCoastalLine(int sx,int sy,int ex,int ey,int iterations,int sign)
{
    int midx,midy;
    srand(time(NULL));

    midx=(sx+ex)/2 + sign*(rand()%70);
    midy=(sy+ey)/2 + sign*(rand()%70);
    sign=sign*-1;
    if(iterations>0)
    {
        simulateCoastalLine(sx,sy,midx,midy,iterations-1,sign);
        sign=sign*-1;
        simulateCoastalLine(midx,midy,ex,ey,iterations-1,sign);
    }
    else{
        line(sx,sy,midx,midy);
        line(midx,midy,ex,ey);
    }
}


int main(void)
{
    int gd = DETECT, gm;
    int iterations, sign = -1,i;
    int choice, x1, x2, y1, y2;
    do
    {
	printf("\n\t 1. Bezier Curve");
	printf("\n\t 2. Koch Curve");
	printf("\n\t 3. coastal line");
	printf("\n\t 4. Exit");
	printf("\n\t Enter your choice: ");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1:
		Point controlPoints[MAX_POINTS];
		acceptControlPolygon(controlPoints);
		printf("\n\t Enter No. of Iterations: ");
		scanf("%d", &iterations);
		initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");
		DrawCurve(controlPoints, 3);
		getch();
		cleardevice();
		Bezier(controlPoints, 3, iterations);
		getch();
		closegraph();
		break;
	    case 2:
		printf("\n\t Enter x1: ");
		scanf("%d", &x1);
		printf("\t Enter y1: ");
		scanf("%d", &y1);
		printf("\t Enter x2: ");
		scanf("%d", &x2);
		printf("\t Enter y2: ");
		scanf("%d", &y2);
		printf("\n\t Enter No. of iterations: ");
		scanf("%d", &iterations);
		initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");
		for(int i = 0; i < iterations; i++)
		{
		    cleardevice();
		    kochCurve(x1, y1, x2, y2, i);
		    getch();
		}
		closegraph();
		break;
	    case 3:
		    printf("\n\t Enter x1: ");
		    scanf("%d", &x1);
		    printf("\t Enter y1: ");
		    scanf("%d", &y1);
		    printf("\t Enter x2: ");
		    scanf("%d", &x2);
		    printf("\t Enter y2: ");
		    scanf("%d", &y2);
		    printf("\n\t Enter the number of iterations: ");
		    scanf("%d", &iterations);
		    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
		    for(i = 0; i < iterations; i++)
		    {
			cleardevice();
			simulateCoastalLine(x1, y1, x2, y2, i, sign);
			sign = sign * -1;
			getch();
		    }
		    closegraph();
		    break;
	    case 4:
		break;
	    default:
		printf("\n\t Invalid choice.");
		break;
	}
    } while(choice != 4);
    return 1;
}
