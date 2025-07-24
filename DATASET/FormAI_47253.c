//FormAI DATASET v1.0 Category: Database simulation ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct paranoidDB { // defining a structure for the paranoid database
    char data[50];
    int key;
    char encryption_key[10];
};

void encrypt(char *str, char *encryption_key) { // function to encrypt the data
    int i = 0;
    while (str[i] != '\0') {
        str[i] = str[i] ^ encryption_key[i%strlen(encryption_key)];
        i++;
    }
}

void decrypt(char *str, char *encryption_key) { // function to decrypt the data
    encrypt(str, encryption_key);
}

int main() {
    
    struct paranoidDB db[10]; // creating 10 records for the database
    strcpy(db[0].data, "John Smith");
    db[0].key = 1;
    strcpy(db[0].encryption_key, "john1234");
    
    strcpy(db[1].data, "Jane Doe");
    db[1].key = 2;
    strcpy(db[1].encryption_key, "jane5678");

    // add more records here
    
    int choice = 0;
    int key = 0;
    
    do {
        printf("\n Welcome to Paranoid Database! ");
        printf("\n ------------------------------ ");
        printf("\n 1. Add data to database");
        printf("\n 2. Read data from database");
        printf("\n 3. Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                printf("\n Enter the data to be added to database : ");
                char temp_data[50];
                scanf("%s", temp_data);
                
                printf("\n Enter the key for the data : ");
                scanf("%d", &key);
                
                printf("\n Enter the encryption key for the data : ");
                char temp_encrypt_key[10];
                scanf("%s", temp_encrypt_key);
                
                encrypt(temp_data, temp_encrypt_key);
                strcpy(db[key].data, temp_data);
                db[key].key = key;
                strcpy(db[key].encryption_key, temp_encrypt_key);
                
                printf("\n Data added successfully!");
                printf("\n ---------------------------");
                break;
            }
            
            case 2: {
                printf("\n Enter the key of the data to be read : ");
                scanf("%d", &key);
                
                if(db[key].key == key) {
                    char temp_data[50];
                    strcpy(temp_data, db[key].data);
                    decrypt(temp_data, db[key].encryption_key);
                    printf("\n The data is : %s", temp_data);
                    printf("\n -----------------------------------");
                }
                else {
                    printf("\n Invalid key!");
                    printf("\n ------------");
                }
                break;
            }
            
            case 3: {
                printf("\n Thank you for using Paranoid Database!");
                printf("\n --------------------------------------"); 
                break;
            }
            
            default: {
                printf("\n Invalid choice!");
                printf("\n ---------------");
            }
        }
    }while(choice!=3);
    
    return 0;
}