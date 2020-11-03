#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"


struct pokemon *new_pokemon(int spd, char * n){
    struct pokemon *np;
    np = malloc(sizeof(struct pokemon));
    strncpy(np->name, n, sizeof(np->name)-1);
    np->speed = spd;
    np->next = NULL;
    return np;
}

void print_stats(struct pokemon *p){
    printf("Pokemon : %s, Speed : %d\n", p->name, p->speed);
}

void modify_stats(struct pokemon * p, int spd, char * n){
    strncpy(p->name, n, sizeof(p->name)-1);
    p->speed = spd;
}

void print_list(struct pokemon * p){
    struct pokemon *pp = p;
    while(pp){ // as long as it's not null, print it out
        print_stats(pp);
        pp = pp->next; // update
    }
}

struct pokemon * insert_front(struct pokemon *p, int spd, char *n){
    struct pokemon *np = new_pokemon(spd, n);
    np->next = p; // link it up to the front
    return np;
}

struct pokemon *free_list(struct pokemon *p){
    printf("Freeing list:\n");
    struct pokemon *pp = p;
    while(pp) {
        pp = p->next;
        printf("Freeing node: ");
        print_stats(p);
        free(p);
        p = pp;
    }

    return NULL;
}

struct pokemon *remove_node(struct pokemon *p, int spd, char *n){
    struct pokemon *pp = p;
    struct pokemon *prev = NULL;
    while(pp) {
        if(!strcmp(pp->name,n) && pp->speed == spd) {
            if(!prev){ // case of front being the removed
                prev = pp->next; // save the next node for the front
                free(pp);
                return prev;
            } 
            else if(!(pp->next)){ // case of the end of the linked list
                free(pp);
                return p; // begin
            } 
            else{ // case of something in the middle
                prev->next = pp->next; // link up previous node to node after removed one
                free(pp); 
                return p; 
            }
        }
        prev = pp; // previous node for next run
        pp = pp->next; // next node for next run
    }
    return p;
}




