//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    /* Define an unclean URL string */
    char unclean_url[] = "https://www.example.com/path/to/page?param1=value1&param2=value2<script>alert('xss')</script>";

    /* Define a clean URL string */
    char clean_url[1024] = "";

    /* Define an array to hold the parameters */
    char params[1024] = "";

    /* Define a flag to check if a script tag has been encountered */
    int script_flag = 0;

    /* Define variables to hold the current position and length of the URL string */
    int pos = 0;
    int len = strlen(unclean_url);

    /* Loop through the URL string and sanitize it */
    while (pos < len) {

        /* Get the current character */
        char c = unclean_url[pos];

        /* Check if the character is a script tag */
        if (c == '<' && strncmp(&unclean_url[pos], "<script", 7) == 0) {
            script_flag = 1;
        }

        /* Check if the character is the closing tag of a script tag */
        if (c == '>' && script_flag == 1 && strncmp(&unclean_url[pos-6], "</script>", 9) == 0) {
            script_flag = 0;
        }

        /* If the script flag is not set and the character is not a script tag, add it to the clean URL */
        if (script_flag == 0 && c != '<' && c != '>') {
            strncat(clean_url, &c, 1);
        }

        /* Check if the character is a parameter delimiter */
        if (c == '&' || c == '?' || pos == len-1) {

            /* Add the parameter to the list of clean parameters */
            int param_pos = strlen(params);
            params[param_pos] = '&';

            /* Loop through the current parameter */
            int i = 0;
            int param_len = 0;
            if (pos == len-1) {
                param_len = len - (pos - i) + 1;
            } else {
                param_len = pos - i;
            }

            for (i; i < param_len; i++) {
                char param_char = unclean_url[pos-param_len+1+i];
                if (param_char != '<' && param_char != '>' && param_char != '=') {
                    strncat(&params[param_pos], &param_char, 1);
                }
            }
        }

        /* Increment the position */
        pos++;
    }

    /* Print out the clean URL and parameters */
    printf("Clean URL: %s%s\n", clean_url, params);

    return 0;
}