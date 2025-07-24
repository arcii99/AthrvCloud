//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void* conspiracy_generator(void* arg){
    int thread_id = *((int*) arg);
    srand(time(NULL) + thread_id);
    char* theories[10] = {
    "The government is controlled by reptilians",
    "The moon landing was faked",
    "Chemtrails are controlling our minds",
    "The Illuminati is real",
    "The world is flat",
    "Aliens built the pyramids",
    "Bigfoot is real and the government is covering it up",
    "The Bermuda Triangle is a gateway to another dimension",
    "9/11 was an inside job",
    "The Loch Ness monster is a government experiment gone wrong"
    };
    for(int i = 0; i < 3; i++){
        int rand_num = rand() % 10;
        printf("Thread %d: %s\n", thread_id, theories[rand_num]);
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[4];
    int ids[4];

    for(int i = 0; i < 4; i++){
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, conspiracy_generator, &ids[i]);
    }

    for(int i = 0; i < 4; i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}