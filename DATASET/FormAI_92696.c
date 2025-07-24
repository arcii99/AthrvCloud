//FormAI DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct for storing information about medieval knights
typedef struct {
    int id;
    char name[30];
    int age;
    char weapon[30];
    char town[30];
} Knight;

void print_menu() {
    printf("\nWelcome to the Knights Database!\n\n"
           "1. View all knights\n"
           "2. Query knights by name\n"
           "3. Query knights by weapon\n"
           "4. Query knights by town\n"
           "5. Add a new knight\n"
           "6. Delete a knight\n"
           "7. Exit\n\n");
}

int get_selection() {
    int choice = -1;
    while (choice < 1 || choice > 7) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 7) {
            printf("Invalid choice, please try again.\n");
        }
    }
    return choice;
}

void view_all_knights(Knight *knights, int num_knights) {
    printf("\n=== All Knights ===\n");
    for (int i = 0; i < num_knights; i++) {
        printf("ID: %d\nName: %s\nAge: %d\nWeapon: %s\nTown: %s\n\n",
               knights[i].id, knights[i].name, knights[i].age, knights[i].weapon, knights[i].town);
    }
}

void query_knights_by_name(Knight *knights, int num_knights) {
    char name[30];
    printf("Enter the name of the knight: ");
    scanf("%s", name);

    printf("\n=== Knights named %s ===\n", name);
    for (int i = 0; i < num_knights; i++) {
        if (strcmp(knights[i].name, name) == 0) {
            printf("ID: %d\nAge: %d\nWeapon: %s\nTown: %s\n\n",
                   knights[i].id, knights[i].age, knights[i].weapon, knights[i].town);
        }
    }
}

void query_knights_by_weapon(Knight *knights, int num_knights) {
    char weapon[30];
    printf("Enter the weapon name: ");
    scanf("%s", weapon);

    printf("\n=== Knights with the weapon %s ===\n", weapon);
    for (int i = 0; i < num_knights; i++) {
        if (strcmp(knights[i].weapon, weapon) == 0) {
            printf("ID: %d\nName: %s\nAge: %d\nTown: %s\n\n",
                   knights[i].id, knights[i].name, knights[i].age, knights[i].town);
        }
    }
}

void query_knights_by_town(Knight *knights, int num_knights) {
    char town[30];
    printf("Enter the name of the town: ");
    scanf("%s", town);

    printf("\n=== Knights from %s ===\n", town);
    for (int i = 0; i < num_knights; i++) {
        if (strcmp(knights[i].town, town) == 0) {
            printf("ID: %d\nName: %s\nAge: %d\nWeapon: %s\n\n",
                   knights[i].id, knights[i].name, knights[i].age, knights[i].weapon);
        }
    }
}

void add_new_knight(Knight *knights, int *num_knights) {
    Knight new_knight;
    new_knight.id = *num_knights + 1;

    printf("Enter the name of the knight: ");
    scanf("%s", new_knight.name);

    printf("Enter the age of the knight: ");
    scanf("%d", &new_knight.age);

    printf("Enter the weapon of the knight: ");
    scanf("%s", new_knight.weapon);

    printf("Enter the town of the knight: ");
    scanf("%s", new_knight.town);

    knights[*num_knights] = new_knight;
    *num_knights += 1;

    printf("Knight added successfully.\n");
}

void delete_knight(Knight *knights, int *num_knights) {
    int id;
    printf("Enter the ID of the knight to delete: ");
    scanf("%d", &id);

    int found_index = -1;
    for (int i = 0; i < *num_knights; i++) {
        if (knights[i].id == id) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("No knight with ID %d found.\n", id);
    } else {
        for (int i = found_index; i < *num_knights - 1; i++) {
            knights[i] = knights[i + 1];
        }
        *num_knights -= 1;
        printf("Knight with ID %d deleted successfully.\n", id);
    }
}

int main() {

    Knight knights[100];
    int num_knights = 0;

    // Add some example knights
    num_knights += 1;
    knights[0].id = 1;
    strcpy(knights[0].name, "Sir Lancelot");
    knights[0].age = 35;
    strcpy(knights[0].weapon, "Sword");
    strcpy(knights[0].town, "Camelot");

    num_knights += 1;
    knights[1].id = 2;
    strcpy(knights[1].name, "Sir Gawain");
    knights[1].age = 28;
    strcpy(knights[1].weapon, "Lance");
    strcpy(knights[1].town, "Orkney");

    num_knights += 1;
    knights[2].id = 3;
    strcpy(knights[2].name, "Sir Galahad");
    knights[2].age = 22;
    strcpy(knights[2].weapon, "Spear");
    strcpy(knights[2].town, "Sarras");

    int choice = 0;
    while (choice != 7) {
        print_menu();
        choice = get_selection();

        switch (choice) {
            case 1:
                view_all_knights(knights, num_knights);
                break;
            case 2:
                query_knights_by_name(knights, num_knights);
                break;
            case 3:
                query_knights_by_weapon(knights, num_knights);
                break;
            case 4:
                query_knights_by_town(knights, num_knights);
                break;
            case 5:
                add_new_knight(knights, &num_knights);
                break;
            case 6:
                delete_knight(knights, &num_knights);
                break;
            case 7:
                printf("Goodbye!\n");
                break;
        }
    }

    return 0;
}