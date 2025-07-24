//FormAI DATASET v1.0 Category: Binary Converter ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

int main(){
    int num, bit, i;
    char choice;

    printf("Enter a decimal number: ");
    scanf("%d", &num);
    printf("Do you want to convert to Little Endian? (y/n): ");
    scanf(" %c", &choice);

    if(choice=='y' || choice=='Y'){
        printf("Binary Representation (Little Endian): ");
        for(i=0; i<32; i++){
            bit = num >> i;
            if(i%8==0){
                printf(" ");
            }
            printf("%d", bit&1);
        }
    }
    else{
        printf("Binary Representation (Big Endian): ");
        for(i=31; i>=0; i--){
            bit = num >> i;
            printf("%d", bit&1);
            if(i%8==0){
                printf(" ");
            }
        }
    }
    printf("\n");
    return 0;
}