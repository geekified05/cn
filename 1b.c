#include <stdio.h>
#include <string.h>

int main(void)
{
    int size, len, count = 0;
    char data[100];

    printf("Enter the data: ");
    fgets(data, sizeof(data), stdin);

    data[strcspn(data, "\n")] = '\0';
    len = strlen(data);

    for (int i = 0; i < len; i += size) {
        count++;

        printf("Enter the frame size: ");
        scanf("%d", &size);

        if (i + size > len)
            size = len - i;

        printf("Frame %d: [%d|", count, size);

        for (int j = 0; j < size; j++) {
            printf("%c", data[i+j]);
        }

        printf("]\n");
    }

    return 0;
}