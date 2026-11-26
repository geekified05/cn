#include <stdio.h>
#define INF 9999

int main()
{
    int n, cost[20][20], dist[20], visited[20]={0};
    int i, j, u, min, src;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    printf("Enter source vertex: ");
    scanf("%d",&src);

    for(i=0;i<n;i++)
        dist[i]=INF;

    dist[src]=0;

    for(i=0;i<n;i++)
    {
        min=INF;
        u=-1;

        for(j=0;j<n;j++)
            if(!visited[j] && dist[j]<min)
                min=dist[j], u=j;

        if(u==-1) break;

        visited[u]=1;

        for(j=0;j<n;j++)
            if(!visited[j] && cost[u][j]!=INF &&
               dist[u]+cost[u][j]<dist[j])
                dist[j]=dist[u]+cost[u][j];
    }

    printf("\nShortest distances from %d:\n",src);

    for(i=0;i<n;i++)
        if(dist[i]==INF)
            printf("To %d = Unreachable\n",i);
        else
            printf("To %d = %d\n",i,dist[i]);

    return 0;
}





Enter number of vertices: 3
Enter cost matrix:
0 2 9
2 0 3
9 3 0
Enter source vertex: 0
To 0: 0  Cost = 0
To 1: 0 -> 1  Cost = 2
To 2: 0 -> 1 -> 2  Cost = 5