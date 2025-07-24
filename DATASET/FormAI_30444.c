//FormAI DATASET v1.0 Category: Color Code Converter ; Style: imaginative
#include <stdio.h>

#define MAX_SIZE 10

int main()
{
    int color_code[MAX_SIZE];
    int user_input;
    int index = 0;
    printf("Enter the color code (in decimal format): ");
    scanf("%d", &user_input);
    
    // Iterate through each byte of the color code
    while(user_input > 0)
    {
        if(index >= MAX_SIZE)
        {
            printf("Error: Color code too large\n");
            return -1;
        }
        
        // Extract the last 8 bits of the color code
        int byte = user_input & 0xFF;
        
        // Store the byte in the color_code array
        color_code[index] = byte;
        
        // Shift the color code to the right by 8 bits
        user_input >>= 8;
        
        // Increment the index
        index++;
    }
    
    // Print the color code in hexadecimal format
    printf("Color code in hexadecimal format: ");
    for(int i = index - 1; i >= 0; i--)
    {
        printf("%02X", color_code[i]);
    }
    printf("\n");
    
    return 0;
}