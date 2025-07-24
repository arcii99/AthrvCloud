//FormAI DATASET v1.0 Category: System event logger ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *fptr;
    fptr = fopen("eventlog.txt", "a");

    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Cryptic Event Logger 1.0\n\n");

    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    fprintf(fptr, "====== Cryptic Event Logger 1.0 started at %s ======\n\n", asctime(timeinfo));

    int i;
    for (i = 1; i <= 10; i++)
    {
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        fprintf(fptr, "[EVENT %d] Time: %s", i, asctime(timeinfo));
        fprintf(fptr, "Description: ");

        char desc[100];
        fgets(desc, sizeof(desc), stdin);
        fflush(stdin);

        fprintf(fptr, "%s\n\n", desc);
    }

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    fprintf(fptr, "====== Cryptic Event Logger 1.0 stopped at %s ======\n", asctime(timeinfo));

    fclose(fptr);

    return 0;
}