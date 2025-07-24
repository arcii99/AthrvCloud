//FormAI DATASET v1.0 Category: Stock market tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/* Define a structure for holding stock data. */
struct StockData {
   char symbol[14];
   float price;
   int volume;
};

/* Define a structure for holding the result of the stock calculation. */
struct StockResult {
   char symbol[14];
   float change;
};

/* Define a shared queue for storing requests to calculate a stock price difference. */
struct Queue {
   struct StockData stockData[100];
   int front;
   int rear;
   int itemCount;
};

/* Declare global variables. */
pthread_mutex_t mutexQueue;
pthread_cond_t condQueueNotEmpty;
struct Queue stockQueue;

/* Define a function to get the current stock data from an external API. */
struct StockData getStockData(char* symbol) {
   struct StockData stockData;
   /* Code to get current stock data from API would be implemented here. */
   strncpy(stockData.symbol, symbol, sizeof(stockData.symbol));
   stockData.price = (float)(rand() % 100) + 1; /* Random value between 1 and 100. */
   stockData.volume = rand() % 1000; /* Random value between 0 and 1000. */
   return stockData;
}

/* Define a function to calculate the difference between two stock prices. */
struct StockResult calculateStockDifference(struct StockData stockData1, struct StockData stockData2) {
   struct StockResult stockResult;
   strncpy(stockResult.symbol, stockData1.symbol, sizeof(stockResult.symbol));
   stockResult.change = stockData2.price - stockData1.price;
   return stockResult;
}

/* Define a function to add a request to the stock queue. */
void enqueueStock(struct StockData stockData) {
   pthread_mutex_lock(&mutexQueue);
   while(stockQueue.itemCount == sizeof(stockQueue.stockData)/sizeof(stockQueue.stockData[0])) {
      pthread_cond_wait(&condQueueNotEmpty, &mutexQueue);
   }
   stockQueue.stockData[stockQueue.rear] = stockData;
   if(stockQueue.rear == sizeof(stockQueue.stockData)/sizeof(stockQueue.stockData[0]) - 1) {
      stockQueue.rear = 0;
   } else {
      stockQueue.rear++;
   }
   stockQueue.itemCount++;
   pthread_mutex_unlock(&mutexQueue);
}

/* Define a function to remove a request from the stock queue. */
struct StockData dequeueStock() {
   struct StockData stockData;
   pthread_mutex_lock(&mutexQueue);
   while(stockQueue.itemCount == 0) {
      pthread_cond_wait(&condQueueNotEmpty, &mutexQueue);
   }
   stockData = stockQueue.stockData[stockQueue.front];
   if(stockQueue.front == sizeof(stockQueue.stockData)/sizeof(stockQueue.stockData[0]) - 1) {
      stockQueue.front = 0;
   } else {
      stockQueue.front++;
   }
   stockQueue.itemCount--;
   pthread_mutex_unlock(&mutexQueue);
   return stockData;
}

/* Define the function executed by the consumer threads that calculate stock price differences. */
void* calculateStockPriceDifference(void* arg) {
   struct StockData stockData1, stockData2;
   struct StockResult stockResult;
   while(1) {
      stockData1 = dequeueStock();
      stockData2 = dequeueStock();
      stockResult = calculateStockDifference(stockData1, stockData2);
      printf("The difference in stock price between %s and %s is %.2f.\n", 
             stockData1.symbol, stockData2.symbol, stockResult.change);
   }
   return NULL;
}

/* Define the function executed by the producer threads that get current stock data. */
void* getStockDataThread(void* arg) {
   char* symbol = (char*)arg;
   struct StockData stockData;
   while(1) {
      stockData = getStockData(symbol);
      enqueueStock(stockData);
      usleep(1000000); /* Sleep for 1 second. */
   }
   return NULL;
}

int main() {
   /* Initialize global variables. */
   pthread_mutex_init(&mutexQueue, NULL);
   pthread_cond_init(&condQueueNotEmpty, NULL);
   stockQueue.front = 0;
   stockQueue.rear = 0;
   stockQueue.itemCount = 0;
   /* Create consumer threads that calculate stock price differences. */
   pthread_t consumerThread1, consumerThread2;
   pthread_create(&consumerThread1, NULL, calculateStockPriceDifference, NULL);
   pthread_create(&consumerThread2, NULL, calculateStockPriceDifference, NULL);
   /* Create producer threads that get current stock data. */
   pthread_t producerThread1, producerThread2;
   char symbol1[] = "AAPL";
   char symbol2[] = "GOOGL";
   pthread_create(&producerThread1, NULL, getStockDataThread, symbol1);
   pthread_create(&producerThread2, NULL, getStockDataThread, symbol2);
   /* Wait for threads to complete. */
   pthread_join(consumerThread1, NULL);
   pthread_join(consumerThread2, NULL);
   pthread_join(producerThread1, NULL);
   pthread_join(producerThread2, NULL);
   /* Destroy global variables. */
   pthread_cond_destroy(&condQueueNotEmpty);
   pthread_mutex_destroy(&mutexQueue);
   return 0;
}