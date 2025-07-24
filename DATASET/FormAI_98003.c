//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>

#define BUFFER_SIZE 2048
#define MAX_MESSAGES 20

struct MemoryStruct {
    char *memory;
    size_t size;
};

// callback function to write received data into memory
static size_t writeMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realSize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *) userp;
    char *ptr = realloc(mem->memory, mem->size + realSize + 1);
    if (ptr == NULL) {
        fprintf(stderr, "Error: insufficient memory");
        return 0;
    }
    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realSize);
    mem->size += realSize;
    mem->memory[mem->size] = '\0';
    return realSize;
}

// function to list messages from mailbox
int listMessages(CURL *curl, const char *mailbox) {
    int returnCode = 0;
    char buffer[BUFFER_SIZE];
    struct MemoryStruct chunk;
    chunk.memory = NULL;
    chunk.size = 0;

    // set options for IMAP command
    snprintf(buffer, BUFFER_SIZE, "LIST \"%s\" *", mailbox);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, buffer);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);

    // execute IMAP command
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
        returnCode = 1;
    } else {
        // parse response for mailbox contents
        char *line = strtok(chunk.memory, "\r\n");
        printf("Messages in %s:\n", mailbox);
        while (line != NULL) {
            if (strstr(line, "EXISTS") != NULL) {
                printf("%s\n", line);
            }
            line = strtok(NULL, "\r\n");
        }
        returnCode = 0;
    }
    free(chunk.memory);
    return returnCode;
}

// function to read message contents for given message number
int readMessage(CURL *curl, const char *mailbox, int messageNum) {
    int returnCode = 0;
    char buffer[BUFFER_SIZE];
    struct MemoryStruct chunk;
    chunk.memory = NULL;
    chunk.size = 0;

    // set options for IMAP command
    snprintf(buffer, BUFFER_SIZE, "FETCH %d (BODY[TEXT])", messageNum);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, buffer);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);

    // execute IMAP command
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
        returnCode = 1;
    } else {
        printf("Message %d from %s:\n%s", messageNum, mailbox, chunk.memory);
        returnCode = 0;
    }
    free(chunk.memory);
    return returnCode;
}

int main(void) {
    CURL *curl;
    CURLcode res;

    // initialize CURL library
    res = curl_global_init(CURL_GLOBAL_ALL);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
        return EXIT_FAILURE;
    }

    // set options for CURL session
    curl = curl_easy_init();
    if (curl) {
        // replace user and password with valid credentials
        curl_easy_setopt(curl, CURLOPT_USERNAME, "user");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "password");
        curl_easy_setopt(curl, CURLOPT_URL, "imaps://imap.gmail.com:993/INBOX");
        // set command to select mailbox
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "SELECT INBOX");
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
        } else {
            // list top messages in mailbox
            if (listMessages(curl, "INBOX") == 0) {
                // read first 5 messages
                for (int i = 1; i <= MAX_MESSAGES; i++) {
                    if (readMessage(curl, "INBOX", i) != 0) {
                        fprintf(stderr, "Error: unable to read message %d\n", i);
                        break;
                    }
                }
            } else {
                fprintf(stderr, "Error: unable to list messages\n");
            }
        }
        // cleanup CURL session
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Error: unable to initialize CURL session\n");
        return EXIT_FAILURE;
    }

    // cleanup CURL library
    curl_global_cleanup();

    return EXIT_SUCCESS;
}