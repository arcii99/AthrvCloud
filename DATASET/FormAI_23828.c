//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multi-threaded
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define MAX_RESUMES 10
#define MAX_THREADS 3

// Structure to hold parsed resume data
struct Resume {
    char name[50];
    int age;
    char skills[100];
};

// Array to hold resumes
struct Resume resumes[MAX_RESUMES];

// Mutex to synchronize access to resumes array
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to parse a single resume
void *parseResume(void *arg) {
    int index = *(int *)arg;
    printf("Parsing resume #%d...\n", index+1);

    // Simulating time-consuming parsing of resume data
    sleep(2);

    // Parsing resume data and storing in the resumes array
    pthread_mutex_lock(&mutex); // Lock the mutex before accessing the resumes array
    strcpy(resumes[index].name, "John Doe"); // Example name
    resumes[index].age = 25; // Example age
    strcpy(resumes[index].skills, "C, Java, Python"); // Example skills
    pthread_mutex_unlock(&mutex); // Unlock the mutex after modifying the resumes array

    printf("Resume #%d parsed and stored.\n", index+1);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int indexes[MAX_RESUMES];

    // Creating threads to parse resumes
    for (int i = 0; i < MAX_THREADS; i++) {
        for (int j = i*(MAX_RESUMES/MAX_THREADS); j < (i+1)*(MAX_RESUMES/MAX_THREADS); j++) {
            indexes[j] = j;
            if (pthread_create(&threads[i], NULL, parseResume, (void *)&indexes[j])) {
                printf("Error creating thread #%d.\n", i+1);
                return -1;
            }
        }
    }

    // Waiting for all threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(threads[i], NULL)) {
            printf("Error joining thread #%d.\n", i+1);
            return -1;
        }
    }

    // Printing all parsed resumes
    for (int i = 0; i < MAX_RESUMES; i++) {
        printf("\nResume #%d\n", i+1);
        printf("Name: %s\n", resumes[i].name);
        printf("Age: %d\n", resumes[i].age);
        printf("Skills: %s\n", resumes[i].skills);
    }

    return 0;
}