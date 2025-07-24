//FormAI DATASET v1.0 Category: Digital Diary ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ENTRIES 1000

typedef struct {
    int year;
    int month;
    int day;
    char* entry;
} DiaryEntry;

typedef struct {
    DiaryEntry entries[MAX_ENTRIES];
    int count;
    pthread_mutex_t mutex;
} DigitalDiary;

void* add_entry(void* diary_ptr) {
    DigitalDiary* diary = (DigitalDiary*) diary_ptr;
    DiaryEntry new_entry;
    new_entry.year = 2021;
    new_entry.month = 7;
    new_entry.day = 25;
    new_entry.entry = "Today was a great day!";

    pthread_mutex_lock(&diary->mutex);

    if (diary->count < MAX_ENTRIES) {
        diary->entries[diary->count] = new_entry;
        diary->count++;
    }

    pthread_mutex_unlock(&diary->mutex);

    return NULL;
}

void* print_entries(void* diary_ptr) {
    DigitalDiary* diary = (DigitalDiary*) diary_ptr;

    pthread_mutex_lock(&diary->mutex);

    for (int i = 0; i < diary->count; i++) {
        printf("%d/%d/%d: %s\n", diary->entries[i].month, diary->entries[i].day, diary->entries[i].year,
               diary->entries[i].entry);
    }

    pthread_mutex_unlock(&diary->mutex);

    return NULL;
}

int main() {
    DigitalDiary diary;
    diary.count = 0;

    pthread_mutex_init(&diary.mutex, NULL);

    pthread_t add_thread;
    pthread_t print_thread;

    pthread_create(&add_thread, NULL, add_entry, (void*) &diary);
    pthread_create(&print_thread, NULL, print_entries, (void*) &diary);

    pthread_join(add_thread, NULL);
    pthread_join(print_thread, NULL);

    pthread_mutex_destroy(&diary.mutex);

    return 0;
}