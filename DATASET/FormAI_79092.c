//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Defining the structure for nodes*/
struct node{
    char symbol;
    int frequency;
    struct node *left,*right;
};
typedef struct node node;

/*Defining the structure for heap*/
struct heap{
    int size;
    int capacity;
    node **array;
};
typedef struct heap heap;

/*Creating a new node*/
node *create_node(char symbol,int frequency){
    node *new = (node *)malloc(sizeof(node));
    new->symbol = symbol;
    new->frequency = frequency;
    new->left = new->right = NULL;
    return new;
}

/*Creating a min heap*/
heap *create_heap(int capacity){
    heap *new =(heap *)malloc(sizeof(heap));
    new->size = 0;
    new->capacity = capacity;
    new->array = (node **)malloc(capacity * sizeof(node *));
    return new;
}

/*Swapping the nodes*/
void swap(node **x, node **y){
    node *temp = *x;
    *x = *y;
    *y = temp;
}

/*Heapify the heap*/
void min_heapify(heap *heap,int index){
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    node *left_node,*right_node;
    left_node = right_node = NULL;
    if(left < heap->size){
        left_node = heap->array[left];
    }
    if(right < heap->size){
        right_node = heap->array[right];
    }
    node *current = heap->array[index];
    if(left_node != NULL && left_node->frequency < current->frequency){
        smallest = left;
    }
    if(right_node != NULL && right_node->frequency < heap->array[smallest]->frequency){
        smallest = right;
    }
    if(smallest != index){
        swap(&heap->array[smallest],&heap->array[index]);
        min_heapify(heap,smallest);
    }
}

/*Check if the heap is empty*/
int is_empty(heap *heap){
    return heap->size == 0;
}

/*Extract the min node from the heap*/
node *extract_min(heap *heap){
    if(is_empty(heap)){
        printf("Heap is empty\n");
        return NULL;
    }
    node *min = heap->array[0];
    heap->array[0] = heap->array[heap->size-1];
    heap->size--;
    min_heapify(heap,0);
    return min;
}

/*Insert the node in the heap*/
void insert_node(heap *heap,node *new){
    if(heap->size == heap->capacity){
        printf("Heap is full\n");
        return;
    }
    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = new;
    while(i!=0 && heap->array[(i-1)/2]->frequency > heap->array[i]->frequency){
        swap(&heap->array[(i-1)/2],&heap->array[i]);
        i = (i-1)/2;
    }
}

/*Build the min heap*/
heap *build_min_heap(char symbols[],int freq[],int size){
    heap *heap = create_heap(size);
    for(int i=0;i<size;i++){
        insert_node(heap,create_node(symbols[i],freq[i]));
    }
    return heap;
}

/*Print the codes for the nodes*/
void print_codes(node *root,int arr[],int size,char code[]){
    if(root->left == NULL && root->right == NULL && size!=0){
        printf("%c : ",root->symbol);
        for(int i=0;i<size;i++){
            printf("%d",arr[i]);
            code[i] = arr[i]+'0';
        }
        printf("\n");
    }
    if(root->left!=NULL){
        arr[size] = 0;
        print_codes(root->left,arr,size+1,code);
    }
    if(root->right!=NULL){
        arr[size] = 1;
        print_codes(root->right,arr,size+1,code);
    }
}

/*Encode the string*/
char *encode(node *root,char text[]){
    int n = strlen(text);
    int code_array[n],top = 0;
    char code[n];
    memset(code_array,0,sizeof(code_array));
    memset(code,0,sizeof(code));
    print_codes(root,code_array,0,code);
    char *result = (char *)malloc(n*10*sizeof(char));
    for(int i=0;i<n;i++){
        for(int j=0;j<strlen(code);j++){
            if(text[i] == code[j]){
                strcat(result,code_array[j]+'0');
            }
        }
    }
    return result;
}

/*Decode the string*/
void decode(node *root,char code[]){
    int n = strlen(code);
    node *current = root;
    printf("Decoded message: ");
    for(int i=0;i<n;i++){
        if(code[i] == '0'){
            current = current->left;
        }
        else{
            current = current->right;
        }
        if(current->left == NULL && current->right == NULL){
            printf("%c",current->symbol);
            current = root;
        }
    }
    printf("\n");
}

int main(){
    int size;
    char symbols[] = {'a','b','c','d','e'};
    int freq[] = {5,9,12,13,16};
    size = sizeof(freq)/sizeof(freq[0]);
    heap *heap = build_min_heap(symbols,freq,size);
    node *root;
    while(heap->size > 1){
        node *min1 = extract_min(heap);
        node *min2 = extract_min(heap);
        node *new = create_node('$',min1->frequency+min2->frequency);
        new->left = min1;
        new->right = min2;
        root = new;
        insert_node(heap,new);
    }
    char text[100];
    printf("Enter the string to be encoded: ");
    scanf("%s",text);
    char *code = encode(root,text);
    printf("Encoded message: %s\n",code);
    decode(root,code);
    return 0;
}