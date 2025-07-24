//FormAI DATASET v1.0 Category: System administration ; Style: statistical
/* Statistical System Administration Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_USERS 100
#define NUM_FILES 50

/* Function to randomly generate a 10 digit alphanumeric string */
void rand_string(char *str)
{
    int i;
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    srand((unsigned int)time(NULL)); 
    for (i = 0; i < 10; i++) {
        int index = rand() % (sizeof(charset) - 1);
        str[i] = charset[index];
    }
    str[i] = '\0';
}

/* Structure to represent a user */
struct user {
    char name[20];
    int files_owned;
    int files_shared;
    int space_used;
};

/* Structure to represent a file */
struct file {
    char name[20];
    char owner[20];
    int size;
};

/* Main function */
int main(void)
{
    int i, j;
    struct user users[NUM_USERS];
    struct file files[NUM_FILES];
    char rand_str[11];

    /* Initialize users */
    for (i = 0; i < NUM_USERS; i++) {
        rand_string(rand_str);
        sprintf(users[i].name, "User%s", rand_str);
        users[i].files_owned = rand() % 10;
        users[i].files_shared = rand() % 10;
        users[i].space_used = users[i].files_owned * (rand() % 100);
    }

    /* Initialize files */
    for (i = 0; i < NUM_FILES; i++) {
        rand_string(rand_str);
        sprintf(files[i].name, "File%s", rand_str);
        sprintf(files[i].owner, "%s", users[rand() % NUM_USERS].name);
        files[i].size = rand() % 100;
    }

    /* Calculate statistics */
    int total_files_owned = 0;
    int total_files_shared = 0;
    int total_space_used = 0;
    int file_sizes[NUM_FILES];
    for (i = 0; i < NUM_USERS; i++) {
        total_files_owned += users[i].files_owned;
        total_files_shared += users[i].files_shared;
        total_space_used += users[i].space_used;
    }
    for (i = 0; i < NUM_FILES; i++) {
        file_sizes[i] = files[i].size;
    }

    /* Print statistics */
    printf("STATISTICS:\n");
    printf("Total number of users: %d\n", NUM_USERS);
    printf("Total number of files: %d\n", NUM_FILES);
    printf("Total number of files owned: %d\n", total_files_owned);
    printf("Total number of files shared: %d\n", total_files_shared);
    printf("Total space used: %d Bytes\n", total_space_used);

    /* Print top 5 largest files */
    printf("\nTOP 5 LARGEST FILES:\n");
    int largest_file_indices[5];
    for (i = 0; i < 5; i++) {
        largest_file_indices[i] = 0;
        for (j = 0; j < NUM_FILES; j++) {
            if (file_sizes[j] > file_sizes[largest_file_indices[i]]) {
                largest_file_indices[i] = j;
            }
        }
        printf("%d. %s (%d Bytes)\n", i+1, files[largest_file_indices[i]].name, files[largest_file_indices[i]].size);
        file_sizes[largest_file_indices[i]] = -1;
    }

    return 0;
}