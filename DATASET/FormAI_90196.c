//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: expert-level
#include<stdio.h>
#include<string.h>
#include<curl/curl.h>
#include<time.h>

#define MAX_URL_SIZE 10000

//function to check website uptime
int check_website_up(char *url) 
{
    CURL *curl = curl_easy_init();
    CURLcode res;

    if(curl) 
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5L);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) 
        {
            return 1;
        }
        curl_easy_cleanup(curl);
    }
    return 0;
}

int main(int argc, char** argv)
{
    char urls[MAX_URL_SIZE][256];
    int url_count = 0;
    char line[256];

    FILE *fptr;
    fptr = fopen("urls.txt", "r");

    if (fptr == NULL)
    {
        printf("Error opening file!");
        return 1;
    }

    while(fgets(line, 256, fptr))
    {
        strncpy(urls[url_count], line, strlen(line)-1);
        url_count++;
    }

    fclose(fptr);

    while(1) 
    {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("Checking uptime at %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        
        int i;
        for(i = 0; i < url_count; i++) 
        {
            if(check_website_up(urls[i])) 
            {
                printf("%s is up\n", urls[i]);
            } 
            else 
            {
                printf("%s is down\n", urls[i]);
            }
        }
        printf("\n");
        sleep(60);
    }
    return 0;
}