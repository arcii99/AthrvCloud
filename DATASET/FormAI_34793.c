//FormAI DATASET v1.0 Category: Arithmetic ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4

int sum = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *addNumbers(void *arg) {
	int *nums = (int *) arg;
	int localSum = 0;
	
	for (int i = 0; i < nums[0]; i++) {
		localSum += nums[i+1];
	}
	
	pthread_mutex_lock(&mutex);
	sum += localSum;
	pthread_mutex_unlock(&mutex);
	
	pthread_exit(NULL);
}

int main() {
	pthread_t threads[NUM_THREADS];
	int nums[8] = {2, 10, 20, 30, 40, 50, 60, 70};
	
	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_create(&threads[i], NULL, addNumbers, (void *) &nums[i*2]);
	}
	
	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}
	
	printf("The sum of the numbers is: %d\n", sum);
	
	return 0;
}