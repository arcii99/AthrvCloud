//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: imaginative
#include <stdio.h>
#include <curl/curl.h>
#include <stdbool.h>
#include <time.h>

// Function to check website availability
bool checkWebsite(char *url)
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    res = curl_easy_perform(curl);
    if(res == CURLE_OK)
    {
      long response_code;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
      curl_easy_cleanup(curl);
      if(response_code == 200)
      {
        return true;
      }
    }
  }
  return false;
}

// Function to log website status
void logStatus(char *url, bool status)
{
  FILE *fp;
  time_t now;

  fp = fopen("website_log.txt", "a+");
  time(&now);
  if(status)
  {
    fprintf(fp, "%s: %s - website is UP\n", ctime(&now), url);
  }
  else
  {
    fprintf(fp, "%s: %s - website is DOWN\n", ctime(&now), url);
  }
  fclose(fp);
}

int main()
{
  char *urls[] = {"https://www.google.com", "https://www.facebook.com", "https://www.amazon.com", "https://www.yahoo.com"};
  int num_urls = sizeof(urls) / sizeof(urls[0]);
  int i;
  bool status;

  for(i = 0; i < num_urls; i++)
  {
    status = checkWebsite(urls[i]);
    logStatus(urls[i], status);
  }

  return 0;
}