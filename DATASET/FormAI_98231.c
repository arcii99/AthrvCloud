//FormAI DATASET v1.0 Category: Color Code Converter ; Style: imaginative
#include <stdio.h>

int main()
{
    char color[20];
    int r, g, b;
    
    printf("Enter a color name: ");
    scanf("%s", color);
    
    if(strcmp(color, "black") == 0)
    {
        r = 0;
        g = 0;
        b = 0;
    }
    else if(strcmp(color, "white") == 0)
    {
        r = 255;
        g = 255;
        b = 255;
    }
    else if(strcmp(color, "red") == 0)
    {
        r = 255;
        g = 0;
        b = 0;
    }
    else if(strcmp(color, "green") == 0)
    {
        r = 0;
        g = 255;
        b = 0;
    }
    else if(strcmp(color, "blue") == 0)
    {
        r = 0;
        g = 0;
        b = 255;
    }
    else if(strcmp(color, "pink") == 0)
    {
        r = 255;
        g = 192;
        b = 203;
    }
    else if(strcmp(color, "orange") == 0)
    {
        r = 255;
        g = 165;
        b = 0;
    }
    else if(strcmp(color, "yellow") == 0)
    {
        r = 255;
        g = 255;
        b = 0;
    }
    else if(strcmp(color, "purple") == 0)
    {
        r = 128;
        g = 0;
        b = 128;
    }
    else
    {
        printf("Invalid color!");
        return 0;
    }
    
    printf("The color %s is represented by the RGB code: (%d, %d, %d)", color, r, g, b);
    
    return 0;
}