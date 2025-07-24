//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 5 //maximum number of URLs to monitor
#define TIMEOUT 5L //timeout value for curl_easy_setopt

//structure to store URL info
typedef struct {
    char url[50];
    bool isOnline;
} URLInfo;

//callback function for curl_easy_setopt
size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream){
    return size * nmemb;
}

//function to check if URL is online
void check_url(CURLM *multi_handle, URLInfo *url_info){
    CURL *easy_handle = curl_easy_init();
    if(easy_handle){
        curl_easy_setopt(easy_handle, CURLOPT_URL, url_info->url);
        curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(easy_handle, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(easy_handle, CURLOPT_NOBODY, true);
        curl_multi_add_handle(multi_handle, easy_handle);
    }
}

int main(){
    URLInfo urls[MAX_URLS];
    int num_urls = 0;

    //populate URL array with sample URLs
    strcpy(urls[num_urls].url, "http://www.google.com");
    urls[num_urls].isOnline = false;
    num_urls++;
    strcpy(urls[num_urls].url, "http://www.example.com");
    urls[num_urls].isOnline = false;
    num_urls++;
    strcpy(urls[num_urls].url, "http://www.github.com");
    urls[num_urls].isOnline = false;
    num_urls++;
    strcpy(urls[num_urls].url, "http://www.stackoverflow.com");
    urls[num_urls].isOnline = false;
    num_urls++;
    strcpy(urls[num_urls].url, "http://www.amazon.com");
    urls[num_urls].isOnline = false;
    num_urls++;

    CURLM *multi_handle = curl_multi_init();
    curl_multi_setopt(multi_handle, CURLMOPT_PIPELINING, CURLPIPE_MULTIPLEX);

    while(true){
        //reset multi_handle and re-register all easy_handles
        curl_multi_remove_handle(multi_handle, NULL);
        for(int i = 0; i < num_urls; i++){
            if(!urls[i].isOnline){
                check_url(multi_handle, &urls[i]);
            }
        }
        curl_multi_perform(multi_handle, NULL);

        //check the results of each easy_handle
        CURLMsg *msg;
        int remaining;
        while((msg = curl_multi_info_read(multi_handle, &remaining))){
            if(msg->msg == CURLMSG_DONE){
                CURL *easy_handle = msg->easy_handle;
                CURLcode code = msg->data.result;
                long http_code = 0;
                if(code == CURLE_OK){
                    curl_easy_getinfo(easy_handle, CURLINFO_RESPONSE_CODE, &http_code);
                    if(http_code >= 200 && http_code < 300){
                        for(int i = 0; i < num_urls; i++){
                            if(easy_handle == curl_easy_init()){
                                strcpy(urls[i].url, "");
                                urls[i].isOnline = true;
                                printf("%s is now online!\n", urls[i].url);
                                break;
                            }
                        }
                    }
                }
                curl_multi_remove_handle(multi_handle, easy_handle);
                curl_easy_cleanup(easy_handle);
            }
        }
        sleep(1); //wait for one second before checking again
    }

    //clean up resources
    curl_multi_cleanup(multi_handle);
    curl_global_cleanup();

    return 0;
}