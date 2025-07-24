//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include <stdio.h>

int main(){
    int number;
    printf("Enter a decimal number: ");
    scanf("%d", &number);

    char hex[50];
    int i = 0;
    while(number > 0){
        int remainder = number % 16;
        if(remainder < 10){
            hex[i] = remainder + '0';
        }else{
            hex[i] = remainder + 55;
        }
        i++;
        number /= 16;
    }

    printf("The hexadecimal equivalent is: ");
    for(int j = i-1; j >= 0; j--){
        printf("%c", hex[j]);
    }
    printf("\n");

    return 0;
}