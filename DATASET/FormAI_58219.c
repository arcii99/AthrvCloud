//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: systematic
#include<stdio.h>
#include<string.h>

void printASCII(char ch) {
    switch(ch) {
        case 'A':
            printf("    RR   \n");
            printf("   R  R  \n");
            printf("  RRRRRR \n");
            printf(" R      R\n");
            printf("R        R\n");
            break;
        case 'B':
            printf("BBBBBB  \n");
            printf("B     B \n");
            printf("BBBBBB  \n");
            printf("B     B \n");
            printf("BBBBBB  \n");
            break;
        case 'C':
            printf(" CCCCCC \n");
            printf("C       \n");
            printf("C       \n");
            printf("C       \n");
            printf(" CCCCCC \n");
            break;
        case 'D':
            printf("DDDDDD  \n");
            printf("D    DD\n");
            printf("D     D\n");
            printf("D    DD\n");
            printf("DDDDDD \n");
            break;
        case 'E':
            printf("EEEEEEE\n");
            printf("E      \n");
            printf("EEEEEE \n");
            printf("E      \n");
            printf("EEEEEEE\n");
            break;
        case 'F':
            printf("FFFFFFF\n");
            printf("F      \n");
            printf("FFFFFF \n");
            printf("F      \n");
            printf("F      \n");
            break;
        case 'G':
            printf(" GGGGGG \n");
            printf("G       \n");
            printf("G   GGGG\n");
            printf("G     G \n");
            printf(" GGGGGG \n");
            break;
        case 'H':
            printf("H       H\n");
            printf("H       H\n");
            printf("HHHHHHHHH\n");
            printf("H       H\n");
            printf("H       H\n");
            break;
        case 'I':
            printf("IIIIIII\n");
            printf("   I   \n");
            printf("   I   \n");
            printf("   I   \n");
            printf("IIIIIII\n");
            break;
        case 'J':
            printf("JJJJJJJ\n");
            printf("     J \n");
            printf("     J \n");
            printf("J   J \n");
            printf(" JJJ  \n");
            break;
        case 'K':
            printf("K    K \n");
            printf("K   K  \n");
            printf("KK K   \n");
            printf("K  K   \n");
            printf("K    K \n");
            break;
        case 'L':
            printf("L      \n");
            printf("L      \n");
            printf("L      \n");
            printf("L      \n");
            printf("LLLLLLL\n");
            break;
        case 'M':
            printf("M       M\n");
            printf("MM     MM\n");
            printf("M M   M M\n");
            printf("M  M M  M\n");
            printf("M   M   M\n");
            break;
        case 'N':
            printf("N       N\n");
            printf("NN      N\n");
            printf("N N     N\n");
            printf("N  N    N\n");
            printf("N   N   N\n");
            break;
        case 'O':
            printf(" OOOOOO \n");
            printf("O      O\n");
            printf("O      O\n");
            printf("O      O\n");
            printf(" OOOOOO \n");
            break;
        case 'P':
            printf("PPPPPP  \n");
            printf("P     P \n");
            printf("PPPPPP  \n");
            printf("P       \n");
            printf("P       \n");
            break;
        case 'Q':
            printf(" QQQQQQ \n");
            printf("Q      Q\n");
            printf("Q      Q\n");
            printf("Q   QQ Q\n");
            printf(" QQQQQQQ\n");
            break;
        case 'R':
            printf("RRRRRR  \n");
            printf("R     R \n");
            printf("RRRRRR  \n");
            printf("R   R   \n");
            printf("R    R  \n");
            break;
        case 'S':
            printf(" SSSSSS \n");
            printf("S       \n");
            printf(" SSSSSS \n");
            printf("       S\n");
            printf("SSSSSSS \n");
            break;
        case 'T':
            printf("TTTTTTTT\n");
            printf("   T   \n");
            printf("   T   \n");
            printf("   T   \n");
            printf("   T   \n");
            break;
        case 'U':
            printf("U       U\n");
            printf("U       U\n");
            printf("U       U\n");
            printf("U       U\n");
            printf(" UUUUUUU \n");
            break;
        case 'V':
            printf("V         V\n");
            printf(" V       V \n");
            printf("  V     V  \n");
            printf("   V   V   \n");
            printf("    VVV    \n");
            break;
        case 'W':
            printf("W       W\n");
            printf("W   W   W\n");
            printf("W  W W  W\n");
            printf("W W   W W\n");
            printf("WW     WW\n");
            break;
        case 'X':
            printf("X     X\n");
            printf(" X   X \n");
            printf("  X X  \n");
            printf(" X   X \n");
            printf("X     X\n");
            break;
        case 'Y':
            printf("Y     Y\n");
            printf(" Y   Y \n");
            printf("  YYY  \n");
            printf("   Y   \n");
            printf("   Y   \n");
            break;
        case 'Z':
            printf("ZZZZZZZ\n");
            printf("     Z \n");
            printf("    Z  \n");
            printf("   Z   \n");
            printf("ZZZZZZZ\n");
            break;
        default:
            printf("\n");
    }
}

int main() {
    char str[20];
    int len, i;
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    len = strlen(str);
    for(i=0; i<len; i++) {
        printASCII(str[i]);
    }
    
    return 0;
}