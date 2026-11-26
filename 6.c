#include <stdio.h>

int main()
{
    int a, b, c, d;

    printf("\nEnter IP address: ");
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);

    if (a >= 1 && a <= 126)
        printf("Class A\nNetwork ID: %d\nHost ID: %d.%d.%d\nMask: 255.0.0.0 (/8)", a, b, c, d);
    else if (a >= 128 && a <= 191)
        printf("Class B\nNetwork ID: %d.%d\nHost ID: %d.%d\nMask: 255.255.0.0 (/16)", a, b, c, d);
    else if (a >= 192 && a <= 223)
        printf("Class C\nNetwork ID: %d.%d.%d\nHost ID: %d\nMask: 255.255.255.0 (/24)", a, b, c, d);
    else if (a >= 224 && a <= 239)
        printf("Class D - Multicast");
    else if (a >= 240 && a <= 255)
        printf("Class E - Reserved special-purpose addresses/Experimental");
    else
        printf("Invalid IP");

    return 0;
}