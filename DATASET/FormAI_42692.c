//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fpIn, *fpOut;
    int c;
    int inCode = 0;
    int indent = 0;
    int i;

    fpIn = fopen("example.html", "r");
    fpOut = fopen("output.html", "w");

    printf("Beautifying started..\n");

    while ((c = getc(fpIn)) != EOF)
    {
        if (!inCode && c != '<')
        {
            putc(c, fpOut);
            if (c == '\n')
            {
                indent = 0;
            }
            else
            {
                indent++;
            }
        }
        else
        {
            switch (c)
            {
            case '>':
                putc(c, fpOut);
                putc('\n', fpOut);
                indent = 0;
                inCode = 0;
                break;
            case '<':
                if (inCode)
                {
                    putc('\n', fpOut);
                    for (i = 0; i < indent; i++)
                    {
                        putc(' ', fpOut);
                    }
                }
                putc(c, fpOut);
                inCode = 1;
                break;
            default:
                putc(c, fpOut);
                break;
            }
        }
    }

    fclose(fpIn);
    fclose(fpOut);

    printf("Beautifying completed..\n");

    return 0;
}