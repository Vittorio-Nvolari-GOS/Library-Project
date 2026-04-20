#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/utenti.h"

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

#include <stdlib.h>
#include <string.h>
#include "../include/utenti.h"

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

typedef struct Utente
{
    int id;
    char nome[100];
    char cognome[100];
    
    int anno;
    float prezzo;
    struct Libro* next;
    struct Libro* next_playlist;
}Utente;