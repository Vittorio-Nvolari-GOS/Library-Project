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

