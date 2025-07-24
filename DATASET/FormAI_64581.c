//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URLS 10
#define INTERVAL_SEC 10

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, void *data)
{
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)data;

    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if(mem->memory == NULL)
        return 0;

    memcpy(&(mem->memory[mem->size]), ptr, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = '\0';

    return realsize;
}

int main(void)
{
    CURL *curl_handle = NULL;
    CURLcode res;
    struct MemoryStruct chunk;

    char *urls[MAX_URLS] = {"www.google.com", "www.facebook.com", "www.apple.com", "www.amazon.com", "www.microsoft.com",
                            "www.twitter.com", "www.linkedin.com", "www.instagram.com", "www.youtube.com", "www.netflix.com"};

    int i;
    for(i=0; i<MAX_URLS; i++) {
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl_handle = curl_easy_init();
        if(curl_handle) {
            chunk.memory = malloc(1);
            chunk.size = 0;

            curl_easy_setopt(curl_handle, CURLOPT_URL, urls[i]);
            curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
            curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

            res = curl_easy_perform(curl_handle);
            if(res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
                curl_easy_cleanup(curl_handle);
                free(chunk.memory);
                exit(EXIT_FAILURE);
            }

            printf("%s - %lu bytes retrieved\n", urls[i], (unsigned long)chunk.size);

            curl_easy_cleanup(curl_handle);
            free(chunk.memory);
        }
        curl_global_cleanup();

        sleep(INTERVAL_SEC);
    }

  return 0;
}