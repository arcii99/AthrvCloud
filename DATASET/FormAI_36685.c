//FormAI DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct index_node {
   int key;
   int pos;
};

struct index_node index[MAX];
int index_size = 0;

int partition(int arr[], int low, int high) {
   int pivot = arr[high];
   int i = low - 1;

   for (int j = low; j < high; j++) {
      if (arr[j] < pivot) {
         i++;
         int temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
      }
   }

   int temp = arr[i + 1];
   arr[i + 1] = arr[high];
   arr[high] = temp;

   return i + 1;
}

void quick_sort(int arr[], int low, int high) {
   if (low < high) {
      int pi = partition(arr, low, high);

      quick_sort(arr, low, pi - 1);
      quick_sort(arr, pi + 1, high);
   }
}

void insert_index(int key, int pos) {
   int i;

   for (i = 0; i < index_size; i++) {
      if (index[i].key == key) {
         // Key already exists, update position
         index[i].pos = pos;
         return;
      } else if (index[i].key > key) {
         // Position found, insert key
         break;
      }
   }

   for (int j = index_size; j > i; j--) {
      index[j] = index[j - 1];
   }

   index[i].key = key;
   index[i].pos = pos;

   index_size++;
}

int search_index(int key) {
   int low = 0;
   int high = index_size - 1;

   while (low <= high) {
      int mid = (low + high) / 2;

      if (index[mid].key == key) {
         return index[mid].pos;
      } else if (index[mid].key < key) {
         low = mid + 1;
      } else {
         high = mid - 1;
      }
   }

   return -1;
}

int main() {
   int arr[] = {5, 2, 8, 1, 3, 9, 4, 7, 6};
   int arr_size = sizeof(arr) / sizeof(arr[0]);

   // Sort the array
   quick_sort(arr, 0, arr_size - 1);

   // Build the index
   for (int i = 0; i < arr_size; i++) {
      insert_index(arr[i], i);
   }

   // Test the index
   printf("Search for key 3: %d\n", search_index(3));
   printf("Search for key 10: %d\n", search_index(10));

   return 0;
}