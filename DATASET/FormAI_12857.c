//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define BAGGAGE_COUNT 10
#define BELT_CAPACITY 5
#define LOADER_COUNT 2
#define UNLOADER_COUNT 1

pthread_mutex_t mutex_belt, mutex_cart, mutex_loader, mutex_unloader;
pthread_cond_t cv_belt_load, cv_cart_upload, cv_cart_unload;
int cart_current_bags, total_processed_bags;
bool is_belt_empty = true;
bool is_loader_free = true;
bool is_unloader_free = true;

void *loader_thread(void *args) {
    while (true) {
        sleep(1);
        pthread_mutex_lock(&mutex_loader);
        if (is_belt_empty && is_loader_free) {
            is_loader_free = false;
            printf("Loader %d is loading the belt.\n", *(int *)args);
            pthread_cond_signal(&cv_belt_load);
        }
        pthread_mutex_unlock(&mutex_loader);
    }
}

void *belt_thread() {
    int baggage_on_belt = 0;
    while (total_processed_bags < BAGGAGE_COUNT) {
        pthread_mutex_lock(&mutex_belt);
        while (baggage_on_belt >= BELT_CAPACITY || !is_loader_free)
            pthread_cond_wait(&cv_belt_load, &mutex_belt);
        is_belt_empty = false;
        baggage_on_belt++;
        printf("Baggage loaded on belt: %d \n", baggage_on_belt);
        pthread_mutex_unlock(&mutex_belt);

        pthread_mutex_lock(&mutex_cart);
        while (cart_current_bags > 0)
            pthread_cond_wait(&cv_cart_upload, &mutex_cart);
        cart_current_bags = baggage_on_belt;
        baggage_on_belt = 0;
        printf("Bags on cart: %d \n", cart_current_bags);
        pthread_cond_signal(&cv_cart_unload);
        pthread_mutex_unlock(&mutex_cart);
    }
}

void *unloader_thread() {
    while (total_processed_bags < BAGGAGE_COUNT) {
        pthread_mutex_lock(&mutex_cart);
        while (cart_current_bags <= 0)
            pthread_cond_wait(&cv_cart_unload, &mutex_cart);
        printf("Unloader is unloading the cart.\n");
        cart_current_bags = 0;
        total_processed_bags += cart_current_bags;
        pthread_mutex_unlock(&mutex_cart);
        pthread_cond_signal(&cv_cart_upload);
    }
}

int main() {
    pthread_t loaders[LOADER_COUNT], belt, unloader;
    int loader_args[LOADER_COUNT];

    pthread_mutex_init(&mutex_belt, NULL);
    pthread_mutex_init(&mutex_cart, NULL);
    pthread_mutex_init(&mutex_loader, NULL);
    pthread_mutex_init(&mutex_unloader, NULL);
    pthread_cond_init(&cv_belt_load, NULL);
    pthread_cond_init(&cv_cart_upload, NULL);
    pthread_cond_init(&cv_cart_unload, NULL);

    for (int i = 0; i < LOADER_COUNT; i++) {
        loader_args[i] = i + 1;
        pthread_create(&loaders[i], NULL, loader_thread, &loader_args[i]);
    }

    pthread_create(&belt, NULL, belt_thread, NULL);

    pthread_create(&unloader, NULL, unloader_thread, NULL);

    for (int i = 0; i < LOADER_COUNT; i++) {
        pthread_join(loaders[i], NULL);
    }

    pthread_join(belt, NULL);

    pthread_join(unloader, NULL);
}