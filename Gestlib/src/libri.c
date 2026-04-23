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
    
void ScriviSuFile(Libro *lista)
{
    
}

typedef struct Lista 
{
    Libro* testa;
    int lunghezza;
} Lista;

void carica_lista()
{

    FILE *f = fopen("../data/libri.csv", "r");
    if (f == NULL) {
        printf("Errore apertura file\n");
        return;
    }

    int id, anno;
    float prezzo;
    char titolo[100], autore[100], genere[100];

    // formato CSV: id,titolo,autore,genere,anno,prezzo
    while (fscanf(f, "%d,%99[^,],%99[^,],%99[^,],%d,%f\n",
                  &id, titolo, autore, genere, &anno, &prezzo) == 6)
    {
        Libro *c = (Libro*)malloc(sizeof(Libro));
        c->id = id;
        c->anno = anno;
        c->prezzo = prezzo;
        strcpy(c->titolo, titolo);
        strcpy(c->autore, autore);
        strcpy(c->genere, genere);
        c->next = l->testa;
        c->next_playlist = NULL;
        l->testa = c;
        l->lunghezza++;
    }

    fclose(f);

}

Lista* crea_lista() 
{
    Lista *l=(Lista*)malloc(sizeof(Lista));
    l->lunghezza=0;
    l->testa=NULL;
    return l;
}

void cercaLibri_ID(Lista *l,int _id)
{
    Libro* temp = l->testa;
    int trovata = 0;
    printf("Ricerca dei libri con id: %s.......\n", temp->id);
    while (temp != NULL) 
    {
        if (strcmp(temp->id, _id) == 0) 
        {
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
    set_Libro(c);
    c->next = l->testa;
    l->testa = c;
    l->lunghezza++;
}