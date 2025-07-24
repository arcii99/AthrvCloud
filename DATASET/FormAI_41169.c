//FormAI DATASET v1.0 Category: Color Code Converter ; Style: brave
#include<stdio.h>

int main(){
    int hex_value;
    char c;

    printf("Enter a Hex value: ");
    scanf("%x", &hex_value);

    printf("ASCII Conversion of %x is: ", hex_value);

    for(int i=0;i<=6;i+=2){
        c = (char)(hex_value >> i);
        printf("%c", c);
    }

    printf("\n");

    return 0;
}