//FormAI DATASET v1.0 Category: Linked list operations ; Style: medieval
#include<stdio.h>
#include<stdlib.h>

// Defining the structure of a medieval person
typedef struct medievalPerson{
    char name[50];
    int age;
    char gender[10];
    struct medievalPerson *next;
}medievalPerson;

// Function declarations
void display_medieval_people(medievalPerson *head);
medievalPerson* create_new_person(char name[], int age, char gender[]);
void add_person_to_end(medievalPerson **head, char name[], int age, char gender[]);
void add_person_to_beginning(medievalPerson **head, char name[], int age, char gender[]);
void insert_person_at_index(medievalPerson **head, int index, char name[], int age, char gender[]);
void delete_first_person(medievalPerson **head);
void delete_last_person(medievalPerson **head);
void delete_person_at_index(medievalPerson **head, int index);

// Main function
int main(){
    medievalPerson *head = NULL; // Initializing the linked list as empty
  
    printf("Medieval People Linked List\n\n");
  
    // Adding people to the linked list
    add_person_to_beginning(&head, "Sir Alfred", 45, "Male");
    add_person_to_end(&head, "Lady Catherine", 32, "Female");
    add_person_to_end(&head, "Sir Henry", 19, "Male");
    add_person_to_beginning(&head, "Lady Elizabeth", 27, "Female");
    insert_person_at_index(&head, 2, "Sir Richard", 37, "Male");
  
    // Displaying the people in the linked list
    display_medieval_people(head);
  
    // Removing people from the linked list
    delete_first_person(&head);
    delete_person_at_index(&head, 2);
    delete_last_person(&head);
  
    // Displaying the people in the linked list after deleting some people
    printf("\nAfter deleting some people from the list:\n");
    display_medieval_people(head);

    return 0;
}

// Function to display the medieval people in the linked list
void display_medieval_people(medievalPerson *head){
    printf("Medieval People:\n\n");
    medievalPerson *current = head;
    int count = 1;
    while(current != NULL){
        printf("%d. %s, Age: %d, Gender: %s\n",count,current->name,current->age,current->gender);
        current = current->next;
        count++;
    }
}

// Function to create a new medieval person
medievalPerson* create_new_person(char name[], int age, char gender[]){
    // Allocating memory for the new person
    medievalPerson *new_person = (medievalPerson*) malloc(sizeof(medievalPerson));
    // Initializing the values of the new person
    strcpy(new_person->name, name);
    new_person->age = age;
    strcpy(new_person->gender, gender);
    new_person->next = NULL;
    return new_person;
}

// Function to add a person to the end of the linked list
void add_person_to_end(medievalPerson **head, char name[], int age, char gender[]){
    medievalPerson *new_person = create_new_person(name, age, gender);
    if(*head == NULL){
        *head = new_person;
    }else{
        medievalPerson *current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_person;
    }
}

// Function to add a person to the beginning of the linked list
void add_person_to_beginning(medievalPerson **head, char name[], int age, char gender[]){
    medievalPerson *new_person = create_new_person(name, age, gender);
    new_person->next = *head;
    *head = new_person;
}

// Function to insert a person at a specific index of the linked list
void insert_person_at_index(medievalPerson **head, int index, char name[], int age, char gender[]){
    // Creating the new person to be inserted
    medievalPerson *new_person = create_new_person(name, age, gender);
    // If index is 1, add the person to the beginning of the list
    if(index == 1){
        new_person->next = *head;
        *head = new_person;
    }else{
        // Traverse the list to get the node at index - 1
        medievalPerson *current = *head;
        int count = 1;
        while(current != NULL && count < index-1){
            current = current->next;
            count++;
        }
        // Insert the new person between the node at index - 1 and the node at index
        if(current != NULL){
            new_person->next = current->next;
            current->next = new_person;
        }
    }
}

// Function to delete the first person from the linked list
void delete_first_person(medievalPerson **head){
    if(*head == NULL){
        return;
    }
    medievalPerson *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete the last person from the linked list
void delete_last_person(medievalPerson **head){
    if(*head == NULL){
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    medievalPerson *current = *head;
    while(current->next->next != NULL){
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// Function to delete the person at a specific index from the linked list
void delete_person_at_index(medievalPerson **head, int index){
    if(*head == NULL){
        return;
    }
    medievalPerson *current = *head;
    // If index is 1, delete the first person
    if(index == 1){
        *head = (*head)->next;
        free(current);
        return;
    }else{
        // Traverse the list to get the node at index - 1
        int count = 1;
        while(current != NULL && count < index-1){
            current = current->next;
            count++;
        }
        // Delete the person at index
        if(current != NULL && current->next != NULL){
            medievalPerson *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
    }
}