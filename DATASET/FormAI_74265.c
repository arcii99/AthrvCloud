//FormAI DATASET v1.0 Category: Compression algorithms ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000
 
/*Structure declaration for DATALIST*/
struct DATALIST {
   char data;
   int count;
   struct DATALIST* next;
};
 
/*Structure declaration for NODE*/
struct NODE {
   char data;
   struct NODE* left;
   struct NODE* right;
};
 
/*Structure declaration for MinHeap*/
struct MINHEAP {
   int heap_size;
   int capacity;
   struct NODE** array;
};
 
/*METHOD TO CREATE NODE*/
struct NODE* createNode(char data, int count) {
   struct NODE* node = (struct NODE*)malloc(sizeof(struct NODE));
   node->data = data;
   node->left = NULL;
   node->right = NULL;
   return node;
}
 
/*METHOD TO CREATE MIN HEAP*/
struct MINHEAP* createMinHeap(int capacity) {
   struct MINHEAP* minHeap = (struct MINHEAP*)malloc(sizeof(struct MINHEAP));
   minHeap->array = (struct NODE**)malloc(capacity * sizeof(struct NODE*));
   minHeap->heap_size = 0;
   minHeap->capacity = capacity;
   return minHeap;
}
 
/*METHOD TO SWAP TWO NODES*/
void swapNode(struct NODE** a, struct NODE** b) {
   struct NODE* temp = *a;
   *a = *b;
   *b = temp;
}
 
/*BUILD MIN HEAP*/
void minHeapify(struct MINHEAP* minHeap, int index) {
   int smallest = index;
   int left = 2 * index + 1;
   int right = 2 * index + 2;
 
   if (left < minHeap->heap_size && 
       minHeap->array[left]->data < 
       minHeap->array[smallest]->data)
     smallest = left;
 
   if (right < minHeap->heap_size &&
       minHeap->array[right]->data < 
       minHeap->array[smallest]->data)
     smallest = right;
 
   if (smallest != index) {
     swapNode(&minHeap->array[smallest], &minHeap->array[index]);
     minHeapify(minHeap, smallest);
   }
}
 
/*CHECK IF SIZE IS 1 AND MIN HEAP*/
int checkMinHeapSizeOne(struct MINHEAP* minHeap) {
   return (minHeap->heap_size == 1);
}
 
/*EXTRACT MINIMUM*/
struct NODE* extractMin(struct MINHEAP* minHeap) {
   struct NODE* temp = minHeap->array[0];
   minHeap->array[0] = minHeap->array[minHeap->heap_size - 1];
   --minHeap->heap_size;
   minHeapify(minHeap, 0);
   return temp;
}
 
/*INSERTION IN MIN HEAP*/
void insertMinHeap(struct MINHEAP* minHeap, struct NODE* node) {
   ++minHeap->heap_size;
   int i = minHeap->heap_size - 1;
   while (i && node->data < minHeap->array[(i - 1)/2]->data) {
     minHeap->array[i] = minHeap->array[(i - 1)/2];
     i = (i - 1)/2;
   }
   minHeap->array[i] = node;
}
 
/*BUILD MIN HEAP*/
void buildMinHeap(struct MINHEAP* minHeap) {
   int n = minHeap->heap_size - 1;
   int i;
   for (i = (n - 1)/2; i >= 0; --i)
     minHeapify(minHeap, i);
}
 
/*CHECK IF NODE IS LEAF*/
int isLeaf(struct NODE* node) {
   return !(node->left) && !(node->right);
}
 
/*CREATION OF MIN HEAP*/
struct MINHEAP* createAndBuildMinHeap(char data[], int count[], int size) {
   struct MINHEAP* minHeap = createMinHeap(size);
   for (int i = 0; i < size; ++i)
     minHeap->array[i] = createNode(data[i], count[i]);
   minHeap->heap_size = size;
   buildMinHeap(minHeap);
   return minHeap;
}
 
/*BUILD HUFFMAN TREE*/
struct NODE* buildHuffmanTree(char data[], int count[], int size) {
   struct NODE *left, *right, *top;
   struct MINHEAP* minHeap = createAndBuildMinHeap(data, count, size);
   while (!checkMinHeapSizeOne(minHeap)) {
     left = extractMin(minHeap);
     right = extractMin(minHeap);
     top = createNode('$', left->data + right->data);
     top->left = left;
     top->right = right;
     insertMinHeap(minHeap, top);
   }
   return extractMin(minHeap);
}
 
/*METHOD TO PRINT HUFFMAN CODE*/
void printHuffmanCode(struct NODE* root, int arr[], int top) {
   if (root->left) {
     arr[top] = 0;
     printHuffmanCode(root->left, arr, top + 1);
   }
 
   if (root->right) {
     arr[top] = 1;
     printHuffmanCode(root->right, arr, top + 1);
   }

   if (isLeaf(root)) {
     printf("%c: ", root->data);
     for (int i = 0; i < top; ++i)
       printf("%d", arr[i]);
     printf("\n");
   }
}
 
/*HUFFMAN CODING*/
void huffmanCoding(char data[], int count[], int size) {
   struct NODE* root = buildHuffmanTree(data, count, size);
   int arr[MAX_SIZE], top = 0;
   printHuffmanCode(root, arr, top);
}

/*MAIN METHOD*/
int main() {
   char data[MAX_SIZE];
   int count[MAX_SIZE], size;
   printf("Enter the number of elements: ");
   scanf("%d", &size);
   printf("Enter the %d elements: \n", size);
   for (int i = 0; i < size; ++i) {
     printf("Enter Character %d: ",i+1);
     scanf(" %c", &data[i]);
     printf("Enter count of %c: ", data[i]);
     scanf("%d", &count[i]);
   }
   printf("\nOUTPUT:\n");
   huffmanCoding(data, count, size);
   return 0;
}