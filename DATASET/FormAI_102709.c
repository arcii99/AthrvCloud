//FormAI DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

struct diary_entry {
    int day;
    int month;
    int year;
    char entry[500];
};

int main() {
    int num_entries;
    printf("How many entries would you like to make?\n");
    scanf("%d", &num_entries);
    struct diary_entry* entries = (struct diary_entry*) malloc(num_entries * sizeof(struct diary_entry));
    for (int i = 0; i < num_entries; i++) {
        printf("Date of entry #%d (dd/mm/yyyy): ", i + 1);
        scanf("%d/%d/%d", &entries[i].day, &entries[i].month, &entries[i].year);
        printf("Write your entry:\n");
        scanf(" %[^\n]", entries[i].entry);
    }
    printf("\nAll diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d/%d/%d\n%s\n\n", entries[i].day, entries[i].month, entries[i].year, entries[i].entry);
    }
    free(entries);
    return 0;
}