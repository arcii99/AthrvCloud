//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <string.h>

char* translate(char* input) {
    int length = strlen(input);
    char output[length + 1];
    for (int i = 0; i < length; i++) {
        switch(input[i]) {
            case 'a':
                strcat(output, "01");
                break;
            case 'b':
                strcat(output, "02");
                break;
            case 'c':
                strcat(output, "03");
                break;
            case 'd':
                strcat(output, "04");
                break;
            case 'e':
                strcat(output, "05");
                break;
            case 'f':
                strcat(output, "06");
                break;
            case 'g':
                strcat(output, "07");
                break;
            case 'h':
                strcat(output, "08");
                break;
            case 'i':
                strcat(output, "09");
                break;
            case 'j':
                strcat(output, "10");
                break;
            case 'k':
                strcat(output, "11");
                break;
            case 'l':
                strcat(output, "12");
                break;
            case 'm':
                strcat(output, "13");
                break;
            case 'n':
                strcat(output, "14");
                break;
            case 'o':
                strcat(output, "15");
                break;
            case 'p':
                strcat(output, "16");
                break;
            case 'q':
                strcat(output, "17");
                break;
            case 'r':
                strcat(output, "18");
                break;
            case 's':
                strcat(output, "19");
                break;
            case 't':
                strcat(output, "20");
                break;
            case 'u':
                strcat(output, "21");
                break;
            case 'v':
                strcat(output, "22");
                break;
            case 'w':
                strcat(output, "23");
                break;
            case 'x':
                strcat(output, "24");
                break;
            case 'y':
                strcat(output, "25");
                break;
            case 'z':
                strcat(output, "26");
                break;
            default:
                strcat(output, "00"); 
                break;          
        }
    }
    return output;
}

int main() {

    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter the phrase to be translated: ");
    char input[100];
    fgets(input, 100, stdin);
    char* output = translate(input);
    printf("Translated phrase: %s\n", output);
    return 0;
}