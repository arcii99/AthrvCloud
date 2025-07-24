//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

/* ASCII art function declarations */
void printA();
void printB();
void printC();
void printD();
void printE();
void printF();
void printG();
void printH();
void printI();
void printJ();
void printK();
void printL();
void printM();
void printN();
void printO();
void printP();
void printQ();
void printR();
void printS();
void printT();
void printU();
void printV();
void printW();
void printX();
void printY();
void printZ();

/* Main function */
int main() {
    char input[MAX_INPUT_LENGTH];
    int i;

    /* Get user input */
    printf("Enter some text (max length %d): ", MAX_INPUT_LENGTH);
    fgets(input, MAX_INPUT_LENGTH, stdin);

    /* Convert input to uppercase */
    for (i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    /* Print ASCII art for each character */
    for (i = 0; i < strlen(input); i++) {
        switch (input[i]) {
            case 'A': printA(); break;
            case 'B': printB(); break;
            case 'C': printC(); break;
            case 'D': printD(); break;
            case 'E': printE(); break;
            case 'F': printF(); break;
            case 'G': printG(); break;
            case 'H': printH(); break;
            case 'I': printI(); break;
            case 'J': printJ(); break;
            case 'K': printK(); break;
            case 'L': printL(); break;
            case 'M': printM(); break;
            case 'N': printN(); break;
            case 'O': printO(); break;
            case 'P': printP(); break;
            case 'Q': printQ(); break;
            case 'R': printR(); break;
            case 'S': printS(); break;
            case 'T': printT(); break;
            case 'U': printU(); break;
            case 'V': printV(); break;
            case 'W': printW(); break;
            case 'X': printX(); break;
            case 'Y': printY(); break;
            case 'Z': printZ(); break;
            default: printf("\n"); break;
        }
    }

    return 0;
}

/* ASCII art for each letter */

/* Letter A */
void printA() {
    printf("  ##  \n");
    printf(" #  # \n");
    printf("#    #\n");
    printf("######\n");
    printf("#    #\n");
    printf("#    #\n\n");
}

/* Letter B */
void printB() {
    printf("##### \n");
    printf("#    #\n");
    printf("##### \n");
    printf("#    #\n");
    printf("#    #\n");
    printf("##### \n\n");
}

/* Letter C */
void printC() {
    printf(" #####\n");
    printf("#     \n");
    printf("#     \n");
    printf("#     \n");
    printf("#     \n");
    printf(" #####\n\n");
}

/* Letter D */
void printD() {
    printf("##### \n");
    printf("#    #\n");
    printf("#    #\n");
    printf("#    #\n");
    printf("#    #\n");
    printf("##### \n\n");
}

/* Letter E */
void printE() {
    printf("######\n");
    printf("#     \n");
    printf("######\n");
    printf("#     \n");
    printf("#     \n");
    printf("######\n\n");
}

/* Letter F */
void printF() {
    printf("######\n");
    printf("#     \n");
    printf("######\n");
    printf("#     \n");
    printf("#     \n");
    printf("#     \n\n");
}

/* Letter G */
void printG() {
    printf(" #####\n");
    printf("#     \n");
    printf("#     \n");
    printf("#  ###\n");
    printf("#    #\n");
    printf(" #####\n\n");
}

/* Letter H */
void printH() {
    printf("#    #\n");
    printf("#    #\n");
    printf("######\n");
    printf("#    #\n");
    printf("#    #\n");
    printf("#    #\n\n");
}

/* Letter I */
void printI() {
    printf("#####\n");
    printf("  #  \n");
    printf("  #  \n");
    printf("  #  \n");
    printf("  #  \n");
    printf("#####\n\n");
}

/* Letter J */
void printJ() {
    printf("     #\n");
    printf("     #\n");
    printf("     #\n");
    printf("#    #\n");
    printf("#    #\n");
    printf(" #####\n\n");
}

/* Letter K */
void printK() {
    printf("#   #\n");
    printf("#  # \n");
    printf("###  \n");
    printf("#  # \n");
    printf("#   #\n");
    printf("#   #\n\n");
}

/* Letter L */
void printL() {
    printf("#     \n");
    printf("#     \n");
    printf("#     \n");
    printf("#     \n");
    printf("#     \n");
    printf("######\n\n");
}

/* Letter M */
void printM() {
    printf("#    #\n");
    printf("##  ##\n");
    printf("# ## #\n");
    printf("#    #\n");
    printf("#    #\n");
    printf("#    #\n\n");
}

/* Letter N */
void printN() {
    printf("#    #\n");
    printf("##   #\n");
    printf("# #  #\n");
    printf("#  # #\n");
    printf("#   ##\n");
    printf("#    #\n\n");
}

/* Letter O */
void printO() {
    printf("##### \n");
    printf("#    #\n");
    printf("#    #\n");
    printf("#    #\n");
    printf("#    #\n");
    printf("##### \n\n");
}

/* Letter P */
void printP() {
    printf("##### \n");
    printf("#    #\n");
    printf("##### \n");
    printf("#     \n");
    printf("#     \n");
    printf("#     \n\n");
}

/* Letter Q */
void printQ() {
    printf("##### \n");
    printf("#    #\n");
    printf("#    #\n");
    printf("#  # #\n");
    printf("#   ##\n");
    printf("#### #\n\n");
}

/* Letter R */
void printR() {
    printf("##### \n");
    printf("#    #\n");
    printf("##### \n");
    printf("#  #  \n");
    printf("#   # \n");
    printf("#    #\n\n");
}

/* Letter S */
void printS() {
    printf(" #####\n");
    printf("#     \n");
    printf(" #####\n");
    printf("     #\n");
    printf("#    #\n");
    printf(" #####\n\n");
}

/* Letter T */
void printT() {
    printf("######\n");
    printf("  #   \n");
    printf("  #   \n");
    printf("  #   \n");
    printf("  #   \n");
    printf("  #   \n\n");
}

/* Letter U */
void printU() {
    printf("#    #\n");
    printf("#    #\n");
    printf("#    #\n");
    printf("#    #\n");
    printf("#    #\n");
    printf(" #####\n\n");
}

/* Letter V */
void printV() {
    printf("#    #\n");
    printf("#    #\n");
    printf("#    #\n");
    printf("#    #\n");
    printf(" #  # \n");
    printf("  ##  \n\n");
}

/* Letter W */
void printW() {
    printf("#    #\n");
    printf("#    #\n");
    printf("# ## #\n");
    printf("# ## #\n");
    printf("# ## #\n");
    printf(" #  # \n\n");
}

/* Letter X */
void printX() {
    printf("#    #\n");
    printf(" #  # \n");
    printf("  ##  \n");
    printf(" #  # \n");
    printf("#    #\n");
    printf("#    #\n\n");
}

/* Letter Y */
void printY() {
    printf("#    #\n");
    printf("#    #\n");
    printf(" #  # \n");
    printf("  ##  \n");
    printf("  ##  \n");
    printf("  ##  \n\n");
}

/* Letter Z */
void printZ() {
    printf("######\n");
    printf("    # \n");
    printf("   #  \n");
    printf("  #   \n");
    printf(" #    \n");
    printf("######\n\n");
}