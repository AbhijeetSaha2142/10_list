#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"
#include <time.h>

int main(){
    srand(time(NULL));
    struct pokemon *missingno = NULL;
    print_list(missingno);
    printf("Adding a bunch of pokemon \n");
    struct pokemon *first_pokemon = new_pokemon(90,"Pikachu");
    struct pokemon *start = first_pokemon;

    struct pokemon *Ditto = new_pokemon(rand()%100+1, "Ditto");
    first_pokemon->next = Ditto;

    struct pokemon *Darkrai = new_pokemon(rand()%150+1,  "Darkrai");
    Ditto->next = Darkrai;

    struct pokemon *Arceus = new_pokemon(120, "Arceus");
    Darkrai->next = Arceus;

    struct pokemon *Palkia = new_pokemon(100, "Palkia");
    Arceus->next = Palkia;

    struct pokemon *Dialga = new_pokemon(100, "Dialga");
    Palkia->next = Dialga;

    printf("Printing list:\n");
    print_list(start);
    
    printf("\nRemoving Pikachu:\n"); // first node
    start = remove_node(first_pokemon, 90, "Pikachu");
    print_list(start);

    printf("\nRemoving Arceus\n");
    start = remove_node(start, 120, "Arceus"); // middle node
    print_list(start);

    printf("\nRemoving Dialga\n");
    start = remove_node(start, 100, "Dialga"); // last node
    print_list(start);

    printf("\nRemoving nonexistent pokemon\n");
    start = remove_node(start, 1, "Blob ");
    print_list(start);

    free_list(start);

}