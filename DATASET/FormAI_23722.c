//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include<stdio.h>
#include<string.h>

/*
 * Welcome to my Hexadecimal Converter program! This program will convert
 * your decimal numbers to hexadecimal format. Are you excited? 
 * Let's get started!
 */

int main(){

    int decimal_num, remainder, quotient;
    int i = 0, j;
    char hexadecimal_num[100];

    printf("Enter a decimal number you want to convert to hexadecimal format\n");

    //Getting input from user
    scanf("%d", &decimal_num);

    quotient = decimal_num;

    while(quotient!=0){

        remainder = quotient % 16;

        //Converting the remainder to character and adding it to hexadecimal_num array
        if(remainder < 10)
            hexadecimal_num[i++] = remainder + '0';          //This is where the magic happens! Isn't it fascinating?
        else
            hexadecimal_num[i++] = remainder + 'A' - 10;

        quotient = quotient / 16;

    }

    //Printing the Hexadecimal format of the input number
    printf("The hexadecimal format of the input decimal number is:\n");

    for(j = i - 1; j>=0; j--)
        printf("%c", hexadecimal_num[j]);

    printf("\nThank you for using my program! I hope you enjoyed the experience. Have a great day :)\n");

    return 0;
}