//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: puzzling
#include <stdio.h>
#include <string.h>

char* convertToHex(int num){
    char *hex = malloc(100*sizeof(char));
    int quotient = num / 16;
    int remainder = num % 16;
    if(num == 0){
        strcpy(hex,"0");
    }else if(num < 0){
        strcpy(hex, "Error: Input must be a positive integer.");
    }else{
        if(quotient != 0){
            convertToHex(quotient);
        }
        if(remainder < 10){
            sprintf(hex+strlen(hex),"%d",remainder);
        }else{
            sprintf(hex+strlen(hex),"%c",(char)remainder+55);
        }
    }
    return hex;
}

int main(){
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    char *hex = convertToHex(num);
    printf("The hexadecimal representation of %d is: %s\n", num, hex);
    free(hex);
    return 0;
}