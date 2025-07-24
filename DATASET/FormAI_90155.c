//FormAI DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
// Welcome to the Shape Shifting Search Algorithm!
// This program will showcase a search algorithm that changes shape as it searches!

#include <stdio.h>

// Function to shift the search method
int shiftShape(int shapeIndex){
    return ++shapeIndex % 5;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate array size
    int searchFor = 8; // Search target
    int shapeIndex = 0; // Starting shape index

    while(1){
        // Shape shifting search algorithm!
        switch(shapeIndex){
            case 0: // Linear search
                for(int i = 0; i < size; i++){
                    if(arr[i] == searchFor){ // Found target
                        printf("Target found at index %d using Linear search!", i);
                        return 0;
                    }
                }
                break;
            case 1: // Binary search
                int low = 0, high = size-1;
                while(low <= high){
                    int mid = (low + high) / 2;
                    if(arr[mid] == searchFor){ // Found target
                        printf("Target found at index %d using Binary search!", mid);
                        return 0;
                    }
                    else if(arr[mid] < searchFor){ // Search upper half
                        low = mid + 1;
                    }
                    else{ // Search lower half
                        high = mid - 1;
                    }
                }
                break;
            case 2: // Jump search
                int blockSize = sqrt(size);
                int current = 0;
                while(arr[current] < searchFor){
                    current += blockSize;
                    if(current >= size){ // Out of bounds
                        break;
                    }
                }
                for(int i = current - blockSize; i <= current; i++){
                    if(arr[i] == searchFor){ // Found target
                        printf("Target found at index %d using Jump search!", i);
                        return 0;
                    }
                }
                break;
            case 3: // Interpolation search
                int lo = 0, hi = size - 1;
                while (lo <= hi && searchFor >= arr[lo] && searchFor <= arr[hi]){
                    int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (searchFor - arr[lo]));
                    if (arr[pos] == searchFor){ // Found target
                        printf("Target found at index %d using Interpolation search!", pos);
                        return 0;
                    }
                    if (arr[pos] < searchFor){
                        lo = pos + 1; // Search to the right
                    }
                    else{
                        hi = pos - 1; // Search to the left
                    }
                }
                break;
            case 4: // Exponential search
                int i = 1;
                while(i < size && arr[i] < searchFor){
                    i *= 2;
                }
                int left = i / 2, right = (i < size) ? i : size-1;
                while(left <= right){
                    int mid = (left + right) / 2;
                    if(arr[mid] == searchFor){ // Found target
                        printf("Target found at index %d using Exponential search!", mid);
                        return 0;
                    }
                    else if(arr[mid] < searchFor){ // Search upper half
                        left = mid + 1;
                    }
                    else{ // Search lower half
                        right = mid - 1;
                    }
                }
                break;
        }

        // Shift shape index and reset loop parameters
        shapeIndex = shiftShape(shapeIndex);
        printf("\nShape shifted to %d!", shapeIndex);
    }

    return 0;
}