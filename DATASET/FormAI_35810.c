//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: decentralized
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

// Declarations
struct luggage{
    int id; // Luggage identifier
    int weight; // Luggage weight in kgs
    char destination[50]; // Destination airport code
};

struct node{
    struct luggage l; // Payload
    struct node * next; // Pointer to the next node in the list
};

// Declarations
struct node * start = NULL; // Head of the linked-list

// Function prototypes
void add_luggage(); // Add luggage to the list
void simulate_transfer(); // Simulate luggage transfer
void display_luggage(); // Display list of luggage 


// Add luggage to the list
void add_luggage(){
    srand(time(NULL));
    int id = rand() % 10000 + 1; // Generate a random id for the luggage
    struct luggage l;
    l.id = id;
    printf("Enter luggage weight (kgs): ");
    scanf("%d",&l.weight);
    printf("Enter destination airport code: ");
    scanf("%s",l.destination);
    struct node * ptr = (struct node*)malloc(sizeof(struct node)); 
    ptr->l = l;
    ptr->next = NULL;
    if(start == NULL)
        start = ptr;
    else{
        struct node * temp = start;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
    printf("Luggage successfully added to the list\n");
}

// Simulate transfer of luggage
void simulate_transfer(){
    if(start == NULL){
        printf("No luggage to transfer\n");
        return;
    }
    struct node * temp = start;
    while(temp != NULL){ // Loop through all luggage
        // Check if luggage needs to be transferred to another airport
        if(strcmp(temp->l.destination,"XYZ")==0){
            printf("Luggage with id : %d needs to be transferred to airport XYZ\n",temp->l.id);
            struct node * ptr = temp;
            temp = temp->next;
            free(ptr); // Remove the luggage from the list as it has been transferred
        }else{
            printf("Luggage with id : %d is waiting to be transferred\n",temp->l.id);
            temp = temp->next;
        }
    }
}

// Display list of luggage
void display_luggage(){
    if(start == NULL){
        printf("No luggage in the system\n");
        return;
    }
    printf("Luggage list : \n");
    struct node * temp = start;
    while(temp != NULL){
        printf("   Id : %d, Weight : %d kgs, Dest : %s\n",temp->l.id,temp->l.weight,temp->l.destination);
        temp = temp->next;
    }
}

// Main function
int main(){
    int choice;
    while(1){
        printf("\n\n----Airport Baggage Handling Simulation System----\n");
        printf("1. Add luggage\n");
        printf("2. Simulate transfer of luggage\n");
        printf("3. Display list of luggage\n");
        printf("4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : add_luggage();
                     break;
            case 2 : simulate_transfer();
                     break;
            case 3 : display_luggage();
                     break;
            case 4 : exit(0);
            default : printf("Invalid choice\n");
        }
    }
    return 0;
}