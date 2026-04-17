#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/libri.h"


typedef struct Libro
{
    int id;
    char titolo[100];
    char autore[100];
    char genere[100];
    int anno;
    float prezzo;
    struct Libro* next;
    struct Libro* next_playlist;
}Libro;
    

typedef struct Lista 
{
    Libro* testa;
    int lunghezza;
} Lista;

void carica_lista()
{

}

Lista* crea_lista() 
{
    Lista *l=(Lista*)malloc(sizeof(Lista));
    l->lunghezza=0;
    l->testa=NULL;
    return l;
}

void cercaLibri_ID()
{
    Libro* temp = l->testa;
    int trovata = 0;
    printf("Ricerca canzoni dell'artista %s.......\n", artista);
    while (temp != NULL) {
        if (strcmp(temp->artista, artista) == 0) {
            stampa_canzone(temp);
            trovata = 1;
        }
        temp = temp->next;
    }
    if(trovata == 0) 
        return 0;
}

void set_Libro(Libro *c,int id) 
{
    
    c->id = id;
    printf("---- Inserimento canzone con id %d ----\n", c->id);
    printf("Inserisci titolo : \n");
    fgets(c->titolo, 100, stdin);
    printf("Inserisci autore : \n");
    fgets(c->autore, 100, stdin);
    printf("inserisci il genere: \n");
    fgets(c->genere,100,stdin);
    printf("inserisci anno di pubblicazione: \n");
    scanf("%d", &c->anno);
    getchar();
    printf("Inserisci prezzo del libro");
    scanf("%f",&c->prezzo);
    getchar();
}

void inserisci_Libro_lista(Lista *l) {
    Libro* c = (Libro*)malloc(sizeof(Libro));
    set_canzone(c);
    c->next = l->testa;
    l->testa = c;
    l->lunghezza++;
}