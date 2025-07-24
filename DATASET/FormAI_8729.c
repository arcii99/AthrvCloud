//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: scalable
#include<stdio.h>
#include<curl/curl.h>
#include<stdlib.h>
#include<string.h>

struct MemoryStruct {
  char *memory;
  size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *) userp;

  mem->memory = realloc(mem->memory, mem->size + realsize + 1);
  if (mem->memory == NULL) {
    printf("Not enough memory (realloc returned NULL)\n");
    return 0;
  }

  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = '\0';

  return realsize;
}

int main(void) {
  CURL *curl_handle;
  CURLcode res;
  struct MemoryStruct chunk;

  chunk.memory = malloc(1);
  chunk.size = 0;

  curl_global_init(CURL_GLOBAL_ALL);
  curl_handle = curl_easy_init();

  if (curl_handle) {
    char username[50];
    char password[50];
    char url[200];
    printf("Enter username:\n");
    fgets(username, 50, stdin);
    printf("Enter password:\n");
    fgets(password, 50, stdin);
    printf("Enter url (excluding imap://):\n");
    fgets(url, 200, stdin);

    char final_url[250];
    sprintf(final_url, "imap://%s:%s@%s", username, password, url);

    curl_easy_setopt(curl_handle, CURLOPT_USERNAME, username);
    curl_easy_setopt(curl_handle, CURLOPT_PASSWORD, password);

    curl_easy_setopt(curl_handle, CURLOPT_URL, final_url);

    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

    curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);

    res = curl_easy_perform(curl_handle);
    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    } else {
      printf("%lu bytes retrieved\n", (unsigned long) chunk.size);
      printf("Response: %s\n", chunk.memory);
    }

    curl_easy_cleanup(curl_handle);
  }

  if (chunk.memory) {
    free(chunk.memory);
  }
  curl_global_cleanup();

  return 0;
}