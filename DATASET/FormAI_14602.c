//FormAI DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include <stdio.h>

// Define a structure for medieval knights
struct knight {
    char name[50];
    int age;
    char type_of_weapon[50];
    struct knight* next;
};

// Function to add a knight at the beginning of the list
void add_knight(struct knight** head_ref, char new_name[], int new_age, char new_weapon[]) {
    struct knight* new_knight = (struct knight*)malloc(sizeof(struct knight));
    strcpy(new_knight->name, new_name);
    new_knight->age = new_age;
    strcpy(new_knight->type_of_weapon, new_weapon);
    new_knight->next = *head_ref;
    *head_ref = new_knight;
}

// Function to print the knights in the list
void print_knights(struct knight* knight_list) {
    struct knight *knight_ptr = knight_list;
    while (knight_ptr != NULL) {
        printf("Knight: %s, Age: %d, Weapon: %s\n", knight_ptr->name, knight_ptr->age, knight_ptr->type_of_weapon);
        knight_ptr = knight_ptr->next;
    }
}

int main() {
    struct knight* head = NULL;

    // Add some knights to the list
    add_knight(&head, "Knight1", 30, "Sword");
    add_knight(&head, "Knight2", 25, "Bow");
    add_knight(&head, "Knight3", 45, "Axe");

    // Print the knights in the list
    print_knights(head);

    return 0;
}