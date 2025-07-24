//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    char* name;
    int age;
    float score;
} Student;

void* parseXML(void* arg) {
    FILE* fp;
    char buffer[200];
    fp = fopen("students.xml", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(buffer, 200, fp)) {
        printf("%s", buffer);
    }

    fclose(fp);
    pthread_exit(NULL);
}


int main() {

    pthread_t tid;
    int err;

    err = pthread_create(&tid, NULL, &parseXML, NULL);
    if (err != 0) {
        printf("Error creating thread.\n");
        exit(1);
    }
    
    pthread_join(tid, NULL);

    return 0;
}