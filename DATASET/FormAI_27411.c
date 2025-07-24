//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_URL_LENGTH 500
#define MAX_THREADS 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void sanitize_url(char *url) {
    // Remove any leading or trailing white space characters
    int i = 0;
    while (url[i] == ' ') {
        i++;
    }
    if (i != 0) {
        memmove(url, url + i, strlen(url) - i + 1);
    }
    i = strlen(url) - 1;
    while (i >= 0 && url[i] == ' ') {
        url[i] = '\0';
        i--;
    }
    // Remove any query string parameters
    char *question_mark = strchr(url, '?');
    if (question_mark != NULL) {
        *question_mark = '\0';
    }
    // Remove any fragments
    char *hash_symbol = strchr(url, '#');
    if (hash_symbol != NULL) {
        *hash_symbol = '\0';
    }
}

void *sanitize_url_thread(void *arg) {
    char url[MAX_URL_LENGTH];
    strcpy(url, (char *) arg);
    sanitize_url(url);
    pthread_mutex_lock(&mutex);
    printf("Sanitized URL: %s\n", url);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
    char urls[][MAX_URL_LENGTH] = {
        "   https://www.example.com/?ref=123#header   ",
        "http://www.example.com/path/to/page.html",
        "https://www.example.com/path/to/page.html?query=string#footer",
        " ftp://www.example.com/path/to/file.txt",
        " ftps://www.example.com/path/to/file.txt",
        " http://www.example.com/path/to/file.exe#malware"
    };
    pthread_t threads[MAX_THREADS];
    int num_threads = sizeof(urls) / sizeof(urls[0]);
    if (num_threads > MAX_THREADS) {
        num_threads = MAX_THREADS;
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, sanitize_url_thread, urls[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}