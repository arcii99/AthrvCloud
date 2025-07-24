//FormAI DATASET v1.0 Category: Color Code Converter ; Style: puzzling
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

char *colorCodes[] = {"#000000", "#FF0000", "#00FF00", "#0000FF", "#FFFF00", "#00FFFF", "#FF00FF", "#C0C0C0"};
char *colorNames[] = {"black", "red", "green", "blue", "yellow", "cyan", "magenta", "silver"};

void printMenu() {
    printf("Welcome to the Color Code Converter\n");
    printf("==================================\n");
    printf("Available colors:\n");
    for(int i=0;i<8;i++){
        printf("%s (%s)\n", colorCodes[i], colorNames[i]);
    }
    printf("==================================\n");
    printf("Enter a color code or name to convert: ");
}

void convert(char *input) {
    if(input[0] == '#') {
        // Convert from color code to name
        for(int i=0;i<8;i++) {
            if(strcmp(input, colorCodes[i]) == 0) {
                printf("%s is %s\n", input, colorNames[i]);
                return;
            }
        }
        printf("Invalid color code\n");
    }
    else {
        // Convert from color name to code
        for(int i=0;i<8;i++) {
            if(strcmp(input, colorNames[i]) == 0) {
                printf("%s is %s\n", input, colorCodes[i]);
                return;
            }
        }
        printf("Invalid color name\n");
    }
}

int main() {
    printf("Initializing Color Code Converter...\n");
    int choice = 0;
    do {
        printMenu();
        char input[10];
        scanf("%s",input);
        convert(input);
        printf("Do you want to convert another color? (1=yes, 0=no): ");
        scanf("%d",&choice);
    } while(choice != 0);
    printf("Exiting Color Code Converter...\n");
    return 0;
}