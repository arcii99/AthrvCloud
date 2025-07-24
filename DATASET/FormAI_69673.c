//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <netinet/in.h>

struct Node {
    char name[64];
    char ip[64];
    int visited;
    struct Node* next;
};

void printNode(struct Node* node) {
    printf("%s with IP Address %s\n", node->name, node->ip);
}

void addNode(struct Node** head, char* name, char* ip) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    strcpy(newNode->ip, ip);
    newNode->visited = 0;
    newNode->next = (*head);
    (*head) = newNode;
}

int findNodeIndex(struct Node** nodes, char* name) {
    int i = 0;
    while(nodes[i]!=NULL) {
        if(strcmp(nodes[i]->name, name)==0) {
            return i;
        }
        i++;
    }
    return -1;
}

void addEdge(struct Node** nodes, char* src, char* dest) {
    int i, j;
    i = findNodeIndex(nodes, src);
    j = findNodeIndex(nodes, dest);
    if(i!=-1 && j!=-1) {
        struct Node* curr = nodes[i];
        while(curr->next!=NULL) {
            curr = curr->next;
        }
        curr->next = nodes[j];
    }
}

void printNodes(struct Node** nodes) {
    int i = 0;
    while(nodes[i]!=NULL) {
        printNode(nodes[i]);
        struct Node* curr = nodes[i]->next;
        while(curr!=NULL) {
            printf(" --> ");
            printNode(curr);
            curr = curr->next;
        }
        printf("\n");
        i++;
    }
}

void mapNetworkTopology() {
    struct ifaddrs* ifaddr, *ifa;
    int family, s, err;
    char host[NI_MAXHOST];
    struct Node* nodes[64];
    for(int i=0; i<64; i++) {
        nodes[i] = NULL;
    }
    if(getifaddrs(&ifaddr)==-1) {
        perror("getifaddrs");
        exit(1);
    }
    for(ifa = ifaddr; ifa!=NULL; ifa = ifa->ifa_next) {
        if(ifa->ifa_addr == NULL) {
            continue;
        }
        family = ifa->ifa_addr->sa_family;
        if(family == AF_INET) {
            s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
            if(s!=0) {
                printf("getnameinfo() failed: %s\n", gai_strerror(s));
                exit(1);
            }
            addNode(nodes, ifa->ifa_name, host);
        }
    }
    freeifaddrs(ifaddr);
    printf("List of Nodes:\n");
    printNodes(nodes);
    char src[64], dest[64];
    while(1) {
        printf("Enter source node or type 'done' to exit: ");
        scanf("%s", src);
        if(strcmp(src, "done")==0) {
            break;
        }
        printf("Enter destination node: ");
        scanf("%s", dest);
        addEdge(nodes, src, dest);
    }
    printf("Network Topology:\n");
    printNodes(nodes);
}

int main() {
    printf("Welcome to the Network Topology Mapper!\n\n");
    mapNetworkTopology();
    return 0;
}