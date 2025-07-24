//FormAI DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    char entry[1000];
    char choice;
    FILE *fp;

    printf("Hello there! Let's start your digital diary journey with me.\n\n");
    printf("Please enter your preferred name: ");
    scanf("%s", name);
    printf("\n");
    printf("Welcome %s!\n", name);
    printf("Today is %s", __DATE__);
    printf("\n\n");

    fp = fopen("mydiary.txt", "a");
    if (fp == NULL)
    {
        printf("\nSorry, file cannot be opened!\n");
        exit(1);
    }

    do
    {
        printf("Enter your diary entry: \n");
        getchar();
        fgets(entry, 1000, stdin);
        printf("\n");

        fprintf(fp, "%s%s\n\n", __DATE__, entry);

        printf("Would you like to write another entry? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for writing with me, %s!\n", name);
    fclose(fp);

    return 0;
}