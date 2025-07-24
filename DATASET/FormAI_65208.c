//FormAI DATASET v1.0 Category: Digital Diary ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function prototypes
void menu(void);
void add_entry(void);
void view_entry(void);
void delete_entry(void);
void edit_entry(void);
void search_entry(void);
void clear_diary(void);
char* get_date_time(void);

// global variables
struct entry {
    char date[20];
    char time[20];
    char title[100];
    char content[1000];
} e;

char filename[] = "diary.txt";

int main(void) {
    menu();
    return 0;
}

void menu(void) {
    int choice = 0;
    printf("*** Digital Diary Menu ***\n");
    printf("1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. Delete Entry\n");
    printf("4. Edit Entry\n");
    printf("5. Search Entries\n");
    printf("6. Clear Diary\n");
    printf("7. Exit\n");
    printf("Enter your choice (1-7): \n");
    scanf("%d", &choice);
    fflush(stdin);
    switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            view_entry();
            break;
        case 3:
            delete_entry();
            break;
        case 4:
            edit_entry();
            break;
        case 5:
            search_entry();
            break;
        case 6:
            clear_diary();
            break;
        case 7:
            printf("*** Goodbye ***\n");
            exit(0);
        default:
            printf("*** Invalid Choice ***\n");
            menu();
            break;
    }
}

void add_entry(void) {
    char ch;
    printf("*** Add Entry ***\n");
    FILE* fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("*** Error: Unable to open file ***\n");
        menu();
    }
    else {
        printf("Enter Title: ");
        fflush(stdin);
        gets(e.title);
        printf("Enter Content: ");
        fflush(stdin);
        gets(e.content);
        strcpy(e.date, get_date_time());
        printf("Do you want to save entry (y/n): ");
        scanf("%c", &ch);
        if (ch == 'y' || ch == 'Y') {
            fprintf(fp, "%s %s %s %s\n", e.date, e.title, e.content, get_date_time());
            printf("*** Entry Saved Successfully ***\n");
        }
        fclose(fp);
        menu();
    }
}

void view_entry(void) {
    printf("*** View Entry ***\n");
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("*** Error: Unable to open file ***\n");
        menu();
    }
    else {
        char search_title[100];
        printf("Enter search title: ");
        fflush(stdin);
        gets(search_title);
        int found = 0, line_no = 1;
        while (fgets(e.date, 20, fp) != NULL) {
            fgets(e.title, 100, fp);
            fgets(e.content, 1000, fp);
            if (strstr(e.title, search_title) != NULL) {
                found = 1;
                printf("Line no: %d\n", line_no);
                printf("Date-Time: %s", e.date);
                printf("Title: %s", e.title);
                printf("Content: %s", e.content);
                printf("\n");
            }
            line_no++;
        }
        if (!found) {
            printf("*** No Entry Found ***\n");
        }
        fclose(fp);
        printf("\n");
        menu();
    }
}

void delete_entry(void) {
    printf("*** Delete Entry ***\n");
    FILE* fp1 = fopen(filename, "r");
    FILE* fp2 = fopen("temp.txt", "a");
    if (fp1 == NULL) {
        printf("*** Error: Unable to open file ***\n");
        menu();
    }
    else {
        char search_title[100], ch;
        printf("Enter search title: ");
        fflush(stdin);
        gets(search_title);
        int found = 0, line_no = 1;
        while (fgets(e.date, 20, fp1) != NULL) {
            fgets(e.title, 100, fp1);
            fgets(e.content, 1000, fp1);
            if (strstr(e.title, search_title) != NULL) {
                found = 1;
                printf("\nLine no: %d\n", line_no);
                printf("Date-Time: %s", e.date);
                printf("Title: %s", e.title);
                printf("Content: %s", e.content);
                printf("Do you want to delete this entry (y/n): ");
                scanf("%c", &ch);
                if (ch == 'y' || ch == 'Y') {
                    printf("*** Entry Deleted Successfully ***\n");
                }
                else {
                    fprintf(fp2, "%s%s%s", e.date, e.title, e.content);
                }
            }
            else {
                fprintf(fp2, "%s%s%s", e.date, e.title, e.content);
            }
            line_no++;
        }
        if (!found) {
            printf("*** No Entry Found ***\n");
        }
        fclose(fp1);
        fclose(fp2);
        remove(filename);
        rename("temp.txt", filename);
        menu();
    }
}

void edit_entry(void) {
    printf("*** Edit Entry ***\n");
    FILE* fp1 = fopen(filename, "r");
    FILE* fp2 = fopen("temp.txt", "a");
    if (fp1 == NULL) {
        printf("*** Error: Unable to open file ***\n");
        menu();
    }
    else {
        char search_title[100], ch;
        printf("Enter search title: ");
        fflush(stdin);
        gets(search_title);
        int found = 0, line_no = 1;
        while (fgets(e.date, 20, fp1) != NULL) {
            fgets(e.title, 100, fp1);
            fgets(e.content, 1000, fp1);
            if (strstr(e.title, search_title) != NULL) {
                found = 1;
                printf("\nLine no: %d\n", line_no);
                printf("Date-Time: %s", e.date);
                printf("Title: %s", e.title);
                printf("Content: %s", e.content);
                printf("Do you want to edit this entry (y/n): ");
                scanf("%c", &ch);
                if (ch == 'y' || ch == 'Y') {
                    printf("Enter Title: ");
                    fflush(stdin);
                    gets(e.title);
                    printf("Enter Content: ");
                    fflush(stdin);
                    gets(e.content);
                    fprintf(fp2, "%s%s%s", e.date, e.title, e.content);
                    printf("*** Entry Updated Successfully ***\n");
                }
                else {
                    fprintf(fp2, "%s%s%s", e.date, e.title, e.content);
                }
            }
            else {
                fprintf(fp2, "%s%s%s", e.date, e.title, e.content);
            }
            line_no++;
        }
        if (!found) {
            printf("*** No Entry Found ***\n");
        }
        fclose(fp1);
        fclose(fp2);
        remove(filename);
        rename("temp.txt", filename);
        menu();
    }
}

void search_entry(void) {
    printf("*** Search Entries ***\n");
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("*** Error: Unable to open file ***\n");
        menu();
    }
    else {
        char search_text[100];
        printf("Enter search text: ");
        fflush(stdin);
        gets(search_text);
        int found = 0, line_no = 1;
        while (fgets(e.date, 20, fp) != NULL) {
            fgets(e.title, 100, fp);
            fgets(e.content, 1000, fp);
            if (strstr(e.title, search_text) != NULL || strstr(e.content, search_text) != NULL) {
                found = 1;
                printf("Line no: %d\n", line_no);
                printf("Date-Time: %s", e.date);
                printf("Title: %s", e.title);
                printf("Content: %s", e.content);
                printf("\n");
            }
            line_no++;
        }
        if (!found) {
            printf("*** No Entry Found ***\n");
        }
        fclose(fp);
        printf("\n");
        menu();
    }
}

void clear_diary(void) {
    printf("*** Warning: This will delete all your diary entries. Are you sure you want to continue (y/n) ***\n");
    char ch;
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y') {
        FILE* fp = fopen(filename, "w");
        if (fp == NULL) {
            printf("*** Error: Unable to open file ***\n");
            menu();
        }
        else {
            fprintf(fp, "");
            printf("*** Diary Cleared Successfully ***\n");
            fclose(fp);
            menu();
        }
    }
    else {
        menu();
    }
}

char* get_date_time(void) {
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char* datetime = asctime(timeinfo);
    return datetime;
}