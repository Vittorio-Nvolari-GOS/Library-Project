#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Utente
{
    int id;
    char nome[100];
    char cognome[100];
    char sesso[1];
    struct Utente* next;
}Utente;

typedef struct ListaUtenti 
{
    Utente* testa;
    int lunghezza;
} ListaUtenti;

ListaUtenti* crea_lista_utenti() 
{
    ListaUtenti *l=(ListaUtenti*)malloc(sizeof(ListaUtenti));
    l->lunghezza=0;
    l->testa=NULL;
    return l;
}

void carica_lista_utenti(ListaUtenti* l)
{

    FILE *f = fopen("../data/utenti.csv", "r");
    if (f == NULL) {
        printf("Errore apertura file\n");
        return;
    }

    int id;
    char nome[100], cognome[100], sesso[2];

    // formato CSV: id,nome,cognome,sesso
    while (fscanf(f, "%d,%99[^,],%99[^,],%1[^\n]\n",
                  &id, nome, cognome, sesso) == 4)
    {
        Utente *c = (Utente*)malloc(sizeof(Utente));
        c->id = id;
        strcpy(c->nome, nome);
        strcpy(c->cognome, cognome);
        strcpy(c->sesso, sesso);
        c->next = l->testa;
        l->testa = c;
        l->lunghezza++;
    }

    fclose(f);

    // stampa la lista caricata
    Utente* temp = l->testa;
    while (temp != NULL) {
        printf("%s - %d\n", temp->nome, temp->id);
        temp = temp->next;
    }

}

void cercaUtenti_ID(ListaUtenti *l, Utente *c)
{
    Utente* temp = l->testa;
    int trovata = 0;
    printf("Ricerca prestito di: %s.......\n", c->nome);
    while (temp != NULL) {
        if (strcmp(temp->nome, c->nome) == 0) {
            stampa_libreria(temp, l);
            trovata = 1;
        }
        temp = temp->next;
    }
    if(trovata == 0)
        return;
}

void set_utente(Utente *c, int id) 
{
    c->id+=1;
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

void inserisci_utente_lista(ListaUtenti *l, int _id) {
    Utente* c = (Utente*)malloc(sizeof(Utente));
    set_utente(c, _id);
    c->next = l->testa;
    l->testa = c;
    l->lunghezza++;
}

void cancella_utente(ListaUtenti *c,int id) {
   
    if (c->testa == NULL) return;
    
    // Se l'elemento è in testa
    if (c->testa->id == id) {
        if (c->lunghezza == 1) {
            free(c->testa);
            c->testa = NULL;
        } else {
            Utente* current = c->testa;
            while (current->next != NULL) {
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

void stampa_libreria(Utente *c, ListaUtenti *l){

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