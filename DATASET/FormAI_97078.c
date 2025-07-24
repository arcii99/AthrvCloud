//FormAI DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    char input[10], hex[10];
    int rgb[3], i;

    printf("Greetings, adventurer! What color code would you like to convert?\n");
    fgets(input, 10, stdin);

    if(strlen(input) != 7 || input[0] != '#') {
        printf("I'm sorry, that is not a valid color code. Please try again.\n");
        return 0;
    }

    for(i = 1; i < 7; i++) {
        switch(input[i]) {
            case '0':
                hex[i-1] = 0;
                break;
            case '1':
                hex[i-1] = 1;
                break;
            case '2':
                hex[i-1] = 2;
                break;
            case '3':
                hex[i-1] = 3;
                break;
            case '4':
                hex[i-1] = 4;
                break;
            case '5':
                hex[i-1] = 5;
                break;
            case '6':
                hex[i-1] = 6;
                break;
            case '7':
                hex[i-1] = 7;
                break;
            case '8':
                hex[i-1] = 8;
                break;
            case '9':
                hex[i-1] = 9;
                break;
            case 'A':
                hex[i-1] = 10;
                break;
            case 'B':
                hex[i-1] = 11;
                break;
            case 'C':
                hex[i-1] = 12;
                break;
            case 'D':
                hex[i-1] = 13;
                break;
            case 'E':
                hex[i-1] = 14;
                break;
            case 'F':
                hex[i-1] = 15;
                break;
            default:
                printf("I'm sorry, that is not a valid color code. Please try again.\n");
                return 0;
        }
    }

    rgb[0] = hex[0] * 16 + hex[1];
    rgb[1] = hex[2] * 16 + hex[3];
    rgb[2] = hex[4] * 16 + hex[5];

    printf("Your color in RGB format is: (%d, %d, %d).\n", rgb[0], rgb[1], rgb[2]);

    return 0;
}