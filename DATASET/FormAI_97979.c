//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: peaceful
#include<stdio.h>
#include<string.h>

void drawA() {
    printf("    /\\    \n");
    printf("   /  \\   \n");
    printf("  /----\\  \n");
    printf(" /      \\ \n");
    printf("/        \\\n");
}

void drawB() {
    printf(" |-----   \n");
    printf(" |     |  \n");
    printf(" |-----   \n");
    printf(" |     |  \n");
    printf(" |-----   \n");
}

void drawC() {
    printf("   _____ \n");
    printf(" /      \\\n");
    printf("/        \\\n");
    printf("\\        /\n");
    printf(" \\_____/\n");
}

void drawD() {
    printf("|-----| \n");
    printf("|     | \n");
    printf("|     | \n");
    printf("|     | \n");
    printf("|-----| \n");
}

void drawE() {
    printf("|-------|\n");
    printf("|--------\n");
    printf("|-------|\n");
    printf("|--------\n");
    printf("|-------|\n");
}

void drawF() {
    printf("|-------|\n");
    printf("|--------\n");
    printf("|-------|\n");
    printf("|--------\n");
    printf("|        \n");
}

void drawG() {
    printf("   _____\n");
    printf(" /      \\\n");
    printf("/   ____|\n");
    printf("\\  |    \n");
    printf(" \\_|____\n");
}

void drawH() {
    printf("|     |\n");
    printf("|     |\n");
    printf("|-----|\n");
    printf("|     |\n");
    printf("|     |\n");
}

void drawI() {
    printf(" ___ \n");
    printf("|_  |\n");
    printf("  | |\n");
    printf("  | |\n");
    printf("  |_|\n");
}

void drawJ() {
    printf(" ______\n");
    printf("|___  /\n");
    printf("    | |\n");
    printf("    | |\n");
    printf("    |/ \n");
}

void drawK() {
    printf("|   /  \n");
    printf("|  /   \n");
    printf("|-|    \n");
    printf("|  \\   \n");
    printf("|   \\  \n");
}

void drawL() {
    printf("|      \n");
    printf("|      \n");
    printf("|      \n");
    printf("|      \n");
    printf("|______\n");
}

void drawM() {
    printf("|\\    /|\n");
    printf("| \\  / |\n");
    printf("|  \\/  |\n");
    printf("|      |\n");
    printf("|      |\n");
}

void drawN() {
    printf("|\\    |\n");
    printf("| \\   |\n");
    printf("|  \\  |\n");
    printf("|   \\ |\n");
    printf("|    \\|\n");
}

void drawO() {
    printf("   ___ \n");
    printf("  /   \\\n");
    printf(" /     \\\n");
    printf(" \\     /\n");
    printf("  \\___/\n");
}

void drawP() {
    printf("|-----\\\n");
    printf("|     |\n");
    printf("|-----/\n");
    printf("|      \n");
    printf("|      \n");
}

void drawQ() {
    printf("   ___  \n");
    printf("  /   \\ \n");
    printf(" /     \\\n");
    printf(" \\   \\ |\n");
    printf("  \\___\\|\n");
}

void drawR() {
    printf("|-----\\\n");
    printf("|     |\n");
    printf("|-----/\n");
    printf("|  \\   \n");
    printf("|   \\  \n");
}

void drawS() {
    printf("  _____\n");
    printf(" /     \\\n");
    printf("|       \\\n");
    printf(" \\_____/\n");
    printf("       | \n");
    printf("\\_____/  \n");
}

void drawT() {
    printf(" ______\n");
    printf("|_   _|\n");
    printf("  | |  \n");
    printf("  | |  \n");
    printf("  |_|  \n");
}

void drawU() {
    printf("|     |\n");
    printf("|     |\n");
    printf("|     |\n");
    printf("|     |\n");
    printf(" \\___/ \n");
}

void drawV() {
    printf("\\       /\n");
    printf(" \\     / \n");
    printf("  \\   /  \n");
    printf("   \\ /   \n");
    printf("    V    \n");
}

void drawW() {
    printf("|      |\n");
    printf("|      |\n");
    printf("|  /\\  |\n");
    printf("|/    \\|\n");
    printf("|      |\n");
}

void drawX() {
    printf("\\     /\n");
    printf(" \\   / \n");
    printf("  \\ /  \n");
    printf("  / \\  \n");
    printf(" /   \\ \n");
}

void drawY() {
    printf("\\     /\n");
    printf(" \\   / \n");
    printf("  \\ /  \n");
    printf("   |   \n");
    printf("   |   \n");
}

void drawZ() {
    printf(" _____\n");
    printf("|___  /\n");
    printf("   / / \n");
    printf("  / /  \n");
    printf("/____/ \n");
}

int main() {
    char text[100];
    printf("Enter some text: ");
    fgets(text, 100, stdin);
    printf("\n");
    for(int i = 0; i < strlen(text); i++) {
        if(text[i] == 'a' || text[i] == 'A') {
            drawA();
        } else if(text[i] == 'b' || text[i] == 'B') {
            drawB();
        } else if(text[i] == 'c' || text[i] == 'C') {
            drawC();
        } else if(text[i] == 'd' || text[i] == 'D') {
            drawD();
        } else if(text[i] == 'e' || text[i] == 'E') {
            drawE();
        } else if(text[i] == 'f' || text[i] == 'F') {
            drawF();
        } else if(text[i] == 'g' || text[i] == 'G') {
            drawG();
        } else if(text[i] == 'h' || text[i] == 'H') {
            drawH();
        } else if(text[i] == 'i' || text[i] == 'I') {
            drawI();
        } else if(text[i] == 'j' || text[i] == 'J') {
            drawJ();
        } else if(text[i] == 'k' || text[i] == 'K') {
            drawK();
        } else if(text[i] == 'l' || text[i] == 'L') {
            drawL();
        } else if(text[i] == 'm' || text[i] == 'M') {
            drawM();
        } else if(text[i] == 'n' || text[i] == 'N') {
            drawN();
        } else if(text[i] == 'o' || text[i] == 'O') {
            drawO();
        } else if(text[i] == 'p' || text[i] == 'P') {
            drawP();
        } else if(text[i] == 'q' || text[i] == 'Q') {
            drawQ();
        } else if(text[i] == 'r' || text[i] == 'R') {
            drawR();
        } else if(text[i] == 's' || text[i] == 'S') {
            drawS();
        } else if(text[i] == 't' || text[i] == 'T') {
            drawT();
        } else if(text[i] == 'u' || text[i] == 'U') {
            drawU();
        } else if(text[i] == 'v' || text[i] == 'V') {
            drawV();
        } else if(text[i] == 'w' || text[i] == 'W') {
            drawW();
        } else if(text[i] == 'x' || text[i] == 'X') {
            drawX();
        } else if(text[i] == 'y' || text[i] == 'Y') {
            drawY();
        } else if(text[i] == 'z' || text[i] == 'Z') {
            drawZ();
        } else {
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}