//FormAI DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include <stdio.h>
#include <string.h>

struct DiaryEntry {
    int day;
    int month;
    int year;
    char entry[1000];
};

int main() {
    struct DiaryEntry diary[365];
    int choice = 0;
    int entries = 0;
    int i;

    while (1) {
        printf("1. New Entry\n");
        printf("2. Display Entries\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (entries < 365) {
                    printf("Enter the date of entry (DD MM YYYY): ");
                    scanf("%d %d %d", &diary[entries].day, &diary[entries].month, &diary[entries].year);
                    printf("Enter your entry: ");
                    getchar();
                    fgets(diary[entries].entry, sizeof(diary[entries].entry), stdin);
                    entries++;
                } else {
                    printf("Sorry, diary is full.\n");
                }
                break;
            case 2:
                for (i = 0; i < entries; i++) {
                    printf("%d/%d/%d: %s", diary[i].day, diary[i].month, diary[i].year, diary[i].entry);
                }
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}