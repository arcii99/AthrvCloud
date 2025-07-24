//FormAI DATASET v1.0 Category: Binary Converter ; Style: introspective
#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
    char input[30];
    int num, binary[30], index=0, i;

    printf("Please enter a decimal number: ");
    scanf("%d", &num);

    //Converting decimal number to binary
    while(num>0){
        binary[index] = num%2;
        num = num/2;
        index++;
    }

    printf("The binary conversion of %d is: ", num);
    //Printing binary representation in reverse order
    for(i=index-1; i>=0; i--){
        printf("%d", binary[i]);
    }
    printf("\n");

    return 0;
}