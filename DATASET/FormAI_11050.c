//FormAI DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include <stdio.h>

int main()
{
    FILE *fptr1, *fptr2;
    char c;

    fptr1 = fopen("input.txt" ,"r");
    fptr2 = fopen("output.txt", "w");

    while((c = fgetc(fptr1)) != EOF)
    {
        c = c + 3; // add 3 to ASCII value of character

        fputc(c, fptr2);
    }

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}