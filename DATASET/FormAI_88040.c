//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_URLS 10
#define MAX_LEN_URL 256
#define MAX_RETRO_WIDTH 78

void check_urls(char **urls, int num_urls, int retro_mode);
void print_retro_banner();
void print_retro_text(char *text, int center);
void print_retro_line(char symbol);

int main()
{
    char *urls[MAX_URLS] = {"https://www.google.com", "https://www.yahoo.com", "https://www.twitter.com", "https://www.reddit.com"};
    int num_urls = 4;
    int retro_mode = 1;
    
    check_urls(urls, num_urls, retro_mode);
    
    return 0;
}

void check_urls(char **urls, int num_urls, int retro_mode)
{
    int i;
    time_t current_time;
    struct tm *time_info;
    char time_string[9];
    
    while(1)
    {
        for(i = 0; i < num_urls; i++)
        {
            FILE *fp = fopen(urls[i], "r");
            if(fp == NULL)
            {
                if(retro_mode)
                    print_retro_text(urls[i], 1);
                else
                    printf("%s is down!\n", urls[i]);
            }
            else
            {
                if(retro_mode)
                    print_retro_text(urls[i], 1);
                else
                    printf("%s is up!\n", urls[i]);
                
                fclose(fp);
            }
        }
        
        // Print current time
        time(&current_time);
        time_info = localtime(&current_time);
        strftime(time_string, sizeof(time_string), "%I:%M%p", time_info);
        if(retro_mode)
            print_retro_text(time_string, 0);
        else
            printf("Current time: %s\n", time_string);
        
        // Sleep for 10 seconds before checking again
        sleep(10);
    }
}

void print_retro_banner()
{
    int i;
    print_retro_line('*');
    print_retro_text("*** WEBSITE UPTIME MONITOR ***", 1);
    print_retro_line('*');
}

void print_retro_text(char *text, int center)
{
    int len_text = strlen(text);
    int spaces_before;
    
    if(center)
        spaces_before = (MAX_RETRO_WIDTH - len_text) / 2;
    else
        spaces_before = 0;
    
    int i;
    for(i = 0; i < spaces_before; i++)
        printf(" ");
    printf("%s", text);
    printf("\n");
}

void print_retro_line(char symbol)
{
    int i;
    for(i = 0; i < MAX_RETRO_WIDTH; i++)
        printf("%c", symbol);
    printf("\n");
}