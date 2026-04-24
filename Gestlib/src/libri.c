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
    struct Persona lista;
    int n = 0;                                                                

    FILE *f = fopen("dati.csv", "r");                                         
    if (f == NULL) 
    {
        printf("Errore apertura file\n");
        return 1;                                                             
    }
                                                       
    // legge riga per riga e salva nella lista
    while (n < fscanf(f, "%49[^,],%d,%49[^\n]\n",
                            lista[n].nome,                                   
                            &lista[n].eta,
                            lista[n].citta) == 3) 
                            {                          
        n++;                                                                  
    }
                                                                            
    fclose(f);  

    // stampa la lista caricata
    for (int i = 0; i < n; i++) {
        printf("%s - %d - %s\n", lista[i].nome, lista[i].eta, lista[i].citta);
    }
                                                                            
    return 0;   
  }

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
    set_canzone(c);
    c->next = l->testa;
    l->testa = c;
    l->lunghezza++;
}