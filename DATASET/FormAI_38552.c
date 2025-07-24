//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

#define NUM_LANES 4
#define NUM_CARS 10

pthread_mutex_t lock;
int lanes[NUM_LANES];

void *car(void *arg){
    
    int car_num = *(int*)arg;
    
    int lane_num = rand() % NUM_LANES;
    
    pthread_mutex_lock(&lock); 
    
    if(lanes[lane_num]){
        printf("Car %d is waiting for lane %d to clear\n", car_num, lane_num);
    }
    
    while(lanes[lane_num]){
        sleep(1);
    }
    
    lanes[lane_num] = car_num;
    
    printf("Car %d is driving in lane %d\n", car_num, lane_num);
    
    pthread_mutex_unlock(&lock);
    
    sleep(rand() % 5 + 1);
    
    pthread_mutex_lock(&lock);
    
    lanes[lane_num] = 0;
    
    printf("Car %d has finished driving in lane %d\n", car_num, lane_num);
    
    pthread_mutex_unlock(&lock);
    
    pthread_exit(NULL);
}

int main(){
    srand(time(NULL));
    
    pthread_t threads[NUM_CARS];
    
    int car_nums[NUM_CARS];
    
    int i;
    for(i=0;i<NUM_LANES;i++){
        lanes[i] = 0;
    }
    
    for(i=0;i<NUM_CARS;i++){
        car_nums[i] = i+1;
        pthread_create(&threads[i], NULL, car, &car_nums[i]);
    }
    
    for(i=0;i<NUM_CARS;i++){
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}