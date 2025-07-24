//FormAI DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include<stdio.h>

int main(){
    //Opening statement
    printf("Welcome to the C Color Code Converter!\n\n");
    
    //User input
    printf("Please enter the hexadecimal color code: ");
    char hexCode[7];
    scanf("%s", hexCode);
    
    //Hexadecimal to RGB Conversion
    int red = (int) strtol(hexCode + 1, NULL, 16);
    int green = (int) strtol(hexCode + 3, NULL, 16);
    int blue = (int) strtol(hexCode + 5, NULL, 16);

    //Output in RGB
    printf("The RGB conversion of %s is (%d,%d,%d)\n", hexCode, red, green, blue);
    
    //Closing statement
    printf("Thank you for using the C Color Code Converter!\n");
    return 0;
}