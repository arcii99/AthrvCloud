//FormAI DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    char name[50];
    int age;
    char address[100];
} Record;

int num_records = 0;
Record records[MAX_RECORDS];

int menu();
void add_record();
void view_records();
void search_record(char query[]);
void delete_record(int index);
void update_record(int index);
void save_to_file();
void load_from_file();

int main() {
    int choice;
    load_from_file();
    do {
        choice = menu();
        switch(choice) {
            case 1:
                add_record();
                break;
            case 2:
                view_records();
                break;
            case 3:
                char query[50];
                printf("Enter search query: ");
                scanf("%s", query);
                search_record(query);
                break;
            case 4:
                int index;
                printf("Enter index number: ");
                scanf("%d", &index);
                delete_record(index);
                break;
            case 5:
                int update_index;
                printf("Enter index number: ");
                scanf("%d", &update_index);
                update_record(update_index);
                break;
            case 6:
                save_to_file();
                break;
            case 7:
                break;
            default:
                printf("Invalid choice! Please choose from the menu.\n");
        }
    } while(choice != 7);

    return 0;
}

int menu() {
    int choice;

    printf("\nMENU\n");
    printf("1. Add record\n");
    printf("2. View records\n");
    printf("3. Search record\n");
    printf("4. Delete record\n");
    printf("5. Update record\n");
    printf("6. Save to file\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void add_record() {
    if(num_records >= MAX_RECORDS) {
        printf("Error: Cannot add more records. Maximum limit reached.\n");
        return;
    }

    Record record;

    printf("Enter name: ");
    scanf("%s", record.name);
    printf("Enter age: ");
    scanf("%d", &record.age);
    printf("Enter address: ");
    scanf("%s", record.address);

    records[num_records] = record;
    num_records++;

    printf("Record added!\n");
}

void view_records() {
    printf("\nRECORDS\n");
    if(num_records == 0) {
        printf("No records found.\n");
        return;
    }

    for(int i = 0; i < num_records; i++) {
        printf("Index: %d\n", i);
        printf("Name: %s\n", records[i].name);
        printf("Age: %d\n", records[i].age);
        printf("Address: %s\n", records[i].address);
        printf("\n");
    }
}

void search_record(char query[]) {
    bool found = false;

    for(int i = 0; i < num_records; i++) {
        if(strstr(records[i].name, query) != NULL || strstr(records[i].address, query) != NULL) {
            printf("Index: %d\n", i);
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            printf("Address: %s\n", records[i].address);
            printf("\n");
            found = true;
        }
    }

    if(!found) {
        printf("No records found.\n");
    }
}

void delete_record(int index) {
    if(index < 0 || index >= num_records) {
        printf("Error: Invalid index number.\n");
        return;
    }

    for(int i = index; i < num_records - 1; i++) {
        records[i] = records[i+1];
    }

    num_records--;
    printf("Record deleted!\n");
}

void update_record(int index) {
    if(index < 0 || index >= num_records) {
        printf("Error: Invalid index number.\n");
        return;
    }

    Record updated_record;

    printf("Enter name: ");
    scanf("%s", updated_record.name);
    printf("Enter age: ");
    scanf("%d", &updated_record.age);
    printf("Enter address: ");
    scanf("%s", updated_record.address);

    records[index] = updated_record;

    printf("Record updated!\n");
}

void save_to_file() {
    FILE *fp;
    fp = fopen("data.txt", "w");

    if(fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    for(int i = 0; i < num_records; i++) {
        fprintf(fp, "%s,%d,%s\n", records[i].name, records[i].age, records[i].address);
    }

    fclose(fp);
    printf("Records saved to file!\n");
}

void load_from_file() {
    FILE *fp;
    fp = fopen("data.txt", "r");

    if(fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    char line[150];
    char *token;

    while(fgets(line, 150, fp) != NULL) {
        token = strtok(line, ",");
        strncpy(records[num_records].name, token, sizeof(records[num_records].name));
        token = strtok(NULL, ",");
        records[num_records].age = atoi(token);
        token = strtok(NULL, ",");
        strncpy(records[num_records].address, token, sizeof(records[num_records].address));
        num_records++;
    }

    fclose(fp);
    printf("Records loaded from file!\n");
}