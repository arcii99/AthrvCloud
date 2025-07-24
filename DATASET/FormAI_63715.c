//FormAI DATASET v1.0 Category: Browser Plugin ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>
#include <pthread.h>

bool is_valid_url(const char* url) {
    /* Your implementation here */
}

void* fetch_url(void* url_ptr) {
    /* Your implementation here */
}

void* parse_html(void* html_ptr) {
    /* Your implementation here */
}

void* filter_links(void* links_ptr) {
    /* Your implementation here */
}

void plugin_main(const char* url) {
    if (!is_valid_url(url)) {
        printf("Invalid URL: %s\n", url);
        return;
    }

    pthread_t fetch_thread;
    int rc = pthread_create(&fetch_thread, NULL, fetch_url, (void*) url);
    if (rc) {
        printf("Error: Could not create fetch thread.\n");
        return;
    }

    pthread_t parse_thread;
    rc = pthread_create(&parse_thread, NULL, parse_html, NULL);
    if (rc) {
        printf("Error: Could not create parse thread.\n");
        return;
    }

    pthread_t filter_thread;
    rc = pthread_create(&filter_thread, NULL, filter_links, NULL);
    if (rc) {
        printf("Error: Could not create filter thread.\n");
        return;
    }

    /* Wait for all threads to finish */
    pthread_join(fetch_thread, NULL);
    pthread_join(parse_thread, NULL);
    pthread_join(filter_thread, NULL);
}

/* Example usage */
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [url]\n", argv[0]);
        return 1;
    }

    plugin_main(argv[1]);
    return 0;
}