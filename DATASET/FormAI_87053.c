//FormAI DATASET v1.0 Category: Color Code Converter ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice;
    char hex[7], RGB[4];
    int r, g, b;

    printf("Enter the choice: \n\n 1.Convert RGB to HEX. \n 2.Convert HEX to RGB.\n");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("\nEnter the Red, Green and Blue values: ");
        scanf("%d%d%d",&r,&g,&b);
        if(r<0 || r>255 || g<0 || g>255 || b<0 || b>255)
        {
            printf("\nInvalid input! RGB values should be between 0 and 255.\n");
            exit(0);
        }
        sprintf(hex, "#%02X%02X%02X", r, g, b);
        printf("Equivalent HEX code: %s\n", hex);
    }

    else if(choice == 2)
    {
        printf("\nEnter a 7-digit hexadecimal color code: ");
        scanf("%s", hex);
        if(hex[0] != '#')
        {
            printf("\nInvalid input! HEX code should start with #\n");
            exit(0);
        }
        r = (int)strtol(hex+1, NULL, 16);
        g = (int)strtol(hex+3, NULL, 16);
        b = (int)strtol(hex+5, NULL, 16);
        sprintf(RGB, "%d %d %d", r, g, b);
        printf("Equivalent RGB code: %s\n", RGB);
    }

    else
    {
        printf("\nInvalid choice! Please enter 1 or 2.\n");
    }
    return 0;
}