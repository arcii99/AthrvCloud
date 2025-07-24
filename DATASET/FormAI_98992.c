//FormAI DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>

int main(){
    char user_choice;
    int r, g, b;
    float y, u, v;
    
    printf("Do you want to convert RGB to YUV? (Y/N): ");
    scanf("%c", &user_choice);
    
    if(user_choice == 'Y'){
        printf("Enter the values of Red, Green, and Blue values respectively (0-255):\n");
        scanf("%d %d %d", &r, &g, &b);
        
        // Converting RGB to YUV
        y = (0.299 * r) + (0.587 * g) + (0.114 * b);
        u = (-0.14713 * r) - (0.28886 * g) + (0.436 * b);
        v = (0.615 * r) - (0.51498 * g) - (0.10001 * b);
        
        // Displaying the result
        printf("YUV color code: (%.2f, %.2f, %.2f)", y, u, v);
        
    } else {
        printf("Enter the values of Y, U, and V respectively (0-1):\n");
        scanf("%f %f %f", &y, &u, &v);
        
        // Converting YUV to RGB
        r = (int) (y + (1.13983 * v));
        g = (int) (y - (0.39465 * u) - (0.5806 * v));
        b = (int) (y + (2.03211 * u));
        
        // Displaying the result
        printf("RGB color code: (%d, %d, %d)", r, g, b);
    }
    
    return 0;
}