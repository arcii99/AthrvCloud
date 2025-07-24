//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char string[100];
    char output[1000];
    int len,i,j,k;
    printf("Enter a string: ");
    fgets(string, 100, stdin);

    len = strlen(string);

    for(i=0;i<len;i++){
        switch(string[i]){
            case 'A':
            case 'a':
                strcat(output,"   /\\ ");
                break;

            case 'B':
            case 'b':
                strcat(output," |\\ \n/\\_/ ");
                break;

            case 'C':
            case 'c':
                strcat(output,"  /--\\ ");
                break;

            case 'D':
            case 'd':
                strcat(output," /|_/|\n| | | ");
                break;

            case 'E':
            case 'e':
                strcat(output,"/-----\\\n|      \n\\-----/ ");
                break;

            case 'F':
            case 'f':
                strcat(output,"/-----\\\n|        \n\\        ");
                break;

            case 'G':
            case 'g':
                strcat(output,"  /---\\  \n /     \\ \n/-------\\ ");
                break;

            case 'H':
            case 'h':
                strcat(output,"| | | |\n| |_| |\n|     | ");
                break;

            case 'I':
            case 'i':
                strcat(output," ------- \n   |     \n ------- ");
                break;

            case 'J':
            case 'j':
                strcat(output,"    /--\\\n    |   |\n\\__/   / ");
                break;

            case 'K':
            case 'k':
                strcat(output,"| |_/ / \n|    <  \n|_| \\_\\ ");
                break;

            case 'L':
            case 'l':
                strcat(output,"|        \n|        \n|_____ ");
                break;

            case 'M':
            case 'm':
                strcat(output,"|\\    /|\n| \\  / |\n|  \\/  |");
                break;

            case 'N':
            case 'n':
                strcat(output,"|\\    |\n| \\   |\n|  \\__|");
                break;

            case 'O':
            case 'o':
                strcat(output,"  /--\\  \n /    \\ \n/------\\ ");
                break;

            case 'P':
            case 'p':
                strcat(output,"/----\\ \n|    | \n\\____/");
                break;

            case 'Q':
            case 'q':
                strcat(output,"  /--\\  \n /    \\ \n/---/__\\");
                break;

            case 'R':
            case 'r':
                strcat(output, "/----\\ \n|     | \n\\_|__/ ");
                break;

            case 'S':
            case 's':
                strcat(output, "  /-----\\\n /_      \\\n/_____/  ");
                break;

            case 'T':
            case 't':
                strcat(output," ------- \n   |     \n   |     ");
                break;

            case 'U':
            case 'u':
                strcat(output,"|     |\n|     |\n|_____|\n");
                break;

            case 'V':
            case 'v':
                strcat(output,"\\        /\n \\      / \n  \\____/");
                break;

            case 'W':
            case 'w':
                strcat(output,"|\\      /|\n| \\    / |\n|  \\__/  |");
                break;

            case 'X':
            case 'x':
                strcat(output,"\\     /\n \\   / \n  \\_/  ");
                break;

            case 'Y':
            case 'y':
                strcat(output,"\\    /\n \\  / \n  \\/  ");
                break;

            case 'Z':
            case 'z':
                strcat(output," -------\n    /   \n  /___/ ");
                break;

            case ' ':
                strcat(output,"     ");
                break;

            default:
                printf("Unsupported letter: '%c'\n", string[i]);
                return 1;
        }
    }
    printf("%s", output);
    return 0;
}