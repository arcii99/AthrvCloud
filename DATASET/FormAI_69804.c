//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#define MAX_PASSWORD_LENGTH 12
#define NUM_THREADS 3

//Function to generate a random password
void generate_password(char password[]){
    int i;
    char temp;
    for(i=0;i<MAX_PASSWORD_LENGTH;i++){
        temp = rand() % 93 + 33;
        password[i] = temp;
    }
    password[i] = '\0';
}

//Thread function to check if the password is valid
void *check_password(void *arg){
    char *password = (char*) arg;
    int i;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    for(i=0;i<MAX_PASSWORD_LENGTH;i++){
        if(isupper(password[i])){
            has_uppercase = 1;
        }
        else if(islower(password[i])){
            has_lowercase = 1;
        }
        else if(isdigit(password[i])){
            has_number = 1;
        }
        else{
            has_special_char = 1;
        }
    }
    if(has_uppercase && has_lowercase && has_number && has_special_char){
        printf("The password is valid: %s\n",password);
    }
    else{
        printf("The password is invalid: %s\n",password);
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    int rc;
    int i;
    char password[MAX_PASSWORD_LENGTH+1];

    for(i=0;i<NUM_THREADS;i++){
        generate_password(password);
        rc = pthread_create(&threads[i], NULL, check_password, (void *)password);
        if(rc){
            printf("Error creating thread\n");
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}