#include <stdio.h>
#include <string.h>

void divide(char data[], char divisor[])
{
    int n = strlen(data);
    int g = strlen(divisor);

    for (int i = 0; i <= n-g; i++)
        if (data[i] == '1')
            for (int j = 0; j < g; j++)
                data[i+j] = (data[i+j] == divisor[j]) ? '0' : '1';
}

int main()
{
    char data[200], temp[200], divisor[50];

    printf("Enter data: ");
    scanf("%150s", data);

    printf("Enter divisor: ");
    scanf("%49s", divisor);

    int n = strlen(data);
    int g = strlen(divisor);

    strcpy(temp, data);

    for (int i = 0; i < g-1; i++)
        temp[n+i] = '0';

    temp[n+g-1] = '\0';

    divide(temp, divisor);

    printf("CRC: %s\n", temp+n);

    strcat(data, temp+n);

    printf("Codeword: %s\n", data);

    divide(data, divisor);

    for (int i = n; i < n+g-1; i++)
    {
        if (data[i] != '0')
        {
            printf("Error detected\n");
            return 0;
        }
    }

    printf("No error detected\n");

    return 0;
}







Enter data: 1101
Enter divisor: 1011
CRC: 001
Codeword: 1101001
No error detected