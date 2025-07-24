//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

void check_website(char *url);

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("Usage: ./website_monitor <url_list.txt>\n");
      exit(0);
   }

   char *filename = argv[1];
   FILE *fp = fopen(filename, "r");

   if (fp == NULL) {
      printf("Error: Could not open file %s\n", filename);
      exit(1);
   }

   char url[100];
   while (fgets(url, sizeof(url), fp) != NULL) {
      check_website(url);
   }

   fclose(fp);
   return 0;
}

void check_website(char *url) {
   CURL *curl;
   CURLcode res;

   curl = curl_easy_init();
   if (curl) {
      curl_easy_setopt(curl, CURLOPT_URL, url);
      curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

      res = curl_easy_perform(curl);

      if (res != CURLE_OK) {
         printf("%s is DOWN\n", url);
      }
      else {
         printf("%s is UP\n", url);
      }

      curl_easy_cleanup(curl);
   }
}