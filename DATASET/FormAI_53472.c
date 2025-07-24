//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

// Function declarations
void hexToRGB(char* hex, int* r, int* g, int* b);
void RGBToHex(int r, int g, int b, char* hex);

int main()
{
    char hexCode[7];
    int r, g, b;
    char choice;

    while(1)
    {
        printf("Choose an option: \n");
        printf("1. Convert HEX code to RGB\n");
        printf("2. Convert RGB code to HEX\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case '1':
                printf("Enter HEX code (without # symbol): ");
                scanf("%s", hexCode);

                hexToRGB(hexCode, &r, &g, &b);
                printf("Red: %d\n", r);
                printf("Green: %d\n", g);
                printf("Blue: %d\n", b);
                break;

            case '2':
                printf("Enter Red (0-255): ");
                scanf("%d", &r);
                printf("Enter Green (0-255): ");
                scanf("%d", &g);
                printf("Enter Blue (0-255): ");
                scanf("%d", &b);

                RGBToHex(r, g, b, hexCode);
                printf("HEX code: #%s\n", hexCode);
                break;

            case '3':
                printf("Exiting..");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

// Function to convert hex code to rgb
void hexToRGB(char* hex, int* r, int* g, int* b)
{
    sscanf(hex, "%02x%02x%02x", r, g, b);
}

// Function to convert rgb to hex code
void RGBToHex(int r, int g, int b, char* hex)
{
    sprintf(hex, "%02x%02x%02x", r, g, b);
}