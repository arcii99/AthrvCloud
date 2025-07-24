//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void sanitizeURL(char *url) {
   //parse the URL to replace any malicious strings and characters, like <script> tags or "../"
   char sanitizedURL[512] = "";

   //regex to remove malicious characters
   regex_t regex;
   regcomp(&regex, "([[:alnum:]\\-\\._~:\\/\\?\\#\\[\\]@!\\$&'\\(\\)\\*\\+,;=])*", REG_EXTENDED);

   int ret = regexec(&regex, url, 0, NULL, 0);
   
   if (ret) {
      //malicious string detected, cleanup
      strncpy(sanitizedURL, url, 510);
      sanitizedURL[strlen(sanitizedURL)] = '\0';
   } else {
      strcpy(sanitizedURL, url);
      sanitizedURL[strlen(sanitizedURL)] = '\0';
   }
   
   printf("Sanitized URL: %s\n", sanitizedURL);
}

int main() {
   //test input url
   char url[512] = "https://www.google.com/search?q=<script>alert('XSS!')</script>&rlz=1C1CHBF_enUS747US747&oq=malware&aqs=chrome.0.69i59l2j0l4j69i60.5215j0j7&sourceid=chrome&ie=UTF-8";

   //sanitize url
   sanitizeURL(url);

   return 0;
}