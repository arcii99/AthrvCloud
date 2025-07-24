//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: complete
#include <stdio.h>
#include <string.h>

int main() {
    char hex[17] = "";
    long decimal = 0;
    int i = 0, val = 0, len = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    
    len = strlen(hex);

    for(i=0; hex[i]!='\0'; i++){
        if(hex[i]>='0' && hex[i]<='9')
            val = hex[i] - 48;
        else if(hex[i]>='a' && hex[i]<='f')
            val = hex[i] - 97 + 10;
        else if(hex[i]>='A' && hex[i]<='F')
            val = hex[i] - 65 + 10;
        else {
            printf("Invalid hexadecimal number\n");
            return 0;
        }
        decimal += val * pow(16, len - i - 1);
    }

    printf("Input hexadecimal number: %s\n", hex);
    printf("Output decimal number: %ld\n", decimal);

    return 0;
}