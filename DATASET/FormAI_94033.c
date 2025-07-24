//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: excited
#include <stdio.h>
#include <ctype.h>

int main() {

    printf("\n\t\t*** Welcome to the ASCII Art Generator! ***\n\n");

    // prompt user for input
    printf("Enter a text: ");
    char user_input[100];
    fgets(user_input, 100, stdin);

    // convert input to uppercase
    for (int i = 0; user_input[i]; i++) {
        user_input[i] = toupper(user_input[i]);
    }

    printf("\n\t\t*** Generating ASCII Art... ***\n\n");

    // ASCII art generation
    for (int i = 0; user_input[i]; i++) {

        switch (user_input[i]) {

            case 'A':
                printf("    A\n");
                printf("   A A\n");
                printf("  AAAAA\n");
                printf(" A     A\n");
                printf("A       A\n\n");
                break;

            case 'B':
                printf("BBBBB\n");
                printf("B    B\n");
                printf("BBBBB\n");
                printf("B    B\n");
                printf("BBBBB\n\n");
                break;

            case 'C':
                printf(" CCCC\n");
                printf("C    \n");
                printf("C    \n");
                printf("C    \n");
                printf(" CCCC\n\n");
                break;

            case 'D':
                printf("DDDD\n");
                printf("D   D\n");
                printf("D   D\n");
                printf("D   D\n");
                printf("DDDD\n\n");
                break;

            case 'E':
                printf("EEEEE\n");
                printf("E    \n");
                printf("EEEEE\n");
                printf("E    \n");
                printf("EEEEE\n\n");
                break;

            case 'F':
                printf("FFFFF\n");
                printf("F    \n");
                printf("FFFFF\n");
                printf("F    \n");
                printf("F    \n\n");
                break;

            case 'G':
                printf(" GGGG\n");
                printf("G    \n");
                printf("G GGG\n");
                printf("G   G\n");
                printf(" GGGG\n\n");
                break;

            case 'H':
                printf("H   H\n");
                printf("H   H\n");
                printf("HHHHH\n");
                printf("H   H\n");
                printf("H   H\n\n");
                break;

            case 'I':
                printf("IIIII\n");
                printf("  I  \n");
                printf("  I  \n");
                printf("  I  \n");
                printf("IIIII\n\n");
                break;

            case 'J':
                printf("   J\n");
                printf("   J\n");
                printf("   J\n");
                printf("J  J\n");
                printf(" JJ \n\n");
                break;

            case 'K':
                printf("K  K\n");
                printf("K K \n");
                printf("KK  \n");
                printf("K K \n");
                printf("K  K\n\n");
                break;

            case 'L':
                printf("L    \n");
                printf("L    \n");
                printf("L    \n");
                printf("L    \n");
                printf("LLLLL\n\n");
                break;

            case 'M':
                printf("M     M\n");
                printf("MM   MM\n");
                printf("M M M M\n");
                printf("M  M  M\n");
                printf("M     M\n\n");
                break;

            case 'N':
                printf("N   N\n");
                printf("NN  N\n");
                printf("N N N\n");
                printf("N  NN\n");
                printf("N   N\n\n");
                break;

            case 'O':
                printf(" OOO\n");
                printf("O   O\n");
                printf("O   O\n");
                printf("O   O\n");
                printf(" OOO\n\n");
                break;

            case 'P':
                printf("PPPP\n");
                printf("P   P\n");
                printf("PPPP\n");
                printf("P    \n");
                printf("P    \n\n");
                break;

            case 'Q':
                printf(" QQQ\n");
                printf("Q   Q\n");
                printf("Q Q Q\n");
                printf("Q  QQ\n");
                printf(" QQQ Q\n\n");
                break;

            case 'R':
                printf("RRRR\n");
                printf("R   R\n");
                printf("RRRR\n");
                printf("R R  \n");
                printf("R  R \n\n");
                break;

            case 'S':
                printf(" SSSS\n");
                printf("S    \n");
                printf(" SSSS\n");
                printf("    S\n");
                printf("SSSS \n\n");
                break;

            case 'T':
                printf("TTTTT\n");
                printf("  T  \n");
                printf("  T  \n");
                printf("  T  \n");
                printf("  T  \n\n");
                break;

            case 'U':
                printf("U   U\n");
                printf("U   U\n");
                printf("U   U\n");
                printf("U   U\n");
                printf(" UUU \n\n");
                break;

            case 'V':
                printf("V     V\n");
                printf("V     V\n");
                printf(" V   V \n");
                printf("  V V  \n");
                printf("   V   \n\n");
                break;

            case 'W':
                printf("W     W\n");
                printf("W  W  W\n");
                printf("W W W W\n");
                printf("WW   WW\n");
                printf("W     W\n\n");
                break;

            case 'X':
                printf("X   X\n");
                printf(" X X \n");
                printf("  X  \n");
                printf(" X X \n");
                printf("X   X\n\n");
                break;

            case 'Y':
                printf("Y   Y\n");
                printf(" Y Y \n");
                printf("  Y  \n");
                printf("  Y  \n");
                printf("  Y  \n\n");
                break;

            case 'Z':
                printf("ZZZZZ\n");
                printf("   Z \n");
                printf("  Z  \n");
                printf(" Z   \n");
                printf("ZZZZZ\n\n");
                break;

            case ' ':
                printf("\n");
                break;

            default:
                printf("Unknown character detected: %c\n", user_input[i]);
                printf("Skipping...\n\n");
                break;

        }

    }

    printf("\n\t\t*** ASCII Art generated successfully! ***\n\n");

    return 0;

}