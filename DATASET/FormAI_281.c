//FormAI DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include<stdio.h>
#include<string.h>

int main(){
    char colorCode[8];
    printf("Enter a 6 digit color code (in hexadecimal): ");
    scanf("%s", colorCode);
    printf("\nThe entered color code is: #%s\n", colorCode);
    if(strlen(colorCode) != 6){
        printf("Invalid color code! Please enter a 6 digit color code."); 
        return 0;
    }
    int red = 0, green = 0, blue = 0;
    sscanf(colorCode, "%02x%02x%02x", &red, &green, &blue);
    printf("\nConverted Color Code is: RGB(%d,%d,%d)", red, green, blue);
    return 0;
}