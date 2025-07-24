//FormAI DATASET v1.0 Category: Database querying ; Style: multi-threaded
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

#define NUM_THREADS 5 

typedef struct {
    int id;
    char* query;
} thread_data;

void* run_query(void* thread_args) {
    thread_data* my_data = (thread_data*) thread_args;
    int thread_id = my_data->id;
    char* query = my_data->query;
    printf("Thread %d: Running query %s\n", thread_id, query);
    // code to run query in database
    printf("Thread %d: Query %s completed.\n", thread_id, query);
    pthread_exit(NULL);
}

int main() { 
    pthread_t threads[NUM_THREADS]; 
    int rc, i; 

    char* queries[NUM_THREADS] = {"SELECT * FROM users WHERE age > 25;", 
                                  "SELECT COUNT(*) FROM orders WHERE status = 'shipped';", 
                                  "UPDATE inventory SET quantity = quantity - 1 WHERE product_id = '123';",
                                  "INSERT INTO customers (first_name, last_name, email) VALUES ('John', 'Doe', 'johndoe@example.com');", 
                                  "DELETE FROM messages WHERE recipient_id = 456;"};

    for (i = 0; i < NUM_THREADS; i++) { 
        thread_data* data = (thread_data*) malloc(sizeof(thread_data));
        data->id = i;
        data->query = queries[i];

        printf("Main: Creating thread %d\n", i);
        rc = pthread_create(&threads[i], NULL, run_query, (void*) data); 
        if (rc) { 
            printf("Error: Unable to create thread %d, return code %d\n", i, rc); 
            exit(-1); 
        } 
    } 

    pthread_exit(NULL); 
}