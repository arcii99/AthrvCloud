//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h> // Install Curl library by running "sudo apt-get install libcurl4-openssl-dev" in the terminal

int main(int argc, char *argv[])
{
   if(argc < 2) 
   {
      printf("Usage: ./websiteUptime http://www.example.com");
      exit(EXIT_FAILURE); // If no website URL is provided as an argument, exit the program with a failure status code
   }

   CURL *curl;
   CURLcode res;
   curl = curl_easy_init(); // Initialize curl session
   
   if(curl)
   {
      curl_easy_setopt(curl, CURLOPT_URL, argv[1]); // Set the URL to check as the first argument provided to the program
      curl_easy_setopt(curl, CURLOPT_NOBODY, 1); // Set the option to not include the body of the response, only headers
      
      res = curl_easy_perform(curl); // Perform the request
      
      if(res == CURLE_OK)
      {
         double time_connect = 0;
         double time_total = 0;
         curl_easy_getinfo(curl, CURLINFO_CONNECT_TIME, &time_connect); // Get the time taken to establish a connection
         curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &time_total); // Get the total time taken for the request
         
         printf("%s is up! Response time: Connect=%.2fsec, Total=%.2fsec\n", argv[1], time_connect, time_total); // Print the results
      }
      else
      {
         printf("%s is down!\n", argv[1]); // If the request was unsuccessful, print a message stating that the website is down
      }
      
      curl_easy_cleanup(curl); // Clean up the curl session
   }

   return 0;
}