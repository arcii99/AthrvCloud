//FormAI DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    CURLcode res = CURLE_OK;
    struct curl_slist *recipients = NULL;
    char smtp_server[] = "smtp.gmail.com";
    char from_address[] = "your_email@gmail.com";
    char to_address[] = "recipient_email@example.com";
    char username[] = "your_username@gmail.com";
    char password[] = "your_password";
    char message[] = "From: your_email@gmail.com\r\n"
                     "To: recipient_email@example.com\r\n"
                     "Subject: Test email\r\n\r\n"
                     "This is a test email sent from a C program using SMTP protocol.\r\n";
    
    curl = curl_easy_init();
    if (curl) 
    {
        curl_easy_setopt(curl, CURLOPT_USERNAME, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);
        curl_easy_setopt(curl, CURLOPT_URL, smtp_server);
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from_address);
        recipients = curl_slist_append(recipients, to_address);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, NULL);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, NULL);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, message);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
    return (int)res;
}