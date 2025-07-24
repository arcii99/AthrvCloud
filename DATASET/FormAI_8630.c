//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter your text: ");
    fgets(input, 100, stdin); // Taking input from user
    
    for (int i = 0; i < strlen(input); i++) {
        switch (input[i]) {
            case 'A': printf("   A  \n  A A \n AAAAA\nA     A\n"); break;
            case 'B': printf("BBBBB \nB    B\nBBBBB \nB    B\nBBBBB \n"); break;
            case 'C': printf(" CCCC \nC    \nC    \nC    \n CCCC\n"); break;
            case 'D': printf("DDDDD \nD    D\nD    D\nD    D\nDDDDD \n"); break;
            case 'E': printf("EEEEE\nE    \nEEEEE\nE    \nEEEEE\n"); break;
            case 'F': printf("FFFFFF\nF    \nFFFFF\nF    \nF    \n"); break;
            case 'G': printf(" GGGG \nG     \nG GGG \nG    G\n GGGG \n"); break;
            case 'H': printf("H    H\nH    H\nHHHHHH\nH    H\nH    H\n"); break;
            case 'I': printf("IIIII\n  I  \n  I  \n  I  \nIIIII\n"); break;
            case 'J': printf("JJJJJ\n   J \n   J \nJ  J \n JJ  \n"); break;
            case 'K': printf("K   K\nK  K \nKKK  \nK  K \nK   K\n"); break;
            case 'L': printf("L    \nL    \nL    \nL    \nLLLLL\n"); break;
            case 'M': printf("M     M\nMM   MM\nM M M M\nM  M  M\nM     M\n"); break;
            case 'N': printf("N    N\nNN   N\nN N  N\nN  N N\nN   NN\n"); break;
            case 'O': printf(" OOO \nO   O\nO   O\nO   O\n OOO \n"); break;
            case 'P': printf("PPPPP \nP   P\nPPPPP \nP     \nP     \n"); break;
            case 'Q': printf(" QQQQ  \nQ    Q \nQ    Q \nQ  Q Q \nQQQQQ\\ \n"); break;
            case 'R': printf("RRRRR \nR   R \nRRRR  \nR  R  \nR   R \n"); break;
            case 'S': printf("SSSSS\nS    \nSSSSS\n    S\nSSSSS\n"); break;
            case 'T': printf("TTTTT\n  T  \n  T  \n  T  \n  T  \n"); break;
            case 'U': printf("U    U\nU    U\nU    U\nU    U\n UUUU \n"); break;
            case 'V': printf("V     V\nV     V\n V   V \n  V V  \n   V   \n"); break;
            case 'W': printf("W     W\nW  W  W\nW W W W\nWW   WW\nW     W\n"); break;
            case 'X': printf("X   X\n X X \n  X  \n X X \nX   X\n"); break;
            case 'Y': printf("Y     Y\n Y   Y \n  Y Y  \n   Y   \n   Y   \n"); break;
            case 'Z': printf("ZZZZZ\n   Z \n  Z  \n Z   \nZZZZZ\n"); break;
            case ' ': printf("     \n     \n     \n     \n     \n"); break;
                // if the character is not in the switch cases
            default: printf("Sorry, cannot generate ASCII art for that character.\n"); 
        }
    }
    
    return 0;
}