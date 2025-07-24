//FormAI DATASET v1.0 Category: Mailing list manager ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 30
#define EMAIL_LEN 50
#define MAX_ENTRIES 100

typedef struct{
    char name[NAME_LEN];
    char email[EMAIL_LEN];
} Entry;

typedef struct{
    Entry entries[MAX_ENTRIES];
    int count;
} List;

void add_entry(List *l){
    printf("Enter name: ");
    fgets(l->entries[l->count].name, NAME_LEN, stdin);
    l->entries[l->count].name[strcspn(l->entries[l->count].name, "\n")] = '\0';
    printf("Enter email: ");
    fgets(l->entries[l->count].email, EMAIL_LEN, stdin);
    l->entries[l->count].email[strcspn(l->entries[l->count].email, "\n")] = '\0';
    l->count++;
    printf("\nEntry added successfully!\n\n");
}

void print_entries(List l){
    printf("Mailing list:\n");
    for(int i = 0; i < l.count; i++){
        printf("%s - %s\n", l.entries[i].name, l.entries[i].email);
    }
    printf("\n");
}

void search_entry(List l){
    char name[NAME_LEN];
    printf("Enter name to search: ");
    fgets(name, NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';
    for(int i = 0; i < l.count; i++){
        if(strcmp(name, l.entries[i].name) == 0){
            printf("%s - %s\n", l.entries[i].name, l.entries[i].email);
            return;
        }
    }
    printf("Entry not found!\n");
}

void delete_entry(List *l){
    char name[NAME_LEN];
    printf("Enter name to delete: ");
    fgets(name, NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';
    for(int i = 0; i < l->count; i++){
        if(strcmp(name, l->entries[i].name) == 0){
            for(int j = i; j < l->count-1; j++){
                strcpy(l->entries[j].name, l->entries[j+1].name);
                strcpy(l->entries[j].email, l->entries[j+1].email);
            }
            l->count--;
            printf("Entry deleted successfully!\n");
            return;
        }
    }
    printf("Entry not found!\n");
}

int main(){
    List mailing_list;
    mailing_list.count = 0;
    int choice;
    while(1){
        printf("1. Add entry\n");
        printf("2. Print entries\n");
        printf("3. Search entry\n");
        printf("4. Delete entry\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
                add_entry(&mailing_list);
                break;
            case 2:
                print_entries(mailing_list);
                break;
            case 3:
                search_entry(mailing_list);
                break;
            case 4:
                delete_entry(&mailing_list);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n\n");
        }
    }
    return 0;
}