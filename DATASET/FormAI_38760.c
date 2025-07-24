//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    
    printf("Enter the string in the Alien Language: ");
    scanf("%s", input);
    
    char output[strlen(input)];
    int i;
    for (i = 0; i < strlen(input); i++) {
        switch(input[i]) {
            case 'A':
                output[i] = 'Z';
                break;
            case 'B':
                output[i] = 'Y';
                break;
            case 'C':
                output[i] = 'X';
                break;
            case 'D':
                output[i] = 'W';
                break;
            case 'E':
                output[i] = 'V';
                break;
            case 'F':
                output[i] = 'U';
                break;
            case 'G':
                output[i] = 'T';
                break;
            case 'H':
                output[i] = 'S';
                break;
            case 'I':
                output[i] = 'R';
                break;
            case 'J':
                output[i] = 'Q';
                break;
            case 'K':
                output[i] = 'P';
                break;
            case 'L':
                output[i] = 'O';
                break;
            case 'M':
                output[i] = 'N';
                break;
            case 'N':
                output[i] = 'M';
                break;
            case 'O':
                output[i] = 'L';
                break;
            case 'P':
                output[i] = 'K';
                break;
            case 'Q':
                output[i] = 'J';
                break;
            case 'R':
                output[i] = 'I';
                break;
            case 'S':
                output[i] = 'H';
                break;
            case 'T':
                output[i] = 'G';
                break;
            case 'U':
                output[i] = 'F';
                break;
            case 'V':
                output[i] = 'E';
                break;
            case 'W':
                output[i] = 'D';
                break;
            case 'X':
                output[i] = 'C';
                break;
            case 'Y':
                output[i] = 'B';
                break;
            case 'Z':
                output[i] = 'A';
                break;
            default:
                output[i] = input[i];
        }
    }
    
    output[strlen(input)] = '\0';
    
    printf("The string in the Earth Language is: %s", output);
    
    return 0;
}