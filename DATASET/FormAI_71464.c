//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

/* Define constants */
#define MAX_FORTUNES 10
#define MAX_FORTUNE_LENGTH 100

/* Define struct for fortune */
typedef struct fortune {
    char text[MAX_FORTUNE_LENGTH];
} fortune_t;

/* Declare global variables */
fortune_t fortunes[MAX_FORTUNES];
int fortune_count = 0;
pthread_mutex_t lock;

/* Declare thread functions */
void *get_fortune(void *arg);
void *add_fortune(void *arg);

int main() {
    int choice;
    pthread_t t1, t2;

    /* Initialize the mutex lock */
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex init failed.\n");
        return 1;
    }

    /* Seed the random number generator */
    srand(time(NULL));

    /* Populate the array of fortunes */
    strcpy(fortunes[0].text, "You will have a great day today.");
    strcpy(fortunes[1].text, "Your hard work will pay off soon.");
    strcpy(fortunes[2].text, "You will meet someone special in the near future.");
    fortune_count = 3;

    /* Display the menu and get the user's choice */
    printf("Welcome to the Fortune Teller!\n");
    printf("1. Get a fortune\n");
    printf("2. Add a fortune\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    /* Create threads based on user's choice */
    switch (choice) {
        case 1:
            pthread_create(&t1, NULL, get_fortune, NULL);
            pthread_join(t1, NULL);
            break;
        case 2:
            pthread_create(&t1, NULL, add_fortune, NULL);
            pthread_create(&t2, NULL, add_fortune, NULL);
            pthread_join(t1, NULL);
            pthread_join(t2, NULL);
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice.\n");
            break;
    }

    /* Destroy the mutex lock */
    pthread_mutex_destroy(&lock);

    return 0;
}

void *get_fortune(void *arg) {
    /* Lock the thread */
    pthread_mutex_lock(&lock);

    /* Display a random fortune */
    int index = rand() % fortune_count;
    printf("Your fortune: %s\n", fortunes[index].text);

    /* Unlock the thread */
    pthread_mutex_unlock(&lock);

    /* Exit the thread */
    pthread_exit(NULL);
}

void *add_fortune(void *arg) {
    /* Lock the thread */
    pthread_mutex_lock(&lock);

    /* Get the new fortune from the user */
    char new_fortune[MAX_FORTUNE_LENGTH];
    printf("Enter your new fortune: ");
    scanf(" %[^\n]s", new_fortune);

    /* Add the new fortune to the array */
    if (fortune_count < MAX_FORTUNES) {
        strcpy(fortunes[fortune_count].text, new_fortune);
        fortune_count++;
        printf("Fortune added successfully!\n");
    } else {
        printf("Fortune array is full, can't add any more fortunes.\n");
    }

    /* Unlock the thread */
    pthread_mutex_unlock(&lock);

    /* Exit the thread */
    pthread_exit(NULL);
}