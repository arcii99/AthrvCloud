//FormAI DATASET v1.0 Category: File handling ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

void* writeToFile(void* arg);
void* readFromFile(void* arg);

int main() {
    pthread_t writer, reader;
    int num = 10;
    char file_name[] = "data.txt";
    
    pthread_create(&writer, NULL, writeToFile, (void*)file_name);
    pthread_create(&reader, NULL, readFromFile, (void*)&num);
    
    pthread_join(writer, NULL);
    pthread_join(reader, NULL);
    
    return 0;
}

void* writeToFile(void* arg) {
    FILE* fp;
    char* file_name = (char*)arg;
    
    fp = fopen(file_name, "w");
    
    if (fp == NULL) {
        printf("Error opening file.");
        pthread_exit(NULL);
    }
    
    char* line1 = "This is line 1.";
    char* line2 = "This is line 2.";
    char* line3 = "This is line 3.";
    
    fputs(line1, fp);
    fputs(line2, fp);
    fputs(line3, fp);
    
    fclose(fp);
    pthread_exit(NULL);
}

void* readFromFile(void* arg) {
    int* num = (int*)arg;
    FILE* fp;
    char* file_name = "data.txt";
    char line[100];
    
    fp = fopen(file_name, "r");
    
    if (fp == NULL) {
        printf("Error opening file.");
        pthread_exit(NULL);
    }
    
    for (int i = 0; i < *num; i++) {
        fgets(line, 100, fp);
        printf("%s", line);
    }
    
    fclose(fp);
    pthread_exit(NULL);
}