//FormAI DATASET v1.0 Category: Color Code Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert hexadecimals to decimal
int hexToDec(char hex[]){
    int len = strlen(hex);
    int dec = 0;
    for (int i = 0; i<len; i++){
        if (hex[i]>='0' && hex[i]<='9')
            dec += (hex[i]-'0')*pow(16,len-i-1);
        else if (hex[i]>='A' && hex[i]<='F')
            dec += (hex[i]-'A'+10)*pow(16,len-i-1);
    }
    return dec;
}

// function to convert RGB color code to hex
void rgbToHex(int red, int green, int blue, char hexCode[]){
    sprintf(hexCode, "#%.2X%.2X%.2X", red, green, blue);
}

// function to convert hex color code to RGB
void hexToRgb(char hex[], int *red, int *green, int *blue){
    sscanf(hex, "#%2x%2x%2x", red, green, blue);
}

int main(){
    char choice;
    do{
        printf("\nPlease choose the operation you want to perform:\n");
        printf("1. Convert RGB code to HEX code\n");
        printf("2. Convert HEX code to RGB code\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int red, green, blue;
        char hexCode[8], hex[8];

        scanf(" %c", &choice);
        switch (choice){
            case '1':
                printf("Enter the value of red (0 to 255): ");
                scanf("%d", &red);
                printf("Enter the value of green (0 to 255): ");
                scanf("%d", &green);
                printf("Enter the value of blue (0 to 255): ");
                scanf("%d", &blue);

                // validate RGB values
                if (red>=0 && red<=255 && green>=0 && green<=255 && blue>=0 && blue<=255){
                    rgbToHex(red, green, blue, hexCode);
                    printf("\nThe equivalent HEX code is: %s\n", hexCode);
                }
                else{
                    printf("\nInvalid RGB values entered. Please try again.\n");
                }
                break;
            case '2':
                printf("Enter the HEX code (ex: #FFAABB): ");
                scanf("%s", hex);

                // validate HEX code
                if (strlen(hex)==7 && hex[0]=='#'){
                    hexToRgb(hex, &red, &green, &blue);
                    printf("\nThe equivalent RGB code is: R=%d, G=%d, B=%d\n", red, green, blue);
                }
                else{
                    printf("\nInvalid HEX code entered. Please try again.\n");
                }
                break;
            case '3':
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice entered. Please try again.\n");
        }
    }while (choice!='3');

    return 0;
}