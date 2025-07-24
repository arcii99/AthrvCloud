//FormAI DATASET v1.0 Category: Pattern printing ; Style: Cyberpunk
#include <stdio.h>

int main() {
    int i, j;
    char mat[9][9];
    for(i=0;i<9;i++) {
        for(j=0;j<9;j++) {
            mat[i][j]=' ';
        }
    }

    for(j=0;j<9;j+=2) {
        mat[0][j]='*';
        mat[8][j]='*';
    }

    for(i=0;i<9;i++) {
        mat[i][4]='*';
    }

    for(i=1;i<8;i+=2) {
        mat[i][0]='*';
        mat[i][8]='*';
    }

    mat[1][2]='C';
    mat[3][2]='Y';
    mat[5][2]='B';
    mat[7][2]='E';

    mat[1][6]='R';
    mat[3][6]='U';
    mat[5][6]='N';
    mat[7][6]='K';

    printf("\n\t\t\t\tCyberPunk C Pattern Printing\n\n");
    for(i=0;i<9;i++) {
        printf("\t\t\t\t");
        for(j=0;j<9;j++) {
            printf("%c",mat[i][j]);
            printf("  ");
        }
        printf("\n\n");
    }
    return 0;
}