#include <stdlib.h>
#include <string.h>
#include "../include/utenti.h"

typedef struct Lista 
{
    Utente* testa;
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

typedef struct Utente
{
    int id;
    char nome[100];
    char cognome[100];
    struct Utente* next;
    struct Utente* next_playlist;
}Utente;

void cercaUtenti_ID(Utente *c)
{
    Utente* temp = l->testa;
    int trovata = 0;
    printf("Ricerca prestito di: %s.......\n", c->nome);
    while (temp != NULL) {
        if (strcmp(temp->nome, artista) == 0) {
            stampa_canzone(temp);
            trovata = 1;
        }
        temp = temp->next;
    }
    if(trovata == 0) 
        return 0;
}

void set_utente(Utente *c, int id) 
{
    
    c->id = id;
    printf("---- Inserimento canzone con id %d ----\n", c->id);
    printf("Inserisci nome : \n");
    fgets(c->nome, 100, stdin);
    printf("Inserisci cognome : \n");
    fgets(c->cognome, 100, stdin);
    getchar();
}

void inserisci_Libro_lista(Lista *l) {
    Utente* c = (Utente*)malloc(sizeof(Libro));
    set_utente(c);
    c->next = l->testa;
    l->testa = c;
    l->lunghezza++;
}