/*
    Roll No.41
    Prim's Algorithm to create MST and Find minimum cost.
*/

#include<stdio.h>
#include<conio.h>


int main()
{

    int a,b,u,v,n,i,j,ne=1;
    int visited[10]={0},minimum,mincost=0,cost[10][10];

    printf("--- Prim's Algorithm ---\n\n");

	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("\nEnter the Weights of Edges:\n\n");
	for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
        {
            if(i!=j)
            {
                printf("(%d,%d):",i,j);
                scanf("%d",&cost[i][j]);
                cost[j][i]=cost[i][j];
                if(cost[i][j]==0)
                {
                    cost[i][j]=999;
                    cost[j][i]=999;
                }
            }
            else
            {
                cost[i][j]=0;
                cost[j][i]=0;
            }
        }


    printf("\n\n");
    printf("Adjacency Matrix:\n");
    for(i=1;i<=n;i++)
    {
        printf("\n");
        for(j=1;j<=n;j++)
        {
            printf(" %d ",cost[i][j]);
        }
    }
	visited[1]=1;
	printf("\n\n\n");
	printf("Linked Edges:\n\n");
	while(ne < n)
	{

		for(i=1,minimum=999;i<=n;i++)
            for(j=1;j<=n;j++)
            if(cost[i][j]< minimum)
                if(visited[i]!=0)
                {

                    minimum=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            if(visited[u]==0 || visited[v]==0)
                {
                    printf("%d) %d----%d  Cost:%d\n",ne++,a,b,minimum);
                    mincost+=minimum;
                    visited[b]=1;
                }
		cost[a][b]=cost[b][a]=999;
	}

	printf("\n\nMinimum Cost = %d\n\n",mincost);

	return 0;

}


