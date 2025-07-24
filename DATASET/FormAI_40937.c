//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

//Function prototypes
void bucketSort(int array[], int n);
void insertionSort(int array[], int n);

//Node for linked list
struct Node
{
    int data;
    struct Node *next;
};

//Bucket size can be varied as per requirement
const int bucketSize = 5;

//Bucket Sort Implementation
void bucketSort(int array[], int n)
{
    struct Node bucket[bucketSize];

    //Initialize buckets
    for(int i = 0; i < bucketSize; i++)
    {
        bucket[i].data = 0;
        bucket[i].next = NULL;
    }

    //Determine maximum element in array
    int max = array[0];
    for(int i = 1; i < n; i++)
    {
        if(array[i] > max)
            max = array[i];
    }

    //Calculate width of each bucket
    float width = (float)(max+1) / bucketSize;

    //Distribute elements into buckets
    for(int i = 0; i < n; i++)
    {
        int index = (int)(array[i] / width);

        //If bucket is empty
        if(bucket[index].next == NULL)
        {
            struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
            temp->data = array[i];
            temp->next = NULL;
            bucket[index].next = temp;          
        }
        else
        {
            struct Node *temp = bucket[index].next;

            //Insert at beginning
            if(array[i] < temp->data)
            {
                struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = array[i];
                newNode->next = temp;
                bucket[index].next = newNode;   
            }
            else
            {
                struct Node *prev = temp;

                //Insert at appropriate position using insertion sort
                while(temp != NULL && array[i] >= temp->data)
                {
                    prev = temp;
                    temp = temp->next;
                }

                struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = array[i];
                newNode->next = temp;
                prev->next = newNode;
            }
        }
    }

    //Copy buckets back into array
    int index = 0;
    for(int i = 0; i < bucketSize; i++)
    {
        struct Node *temp = bucket[i].next;

        while(temp != NULL)
        {
            array[index++] = temp->data;
            temp = temp->next;
        }
    }

    //Perform Insertion Sort on each bucket
    for(int i = 0; i < bucketSize; i++)
    {
        struct Node *temp = bucket[i].next;
        int arr[bucketSize], j = 0;

        while(temp != NULL)
        {
            arr[j++] = temp->data;
            temp = temp->next;
        }

        insertionSort(arr, j);

        //Copy sorted array back into bucket
        temp = bucket[i].next;
        j = 0;

        while(temp != NULL)
        {
            temp->data = arr[j++];
            temp = temp->next;
        }
    }
}

//Insertion Sort for internal bucket sorting
void insertionSort(int array[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = array[i];
        int j = i - 1;

        while(j >= 0 && array[j] > key)
        {
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = key;
    }
}

//Main function
int main()
{
    int array[] = {54, 46, 83, 66, 95, 92, 43};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array before sorting:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", array[i]);

    printf("\n");

    bucketSort(array, n);

    printf("Array after sorting:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", array[i]);

    printf("\n");

    return 0;
}