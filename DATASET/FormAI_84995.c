//FormAI DATASET v1.0 Category: Browser Plugin ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define URL_MAX_LENGTH 100

/* Struct for storing URL and its status */
typedef struct{
    char url[URL_MAX_LENGTH];
    bool visited;
}Page;

/* Array of pages */
Page pages[100];

/* Counter for number of pages */
int pageCounter = 0;

/* Function to check if URL exists in array */
bool pageExists(char* url){
    for(int i=0;i<pageCounter;i++){
        if(strcmp(pages[i].url, url) == 0){
            return true;
        }
    }
    return false;
}

/* Function to add new page */
void addPage(char* url){
    if(!pageExists(url)){
        Page newPage;
        strcpy(newPage.url, url);
        newPage.visited = false;
        pages[pageCounter] = newPage;
        pageCounter++;
    }
}

/* Function to mark page as visited */
void markAsVisited(char* url){
    for(int i=0;i<pageCounter;i++){
        if(strcmp(pages[i].url, url) == 0){
            pages[i].visited = true;
        }
    }
}

/* Function to check if page has been visited */
bool isVisited(char* url){
    for(int i=0;i<pageCounter;i++){
        if(strcmp(pages[i].url, url) == 0){
            return pages[i].visited;
        }
    }
    return false;
}

/* Function to perform page crawl */
void crawl(char* url){
    printf("Crawling %s...\n", url);
    markAsVisited(url);

    /* Code to crawl webpage */
    /* ... */
    /* End of code to crawl webpage */

    /* Assume 3 links found on webpage */
    char link1[] = "www.example.com/link1";
    char link2[] = "www.example.com/link2";
    char link3[] = "www.example.com/link3";

    /* Add new links to array */
    addPage(link1);
    addPage(link2);
    addPage(link3);

    /* Recursively crawl new pages */
    if(!isVisited(link1)){
        crawl(link1);
    }
    if(!isVisited(link2)){
        crawl(link2);
    }
    if(!isVisited(link3)){
        crawl(link3);
    }
}

/* Main function */
int main(){
    char startingURL[] = "www.example.com/start";
    addPage(startingURL);
    crawl(startingURL);
    return 0;
}