//FormAI DATASET v1.0 Category: Phone Book ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ENTRIES 100

struct contact {
    char name[20];
    char phone[15];
};

struct phone_book {
    struct contact entries[MAX_ENTRIES];
    int num_entries;
    pthread_mutex_t lock;
};

struct phone_book my_phone_book;

void *add_contact(void *arg) {
    pthread_mutex_lock(&my_phone_book.lock);
    if (my_phone_book.num_entries >= MAX_ENTRIES) {
        fprintf(stderr, "Phone book is full!\n");
        pthread_mutex_unlock(&my_phone_book.lock);
        return NULL;
    }
    struct contact *new_contact = (struct contact *) arg;
    my_phone_book.entries[my_phone_book.num_entries++] = *new_contact;
    pthread_mutex_unlock(&my_phone_book.lock);
    printf("Added contact: %s, %s\n", new_contact->name, new_contact->phone);
    return NULL;
}

void *search_contact(void *arg) {
    pthread_mutex_lock(&my_phone_book.lock);
    char *name_to_search = (char *) arg;
    int i;
    for (i = 0; i < my_phone_book.num_entries; i++) {
        if (strcmp(my_phone_book.entries[i].name, name_to_search) == 0) {
            printf("Found matching contact: %s, %s\n", my_phone_book.entries[i].name, my_phone_book.entries[i].phone);
            break;
        }
    }
    if (i == my_phone_book.num_entries) {
        printf("No matching contact found for %s\n", name_to_search);
    }
    pthread_mutex_unlock(&my_phone_book.lock);
    return NULL;
}

int main() {
    my_phone_book.num_entries = 0;
    pthread_mutex_init(&my_phone_book.lock, NULL);

    pthread_t add_thread, search_thread;

    struct contact new_contact = {"John", "123-456-7890"};
    pthread_create(&add_thread, NULL, add_contact, &new_contact);

    struct contact new_contact2 = {"Jane", "987-654-3210"};
    pthread_create(&add_thread, NULL, add_contact, &new_contact2);

    char *name_to_search = "John";
    pthread_create(&search_thread, NULL, search_contact, (void *) name_to_search);

    pthread_join(add_thread, NULL);
    pthread_join(search_thread, NULL);

    pthread_mutex_destroy(&my_phone_book.lock);

    return 0;
}