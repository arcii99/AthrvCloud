//FormAI DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Entry {
    int day, month, year;
    char content[1000];
};

void main() {
    int num_entries, i, j;
    printf("How many entries would you like to make in your Digital Diary: ");
    scanf("%d", &num_entries);

    struct Entry diary[num_entries];

    for (i = 0; i < num_entries; i++) {
        printf("\nEnter entry for day %d: \n\n", i + 1);
        printf("Enter day (DD): ");
        scanf("%d", &diary[i].day);
        printf("Enter month (MM): ");
        scanf("%d", &diary[i].month);
        printf("Enter year (YYYY): ");
        scanf("%d", &diary[i].year);
        printf("Enter content: ");
        getchar();
        fgets(diary[i].content, 1000, stdin);
    }

    printf("\n\n ===== DIARY ENTRIES ===== \n\n");

    for (j = 0; j < num_entries; j++) {
        printf("\nEntry %d - Date: %d/%d/%d\n\n", j + 1, diary[j].day, diary[j].month, diary[j].year);
        printf("Content: %s\n", diary[j].content);
    }
}