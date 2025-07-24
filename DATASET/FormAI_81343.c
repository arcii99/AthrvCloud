//FormAI DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void binaryConversion(int numberToConvert){
    int binaryArray[32], index=0, temp = numberToConvert; 
    
    //loop until division by 2 gives 0
    while(temp > 0){
        binaryArray[index] = temp%2;
        temp = temp/2;
        index++;
    }
    
    //printing binary result in reverse order
    printf("Binary equivalent of %d is ", numberToConvert);
    for(int i= index-1; i>=0; i--){
        printf("%d ", binaryArray[i]);
    }
}

int main(){
    int numberToConvert;
    printf("Enter decimal number to be converted: ");
    scanf("%d", &numberToConvert);
    
    binaryConversion(numberToConvert); //calling binaryConversion function
    
    return 0;
}