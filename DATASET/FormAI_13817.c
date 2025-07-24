//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: systematic
#include<stdio.h>
#include<string.h>

void hexConverter(int num){
    int remainder;
    char hexNum[100];
    int i = 0, j = 0;
    
    //loop to find hex digits
    while(num>0){
        remainder = num%16;

        if(remainder<10){
            hexNum[i++] = remainder + 48;
        }else{
            hexNum[i++] = remainder + 55;
        }

        num = num/16;
    }
    
    //printing equivalent hex numbers
    printf("Equivalent hexadecimal number: ");
    for(j=i-1; j>=0; j--){
        printf("%c", hexNum[j]);
    }
}

int main(){
    int decimalNum;
    
    //taking input from user
    printf("Enter decimal number: ");
    scanf("%d", &decimalNum);
    
    //calling function to convert decimal to hexadecimal
    hexConverter(decimalNum);

    return 0;
}