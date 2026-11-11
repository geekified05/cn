#include <stdio.h>
#define INF 9999

int main()
{
    int n, cost[10][10], dist[10][10], next[10][10];
    int i,j,k,change;

    printf("Enter number of routers: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            dist[i][j]=cost[i][j];
            next[i][j]=(i==j)?i:(cost[i][j]==INF?-1:j);
        }

    do
    {
        change=0;

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                    if(cost[i][k]!=INF && dist[k][j]!=INF &&
                       cost[i][k]+dist[k][j]<dist[i][j])
                    {
                        dist[i][j]=cost[i][k]+dist[k][j];
                        next[i][j]=k;
                        change=1;
                    }

    }while(change);

    for(i=0;i<n;i++)
    {
        printf("\nRouting Table of Router %d\n",i+1);
        printf("Destination\tNext Hop\tDistance\n");

        for(j=0;j<n;j++)
            if(dist[i][j]==INF)
                printf("%d\t\t-\t\tUnreachable\n",j+1);
            else
                printf("%d\t\t%d\t\t%d\n",
                       j+1,next[i][j]+1,dist[i][j]);
    }

    return 0;
}