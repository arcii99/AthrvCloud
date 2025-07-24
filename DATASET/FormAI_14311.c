//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void hex_convert(unsigned int num){
    char hex[17]=" ";
    int i=0;
    while(num)
    {
        int hex_value = num % 16;
        if(hex_value >= 10){
            hex[i++] = (char)(hex_value+55);
        }
        else{
            hex[i++] = (char)(hex_value+48);
        }
        num /= 16;
    }
    for(int j=strlen(hex)-1;j>=0;j--){
        printf("%c",hex[j]);
    }
}

int main(){
    printf("Welcome to the puzzling hexadecimal converter!\n");
    printf("Please enter an integer value to convert: ");
    unsigned int num;
    scanf("%u",&num);
    printf("The hexadecimal representation of %d is: ",num);
    hex_convert(num);
    printf("\nLet's try another number? (Y/N): ");
    char response = getchar();
    if(response == 'Y' || response == 'y'){
        printf("\nPlease enter the number: ");
        scanf("%u",&num);
        printf("The hexadecimal representation of %d is: ",num);
        hex_convert(num);
    }
    printf("\nThank you for using the puzzling hexadecimal converter!");
    return 0;
}