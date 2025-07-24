//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include<stdio.h>

int main(){
    int num;
    char hex[10];
    
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    printf("The hexadecimal equivalent of %d is: ", num);
    
    int i=0;
    while(num>0){
        if(num%16<10){
            hex[i] = num%16 + 48; //ascii value of '0' = 48
        }
        else{
            hex[i] = num%16 + 55; //ascii value of 'A' = 65
        }
        num /= 16;
        i++;
    }
    
    for(int j=i-1; j>=0; j--){
        printf("%c", hex[j]);
    }
    
    printf("\nAmazing! You just converted decimal number into hexadecimal number. Your coding skills are just like magic. Keep it up!");
    
    return 0;
}