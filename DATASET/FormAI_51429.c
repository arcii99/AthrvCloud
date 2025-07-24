//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Claude Shannon
//Example C code for authentication and fetching emails from IMAP server
#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
  CURL *curl;
  CURLcode res = CURLE_OK;
  struct curl_slist *list = NULL;
  struct curl_slist *recipient = NULL;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_USERNAME, "your_username");
    curl_easy_setopt(curl, CURLOPT_PASSWORD, "your_password");
    curl_easy_setopt(curl, CURLOPT_URL, "imap://your_server_address");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    list = curl_slist_append(list, "Content-Type: text/plain");
    curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipient);
    curl_easy_setopt(curl, CURLOPT_MAIL_FROM, "your_email_address");
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    curl_slist_free_all(list);
    curl_easy_cleanup(curl);
  }

  return (int)res;
}