//FormAI DATASET v1.0 Category: Digital Diary ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("\n\n\t\tC DIGITAL DIARY\n\n");

    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    printf("\n\nHello %s,\n\n", name);
    printf("Today is %s.\n", __DATE__);

    time_t t = time(NULL);
    struct tm now = *localtime(&t);
    printf("The time now is %02d:%02d:%02d.\n\n", now.tm_hour, now.tm_min, now.tm_sec);

    printf("What would you like to write in your digital diary today?\n\n");

    char entry[1000];
    scanf(" %[^\n]", entry);

    srand((unsigned int)time(NULL));
    int code = rand() % 1000;

    printf("\n\nYour unique code for this entry is: %04d\n\n", code);

    char filename[100] = "diary_";
    char num[5];
    sprintf(num, "%04d", code);
    strcat(filename, num);
    strcat(filename, ".txt");
    FILE *fp = fopen(filename, "w");

    fprintf(fp, "%s\n\n", __DATE__);
    fprintf(fp, "%02d:%02d:%02d\n\n", now.tm_hour, now.tm_min, now.tm_sec);
    fprintf(fp, "%s\n\n", entry);

    fclose(fp);

    printf("Your diary entry has been saved in %s.\n\n", filename);
    printf("Thank you for using the C Digital Diary. See you tomorrow, %s!\n\n", name);

    return 0;
}