//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: romantic
#include<stdio.h>
#include<string.h>
#include<curl/curl.h>

#define MAX_EMAILS 50
#define MAX_ID_LEN 10
#define MAX_SUBJECT_LEN 50
#define MAX_DATE_LEN 50

typedef struct {
    char id[MAX_ID_LEN+1];
    char subject[MAX_SUBJECT_LEN+1];
    char date[MAX_DATE_LEN+1];
} email;

typedef struct {
    email emails[MAX_EMAILS];
    int count;
} email_list;

size_t curl_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    email_list *email_list_ptr = (email_list *)userdata;
    char *token;
    if (email_list_ptr->count == MAX_EMAILS) 
         return size*nmemb;
    ptr[size*nmemb-2]='\0'; //remove '\r\n'
    token=strtok(ptr,"\n");  //get first line
    while (token != NULL) {
        switch (token[0]) {
            case 'A': sscanf(token,"A%d %s %s",
                              &email_list_ptr->emails[email_list_ptr->count].id,
                              email_list_ptr->emails[email_list_ptr->count].date,
                              email_list_ptr->emails[email_list_ptr->count].subject);
                     break;
            default: break;
        }
        token=strtok(NULL,"\n");
    email_list_ptr->count++;
    }
    return size*nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    email_list email_list;
    int i;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_USERNAME, "your_username");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "your_password");
        curl_easy_setopt(curl, CURLOPT_URL, "imaps://imap.gmail.com:993/INBOX");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &email_list);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) 
            fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
       
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Error initializing libcurl.\n");
        return 1;
    }

    //Print emails
    printf("Total emails: %d\n", email_list.count);
    for (i=0; i<email_list.count; i++) {
        printf("%s\t%s\t%s\n",
               email_list.emails[i].id,
               email_list.emails[i].date,
               email_list.emails[i].subject);
    }

    return 0;
}