//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: shape shifting
#include <stdio.h>
#include <string.h>

void shift(char str[]) {
    int n = strlen(str);
    for(int i = 0; i < n; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a') + 7) % 26 + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ((str[i] - 'A') + 7) % 26 + 'A';
        }
    }
}

void translate(char str[]) {
    int n = strlen(str);
    for(int i = 0; i < n; i++) {
        switch(str[i]) {
            case 'a':
                printf("k ");
                break;
            case 'b':
                printf("j ");
                break;
            case 'c':
                printf("h ");
                break;
            case 'd':
                printf("m ");
                break;
            case 'e':
                printf("u ");
                break;
            case 'f':
                printf("w ");
                break;
            case 'g':
                printf("f ");
                break;
            case 'h':
                printf("t ");
                break;
            case 'i':
                printf("p ");
                break;
            case 'j':
                printf("o ");
                break;
            case 'k':
                printf("y ");
                break;
            case 'l':
                printf("n ");
                break;
            case 'm':
                printf("q ");
                break;
            case 'n':
                printf("r ");
                break;
            case 'o':
                printf("b ");
                break;
            case 'p':
                printf("v ");
                break;
            case 'q':
                printf("z ");
                break;
            case 'r':
                printf("x ");
                break;
            case 's':
                printf("c ");
                break;
            case 't':
                printf("d ");
                break;
            case 'u':
                printf("e ");
                break;
            case 'v':
                printf("i ");
                break;
            case 'w':
                printf("g ");
                break;
            case 'x':
                printf("s ");
                break;
            case 'y':
                printf("l ");
                break;
            case 'z':
                printf("a ");
                break;
            default:
                printf("%c ", str[i]);
                break;
        }
    }
}

int main() {
    char str[100];
    printf("Enter the string to translate: ");
    fgets(str, 100, stdin);

    printf("\nShifting the string...\n");
    shift(str);
    printf("Shifted string: %s\n\n", str);

    printf("Translating the string to Alien Language...\n");
    translate(str);
    printf("\n");
    
    return 0;
}