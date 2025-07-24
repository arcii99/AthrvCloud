//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <curl/easy.h>

int main(void)
{
    // initializing variables and structures
    char host[256] = "imap.gmail.com";
    int port = 993;
    char username[256] = "example@gmail.com";
    char password[256] = "example_password";
    char mailbox[256] = "INBOX";
    int verbose = 1;
    CURL *curl;
    CURLcode res;

    //step 1: Initializing cURL library and setting IMAP API URL
    curl = curl_easy_init();
    if (curl) {
        char url[256];
        sprintf(url, "imaps://%s:%d", host, port);
        curl_easy_setopt(curl, CURLOPT_URL, url);
    }

    //step 2: Setting login details
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_USERNAME, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);
    }

    //step 3: Selecting mailbox
    if (curl) {
        char select_mailbox[256];
        sprintf(select_mailbox, "SELECT \"%s\"", mailbox);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, select_mailbox);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, verbose);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "Failed to select mailbox: %s\n", curl_easy_strerror(res));
        }
    }

    //step 4: Fetching email IDs from selected mailbox
    if (curl) {
        char fetch_ids[256] = "SEARCH ALL";
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, fetch_ids);
        /* No data is actually transferred in the presence of this option */
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, verbose);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "Failed to fetch email IDs: %s\n", curl_easy_strerror(res));
        }
    }

    //step 5: Parsing email IDs and fetching email headers and bodies
    if (curl) {
        char fetch_email[256];
        char *id_list_str;
        char *id_token;
        char *remaining_ids;
        long email_count = 0;
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, NULL);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 0L);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, verbose);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &email_count);
        if (email_count) {
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
            id_list_str = strtok_r(remaining_ids, " \n", &remaining_ids);
            while (id_list_str) {
                sprintf(fetch_email, "FETCH %s BODY[] HEADER", id_list_str);
                curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, fetch_email);
                res = curl_easy_perform(curl);
                if (res != CURLE_OK) {
                    fprintf(stderr, "Failed to fetch email headers: %s\n", curl_easy_strerror(res));
                }
                sprintf(fetch_email, "FETCH %s BODY[]", id_list_str);
                curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, fetch_email);
                res = curl_easy_perform(curl);
                if (res != CURLE_OK) {
                    fprintf(stderr, "Failed to fetch email body: %s\n", curl_easy_strerror(res));
                }
                id_list_str = strtok_r(remaining_ids, " \n", &remaining_ids);
            }
        }
    }

    //step 6: Cleanup cURL library
    if (curl) {
        curl_easy_cleanup(curl);
    }

    return 0;
}