#include <stdio.h>

int main()
{
    int cap, rate, n, packet, bucket = 0;

    printf("Enter bucket capacity and output rate: ");
    scanf("%d%d", &cap, &rate);

    printf("Enter number of packets: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter packet size: ");
        scanf("%d", &packet);

        if (bucket + packet <= cap)
        {
            bucket += packet;
            printf("Accepted\n");
        }
        else
            printf("Discarded\n");

        int sent = (bucket < rate) ? bucket : rate;
        bucket -= sent;

        printf("Sent: %d, Remaining: %d\n", sent, bucket);
    }

    while (bucket > 0)
    {
        int sent = (bucket < rate) ? bucket : rate;
        bucket -= sent;

        printf("Final Transmission: Sent: %d, Remaining: %d\n", sent, bucket);
    }

    return 0;
}