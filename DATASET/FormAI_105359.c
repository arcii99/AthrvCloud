//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_NAME_LEN 50
#define MAX_SKILLS_LEN 100

typedef struct{
    char name[MAX_NAME_LEN];
    char skills[MAX_SKILLS_LEN];
} Resume;

void* parse_resume(void* resume){
    Resume* r = (Resume*)resume;
    printf("Parsing resume for %s\n", r->name);
    sleep(2); // Simulating parsing delay
    printf("Skills extracted: %s\n", r->skills);

    pthread_exit(NULL);
}

int main(){
    Resume resumes[3] = {{"John Smith", "C++, Python, Java"},
                         {"Sarah Johnson", "JavaScript, HTML, CSS, React"},
                         {"Mark Brown", "Ruby, PHP, SQL"}};

    pthread_t threads[3];
    int rc;

    for(int i=0; i<3; i++){
        rc = pthread_create(&threads[i], NULL, parse_resume, (void*)&resumes[i]);
        if(rc){
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(1);
        }
    }

    for(int i=0; i<3; i++){
        rc = pthread_join(threads[i], NULL);
        if(rc){
            printf("Error: return code from pthread_join() is %d\n", rc);
            exit(1);
        }
    }

    pthread_exit(NULL);
}