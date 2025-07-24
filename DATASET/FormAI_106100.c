//FormAI DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000

struct DiaryEntry {
    char date[11];
    char time[6];
    char entry[1000];
};

struct Diary {
    struct DiaryEntry entries[MAX_ENTRIES];
    int count;
};

int main() {
    struct Diary diary = { .count = 0 };

    int choice = 1;
    int index;

    while (choice) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. View all entries\n");
        printf("3. Search for entries\n");
        printf("4. Edit entry\n");
        printf("5. Delete entry\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (diary.count == MAX_ENTRIES) {
                    printf("\nDiary is full. Cannot add any more entries\n");
                    break;
                }

                printf("\nEnter the entry date (format: mm/dd/yyyy): ");
                scanf("%s", &diary.entries[diary.count].date);

                printf("Enter the entry time (format: hh:mm): ");
                scanf("%s", &diary.entries[diary.count].time);

                printf("Enter the diary entry:\n");
                getchar();
                fgets(diary.entries[diary.count].entry, 1000, stdin);

                diary.count++;
                printf("\nEntry added successfully\n");
                break;
            
            case 2:
                printf("\n\tAll Entries\n");
                printf("-----------------------------------------------\n");
                if(diary.count == 0){
                    printf("\tThe diary is empty!\n");
                }
                for(int i = 0; i < diary.count; i++){
                    printf("Entry %d:\n",i+1);
                    printf("\tDate: %s\n",diary.entries[i].date);
                    printf("\tTime: %s\n", diary.entries[i].time);
                    printf("\tEntry: %s\n\n", diary.entries[i].entry);
                }
                break;
            
            case 3:
                printf("\n\tSearch Results\n");
                printf("-----------------------------------------------\n");
                if(diary.count == 0){
                    printf("\tThe diary is empty!\n");
                    break;
                }
                printf("Enter the keyword you are searching for: ");
                char keyword[1000];
                getchar();
                fgets(keyword, 1000, stdin);
                printf("\nResults:\n");
                for(int i = 0; i < diary.count; i++){
                    if(strstr(diary.entries[i].entry, keyword)){
                        printf("Entry %d:\n",i+1);
                        printf("\tDate: %s\n",diary.entries[i].date);
                        printf("\tTime: %s\n", diary.entries[i].time);
                        printf("\tEntry: %s\n\n", diary.entries[i].entry);
                    }
                }
                break;

            case 4:
                printf("\n\tEdit Entry\n");
                printf("-----------------------------------------------\n");
                if(diary.count == 0){
                    printf("\tThe diary is empty!\n");
                    break;
                }
                printf("Enter the index of the entry you want to edit: ");
                scanf("%d", &index);
                if(index > diary.count || index < 1){
                    printf("\nThe index you entered is out of range!\n");
                    break;
                }
                printf("\tDate: %s\n",diary.entries[index-1].date);
                printf("\tTime: %s\n", diary.entries[index-1].time);
                printf("\tEntry: %s\n", diary.entries[index-1].entry);

                printf("\nEnter the new entry:\n");
                getchar();
                fgets(diary.entries[index-1].entry, 1000, stdin);
                printf("\nThe entry has been updated\n");
                break;

            case 5:
                printf("\n\tDelete Entry\n");
                printf("-----------------------------------------------\n");
                if(diary.count == 0){
                    printf("\tThe diary is empty!\n");
                    break;
                }
                printf("Enter the index of the entry you want to delete: ");
                scanf("%d", &index);
                if(index > diary.count || index < 1){
                    printf("\nThe index you entered is out of range!\n");
                    break;
                }
                for(int i = index-1; i< diary.count-1; i++){
                    diary.entries[i] = diary.entries[i+1];
                }
                diary.count--;
                printf("\nThe entry has been deleted!\n");
                break;

            case 0:
                printf("\nExiting..");
                break;

            default:
                printf("\nInvalid choice. Try again\n");
        }
    }

    return 0;
}