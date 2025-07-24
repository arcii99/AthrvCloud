//FormAI DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main(){
    char colorCode[7], color[20];
    printf("Welcome to the Cheery Color Code Converter!\n");
    printf("Enter a 6-digit hexadecimal color code: ");
    scanf("%s", colorCode);
    // Check if entered color code is valid
    if(strlen(colorCode) != 6){
        printf("Invalid color code!\n");
        return 0;
    }
    // Converting hex digits to decimal
    int r = (int) strtol(strndup(colorCode, 2), NULL, 16);
    int g = (int) strtol(strndup(colorCode+2, 2), NULL, 16);
    int b = (int) strtol(strndup(colorCode+4, 2), NULL, 16);
    // Getting color name based on decimal values
    if(r > g && r > b) strcpy(color, "RED");
    else if(g > r && g > b) strcpy(color, "GREEN");
    else if(b > r && b > g) strcpy(color, "BLUE");
    else if(r == g && r > b) strcpy(color, "YELLOW");
    else if(r == b && r > g) strcpy(color, "MAGENTA");
    else if(g == b && g > r) strcpy(color, "CYAN");
    else strcpy(color, "GREY");
    // Printing results
    printf("The decimal values are: R=%d, G=%d, B=%d\n", r, g, b);
    printf("The color is: %s\n", color);
    printf("Have a delightful day!\n");
    return 0;
}