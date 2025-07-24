//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_char(int char_bit) {
    switch(char_bit) {
        case 0:
            printf(" ");
            break;
        case 1:
            printf(".");
            break;
        case 2:
            printf("'");
            break;
        case 3:
            printf(":");
            break;
        case 4:
            printf("~");
            break;
        case 5:
            printf("*");
            break;
        case 6:
            printf("=");
            break;
        case 7:
            printf("&");
            break;
        case 8:
            printf("%");
            break;
        case 9:
            printf("#");
            break;
        case 10:
            printf("@");
            break;
        case 11:
            printf("$");
            break;
        case 12:
            printf("7");
            break;
        case 13:
            printf("I");
            break;
        case 14:
            printf("t");
            break;
        case 15:
            printf(";");
            break;
        default:
            printf(" ");
            break;
    }
}

int main() {

    char input[50], ch;
    int len, i, j, k, m, n, char_bit;

    printf("Enter your text: ");
    fgets(input, 50, stdin);
    len = strlen(input);

    int ascii_matrix[50][80];

    for(i=0;i<50;i++) {
        for(j=0;j<80;j++) {
            ascii_matrix[i][j] = 0;
        }
    }

    for(i=0;i<len;i++) {
        ch = input[i];
        if(ch == '\n') {
            break;
        }
        for(j=0;j<8;j++) {
            char_bit = (ch >> j) & 1;
            if(j < 5) {
                for(k=31+(i*6);k<37+(i*6);k++) {
                    ascii_matrix[k][j+22] = char_bit;
                }
            }
            else {
                m = (j-5) * 6;
                for(k=m+(i*6);k<m+6+(i*6);k++) {
                    ascii_matrix[k][j+23] = char_bit;
                }
            }
        }
    }

    for(i=0;i<50;i++) {
        for(j=0;j<80;j++) {
            char_bit = ascii_matrix[i][j];
            print_char(char_bit);
        }
        printf("\n");
    }

    return 0;
}