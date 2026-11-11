#include <stdio.h>

int main()
{
    int a, b, c, d;

    printf("Enter IP address: ");
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);

    if (a >= 1 && a <= 126)
        printf("Class A\nNetwork ID: %d\nHost ID: %d.%d.%d\nMask: 255.0.0.0", a, b, c, d);
    else if (a >= 128 && a <= 191)
        printf("Class B\nNetwork ID: %d.%d\nHost ID: %d.%d\nMask: 255.255.0.0", a, b, c, d);
    else if (a >= 192 && a <= 223)
        printf("Class C\nNetwork ID: %d.%d.%d\nHost ID: %d\nMask: 255.255.255.0", a, b, c, d);
    else if (a >= 224 && a <= 239)
        printf("Class D - Multicast");
    else if (a >= 240 && a <= 255)
        printf("Class E - Experimental");
    else
        printf("Invalid or Reserved IP");

    return 0;
}