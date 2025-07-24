//FormAI DATASET v1.0 Category: Database simulation ; Style: creative
#include<stdio.h>
#include<stdlib.h>
//structure definition for database entries
struct DatabaseEntry{
    int id;
    char name[50];
    char email[50];
    char address[100];
};

//function to display a specific entry in the database
void displayEntry(struct DatabaseEntry *ptr){
    printf("ID: %d\n", ptr->id);
    printf("Name: %s\n", ptr->name);
    printf("Email: %s\n", ptr->email);
    printf("Address: %s\n", ptr->address);
}

//function to add a new entry to the database
void addEntry(struct DatabaseEntry **ptr, int *size){
    //increase size of the array by 1
    *size = *size + 1;
    //allocate memory for the new entry
    *ptr = (struct DatabaseEntry*)realloc(*ptr, *size * sizeof(struct DatabaseEntry));
    //get input for new entry
    printf("Enter ID: ");
    scanf("%d", &((*ptr+(*size-1))->id));
    printf("Enter Name: ");
    scanf("%s", ((*ptr+(*size-1))->name));
    printf("Enter Email: ");
    scanf("%s", ((*ptr+(*size-1))->email));
    printf("Enter Address: ");
    scanf("%s", ((*ptr+(*size-1))->address));
    //display success message
    printf("Entry added successfully!\n");
}

//function to delete an entry from the database
void deleteEntry(struct DatabaseEntry **ptr, int *size){
    int id, i, index=-1;
    //get id of entry to be deleted
    printf("Enter ID of entry to be deleted: ");
    scanf("%d", &id);
    //search for entry with matching id
    for(i=0; i<*size; i++){
        if((*ptr+i)->id == id){
            index = i;
            break;
        }
    }
    //if entry is found, delete it
    if(index != -1){
        //shift all entries after the deleted entry by 1
        for(i=index; i<(*size-1); i++){
            *(*ptr+i) = *(*ptr+i+1);
        }
        //decrease size of array by 1
        *size = *size - 1;
        //reallocate memory for the smaller array
        *ptr = (struct DatabaseEntry*)realloc(*ptr, *size * sizeof(struct DatabaseEntry));
        //display success message
        printf("Entry deleted successfully!\n");
    }
    //if entry is not found, display error message
    else{
        printf("Entry not found!\n");
    }
}

int main(){
    int choice, size=2;
    //allocate memory for initial array of size 2
    struct DatabaseEntry *ptr = (struct DatabaseEntry*)malloc(size * sizeof(struct DatabaseEntry));
    //initialize first entry with some value
    (ptr+0)->id = 1;
    sprintf((ptr+0)->name, "John Doe");
    sprintf((ptr+0)->email, "johndoe@gmail.com");
    sprintf((ptr+0)->address, "123 Main St, Anytown USA");
    //initialize second entry with some value
    (ptr+1)->id = 2;
    sprintf((ptr+1)->name, "Jane Smith");
    sprintf((ptr+1)->email, "janesmith@yahoo.com");
    sprintf((ptr+1)->address, "456 Elm St, Somewhere Else");

    while(1){
        //display menu
        printf("\n------------------------------\n");
        printf("Database simulation program\n");
        printf("------------------------------\n");
        printf("1. Display all entries\n");
        printf("2. Display specific entry\n");
        printf("3. Add new entry\n");
        printf("4. Delete an entry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        //perform action based on user's choice
        switch(choice){
            case 1:
                //display all entries
                printf("List of all entries:\n");
                for(int i=0; i<size; i++){
                    displayEntry(ptr+i);
                    printf("------------------------------\n");
                }
                break;
            case 2:
                //display specific entry
                int id;
                printf("Enter ID of entry to be displayed: ");
                scanf("%d", &id);
                //search for entry with matching id
                for(int i=0; i<size; i++){
                    if((ptr+i)->id == id){
                        displayEntry(ptr+i);
                        break;
                    }
                    //if entry is not found, display error message
                    if(i == size-1){
                        printf("Entry not found!\n");
                    }
                }
                break;
            case 3:
                //add new entry
                addEntry(&ptr, &size);
                break;
            case 4:
                //delete an entry
                deleteEntry(&ptr, &size);
                break;
            case 5:
                //exit program
                printf("Thank you for using the database simulation program!\n");
                exit(0);
            default:
                //display error message for invalid choice
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }
    return 0;
}