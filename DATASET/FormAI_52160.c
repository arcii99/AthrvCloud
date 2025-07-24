//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

static size_t write_callback(char *data, size_t size, size_t nmemb, void *userp)
{
  return size * nmemb;
}

int main()
{
    CURL *curl_handle;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);

    curl_handle = curl_easy_init();

    const char* test_url = "http://speedtest.net/mini.php";

    if(curl_handle) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, test_url);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl_handle, CURLOPT_FILETIME, 1L);

        res = curl_easy_perform(curl_handle);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else {
            double content_length;
            res = curl_easy_getinfo(curl_handle, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &content_length);

            if((res == CURLE_OK) && (content_length > 0)) {
                double speed_download;
                res = curl_easy_getinfo(curl_handle, CURLINFO_SPEED_DOWNLOAD, &speed_download);

                if(res == CURLE_OK) {
                    printf("\nSpeed Test Result:\n");
                    printf("Download speed: %.2f Mbps\n", speed_download/1000000);
                }
            }
        }

        curl_easy_cleanup(curl_handle);
    }

    curl_global_cleanup();

    return 0;
}