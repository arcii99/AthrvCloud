//FormAI DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    char content[200];

    fp = fopen("digital_diary.txt", "a");

    if(fp == NULL) 
    {
        printf("Error opening file!");
        exit(1);
    }

    printf("Enter the content for your digital diary:\n");
    scanf("%[^\n]",content);

    fprintf(fp, "%s\n", content);

    printf("Content added successfully!\n");

    fclose(fp);

    return 0;
}