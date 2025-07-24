//FormAI DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct Entry {
    int day;
    int month;
    int year;
    char title[100];
    char message[500];
};

struct Diary {
    struct Entry entries[MAX_ENTRIES];
    int num_entries;
};

void main_menu();
void add_entry(struct Diary* diary);
void view_entry(struct Diary* diary);
void delete_entry(struct Diary* diary);
void save_entries(struct Diary* diary);
void load_entries(struct Diary* diary);

int main() {
    struct Diary diary;
    diary.num_entries = 0;
    load_entries(&diary);
    main_menu(&diary);
    save_entries(&diary);

    return 0;
}

void main_menu(struct Diary* diary) {
    int choice;

    do {
        printf("Digital Diary Menu\n");
        printf("1. Add Entry\n");
        printf("2. View Entry\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(diary);
                break;
            case 2:
                view_entry(diary);
                break;
            case 3:
                delete_entry(diary);
                break;
            case 4:
                printf("Exiting Digital Diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
}

void add_entry(struct Diary* diary) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if (diary->num_entries >= MAX_ENTRIES) {
        printf("Cannot add more entries. Diary is at full capacity.\n");
        return;
    }

    printf("\nAdding new entry\n");
    printf("Enter entry date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &diary->entries[diary->num_entries].day, &diary->entries[diary->num_entries].month, &diary->entries[diary->num_entries].year);
    fflush(stdin);

    printf("\nEnter entry title: ");
    fgets(diary->entries[diary->num_entries].title, 100, stdin);
    fflush(stdin);

    printf("\nEnter entry message: ");
    fgets(diary->entries[diary->num_entries].message, 500, stdin);
    fflush(stdin);

    printf("\nEntry added successfully!\n");
    diary->num_entries++;
}

void view_entry(struct Diary* diary) {
    int i, day, month, year;
    printf("\nView Entry\n");
    printf("Enter entry date (DD/MM/YYYY): ");

    scanf("%d/%d/%d", &day, &month, &year);

    for (i = 0; i < diary->num_entries; i++) {
        if (diary->entries[i].day == day && diary->entries[i].month == month && diary->entries[i].year == year) {
            printf("\nTitle: %s\nDate: %d/%d/%d\nMessage: %s\n", diary->entries[i].title, diary->entries[i].day, diary->entries[i].month, diary->entries[i].year, diary->entries[i].message);
            return;
        }
    }

    printf("\nNo entry found on that date.\n");
}

void delete_entry(struct Diary* diary) {
    int i, j, day, month, year;

    printf("\nDelete Entry\n");
    printf("Enter entry date (DD/MM/YYYY): ");

    scanf("%d/%d/%d", &day, &month, &year);

    for (i = 0; i < diary->num_entries; i++) {
        if (diary->entries[i].day == day && diary->entries[i].month == month && diary->entries[i].year == year) {
            for (j = i; j < diary->num_entries; j++) {
                diary->entries[j] = diary->entries[j + 1];
            }

            diary->num_entries--;
            printf("\nEntry deleted successfully!\n");

            return;
        }
    }

    printf("\nNo entry found on that date.\n");
}

void save_entries(struct Diary* diary) {
    FILE* fp = fopen("diary.dat", "wb");

    if (fp == NULL) {
        printf("\nError: Could not save diary entries.\n");
        return;
    }

    fwrite(&diary->num_entries, sizeof(int), 1, fp);
    fwrite(diary->entries, sizeof(struct Entry), diary->num_entries, fp);

    fclose(fp);
    printf("\nDiary entries saved successfully!\n");
}

void load_entries(struct Diary* diary) {
    FILE* fp = fopen("diary.dat", "rb");

    if (fp == NULL) {
        printf("\nNo saved diary entries found.\n");
        return;
    }

    fread(&diary->num_entries, sizeof(int), 1, fp);
    fread(diary->entries, sizeof(struct Entry), diary->num_entries, fp);

    fclose(fp);
    printf("\n%s saved diary entries found. Loading...\n", diary->num_entries ? "Some" : "No");
}