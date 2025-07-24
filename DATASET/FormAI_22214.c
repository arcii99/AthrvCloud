//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main(){
    char hex[17];
    long decimal, place;
    int i = 0, val, len;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    decimal = 0;
    place = 1;
    len = strlen(hex);
    for(i=len-1;i>=0;i--){
        if(hex[i]>='0' && hex[i]<='9'){
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f'){
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F'){
            val = hex[i] - 65 + 10;
        }
        decimal += val * place;
        place *= 16;
    }

    printf("Hexadecimal number = %s\n", hex);
    printf("Decimal number = %ld\n", decimal);
    return 0;
}