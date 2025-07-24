//FormAI DATASET v1.0 Category: Phone Book ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 15

struct contact {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
};

struct phone_book {
    struct contact contacts[MAX_CONTACTS];
    int num_contacts;
};

struct phone_book my_phone_book;
pthread_mutex_t lock;

void add_contact(char* name, char* number) {
    pthread_mutex_lock(&lock);
    if (my_phone_book.num_contacts == MAX_CONTACTS) {
        printf("Phone book full\n");
    } else {
        struct contact new_contact;
        strcpy(new_contact.name, name);
        strcpy(new_contact.number, number);
        my_phone_book.contacts[my_phone_book.num_contacts] = new_contact;
        my_phone_book.num_contacts++;
        printf("Added %s with number %s\n", name, number);
    }
    pthread_mutex_unlock(&lock);
}

void* thread_func(void* arg) {
    printf("Thread added new contact\n");
    add_contact("John Smith", "123-456-7890");
    return NULL;
}

int main() {
    my_phone_book.num_contacts = 0;
    pthread_t tid;
    pthread_mutex_init(&lock, NULL);
    int i;
    for (i = 0; i < 10; i++) {
        pthread_create(&tid, NULL, thread_func, NULL);
        pthread_join(tid, NULL);
    }
    pthread_mutex_destroy(&lock);
    return 0;
}