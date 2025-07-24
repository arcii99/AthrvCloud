//FormAI DATASET v1.0 Category: Color Code Converter ; Style: relaxed
#include <stdio.h>

int main(){
   char color_code;
   printf("Enter the color code: ");
   scanf("%c", &color_code);
   
   switch(color_code){
        case 'r':
        case 'R':
            printf("\nThe RGB color value of red is: 255,0,0");
            break;
        case 'g':
        case 'G':
            printf("\nThe RGB color value of green is: 0,255,0");
            break;
        case 'b':
        case 'B':
            printf("\nThe RGB color value of blue is: 0,0,255");
            break;
        case 'y':
        case 'Y':
            printf("\nThe RGB color value of yellow is: 255,255,0");
            break;
        case 'm':
        case 'M':
            printf("\nThe RGB color value of magenta is: 255,0,255");
            break;
        case 'c':
        case 'C':
            printf("\nThe RGB color value of cyan is: 0,255,255");
            break;
        default:
            printf("\nInvalid color code entered.");
    }

    return 0;
}