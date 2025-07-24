//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_RESUMES 10000
#define MAX_THREADS 50

struct Resume {
    char* name;
    char* email;
    char* skills;
};

struct Resume resumes[MAX_RESUMES];
int num_resumes = 0;

pthread_mutex_t resume_mutex = PTHREAD_MUTEX_INITIALIZER;

void* parse_resume(void* arg) {
    int* thread_num = (int*) arg;
    int i;
    for (i = *thread_num; i < num_resumes; i += MAX_THREADS) {
        pthread_mutex_lock(&resume_mutex);
        struct Resume r = resumes[i];
        pthread_mutex_unlock(&resume_mutex);
        
        // Do parsing of resume fields here
        
        printf("Resume parsed by Thread %d: Name=%s, Email=%s, Skills=%s\n", *thread_num, r.name, r.email, r.skills);
    }
    return NULL;
}

int main() {
    // Read resumes from file into resumes array
    // ...

    num_resumes = MAX_RESUMES;

    pthread_t threads[MAX_THREADS];
    int thread_nums[MAX_THREADS];
    int i;

    for (i = 0; i < MAX_THREADS; i++) {
        thread_nums[i] = i;
        pthread_create(&threads[i], NULL, parse_resume, &thread_nums[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}