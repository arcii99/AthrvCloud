//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function removes any unwanted characters from the URL */
void sanitize_url(char *url) {
    int i=0, j=0, k=0;
    char *new_url = (char *) malloc(sizeof(char) * strlen(url) + 1);
    char allowed_chars[] = "-._~:/?#[]@!$&'()*+,;="; /* these are the allowed characters */

    while(url[i] != '\0') {
        if(isalnum(url[i]) || strchr(allowed_chars, url[i]) != NULL) { /* if character is alphanumeric or allowed */
            new_url[j] = url[i];
            j++;
        }
        i++;
    }

    new_url[j] = '\0'; /* add null character at the end */
    strcpy(url, new_url); /* overwrite url with the new_url */
    free(new_url); /* free allocated memory */
}

/* Testing the function */
int main() {
    char url[] = "https://www.#g00gle!com/search?q=c%20language&rlz=1C1GCEA_enUS832US832&oq=c%20language&aqs=chrome.0.69i59l3j69i60l2j69i61.2910j0j7&sourceid=chrome&ie=UTF-8";
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url); /* should output httpswwwg00glecomsearchqc%20language%20rlz1C1GCEA_enUS832US832oqc%20languageaqschrome069i59l3j69i60l2j69i61.2910j0j7sourceidchromeieUTF-8 */
    return 0;
}