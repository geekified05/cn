#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int rate, cap, size, time, bucket=0, packet, i;

    printf("Enter output rate: ");
    scanf("%d",&rate);

    printf("Enter bucket capacity: ");
    scanf("%d",&cap);

    printf("Enter maximum packet size: ");
    scanf("%d",&size);

    printf("Enter total time: ");
    scanf("%d",&time);

    if(rate<=0 || cap<=0 || size<=0 || time<=0)
    {
        printf("Invalid input");
        return 0;
    }

    srand(time(NULL));

    printf("\nTime\tPacket\tBucket\tAction\n");

    for(i=1;i<=time;i++)
    {
        packet=rand()%size+1;

        printf("%d\t%d\t%d\t",i,packet,bucket);

        if(packet<=cap-bucket)
        {
            bucket+=packet;
            printf("Accepted");
        }
        else
            printf("Discarded");

        if(bucket>=rate)
            bucket-=rate;
        else
            bucket=0;

        printf("\tRemaining: %d\n",bucket);
    }

    while(bucket>0)
    {
        int sent = (bucket<rate) ? bucket : rate;
        bucket-=sent;
        printf("Final transmission: %d, Remaining: %d\n",sent,bucket);
    }

    return 0;
}