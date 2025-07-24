//FormAI DATASET v1.0 Category: Digital Diary ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ENTRIES 50
#define MAX_CHAR 100

typedef struct entry {
    char date[20];
    char time[10];
    char content[MAX_CHAR];
} Entry;

Entry diary[MAX_ENTRIES];
int count = 0;

pthread_mutex_t mutex;

void *write_entry(void *arg) {
    char entry[MAX_CHAR];
    printf("Enter the diary entry:\n");
    fgets(entry, MAX_CHAR, stdin);

    pthread_mutex_lock(&mutex);

    if (count < MAX_ENTRIES) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        snprintf(diary[count].date, 20, "%d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
        snprintf(diary[count].time, 10, "%02d:%02d:%02d", t->tm_hour, t->tm_min, t->tm_sec);
        strncpy(diary[count].content, entry, strlen(entry) - 1);
        count++;
    } else {
        printf("Diary is full. Cannot add more entries.\n");
    }

    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *read_diary(void *arg) {
    pthread_mutex_lock(&mutex);

    if (count == 0) {
        printf("Diary is empty.\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("[%s %s] %s\n", diary[i].date, diary[i].time, diary[i].content);
        }
    }

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);

    pthread_t thread1, thread2;
    int thread1_status, thread2_status;

    thread1_status = pthread_create(&thread1, NULL, write_entry, NULL);
    if (thread1_status < 0) {
        fprintf(stderr, "Error creating thread 1\n");
        exit(1);
    }

    thread2_status = pthread_create(&thread2, NULL, read_diary, NULL);
    if (thread2_status < 0) {
        fprintf(stderr, "Error creating thread 2\n");
        exit(1);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}