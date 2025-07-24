//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000], word[1000], c;
    printf("Enter the sentence to translate into C Cat language: ");
    fgets(sentence, sizeof(sentence), stdin);

    int i = 0, j = 0;

    while (sentence[i] != '\0')
    {
        if (sentence[i] == ' ')
        {
            printf("Meow ");
        }
        else
        {
            switch (sentence[i])
            {
            case 'a':
            case 'A':
                printf("Me ");
                break;

            case 'b':
            case 'B':
                printf("Meow Me Me Me ");
                break;

            case 'c':
            case 'C':
                printf("Meow Me Meow Me ");
                break;

            case 'd':
            case 'D':
                printf("Meow Me Me ");
                break;

            case 'e':
            case 'E':
                printf("Me ");
                break;

            case 'f':
            case 'F':
                printf("Me Meow Me Me ");
                break;

            case 'g':
            case 'G':
                printf("Meow Meow Me ");
                break;

            case 'h':
            case 'H':
                printf("Me Me Me Me ");
                break;

            case 'i':
            case 'I':
                printf("Me Me ");
                break;

            case 'j':
            case 'J':
                printf("Me Meow Meow Meow ");
                break;

            case 'k':
            case 'K':
                printf("Meow Me Meow ");
                break;

            case 'l':
            case 'L':
                printf("Me Meow Me Me Me ");
                break;

            case 'm':
            case 'M':
                printf("Meow Meow ");
                break;

            case 'n':
            case 'N':
                printf("Meow Me ");
                break;

            case 'o':
            case 'O':
                printf("Meow Meow Meow ");
                break;

            case 'p':
            case 'P':
                printf("Me Meow Meow Me ");
                break;

            case 'q':
            case 'Q':
                printf("Meow Meow Meow Me ");
                break;

            case 'r':
            case 'R':
                printf("Me Meow Me ");
                break;

            case 's':
            case 'S':
                printf("Me Me Me ");
                break;

            case 't':
            case 'T':
                printf("Meow ");
                break;

            case 'u':
            case 'U':
                printf("Me Meow Meow ");
                break;

            case 'v':
            case 'V':
                printf("Me Me Meow Me ");
                break;

            case 'w':
            case 'W':
                printf("Me Meow Meow ");
                break;

            case 'x':
            case 'X':
                printf("Meow Me Meow Me ");
                break;

            case 'y':
            case 'Y':
                printf("Meow Meow Meow Meow ");
                break;

            case 'z':
            case 'Z':
                printf("Meow Me Meow Me Me ");
                break;

            case '.':
                printf("Purr ");
                break;

            case ',':
                printf("Meow Meow ");
                break;

            case '!':
                printf("Meow Meow Meow Meow Me ");
                break;

            case '?':
                printf("Me Meow Meow Me Meow ");
                break;

            default:
                break;
            }
        }

        i++;
    }

    return 0;
}