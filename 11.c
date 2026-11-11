#include <stdio.h>
#define INF 9999

int main()
{
    int n, cost[10][10], dist[10], visited[10]={0};
    int last[10], i, j, u, min, src, path[10], k;

    printf("Enter number of routers: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    printf("Enter source router: ");
    scanf("%d",&src);

    for(i=0;i<n;i++)
    {
        dist[i]=cost[src][i];
        last[i]=src;
    }

    dist[src]=0;
    visited[src]=1;

    for(i=1;i<n;i++)
    {
        min=INF;
        u=-1;

        for(j=0;j<n;j++)
            if(!visited[j] && dist[j]<min)
                min=dist[j],u=j;

        if(u==-1) break;

        visited[u]=1;

        for(j=0;j<n;j++)
            if(!visited[j] && cost[u][j]!=INF &&
               dist[u]+cost[u][j]<dist[j])
            {
                dist[j]=dist[u]+cost[u][j];
                last[j]=u;
            }
    }

    printf("\nShortest paths from Router %d:\n",src);

    for(i=0;i<n;i++)
    {
        if(dist[i]==INF)
        {
            printf("To %d: Unreachable\n",i);
            continue;
        }

        k=0;
        j=i;

        while(j!=src)
        {
            path[k++]=j;
            j=last[j];
        }

        printf("To %d: %d",i,src);

        while(k>0)
            printf(" -> %d",path[--k]);

        printf("  Cost = %d\n",dist[i]);
    }

    return 0;
}