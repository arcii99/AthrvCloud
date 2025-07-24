//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* beautify_html(char *html) {
    char *result, *res_ptr;
    int indent_level = 0, token_len, i, j, k, n, m, q, len;
    const int spaces_per_indent = 2;
    const char *indent_string = "  ";
    const char *start_tag_chars = "<";
    const char *end_tag_chars = "</";
    const char *skip_tag_chars = "<?";
    const char *empty_tag_chars = "<img";
    const char *single_line_tag_chars = "<meta";
    const char *newline_chars = "\r\n";
    
    len = strlen(html);
    result = (char*) malloc(sizeof(char) * len * 2);
    memset(result, 0, sizeof(char) * len * 2);
    res_ptr = result;

    for (i = 0; i < len; i += token_len) {
        q = 0;
        token_len = 1;
        if (strncmp(&html[i], skip_tag_chars, strlen(skip_tag_chars)) == 0 ||
            strncmp(&html[i], single_line_tag_chars, strlen(single_line_tag_chars)) == 0) {
            token_len = strcspn(&html[i], newline_chars) + 1;
            strncpy(res_ptr, &html[i], token_len);
            res_ptr += token_len;
            continue;
        }
        if (strncmp(&html[i], empty_tag_chars, strlen(empty_tag_chars)) == 0) {
            j = strcspn(&html[i], ">") + 1;
            strncpy(res_ptr, &html[i], j);
            res_ptr += j;
            continue;
        }
        if (strncmp(&html[i], end_tag_chars, strlen(end_tag_chars)) == 0) {
            indent_level--;
        }
        for (j = 0; j < indent_level * spaces_per_indent; j++) {
            *res_ptr = ' ';
            res_ptr++;
        }
        strncpy(res_ptr, &html[i], 1);
        res_ptr++;
        i++;
        token_len = strcspn(&html[i], ">") + 1;
        j = strcspn(&html[i], " \t") + 1;
        if (j < token_len) {
            token_len = j;
            q = 1;
        }
        if (strncmp(&html[i], end_tag_chars, strlen(end_tag_chars)) == 0) {
            indent_level++;
        }
        strncpy(res_ptr, &html[i], token_len);
        res_ptr += token_len;
        if (q == 1) {
            for (k = i + token_len; k < i + j; k++) {
                strncpy(res_ptr, &html[k], 1);
                res_ptr++;
            }
            i = k - 1;
        }
        else {
            i += token_len - 1;
            if (strncmp(&html[i], start_tag_chars, strlen(start_tag_chars)) == 0 &&
                strncmp(&html[i+token_len-2], "/>", 2) != 0) {
                strncpy(res_ptr, newline_chars, strlen(newline_chars));
                res_ptr += strlen(newline_chars);
            }
        }
    }
    *res_ptr = '\0';
    return result;
}

int main() {
    char *html = "<html><head><title>Example</title></head><body><p>Hello, World!</p></body></html>";
    printf("Input HTML:\n%s\n\n", html);
    printf("Beautified HTML:\n%s\n", beautify_html(html));
    return 0;
}