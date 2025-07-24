//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_RESUMES 1000

typedef struct {
    char* name;
    char* email;
    char* phone;
    char* address;
    char** skills;
} Resume;

typedef struct {
    Resume* resumes[MAX_RESUMES];
    int num_resumes;
} ResumeRepo;

void parse_resume(char* resume_text, Resume* resume) {
    // parse resume text and fill in resume object fields
}

void* parse_thread_func(void* args) {
    char* resume_text = (char*)args;
    Resume* resume = malloc(sizeof(Resume));
    parse_resume(resume_text, resume);
    return (void*)resume;
}

bool add_resume(ResumeRepo* repo, char* resume_text) {
    if (repo->num_resumes >= MAX_RESUMES) {
        fprintf(stderr, "Error: ResumeRepo is full\n");
        return false;
    }
    pthread_t parse_thread;
    if (pthread_create(&parse_thread, NULL, parse_thread_func, resume_text) != 0) {
        fprintf(stderr, "Error: failed to create parse thread\n");
        return false;
    }
    void* thread_return;
    if (pthread_join(parse_thread, &thread_return) != 0) {
        fprintf(stderr, "Error: failed to join parse thread\n");
        return false;
    }
    repo->resumes[repo->num_resumes] = (Resume*)thread_return;
    repo->num_resumes++;
    return true;
}

int main() {
    ResumeRepo repo = { .num_resumes = 0 };
    char* resume_text1 = "John Doe\njohndoe@email.com\n555-555-5555\n123 Main St.";
    char* resume_text2 = "Jane Smith\njanesmith@email.com\n444-444-4444\n456 Oak Ave.";
    add_resume(&repo, resume_text1);
    add_resume(&repo, resume_text2);
    for (int i = 0; i < repo.num_resumes; i++) {
        printf("Name: %s\n", repo.resumes[i]->name);
        printf("Email: %s\n", repo.resumes[i]->email);
        printf("Phone: %s\n", repo.resumes[i]->phone);
        printf("Address: %s\n", repo.resumes[i]->address);
        printf("Skills:\n");
        for (int j = 0; repo.resumes[i]->skills[j] != NULL; j++) {
            printf("%s\n", repo.resumes[i]->skills[j]);
        }
        printf("\n");
    }
    return 0;
}