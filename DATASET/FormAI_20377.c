//FormAI DATASET v1.0 Category: Color Code Converter ; Style: curious
#include<stdio.h>
#include<string.h>

/*Function to convert hex string to decimal*/
int hexToDec(char hex[]){
    int len = strlen(hex);
    int base = 1, dec = 0;
    for (int i = len - 1; i >= 0; i--){
        if (hex[i] >= '0' && hex[i] <= '9'){
            dec += (hex[i] - 48) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F'){
            dec += (hex[i] - 55) * base;
            base = base * 16;
        }
    }
    return dec;  //returning decimal value obtained from hex string
}

int main(){
    char hex[10], choice;
    printf("C Color Code Converter\n\n");
    printf("Enter the color code in hex format (eg. FF55CC): ");
    scanf("%s", hex);
    int r = hexToDec(strncat(strncpy(hex, hex, 2), "\0", 1)); //getting the decimal value of red
    int g = hexToDec(strncat(strncpy(hex, hex+2, 2), "\0", 1)); //getting the decimal value of green
    int b = hexToDec(strncat(strncpy(hex, hex+4, 2), "\0", 1)); //getting the decimal value of blue
    printf("The RGB color code for %s is RGB(%d,%d,%d)\n", hex, r, g, b);
    
    printf("\nDo you want to convert RGB to hex Format? (Y or N)");
    scanf("%s", &choice);
    if(choice=='Y' || choice=='y'){
        int r, g, b;
        printf("\nEnter the RGB color code: ");
        scanf("%d,%d,%d", &r, &g, &b);
        printf("The hex color code for RGB(%d,%d,%d) is #%02x%02x%02x\n", r, g, b, r, g, b);
    }
    else if(choice=='N' || choice=='n'){
        printf("Thank you for using C Color Code Converter!\n");
    }
    else{
        printf("Invalid input. Exiting...\n");
    }
    return 0;
}