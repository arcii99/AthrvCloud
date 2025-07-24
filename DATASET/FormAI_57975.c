//FormAI DATASET v1.0 Category: Digital Diary ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char date[10];
    char entry[200];

    FILE *fp;
    fp = fopen("my_diary.txt", "a+");

    printf("Hello my love,\n");
    printf("I am here to write down my thoughts and feelings for you today. What is today's date? (mm/dd/yyyy): ");
    scanf("%s", date);
    fprintf(fp, "%s\n", date);

    printf("\nMy love, I feel like I am walking on cloud nine whenever I am with you. ");
    printf("All my worries disappear and my heart is filled with warmth. ");
    printf("Today, I want to express my adoration for you in this diary entry. \n\n");

    printf("What would you like to write about my love? Please pour your heart out: \n");
    getchar();
    fgets(entry, 200, stdin);

    fprintf(fp, "%s", entry);

    printf("\n\nI love you so much my darling. I hope you have a wonderful day. \n\n");

    fclose(fp);
    return 0;
}