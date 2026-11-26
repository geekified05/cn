#include <stdio.h>

int main()
{
    char text[100];
    int key;

    printf("Enter the text: ");
    scanf("%99s", text);

    printf("Enter the key: ");
    scanf("%d", &key);

    for (int i = 0; text[i] != '\0'; i++)
        text[i] += key;

    printf("Encrypted text: %s\n", text);

    for (int i = 0; text[i] != '\0'; i++)
        text[i] -= key;

    printf("Decrypted text: %s\n", text);

    return 0;
}
