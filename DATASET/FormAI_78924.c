//FormAI DATASET v1.0 Category: Color Code Converter ; Style: creative
#include<stdio.h>
#include<stdlib.h>

//Function to convert RGB to HEX
char* RGBtoHEX(int r, int g, int b){
    char* hex = (char*)malloc(sizeof(char)*7);
    sprintf(hex, "#%02x%02x%02x", r, g, b);
    return hex;
}

//Function to convert HEX to RGB
void HEXtoRGB(char* hex, int* r, int* g, int* b){
    sscanf(hex, "#%02x%02x%02x", r, g, b);
}

int main(){
    int choice;
    do{
        //Menu
        printf("Welcome to the Color Converter Program!\n");
        printf("1. RGB to HEX\n");
        printf("2. HEX to RGB\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: {
                //Convert RGB to HEX
                int r, g, b;
                printf("Enter RGB values (0-255)\n");
                printf("R: ");
                scanf("%d", &r);
                printf("G: ");
                scanf("%d", &g);
                printf("B: ");
                scanf("%d", &b);
                char* hex = RGBtoHEX(r, g, b);
                printf("HEX code: %s\n\n", hex);
                break;
            }
            case 2: {
                //Convert HEX to RGB
                char* hex = (char*)malloc(sizeof(char)*7);
                int r, g, b;
                printf("Enter HEX code (include the # symbol): ");
                scanf("%s", hex);
                HEXtoRGB(hex, &r, &g, &b);
                printf("RGB values: %d, %d, %d\n\n", r, g, b);
                free(hex); //Free allocated memory
                break;
            }
            case 3: {
                //Exit program
                printf("Thank you for using the Color Converter Program!\n");
                break;
            }
            default: {
                //Invalid choice
                printf("Invalid choice, please try again!\n");
                break;
            }
        }
    }while(choice != 3);

    return 0;
}