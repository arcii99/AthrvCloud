//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include<stdio.h>

int main(){

    int hex_num, remainder, i=1, decimal=0;

    printf("Greetings! I am a medieval hexadecimal converter. Please enter the hexadecimal number: \n");
    scanf("%x", &hex_num); 

    printf("Calculating...\n");

    while(hex_num != 0){

        remainder = hex_num % 10;

        if(remainder>=0 && remainder<=9){
            decimal += remainder * i;
        }
        else if(remainder=='A' || remainder=='a'){
            decimal += 10 * i;
        }
        else if(remainder=='B' || remainder=='b'){
            decimal += 11 * i;
        }
        else if(remainder=='C' || remainder=='c'){
            decimal += 12 * i;
        }
        else if(remainder=='D' || remainder=='d'){
            decimal += 13 * i;
        }
        else if(remainder=='E' || remainder=='e'){
            decimal += 14 * i;
        }
        else if(remainder=='F' || remainder=='f'){
            decimal += 15 * i;
        }

        hex_num /= 10;
        i *= 16;

    }

    printf("The equivalent decimal number is: %d", decimal);

    return 0;
}