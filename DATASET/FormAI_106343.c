//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define EMAIL_ADDRESS "YourEmailAddress@example.com"
#define EMAIL_PASSWORD "YourEmailPassword"
#define SMTP_SERVER "smtp.example.com"
#define SMTP_PORT 587
#define SMTP_EMAIL_ADDRESS "YourSMTPEmailAddress@example.com"

bool is_website_up(const char* url) {
  CURL* curl;
  CURLcode res;
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    res = curl_easy_perform(curl);
    if(res == CURLE_OK) {
      long response_code;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
      if (response_code >= 200 && response_code < 300) {
        curl_easy_cleanup(curl);
        return true;
      }
    }
    curl_easy_cleanup(curl);
  }
  return false;
}

void send_email(const char* subject, const char* message) {
  FILE *fpipe;
  char smtp[1024] = {0};
  snprintf(smtp, sizeof(smtp), "openssl s_client -starttls smtp -crlf -connect %s:%d", SMTP_SERVER, SMTP_PORT);
  fpipe = popen(smtp, "w");
  fprintf(fpipe, "helo %s\r\n", SMTP_SERVER);
  fprintf(fpipe, "auth login\r\n");
  fprintf(fpipe, "%s\r\n", EMAIL_ADDRESS);
  fprintf(fpipe, "%s\r\n", EMAIL_PASSWORD);
  fprintf(fpipe, "mail from:<%s>\r\n", SMTP_EMAIL_ADDRESS);
  fprintf(fpipe, "rcpt to:<%s>\r\n", EMAIL_ADDRESS);
  fprintf(fpipe, "data\r\n");
  fprintf(fpipe, "subject: %s\r\n", subject);
  fprintf(fpipe, "from: %s\r\n", SMTP_EMAIL_ADDRESS);
  fprintf(fpipe, "to: %s\r\n", EMAIL_ADDRESS);
  fprintf(fpipe, "\r\n");
  fprintf(fpipe, "%s\r\n", message);
  fprintf(fpipe, ".\r\n");
  fprintf(fpipe, "quit\r\n");
  pclose(fpipe);
}

int main(void) {
  const char* url = "https://example.com";
  bool last_uptime = true;
  while (true) {
    bool is_up = is_website_up(url);
    if (!is_up && last_uptime) {
      send_email("Website down", "The website is currently down.");
      last_uptime = false;
    } else if (is_up && !last_uptime) {
      send_email("Website back up", "The website is back up.");
      last_uptime = true;
    }
    sleep(60); // Wait for 1 minute before checking again
  }
  return 0;
}