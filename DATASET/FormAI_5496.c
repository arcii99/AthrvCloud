//FormAI DATASET v1.0 Category: File handling ; Style: bold
#include <stdio.h>

int main()
{
    FILE *fp;
    char ch, filename[50];

    printf("Enter the name of file you wish to create\n");
    scanf("%s", filename);

    fp = fopen(filename, "w"); //creating new file as write mode
    printf("Enter the contents of file %s\n", filename);

    while((ch = getchar()) != EOF)
    {
        fputc(ch, fp);
    }

    printf("The file %s has been created and saved successfully\n", filename);
    fclose(fp);

    printf("\nDo you want to read the contents of file %s now? (y/n)\n", filename);
    scanf("%c", &ch);

    if(ch == 'y' || ch == 'Y')
    {
        fp = fopen(filename, "r"); //opening same file in read mode
        printf("\nThe contents of file %s are: \n\n", filename);

        while((ch = fgetc(fp)) != EOF)
        {
            putchar(ch);
        }

        fclose(fp);
    }

    printf("\nThank you for using our program!\n");

    return 0;
}