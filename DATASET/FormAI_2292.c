//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
char output[1000];

void *worker(void *arg) {
    char *s = (char *) arg;
    int n = strlen(s);
    output[0] = 0;
    for(int i=0;i<n;i++){
        if(s[i] == ' '){
            strcat(output, " ");
            continue;
        }
        int idx = strchr(alphabet, s[i]) - alphabet;
        strcat(output, morse[idx]);
        strcat(output, " ");
    }
    return NULL;
}

int main(){
    char str[1000];
    scanf("%[^\n]", str);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, worker, str);
    pthread_join(thread_id, NULL);

    printf("%s", output);
    return 0;
}