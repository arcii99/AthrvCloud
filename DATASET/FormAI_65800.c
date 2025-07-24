//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_MESSAGES 1000
#define MAX_LEN 1024

char spam_words[][MAX_LEN] = {"free", "win", "prize", "giveaway"};

struct message {
    int id;
    char text[MAX_LEN];
    int is_spam;
};

struct message_queue {
    struct message messages[MAX_MESSAGES];
    int front;
    int rear;
    int size;
};

struct message_queue queue;

pthread_mutex_t mutex;
pthread_cond_t cond;

void enqueue_message(struct message msg) {
    pthread_mutex_lock(&mutex);

    while (queue.size >= MAX_MESSAGES) {
        pthread_cond_wait(&cond, &mutex);
    }

    queue.messages[queue.rear] = msg;
    queue.rear = (queue.rear + 1) % MAX_MESSAGES;
    queue.size++;

    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
}

struct message dequeue_message() {
    pthread_mutex_lock(&mutex);

    while (queue.size <= 0) {
        pthread_cond_wait(&cond, &mutex);
    }

    struct message msg = queue.messages[queue.front];
    queue.front = (queue.front + 1) % MAX_MESSAGES;
    queue.size--;

    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);

    return msg;
}

void* detect_spam(void* arg) {
    struct message msg;
    while (1) {
        msg = dequeue_message();
        int i;
        for (i = 0; i < sizeof(spam_words) / sizeof(spam_words[0]); i++) {
            if (strstr(msg.text, spam_words[i])) {
                msg.is_spam = 1;
                break;
            }
        }
        printf("[Thread %ld] Message %d: %s\n", pthread_self(), msg.id, msg.text);
        if (msg.is_spam) {
            printf("[Thread %ld] Detected as spam!\n", pthread_self());
        }
    }
    pthread_exit(NULL);
}

int main() {
    queue.front = 0;
    queue.rear = 0;
    queue.size = 0;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_t threads[4];
    int i;
    for (i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, detect_spam, NULL);
    }

    char input[MAX_LEN];
    int count = 0;
    while (fgets(input, MAX_LEN, stdin) != NULL) {
        struct message msg;
        msg.id = count++;
        strcpy(msg.text, input);
        msg.is_spam = 0;
        enqueue_message(msg);
    }

    for (i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}