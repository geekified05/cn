#include <stdio.h>
#include <string.h>

int main(void) {

    char data[100], stuffed[200];
    int j=0, count=0, len;

    printf("\nEnter the bitwise data: ");
    scanf("%99s", data);
    len = strlen(data);

    for (int i=0; i<len; i++) {
        if (data[i] != '0' && data[i] != '1') {
            printf("\nInvalid Bit string! Only to contain 0 or 1.\n");
            return(1);
        }
        
        stuffed[j++] = data[i];
        if (data[i] == '1') count++;
        else count = 0;
        
        if (count == 5) {
            stuffed[j++] = '0';
            count = 0;
        }
    }
    stuffed[j] = '\0';

    printf("\nThe bit-stuffed data string: %s\n", stuffed);
    
    return 0;
}