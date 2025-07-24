//FormAI DATASET v1.0 Category: Database Indexing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXKEYS 100 // maximum number of keys in an index
#define MAXSIZE 100 // maximum size of a key value

struct data{
    char key[MAXSIZE];          // key value
    char value[MAXSIZE];        // value associated with the key
};

struct index{
    char indexName[MAXSIZE];    // index name
    int numKeys;                // number of keys in the index
    char keys[MAXKEYS][MAXSIZE];// array of keys
    int numData;                // number of data in the index
    struct data dataList[MAXSIZE];// array of data
};

void addData(struct index *pIndex){ // function to add data to the index
   
    if(pIndex->numData == MAXSIZE){ // check if index is full
        printf("The index is full. Cannot add any data.\n");
        return; // return from the function
    }
    
    char key[MAXSIZE];
    char value[MAXSIZE];
    
    printf("Enter the key: ");
    scanf("%s", key);
    
    for(int i=0; i<pIndex->numKeys; i++){ // check if the key exists in the index
        if(strcmp(key, pIndex->keys[i]) == 0){
            printf("Key already exists. Cannot add new data.\n");
            return; // return from the function
        }
    }
    
    printf("Enter the value: ");
    scanf("%s", value);
    
    strcpy(pIndex->dataList[pIndex->numData].key, key); // copy key value to the data list
    strcpy(pIndex->dataList[pIndex->numData].value, value); // copy value to the data list
    pIndex->numData++; // increment the number of data in the index
    
    printf("Data added successfully.\n");
}

void printData(struct index *pIndex){ // function to print all data in the index
    
    printf("Printing all data in the index...\n\n");
    
    for(int i=0; i<pIndex->numData; i++){
        printf("Key: %s\tValue: %s\n", pIndex->dataList[i].key, pIndex->dataList[i].value);
    }
    
    printf("\n");
}

int main(){
    
    struct index myIndex; // initialize a new index
    strcpy(myIndex.indexName, "example index"); // set index name
    
    myIndex.numKeys = 3; // set number of keys in the index
    strcpy(myIndex.keys[0], "name"); // set key 1
    strcpy(myIndex.keys[1], "age"); // set key 2
    strcpy(myIndex.keys[2], "gender"); // set key 3
    
    myIndex.numData = 0; // set initial number of data in the index
    
    printf("\nWelcome to the %s!\n\n", myIndex.indexName);
    
    while(1){ // loop to prompt user for options
        
        printf("Enter 1 to add data to the index.\n");
        printf("Enter 2 to print all data in the index.\n");
        printf("Enter 3 to exit.\n");
        
        int choice;
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice){
            case 1:
                addData(&myIndex); // call function to add data to the index
                break;
            case 2:
                printData(&myIndex); // call function to print all data in the index
                break;
            case 3:
                printf("Thank you for using %s. Goodbye!\n\n", myIndex.indexName);
                exit(0); // exit the program
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
    
    return 0;
}