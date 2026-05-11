#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/utenti.h"

typedef struct Utente
{
    int id=0;
    char nome[100];
    char cognome[100];
    char sesso[1];
    struct Utente* next;
    struct Utente* next_playlist;
}Utente;

typedef struct Lista 
{
    Utente* testa;
    int lunghezza;
} Lista;

Lista* crea_lista() 
{
    Lista *l=(Lista*)malloc(sizeof(Lista));
    l->lunghezza=0;
    l->testa=NULL;
    return l;
}

void carica_lista()
{

    struct Persona lista[MAX];
    int n = 0;                                                                

    FILE *f = fopen("utenti.csv", "r");                                         
    if (f == NULL) 
    {
        printf("Errore apertura file\n");
        return 1;                                                             
    }
                                                                            
    // legge riga per riga e salva nella lista
    // formato CSV: id,nome,cognome,sesso
    while (fscanf(f, "%d,%99[^,],%99[^,],%99[^,]\n",
                  &id, nome, cognome, sesso) == 4){
        n++;
    }

    fclose(f);  

    // stampa la lista caricata
    for (int i = 0; i < n; i++) {
        printf("%s - %d\n", lista[i].nome, lista[i].eta);
    }
    
    return 0;  

}

void cercaUtenti_ID(Utente *c)
{
    Utente* temp = l->testa;
    int trovata = 0;
    printf("Ricerca prestito di: %s.......\n", c->nome);
    while (temp != NULL) {
        if (strcmp(temp->nome, c->nome) == 0) {
            stampa_libreria(temp);
            trovata = 1;
        }
        temp = temp->next;
    }
    if(trovata == 0) 
        return 0;
}

void set_utente(Utente *c, int id) 
{
    c->id+1;
    printf("---- Inserimento utente con id %d ----\n", c->id);
    printf("Inserisci nome : \n");
    fgets(c->nome, 100, stdin);
    printf("Inserisci cognome : \n");
    fgets(c->cognome, 100, stdin);
    getchar();
    printf("inserire il sesso: \n");
    fgets(c->sesso, 1, stdin);
    getchar();
}

void inserisci_utente_lista(Lista *l) {
    Utente* c = (Utente*)malloc(sizeof(Libro));
    set_utente(c);
    c->next = l->testa;
    l->testa = c;
    l->lunghezza++;
}

void cancella_utente(Utente *c) {
    int id;
    printf("Inserisci id dell'utente che si desidera eliminare: ");
    scanf("%d", &id);
    getchar();

    if (c->testa == NULL) return;
    
    // Se l'elemento è in testa
    if (c->testa->id == id) {
        if (c->lunghezza == 1) {
            free(c->testa);
            c->testa = NULL;
        } else {
            Utente* current = c->testa;
            while (current->next != playlist->testa) {
                current = current->next;
            }
            Utente* temp = c->testa;
            c->testa = c->testa->next;
            current->next = c->testa;
            free(temp);
        }
        c->lunghezza--;
        return;
    }
}

void stampa_libreria(Utente *c, Lista *l){

    Utente* temp = l->testa;    
    while (temp != NULL) 
    {
        printf("Utente trovato!!!");
        printf("-----------------------------\n");
        printf("Nome: %s\n",temp->nome);
        printf("Cognome: %s\n",temp->cognome);
        printf("Sesso: %s\n",temp->sesso);
        printf("------------------------------\n");                     
        
        temp = temp->next;
    }
    
}