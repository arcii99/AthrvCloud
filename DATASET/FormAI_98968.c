//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 10 // number of URLs to monitor
#define INTERVAL 30 // time interval for checking URL

struct URL {
  char* url; // URL to monitor
  int status; // current status of the URL
  pthread_mutex_t mutex; // mutex for accessing status variable
};

void *monitor(void *arg) {
  struct URL *url = arg;
  
  while (1) {
    CURL *curl_handle = curl_easy_init();
    
    if (curl_handle) {
      curl_easy_setopt(curl_handle, CURLOPT_URL, url->url);
      curl_easy_setopt(curl_handle, CURLOPT_NOBODY, 1L);

      CURLcode res = curl_easy_perform(curl_handle);

      if (res == CURLE_OK) {
        long response_code;
        curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &response_code);

        pthread_mutex_lock(&url->mutex);
        if (response_code >= 200 && response_code < 400) {
          url->status = 1; // URL is up
        } else {
          url->status = 0; // URL is down
        }
        pthread_mutex_unlock(&url->mutex);
      } else {
        pthread_mutex_lock(&url->mutex);
        url->status = 0; // URL is down
        pthread_mutex_unlock(&url->mutex);
      }

      curl_easy_cleanup(curl_handle);
    }

    sleep(INTERVAL);
  }
  
  return NULL;
}

int main() {
  pthread_t threads[NUM_THREADS];
  struct URL urls[NUM_THREADS] = {
    {"https://www.google.com/", 1, PTHREAD_MUTEX_INITIALIZER},
    {"https://www.github.com/", 1, PTHREAD_MUTEX_INITIALIZER},
    {"https://www.yahoo.com/", 1, PTHREAD_MUTEX_INITIALIZER},
    {"https://www.youtube.com/", 1, PTHREAD_MUTEX_INITIALIZER},
    {"https://www.linkedin.com/", 1, PTHREAD_MUTEX_INITIALIZER},
    {"https://www.amazon.com/", 1, PTHREAD_MUTEX_INITIALIZER},
    {"https://www.facebook.com/", 1, PTHREAD_MUTEX_INITIALIZER},
    {"https://www.twitter.com/", 1, PTHREAD_MUTEX_INITIALIZER},
    {"https://www.microsoft.com/", 1, PTHREAD_MUTEX_INITIALIZER},
    {"https://www.apple.com/", 1, PTHREAD_MUTEX_INITIALIZER}
  };

  int i;
  for (i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, monitor, &urls[i]);
  }

  while (1) {
    printf("URL Status:\n");
    printf("-----------\n");
    for (i = 0; i < NUM_THREADS; i++) {
      pthread_mutex_lock(&urls[i].mutex);
      int status = urls[i].status;
      pthread_mutex_unlock(&urls[i].mutex);
      if (status == 1) {
        printf("%s is UP\n", urls[i].url);
      } else {
        printf("%s is DOWN\n", urls[i].url);
      }
    }
    printf("\n");

    sleep(INTERVAL);
  }

  for (i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}