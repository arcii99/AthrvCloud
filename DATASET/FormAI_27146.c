//FormAI DATASET v1.0 Category: Digital Diary ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DiaryEntry {
    char date[12];
    char text[500];
};

int main() {
    int numEntries, i;
    printf("How many diary entries do you want to make? ");
    scanf("%d", &numEntries);

    struct DiaryEntry diary[numEntries];

    for (i = 0; i < numEntries; i++) {
        printf("\nEntry %d:\n", i + 1);
        printf("Enter the date (dd/mm/yyyy): ");
        scanf("%s", diary[i].date);
        printf("Enter your diary entry (500 character limit):\n");
        getchar(); // to consume the newline character left behind by scanf
        fgets(diary[i].text, 500, stdin);
    }

    printf("\nHere are your diary entries:\n");

    for (i = 0; i < numEntries; i++) {
        printf("\n%s:\n%s", diary[i].date, diary[i].text);
    }

    return 0;
}