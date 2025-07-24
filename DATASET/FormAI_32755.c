//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Struct to store email details
struct email_details {
    char *from;
    char *subject;
    char *date;
};

// Callback function to handle email data
static size_t handle_imap_email_data(void *ptr, size_t size, size_t nmemb, void *userdata) {
    int i, j;
    char *full_email = (char *) ptr;

    // Create email_details struct
    struct email_details *email = (struct email_details *) malloc(sizeof(struct email_details));
    email->from = NULL;
    email->subject = NULL;
    email->date = NULL;

    // Parse email details
    char *start_of_email = strstr(full_email, "From:");
    char *end_of_email = strstr(full_email, "\r\n\r\n");

    // Parse email from
    email->from = (char *) malloc(sizeof(char) * 100);
    i = 0;
    j = 6;
    while (start_of_email[j] != '<') {
        email->from[i] = start_of_email[j];
        i++;
        j++;
    }
    email->from[i - 1] = '\0';

    // Parse email subject
    email->subject = (char *) malloc(sizeof(char) * 100);
    start_of_email = strstr(start_of_email, "Subject:");
    i = 0;
    j = 9;
    while (start_of_email[j] != '\r') {
        email->subject[i] = start_of_email[j];
        i++;
        j++;
    }
    email->subject[i] = '\0';

    // Parse email date
    email->date = (char *) malloc(sizeof(char) * 100);
    start_of_email = strstr(start_of_email, "Date:");
    i = 0;
    j = 6;
    while (start_of_email[j] != '\r') {
        email->date[i] = start_of_email[j];
        i++;
        j++;
    }
    email->date[i] = '\0';

    // Print email details
    printf("From: %s\n", email->from);
    printf("Subject: %s\n", email->subject);
    printf("Date: %s\n", email->date);

    // Cleanup email_details struct
    free(email->from);
    free(email->subject);
    free(email->date);
    free(email);

    return size * nmemb;
}

// Main function
int main(int argc, char *argv[]) {
    // Check for command line arguments
    if (argc != 4) {
        printf("Please provide a valid IMAP server, email address, and password.\n");
        return 1;
    }

    // Set variables for email server, address, and password
    char *server = argv[1];
    char *email_address = argv[2];
    char *password = argv[3];

    // Initialize cURL
    CURL *curl_handle = curl_easy_init();
    if (!curl_handle) {
        printf("Error initializing cURL.\n");
        return 1;
    }

    // Set options for cURL handle
    char url[100];
    sprintf(url, "imap://%s/INBOX", server);
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_USERNAME, email_address);
    curl_easy_setopt(curl_handle, CURLOPT_PASSWORD, password);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, stdout);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, handle_imap_email_data);

    // Perform cURL request and cleanup cURL handle
    CURLcode res = curl_easy_perform(curl_handle);
    curl_easy_cleanup(curl_handle);

    return 0;
}