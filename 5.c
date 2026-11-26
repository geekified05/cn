#include <stdio.h>

int main()
{
    int n, w, lost, i = 1, j;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter window size: ");
    scanf("%d", &w);

    while (i <= n)
    {
        for (j = i; j < i+w && j <= n; j++)
            printf("Frame %d sent\n", j);

        printf("Enter lost frame (0 for no loss): ");
        scanf("%d", &lost);

        if (lost == 0)
        {
            printf("ACK received up to frame %d\n", j-1);
            i = j;
        }
        else if (lost >= i && lost < j)
        {
            printf("ACK received up to frame %d\n", lost-1);
            printf("Timeout! Retransmitting from frame %d\n", lost);
            i = lost;
        }
    }

    printf("All frames transmitted successfully\n");

    return 0;
}