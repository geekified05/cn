#include <stdio.h>
#include <string.h>

int main(void) {

    char data[100];
    int size, len;

    printf("\nEnter the data: ");
    fgets(data, sizeof(data), stdin);
    
    data[strcspn(data, "\n")] = '\0';
    len = strlen(data);

    printf("\nEnter the frame size: ");
    scanf("%d", &size);

    printf("\nFrames:\n");

    for (int i=0; i<len; i+=size) {
        printf("[");
        for (int j=0; j<size; j++) {
            if(i+j < len) {
                printf("%c", data[i+j]);
            } else {
                printf("-");
            }
        }
        printf("]\n");
    }

    return 0;
}

