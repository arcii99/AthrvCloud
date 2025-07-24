//FormAI DATASET v1.0 Category: Color Code Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to convert RGB values to HEX code
char* convertToHex(int R, int G, int B)
{
    // Allocate memory to store the HEX code
    char* hexCode = (char*)malloc(sizeof(char) * 8);
    
    // Convert the values to HEX characters and store in the memory
    sprintf(hexCode, "#%02X%02X%02X", R, G, B);
    
    // Return the address of the memory block storing HEX code
    return hexCode;
}

int main()
{
    int R, G, B;
    
    // Read the RGB values
    printf("Enter the value for Red (0-255): ");
    scanf("%d", &R);
    
    printf("Enter the value for Green (0-255): ");
    scanf("%d", &G);
    
    printf("Enter the value for Blue (0-255): ");
    scanf("%d", &B);
    
    // Convert the RGB values to HEX code using the function
    char* hexCode = convertToHex(R, G, B);
    
    // Print the result
    printf("The HEX code for the entered RGB values is: %s", hexCode);
    
    // Free the memory allocated to the HEX code
    free(hexCode);
    
    return 0;
}