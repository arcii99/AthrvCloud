//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: all-encompassing
#include <curl/curl.h>

int main(int argc, char *argv[])
{
  CURL *curl;

  // initialize the curl session
  curl = curl_easy_init();

  if (curl) {
    // set the options for the session
    curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
    curl_easy_setopt(curl, CURLOPT_USERNAME, "your_username");
    curl_easy_setopt(curl, CURLOPT_PASSWORD, "your_password");
    curl_easy_setopt(curl, CURLOPT_URL, "imap://your_imap_server.com");

    // perform the session
    curl_easy_perform(curl);

    // clean up the curl session
    curl_easy_cleanup(curl);
  }

  return 0;
}