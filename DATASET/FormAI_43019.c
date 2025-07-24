//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

typedef struct {
    char name[50];
    char email[50];
    int age;
} Record;

Record records[MAX_RECORDS];
int total_records = 0;

void add_record(char name[], char email[], int age) {
    if (total_records >= MAX_RECORDS) {
        printf("Error: Database is full\n");
        return;
    }
    strcpy(records[total_records].name, name);
    strcpy(records[total_records].email, email);
    records[total_records].age = age;
    total_records++;
}

void search_records(char search_term[]) {
    printf("Search results for '%s':\n", search_term);
    for (int i = 0; i < total_records; i++) {
        if (strstr(records[i].name, search_term) != NULL || strstr(records[i].email, search_term) != NULL) {
            printf("%s, %s, %d\n", records[i].name, records[i].email, records[i].age);
        }
    }
}

void display_records() {
    printf("Database contents:\n");
    for (int i = 0; i < total_records; i++) {
        printf("%s, %s, %d\n", records[i].name, records[i].email, records[i].age);
    }
}

int main() {
    printf("Welcome to my unique indexing system!\n");
    
    add_record("John Doe", "johndoe@example.com", 35);
    add_record("Jane Smith", "janesmith@example.com", 28);
    add_record("Bob Johnson", "bobjohnson@example.com", 42);
    
    char search_term[50];
    printf("Enter search term: ");
    fgets(search_term, 50, stdin);
    search_records(search_term);
    
    display_records();
    
    return 0;
}