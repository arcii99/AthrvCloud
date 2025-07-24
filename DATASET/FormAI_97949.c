//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: artistic
#include <stdio.h>
#include <string.h>

void translation(char c[]) {
    int i=0;
    while(c[i]!='\0'){
        switch(c[i]){
            case 'A': // Base 1
                printf("Zorgon");
                break;
            case 'B': // Base 2
                printf("Dexor");
                break;
            case 'C': // Base 3
                printf("Gorlon");
                break;
            case 'D': // Base 4
                printf("Yorin");
                break;
            case 'E': // Base 5
                printf("Naxxar");
                break;
            case 'F': // Base 6
                printf("Varax");
                break;
            case 'G': // Base 7
                printf("Korax");
                break;
            case 'H': // Base 8
                printf("Jargon");
                break;
            case 'I': // Base 9
                printf("Kriton");
                break;
            case 'J': // Base 10
                printf("Laxer");
                break;
            case 'K': // Base 11
                printf("Zaxon");
                break;
            case 'L': // Base 12
                printf("Morgon");
                break;
            case 'M': // Base 13
                printf("Xarzon");
                break;
            case 'N': // Base 14
                printf("Gexron");
                break;
            case 'O': // Base 15
                printf("Fargon");
                break;
            case 'P': // Base 16
                printf("Vargon");
                break;
            case 'Q': // Base 17
                printf("Chorgon");
                break;
            case 'R': // Base 18
                printf("Gorgax");
                break;
            case 'S': // Base 19
                printf("Zarlon");
                break;
            case 'T': // Base 20
                printf("Zargax");
                break;
            case 'U': // Base 21
                printf("Horgax");
                break;
            case 'V': // Base 22
                printf("Gexar");
                break;
            case 'W': // Base 23
                printf("Targar");
                break;
            case 'X': // Base 24
                printf("Hargon");
                break;
            case 'Y': // Base 25
                printf("Zorlon");
                break;
            case 'Z': // Base 26
                printf("Horgon");
                break;
            case ' ': // Space
                printf(" ");
                break;
            default: // For any other character
                printf("Invalid character");
                break;
        }
        i++;
    }
}


int main() {
    char c[100];
    printf("Enter text in English to translate to Alien Language: ");
    fgets(c, sizeof(c), stdin);
    printf("In Alien Language: ");
    translation(c);
    return 0;
}