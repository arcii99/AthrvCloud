//FormAI DATASET v1.0 Category: Firewall ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_LIST_SIZE 100

// A structure for storing blocked IP addresses
struct IP {
    int a;
    int b;
    int c;
    int d;
};

// A structure for storing blocked IP addresses along with their blocking reason
struct BlockRecord {
    struct IP ip;
    char reason[50];
};

// Function to add an IP to the block list
void addToBlockList(struct BlockRecord blockList[], int *size, struct IP ip, char reason[]) {
    if (*size < BLOCK_LIST_SIZE) {
        blockList[*size].ip = ip;
        strcpy(blockList[*size].reason, reason);
        (*size)++;
        printf("\nIP added to block list successfully!\n");
    } else {
        printf("\nError: Block list is full. Cannot add IP.\n");
    }
}

// Function to check if an IP is in the block list
int isBlocked(struct BlockRecord blockList[], int size, struct IP ip) {
    for (int i = 0; i < size; i++) {
        if (blockList[i].ip.a == ip.a && blockList[i].ip.b == ip.b && blockList[i].ip.c == ip.c && blockList[i].ip.d == ip.d) {
            printf("\nIP is blocked. Reason: %s\n", blockList[i].reason);
            return 1;
        }
    }
    return 0;
}

int main() {
    struct BlockRecord blockList[BLOCK_LIST_SIZE];
    int blockListSize = 0;

    // Add some IPs to the block list for testing
    struct IP ip1 = {192, 168, 0, 1};
    addToBlockList(blockList, &blockListSize, ip1, "Test block reason 1");
    struct IP ip2 = {10, 0, 0, 2};
    addToBlockList(blockList, &blockListSize, ip2, "Test block reason 2");
    struct IP ip3 = {172, 16, 0, 3};
    addToBlockList(blockList, &blockListSize, ip3, "Test block reason 3");

    // Check if some IPs are blocked
    struct IP ip4 = {192, 168, 0, 1};
    isBlocked(blockList, blockListSize, ip4);
    struct IP ip5 = {10, 0, 0, 1};
    isBlocked(blockList, blockListSize, ip5);
    struct IP ip6 = {172, 16, 0, 3};
    isBlocked(blockList, blockListSize, ip6);
    struct IP ip7 = {192, 168, 1, 1};
    isBlocked(blockList, blockListSize, ip7);

    return 0;
}