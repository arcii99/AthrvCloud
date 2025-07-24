//FormAI DATASET v1.0 Category: Binary Converter ; Style: excited
#include<stdio.h>

int main(){
    printf("Welcome to the binary converter!\n");
    printf("Enter a decimal number: ");
    int decimal;
    scanf("%d", &decimal);
    printf("\nConverting decimal %d to binary...\n", decimal);
    int binary[32];
    int i=0;
    while(decimal>0){
        binary[i] = decimal%2;
        decimal = decimal/2;
        i++;
    }
    printf("\nThe binary equivalent of %d is: ", decimal);

    for(int j=i-1;j>=0;j--){
        printf("%d", binary[j]);
    }
    return 0;
}