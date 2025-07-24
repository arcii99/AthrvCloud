//FormAI DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    time_t now;
    struct tm *td;
    char name[20];

    printf("Welcome to the Digital Diary!\n");
    printf("What's your name? ");
    scanf("%s", name);

    now = time(NULL);
    td = localtime(&now);

    printf("\nDate: %d-%d-%d\n", td->tm_mday, td->tm_mon+1, td->tm_year+1900);

    FILE *fp;
    char filename[40];
    char data[1000];
    sprintf(filename, "%s_%d-%d-%d.txt", name, td->tm_mday, td->tm_mon+1, td->tm_year+1900);
    fp = fopen(filename, "w");

    printf("\nStart writing your diary entry:\n");
    scanf(" %[^\n]s", data);
    fprintf(fp, "%d-%d-%d\n%s\n", td->tm_mday, td->tm_mon+1, td->tm_year+1900, data);

    printf("Your diary entry has been saved to %s\n", filename);
    fclose(fp);
    printf("\nGoodbye!\n");

    return 0;
}