//FormAI DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>

//Conversion function
void convertColorCode(char colorCode[]) {
    switch(colorCode[0]) {
        case 'R':
        case 'r':
            printf("Color code %s is RED\n", colorCode);
            break;
        case 'B':
        case 'b':
            printf("Color code %s is BLUE\n", colorCode);
            break;
        case 'G':
        case 'g':
            printf("Color code %s is GREEN\n", colorCode);
            break;
        case 'Y':
        case 'y':
            printf("Color code %s is YELLOW\n", colorCode);
            break;
        default:
            printf("Invalid color code!\n");
    }
}

int main() {
    char colorCode[10];

    //Input color code
    printf("Enter a color code: ");
    scanf("%s", colorCode);

    //Convert and print color name
    convertColorCode(colorCode);
    
    return 0;
}