//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: relaxed
#include <stdio.h>
#include <string.h>

void translate(char* input)
{
    for(int i=0; i<strlen(input); i++)
    {
        switch(input[i])
        {
            case 'a':
                printf("kz");
                break;
            case 'b':
                printf("lp");
                break;
            case 'c':
                printf("mq");
                break;
            case 'd':
                printf("nr");
                break;
            case 'e':
                printf("os");
                break;
            case 'f':
                printf("pt");
                break;
            case 'g':
                printf("qu");
                break;
            case 'h':
                printf("rv");
                break;
            case 'i':
                printf("sw");
                break;
            case 'j':
                printf("tx");
                break;
            case 'k':
                printf("uy");
                break;
            case 'l':
                printf("vz");
                break;
            case 'm':
                printf("wa");
                break;
            case 'n':
                printf("xb");
                break;
            case 'o':
                printf("yc");
                break;
            case 'p':
                printf("zd");
                break;
            case 'q':
                printf("ae");
                break;
            case 'r':
                printf("bf");
                break;
            case 's':
                printf("cg");
                break;
            case 't':
                printf("dh");
                break;
            case 'u':
                printf("ei");
                break;
            case 'v':
                printf("fj");
                break;
            case 'w':
                printf("gk");
                break;
            case 'x':
                printf("hl");
                break;
            case 'y':
                printf("im");
                break;
            case 'z':
                printf("jn");
                break;
            default:
                printf(" ");
                break;
        }
    }
}

int main()
{
    printf("Enter a sentence in English to translate to Alien Language:\n");
    char input[100];
    fgets(input, 100, stdin);
    
    translate(input);

    return 0;
}