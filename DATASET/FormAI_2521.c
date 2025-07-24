//FormAI DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

int main() {
    int choice, num_people = 0;
    Person people[100];

    while(1) {
        printf("What would you like to do?\n");
        printf("1. Add a person\n");
        printf("2. Remove a person\n");
        printf("3. Search for a person\n");
        printf("4. Print all people in the database\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                Person p;
                printf("Enter the person's id:\n");
                scanf("%d", &(p.id));
                printf("Enter the person's name:\n");
                scanf("%s", p.name);
                printf("Enter the person's age:\n");
                scanf("%d", &(p.age));
                people[num_people] = p;
                num_people++;
                break;
            }
            case 2: {
                int id_to_remove, index_to_remove = -1;
                printf("Enter the id of the person you would like to remove:\n");
                scanf("%d", &id_to_remove);
                for(int i = 0; i < num_people; i++) {
                    if(people[i].id == id_to_remove) {
                        index_to_remove = i;
                    }
                }
                if(index_to_remove != -1) {
                    for(int i = index_to_remove; i < num_people - 1; i++) {
                        people[i] = people[i + 1];
                    }
                    num_people--;
                    printf("Person removed successfully.\n");
                }
                else {
                    printf("Person not found in database.\n");
                }
                break;
            }
            case 3: {
                int id_to_search, index_to_search = -1;
                printf("Enter the id of the person you would like to search for:\n");
                scanf("%d", &id_to_search);
                for(int i = 0; i < num_people; i++) {
                    if(people[i].id == id_to_search) {
                        index_to_search = i;
                    }
                }
                if(index_to_search != -1) {
                    printf("Person found:\n");
                    printf("ID: %d\n", people[index_to_search].id);
                    printf("Name: %s\n", people[index_to_search].name);
                    printf("Age: %d\n", people[index_to_search].age);
                }
                else {
                    printf("Person not found in database.\n");
                }
                break;
            }
            case 4: {
                printf("%-5s %-20s %-5s\n", "ID", "Name", "Age");
                for(int i = 0; i < num_people; i++) {
                    printf("%-5d %-20s %-5d\n", people[i].id, people[i].name, people[i].age);
                }
                break;
            }
            case 5: {
                printf("Exiting... Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please choose again.\n");
                break;
            }
        }
    }
    return 0;
}