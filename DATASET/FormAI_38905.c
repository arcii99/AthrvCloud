//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: sophisticated
#include <curl/curl.h>

int main(void)
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_USERNAME, "user");
    curl_easy_setopt(curl, CURLOPT_PASSWORD, "password");
    curl_easy_setopt(curl, CURLOPT_URL, "imap://mailserver.com");
 
    /* Set the IMAP command */
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "FETCH 1 BODY.PEEK[]");
 
    /* Perform the IMAP fetch */
    res = curl_easy_perform(curl);
    
    /* Check if the request was successful */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* cleanup */
    curl_easy_cleanup(curl);
  }
  return 0;
}