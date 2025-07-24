//FormAI DATASET v1.0 Category: Stock market tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// Function to write received data to a string variable
static size_t WriteCallback(char* contents, size_t size, size_t nmemb, void* userp) {
  ((char*)userp)[0] = '\0'; // Clear userp buffer before append
  strcat(userp, contents); // Append contents to userp buffer
  return size * nmemb;
}

int main(void) {
  CURL* curl;
  CURLcode res;

  // URL to retrieve stock data for Apple Inc.
  char url[] = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=AAPL&apikey=YOUR_API_KEY";

  curl = curl_easy_init(); // Initialize CURL
  if (curl) {
    // Set URL and write function
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

    // Create buffer to hold received data
    char buffer[16384];
    buffer[0] = '\0'; // Clear buffer before use

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer); // Set userp buffer

    // Perform the request, res will contain the return code
    res = curl_easy_perform(curl);

    // Check for errors
    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    } else {
      printf("%s\n", buffer); // Print received data
    }

    // Cleanup
    curl_easy_cleanup(curl);
  }

  return 0;
}