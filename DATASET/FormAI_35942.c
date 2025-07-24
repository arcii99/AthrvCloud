//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// function to simulate a spooky sound effect
void spooky_sound_effect() {
    for (int i=0; i<5; i++) {
        printf("\a"); // plays system beep sound
        sleep(1);
    }
}

// function to simulate a ghost encounter
void ghost_encounter() {
    printf("\nYou have encountered a ghost!\n");
    spooky_sound_effect();
    printf("The ghost disappears...\n");
}

// function for the guest thread
void *guest_thread_func(void *arg) {
    char *guest_name = (char *) arg;
    printf("%s enters the Haunted House.\n", guest_name);
    sleep(2); // simulate walking time
    printf("%s hears a strange noise...\n", guest_name);
    spooky_sound_effect();
    printf("%s cautiously moves forward...\n", guest_name);
    sleep(2); // simulate walking time
    ghost_encounter();
    printf("%s exits the Haunted House, relieved to have survived.\n", guest_name);
    return NULL;
}

int main() {
    pthread_t guests[5];
    char *guest_names[5] = {"John", "Jane", "Bob", "Alice", "Mike"};

    printf("Welcome to the Haunted House Simulator!\n");

    // create and execute guest threads
    for (int i=0; i<5; i++) {
        int ret = pthread_create(&guests[i], NULL, guest_thread_func, (void *) guest_names[i]);
        if (ret) {
            printf("Error creating guest thread.\n");
            exit(1);
        }
    }

    // wait for guest threads to finish execution
    for (int i=0; i<5; i++) {
        pthread_join(guests[i], NULL);
    }

    printf("All guests have escaped the Haunted House unscathed...\n");

    pthread_exit(NULL);
}