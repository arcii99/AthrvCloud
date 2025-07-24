//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include<stdio.h>
#include<string.h>

int main() {
    char input[1000];
    printf("Enter the alien language: ");
    scanf("%s", input);
    int len = strlen(input);
    char output[len];
    for(int i = 0; i < len; i++) {
        int asc = (int)input[i];
        switch(asc) {
            case 65: output[i] = 'z'; break;
            case 66: output[i] = 'y'; break;
            case 67: output[i] = 'x'; break;
            case 68: output[i] = 'w'; break;
            case 69: output[i] = 'v'; break;
            case 70: output[i] = 'u'; break;
            case 71: output[i] = 't'; break;
            case 72: output[i] = 's'; break;
            case 73: output[i] = 'r'; break;
            case 74: output[i] = 'q'; break;
            case 75: output[i] = 'p'; break;
            case 76: output[i] = 'o'; break;
            case 77: output[i] = 'n'; break;
            case 78: output[i] = 'm'; break;
            case 79: output[i] = 'l'; break;
            case 80: output[i] = 'k'; break;
            case 81: output[i] = 'j'; break;
            case 82: output[i] = 'i'; break;
            case 83: output[i] = 'h'; break;
            case 84: output[i] = 'g'; break;
            case 85: output[i] = 'f'; break;
            case 86: output[i] = 'e'; break;
            case 87: output[i] = 'd'; break;
            case 88: output[i] = 'c'; break;
            case 89: output[i] = 'b'; break;
            case 90: output[i] = 'a'; break;
            case 97: output[i] = 'Z'; break;
            case 98: output[i] = 'Y'; break;
            case 99: output[i] = 'X'; break;
            case 100: output[i] = 'W'; break;
            case 101: output[i] = 'V'; break;
            case 102: output[i] = 'U'; break;
            case 103: output[i] = 'T'; break;
            case 104: output[i] = 'S'; break;
            case 105: output[i] = 'R'; break;
            case 106: output[i] = 'Q'; break;
            case 107: output[i] = 'P'; break;
            case 108: output[i] = 'O'; break;
            case 109: output[i] = 'N'; break;
            case 110: output[i] = 'M'; break;
            case 111: output[i] = 'L'; break;
            case 112: output[i] = 'K'; break;
            case 113: output[i] = 'J'; break;
            case 114: output[i] = 'I'; break;
            case 115: output[i] = 'H'; break;
            case 116: output[i] = 'G'; break;
            case 117: output[i] = 'F'; break;
            case 118: output[i] = 'E'; break;
            case 119: output[i] = 'D'; break;
            case 120: output[i] = 'C'; break;
            case 121: output[i] = 'B'; break;
            case 122: output[i] = 'A'; break;
            default: output[i] = input[i]; break;
        }
    }
    printf("Translated alien language: %s", output);
    return 0;
}