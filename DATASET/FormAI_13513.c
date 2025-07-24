//FormAI DATASET v1.0 Category: Firewall ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct rule{
    char protocol[20];
    char source[20];
    char destination[20];
    int port;
};

struct firewall{
    struct rule *rules;
    int count;
};

void init_firewall(struct firewall *fw){
    fw->count = 0;
    fw->rules = (struct rule*)malloc(sizeof(struct rule));
}

void add_rule(struct firewall *fw, char *protocol, char *source, char *destination, int port){
    fw->count++;
    fw->rules = (struct rule*)realloc(fw->rules, fw->count* sizeof(struct rule));
    strcpy(fw->rules[fw->count-1].protocol, protocol);
    strcpy(fw->rules[fw->count-1].source, source);
    strcpy(fw->rules[fw->count-1].destination, destination);
    fw->rules[fw->count-1].port = port;
}

void delete_rule(struct firewall *fw, int index){
    int i;
    for(i=index;i<fw->count-1;i++){
        fw->rules[i] = fw->rules[i+1];
    }
    fw->count--;
    fw->rules = (struct rule*)realloc(fw->rules, fw->count* sizeof(struct rule));
}

void show_rules(struct firewall *fw){
    int i;
    for(i=0;i<fw->count;i++){
        printf("Rule %d: %s from %s to %s on port %d\n", i+1, fw->rules[i].protocol, fw->rules[i].source, fw->rules[i].destination, fw->rules[i].port);
    }
}

int check_rule(struct rule *r, char *protocol, char *source, char *destination, int port){
    if(strcmp(r->protocol,protocol) == 0 &&
        strcmp(r->source,source) == 0 &&
        strcmp(r->destination,destination) == 0 &&
        r->port == port){
            return 1;
        }
    return 0;

}

int check_packet(struct firewall *fw, char *protocol, char *source, char *destination, int port){
    int i;
    for(i=0;i<fw->count;i++){
        if(check_rule(&fw->rules[i], protocol, source, destination, port)){
            return 1;
        }
    }
    return 0;
}

int main(){
    struct firewall fw;
    init_firewall(&fw);
    add_rule(&fw,"TCP", "192.168.1.1", "*", 80);
    add_rule(&fw,"UDP", "*", "192.168.1.1", 443);
    add_rule(&fw,"ICMP", "*", "*", 0);
    show_rules(&fw);
    if(check_packet(&fw,"TCP", "192.168.1.1", "192.168.1.2", 80)){
        printf("Packet allowed\n");
    }else{
        printf("Packet blocked\n");
    }
    delete_rule(&fw,1);
    show_rules(&fw);
    return 0;
}