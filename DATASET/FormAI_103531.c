//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: inquisitive
#include <curl/curl.h>
#include <stdio.h>
#include <string.h>

int main()
{
    CURL *curl;
    CURLcode res;
    char *username = "your_email@example.com";
    char *password = "your_email_password";
    char *server = "imap.example.com";
    int port = 993;

    curl = curl_easy_init();
    if (curl)
    {
        /* Set username and password */
        curl_easy_setopt(curl, CURLOPT_USERNAME, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);

        /* Set the server URL */
        char url[128];
        snprintf(url, sizeof(url), "imaps://%s:%d", server, port);
        curl_easy_setopt(curl, CURLOPT_URL, url);

        /* Set security options */
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);

        /* Send the IMAP login request */
        char cmd[128];
        snprintf(cmd, sizeof(cmd), "LOGIN %s %s\r\n", username, password);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, cmd);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        /* Send the IMAP select mailbox request */
        snprintf(cmd, sizeof(cmd), "SELECT INBOX\r\n");
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, cmd);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        /* Send the IMAP fetch request */
        snprintf(cmd, sizeof(cmd), "FETCH 1:* (UID BODY[HEADER.FIELDS (SUBJECT FROM DATE)])\r\n");
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, cmd);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        /* Cleanup */
        curl_easy_cleanup(curl);
    }

    return 0;
}