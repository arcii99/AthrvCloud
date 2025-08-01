//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include <stdio.h>
#include <string.h>

int main(){
    char hex[100], bin[400], dec;
    int i, j = 0;

    printf("Enter the hexadecimal value: ");
    scanf("%s", hex);
    int len = strlen(hex);

    for(i=0; hex[i]!='\0'; i++){

        switch(hex[i]){
            case '0': strcat(bin, "0000"); break;
            case '1': strcat(bin, "0001"); break;
            case '2': strcat(bin, "0010"); break;
            case '3': strcat(bin, "0011"); break;
            case '4': strcat(bin, "0100"); break;
            case '5': strcat(bin, "0101"); break;
            case '6': strcat(bin, "0110"); break;
            case '7': strcat(bin, "0111"); break;
            case '8': strcat(bin, "1000"); break;
            case '9': strcat(bin, "1001"); break;
            case 'a': strcat(bin, "1010"); break;
            case 'b': strcat(bin, "1011"); break;
            case 'c': strcat(bin, "1100"); break;
            case 'd': strcat(bin, "1101"); break;
            case 'e': strcat(bin, "1110"); break;
            case 'f': strcat(bin, "1111"); break;   
            default:
                printf("Invalid hexadecimal input");
                return 0;
        }
    }

    printf("Binary value of %s is %s\n", hex, bin);

    int binary = atoi(bin);
    int decimal = 0, p = 0;
    while(binary!=0){
        int rem = binary%10;
        decimal += rem*pow(2,p);
        p++;
        binary /= 10;
    }

    printf("Decimal value of %s is %d\n", bin, decimal);

    return 0;
}