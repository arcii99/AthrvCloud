//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: modular
#include <stdio.h>
#include <string.h>

void translate(char sentence[]) {
    int length = strlen(sentence);
    for (int i = 0; i < length; i++) {
        switch (sentence[i]) {
            case 'a':
                printf("yik ");
                break;
            case 'b':
                printf("bul ");
                break;
            case 'c':
                printf("jik ");
                break;
            case 'd':
                printf("gut ");
                break;
            case 'e':
                printf("mug ");
                break;
            case 'f':
                printf("nuk ");
                break;
            case 'g':
                printf("suk ");
                break;
            case 'h':
                printf("jut ");
                break;
            case 'i':
                printf("zut ");
                break;
            case 'j':
                printf("wut ");
                break;
            case 'k':
                printf("tut ");
                break;
            case 'l':
                printf("fut ");
                break;
            case 'm':
                printf("vut ");
                break;
            case 'n':
                printf("hik ");
                break;
            case 'o':
                printf("zik ");
                break;
            case 'p':
                printf("dut ");
                break;
            case 'q':
                printf("sut ");
                break;
            case 'r':
                printf("kik ");
                break;
            case 's':
                printf("zuk ");
                break;
            case 't':
                printf("tik ");
                break;
            case 'u':
                printf("buk ");
                break;
            case 'v':
                printf("gik ");
                break;
            case 'w':
                printf("puk ");
                break;
            case 'x':
                printf("gut ");
                break;
            case 'y':
                printf("kuk ");
                break;
            case 'z':
                printf("wuk ");
                break;
            case ' ':
                printf("/ ");
                break;
            default:
                printf("* ");
        }
    }
}

int main() {
    printf("Enter a sentence in C Alien Language: ");
    char sentence[100];
    fgets(sentence, 100, stdin);
    translate(sentence);
    return 0;
}