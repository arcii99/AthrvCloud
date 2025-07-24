//FormAI DATASET v1.0 Category: Browser Plugin ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/*
 * This is a simple C browser plugin that will count the number of times a user visits a webpage and
 * display the count on the page.
 * It works by accessing and modifying cookies on the user's computer.
 * When the plugin is first installed, it creates a cookie with a count of 1.
 * Each time the user visits the page, the plugin retrieves the cookie, increments the count, and saves the updated cookie.
 * The count is then displayed on the page.
 */

// Constants
#define COOKIE_NAME "visit_count"
#define COOKIE_EXPIRATION "Expires=Tue, 31 Dec 2030 23:59:59 GMT"
#define MAX_COOKIE_SIZE 100
#define MAX_COUNT_SIZE 10
#define PAGE_HEADER "<html><head><title>Visit Count</title></head><body>"
#define PAGE_FOOTER "</body></html>"

// Function prototypes
char *get_cookie_value(char *);
void set_cookie_value(char *, char *);
void increment_visit_count(char *);
void generate_page_html(char *, int);

int main(int argc, char *argv[]) {
    // Get the URL of the page the user is visiting
    char *url = argv[1];

    // Check if there is a cookie with the visit count
    char *cookie_value = get_cookie_value(COOKIE_NAME);

    if (cookie_value == NULL) {
        // First visit, set the cookie value to 1
        set_cookie_value(COOKIE_NAME, "1");

        // Display the count on the page
        generate_page_html(url, 1);
    } else {
        // Increment the visit count
        increment_visit_count(COOKIE_NAME);

        // Display the count on the page
        int count = atoi(cookie_value) + 1;
        generate_page_html(url, count);
    }

    return 0;
}

/*
 * Retrieves the value of a cookie with the specified name.
 * Returns NULL if the cookie does not exist.
 */
char *get_cookie_value(char *name) {
    char *cookie_header = getenv("HTTP_COOKIE");

    if (cookie_header == NULL) {
        return NULL;
    }

    char *cookie_start = strstr(cookie_header, name);

    if (cookie_start == NULL) {
        return NULL;
    }

    cookie_start += strlen(name) + 1;
    char *cookie_end = strchr(cookie_start, ';');

    if (cookie_end == NULL) {
        cookie_end = cookie_header + strlen(cookie_header);
    }

    int cookie_length = cookie_end - cookie_start;
    char *cookie_value = (char *)malloc(cookie_length + 1);
    strncpy(cookie_value, cookie_start, cookie_length);
    cookie_value[cookie_length] = '\0';

    return cookie_value;
}

/*
 * Sets the value of a cookie with the specified name.
 */
void set_cookie_value(char *name, char *value) {
    char cookie[MAX_COOKIE_SIZE];
    snprintf(cookie, sizeof(cookie), "Set-Cookie: %s=%s; %s", name, value, COOKIE_EXPIRATION);
    printf("%s\n", cookie);
}

/*
 * Increments the value of a cookie with the specified name.
 */
void increment_visit_count(char *name) {
    char *cookie_value = get_cookie_value(name);
    int count = atoi(cookie_value) + 1;
    char count_str[MAX_COUNT_SIZE];
    snprintf(count_str, sizeof(count_str), "%d", count);
    set_cookie_value(name, count_str);
}

/*
 * Generates HTML for the page with the visit count displayed.
 */
void generate_page_html(char *url, int count) {
    printf("Content-Type: text/html\n\n");
    printf("%s<p>You have visited %s %d times.</p>%s", PAGE_HEADER, url, count, PAGE_FOOTER);
}