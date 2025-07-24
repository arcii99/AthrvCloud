//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

#define MAX_PASSWORD_LENGTH 20
#define NO_OF_PASSWORDS 10

void *password_generator(void *params);
void *password_validator(void *params);

char passwords[NO_OF_PASSWORDS][MAX_PASSWORD_LENGTH+1]; // +1 for null character
pthread_t tid[NO_OF_PASSWORDS];  // array of thread identifiers

int main(){

    int i;
    srand(time(NULL));  // to initialize random number generator with current time
    
    // Creating threads for generating passwords
    for(i=0;i<NO_OF_PASSWORDS;i++){
        pthread_create(&(tid[i]), NULL, &password_generator, NULL);
    }
    
    // Waiting for all generating threads to complete their work
    for(i=0;i<NO_OF_PASSWORDS;i++){
        pthread_join(tid[i], NULL);
    }
    printf("All Passwords Generated!\n");
    
    // Creating threads for validating passwords
    for(i=0;i<NO_OF_PASSWORDS;i++){
        pthread_create(&(tid[i]), NULL, &password_validator, (void*) &(passwords[i]));
    }
    
    // Waiting for all validation threads to complete their work
    for(i=0;i<NO_OF_PASSWORDS;i++){
        pthread_join(tid[i], NULL);
    }
    printf("All Passwords Validated!\n");
    
    return 0;
}

void *password_generator(void *params){

    int i, j;
    char password[MAX_PASSWORD_LENGTH+1];
    
    for(i=0;i<MAX_PASSWORD_LENGTH;i++){
        password[i] = (rand()%26) + 'a';  // generating random lowercase alphabets
    }
    password[MAX_PASSWORD_LENGTH] = '\0';  // adding null character at the end
    
    for(j=0;j<NO_OF_PASSWORDS;j++){
        if(strcmp(passwords[j], password) == 0){ // checking if password already exists
            break;
        }
    }
    if(j == NO_OF_PASSWORDS){ // if password doesn't exist then adding to the array
        strcpy(passwords[i], password);
    }
    
    pthread_exit(0);
}

void *password_validator(void *params){

    char *password = (char *) params;
    int i, j;
    
    for(i=0;i<MAX_PASSWORD_LENGTH;i++){
        if(password[i] < 'a' || password[i] > 'z'){ // checking if password contains only lowercase alphabets
            printf("Invalid password: %s\n", password);
            pthread_exit(0);
        }
    }
    
    // checking if password already exists in the array
    for(j=0;j<NO_OF_PASSWORDS;j++){
        if(strcmp(passwords[j], password) == 0){ 
            printf("Duplicate password found: %s\n", password);
            pthread_exit(0);
        }
    }
    
    printf("Valid password: %s\n", password);
    pthread_exit(0);
}