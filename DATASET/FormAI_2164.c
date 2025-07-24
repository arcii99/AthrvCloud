//FormAI DATASET v1.0 Category: Color Code Converter ; Style: synchronous
#include <stdio.h>

// Function to convert RGB values to hexadecimal color code
char* convertColorCode(int r, int g, int b) {
    char* hexCode = (char*) malloc(7 * sizeof(char));  // Allocate memory for 7 characters including '\0'
    
    // Obtain hexadecimal digits for red, green, and blue channels
    int r1 = r / 16;
    int r2 = r % 16;
    int g1 = g / 16;
    int g2 = g % 16;
    int b1 = b / 16;
    int b2 = b % 16;
    
    // Convert decimal digits to hexadecimal digits
    char hexDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    hexCode[0] = '#';
    hexCode[1] = hexDigits[r1];
    hexCode[2] = hexDigits[r2];
    hexCode[3] = hexDigits[g1];
    hexCode[4] = hexDigits[g2];
    hexCode[5] = hexDigits[b1];
    hexCode[6] = hexDigits[b2];
    
    return hexCode;
}

int main() {
    int r, g, b;
    printf("Enter the values of red, green, and blue channels (between 0 and 255):\n");
    scanf("%d %d %d", &r, &g, &b);
    printf("The RGB values are R=%d, G=%d, B=%d\n", r, g, b);
    
    char* hexCode = convertColorCode(r, g, b);
    printf("The hexadecimal color code is %s\n", hexCode);
    free(hexCode);  // Free the allocated memory
    
    return 0;
}