#include <stdio.h>

int add(int a, int b)
{
    int sum = a + b;

    if (sum > 255)
        sum = (sum & 255) + 1;

    return sum;
}

int binaryToDecimal(char binary[])
{
    int value = 0;

    for (int i = 0; i < 8; i++)
        value = value * 2 + (binary[i] - '0');

    return value;
}

void printBinary(int n)
{
    for (int i = 7; i >= 0; i--)
        printf("%d", (n >> i) & 1);
}

int main(void)
{
    int n, sum = 0, checksum;
    char binary[9];

    printf("Enter number of bytes: ");
    scanf("%d", &n);

    printf("Enter data in binary (8-bit):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%8s", binary);
        sum = add(sum, binaryToDecimal(binary));
    }

    printf("Sum = ");
    printBinary(sum);

    checksum = (~sum) & 255;
    printf("\nChecksum = ");
    printBinary(checksum);

    if (add(sum, checksum) == 255)
        printf("\nNo error detected\n");
    else
        printf("\nError detected\n");

    return 0;
}