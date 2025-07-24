//FormAI DATASET v1.0 Category: Syntax parsing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int main() {
    char line[MAX_LEN];
    printf("Enter a C syntax statement:\n");
    fgets(line, MAX_LEN, stdin);
    int len = strlen(line);
    if (len == 1) {
        printf("Invalid input.\n");
        return 1;
    }
    if (line[len-1] == '\n') {
        line[len-1] = '\0';
    }
    int state = 0;
    int i = 0;
    while (line[i] != '\0') {
        switch (state) {
            case 0:
                if (line[i] == 'i') {
                    state = 1;
                } else if (line[i] == 'f') {
                    state = 2;
                } else if (line[i] == 'w') {
                    state = 4;
                } else if (line[i] == 'd') {
                    state = 6;
                } else if (line[i] == 'l') {
                    state = 8;
                } else if (line[i] == 'e') {
                    state = 10;
                } else if (line[i] == 'r') {
                    state = 14;
                } else if (line[i] == 's') {
                    state = 17;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                i++;
                break;
            case 1:
                if (line[i] == 'n' && line[i+1] == 't') {
                    state = 3;
                    i += 2;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 2:
                if (line[i] == 'o' && line[i+1] == 'r') {
                    state = 3;
                    i += 2;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 3:
                if (line[i] == ' ') {
                    state = 15;
                    i++;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 4:
                if (line[i] == 'h' && line[i+1] == 'i' && line[i+2] == 'l' && line[i+3] == 'e') {
                    state = 5;
                    i += 4;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 5:
                if (line[i] == ' ') {
                    state = 15;
                    i++;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 6:
                if (line[i] == 'o' && line[i+1] == 'u' && line[i+2] == 'b' && line[i+3] == 'l' && line[i+4] == 'e') {
                    state = 7;
                    i += 5;
                } else if (line[i] == 'e' && line[i+1] == 'x' && line[i+2] == 't' && line[i+3] == 'e' && line[i+4] == 'r' && line[i+5] == 'n') {
                    state = 9;
                    i += 6;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 7:
                if (line[i] == ' ') {
                    state = 16;
                    i++;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 8:
                if (line[i] == 'i' && line[i+1] == 'b' && line[i+2] == 'r' && line[i+3] == 'a' && line[i+4] == 'r' && line[i+5] == 'y') {
                    state = 11;
                    i += 6;
                } else if (line[i] == 'o' && line[i+1] == 'n' && line[i+2] == 'g') {
                    state = 12;
                    i += 3;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 9:
                if (line[i] == ' ') {
                    state = 18;
                    i++;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 10:
                if (line[i] == 'l' && line[i+1] == 's' && line[i+2] == 'e') {
                    state = 13;
                    i += 3;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 11:
                if (line[i] == ' ') {
                    state = 19;
                    i++;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 12:
                if (line[i] == ' ') {
                    state = 20;
                    i++;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 13:
                if (line[i] == ' ') {
                    state = 21;
                    i++;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 14:
                if (line[i] == 'e' && line[i+1] == 't' && line[i+2] == 'u' && line[i+3] == 'r' && line[i+4] == 'n') {
                    state = 15;
                    i += 5;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 15:
                if (line[i] == ' ') {
                    i++;
                } else if (line[i] == ';') {
                    printf("Syntax is correct.\n");
                    return 0;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 16:
                if (line[i] == ' ') {
                    i++;
                } else if (line[i] == ';') {
                    printf("Syntax is correct.\n");
                    return 0;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 17:
                if (line[i] == 't' && line[i+1] == 'a' && line[i+2] == 't' && line[i+3] == 'i' && line[i+4] == 'c') {
                    state = 22;
                    i += 5;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 18:
                if (line[i] == ' ') {
                    i++;
                } else if (line[i] == ';') {
                    printf("Syntax is correct.\n");
                    return 0;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 19:
                if (line[i] == ' ') {
                    i++;
                } else if (line[i] == ';') {
                    printf("Syntax is correct.\n");
                    return 0;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 20:
                if (line[i] == ' ') {
                    i++;
                } else if (line[i] == ';') {
                    printf("Syntax is correct.\n");
                    return 0;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 21:
                if (line[i] == ' ') {
                    i++;
                } else if (line[i] == ';') {
                    printf("Syntax is correct.\n");
                    return 0;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 22:
                if (line[i] == ' ') {
                    state = 23;
                    i++;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            case 23:
                if (line[i] == ' ') {
                    i++;
                } else if (line[i] == ';') {
                    printf("Syntax is correct.\n");
                    return 0;
                } else {
                    printf("Invalid syntax.\n");
                    return 1;
                }
                break;
            default:
                printf("Invalid syntax.\n");
                return 1;
        }
    }
    printf("Invalid syntax.\n");
    return 1;
}