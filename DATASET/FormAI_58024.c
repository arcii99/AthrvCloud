//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

struct resume {
    char name[50];
    char email[50];
    char skills[100];
    char experience[200];
};

void *parse_resume(void *arg) {
    struct resume *r = (struct resume *) arg;

    // parsing the resume
    // some complex logic for parsing the resume

    // printing the parsed resume
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];
    struct resume resumes[10];

    // assume we have 10 resumes stored in a file
    // read the resumes from the file, and store them in an array of structs

    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, parse_resume, (void *) &resumes[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}