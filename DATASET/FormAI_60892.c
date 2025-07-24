//FormAI DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>

void RGB_to_HEX(int R, int G, int B)
{
    char hex[7];
    sprintf(hex, "#%02X%02X%02X", R, G, B);
    printf("HEX code: %s\n", hex);
}

void HEX_to_RGB(char *hex)
{
    int R, G, B;
    sscanf(hex, "#%02X%02X%02X", &R, &G, &B);
    printf("RGB code: %d,%d,%d\n", R, G, B);
}

int main()
{
    int option;
    printf("1. RGB to HEX code\n");
    printf("2. HEX to RGB code\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    if (option == 1)
    {
        int R, G, B;
        printf("Enter R value (0-255): ");
        scanf("%d", &R);
        printf("Enter G value (0-255): ");
        scanf("%d", &G);
        printf("Enter B value (0-255): ");
        scanf("%d", &B);
        RGB_to_HEX(R, G, B);
    }
    else if (option == 2)
    {
        char hex[7];
        printf("Enter HEX code: ");
        scanf("%s", hex);
        HEX_to_RGB(hex);
    }
    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}