#include <stdio.h>
#include <string.h>

int main()
{
    char data[100];

    printf("Enter the data: ");
    scanf("%99s", data);

    printf("Stuffed data: STX DLE ");

    for (int i = 0; i < strlen(data); i++)
    {
        if (strncmp(data + i, "DLE", 3) == 0)
            printf("DLE");

        printf("%c", data[i]);
    }

    printf(" DLE ETX\n");

    return 0;
}