//FormAI DATASET v1.0 Category: Email Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_BUFFER_SIZE 1024

// Function Definitions
static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
void send_email(char *to, char *from, char *subject, char *body);

// Main Function
int main()
{
    char to[MAX_BUFFER_SIZE], from[MAX_BUFFER_SIZE], subject[MAX_BUFFER_SIZE], body[MAX_BUFFER_SIZE];

    printf("Enter the recipient email address: ");
    fgets(to, MAX_BUFFER_SIZE, stdin);

    printf("Enter the sender email address: ");
    fgets(from, MAX_BUFFER_SIZE, stdin);

    printf("Enter the email subject: ");
    fgets(subject, MAX_BUFFER_SIZE, stdin);

    printf("Enter the email body: ");
    fgets(body, MAX_BUFFER_SIZE, stdin);

    send_email(to, from, subject, body);

    return 0;
}

// Sends the email using SMTP protocol
void send_email(char *to, char *from, char *subject, char *body)
{
    CURL *curl;
    CURLcode res = CURLE_OK;

    struct curl_slist* list = NULL;

    char payload[MAX_BUFFER_SIZE];
    char buffer[MAX_BUFFER_SIZE];

    // Create and initialize the cURL handle
    curl = curl_easy_init();
    if (curl)
    {
        snprintf(buffer, sizeof(buffer), "To: %s", to);
        list = curl_slist_append(list, buffer);

        snprintf(buffer, sizeof(buffer), "From: %s", from);
        list = curl_slist_append(list, buffer);

        snprintf(buffer, sizeof(buffer), "Subject: %s", subject);
        list = curl_slist_append(list, buffer);

        snprintf(buffer, sizeof(buffer), "%s\n", body);
        list = curl_slist_append(list, buffer);

        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.example.com:587");
        curl_easy_setopt(curl, CURLOPT_USERNAME, "email@example.com");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "password");
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, list);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        snprintf(payload, sizeof(payload), "%s\n%s\n%s\n%s\n", to, from, subject, body);

        curl_easy_setopt(curl, CURLOPT_READDATA, payload);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            printf("Error sending email: %s\n", curl_easy_strerror(res));
        }

        curl_slist_free_all(list);
        curl_easy_cleanup(curl);
    }
}

// Callback function for writing data
static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    return size * nmemb;
}