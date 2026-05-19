/*
funzioni dei prestiti
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "../include/libri.h"

typedef struct Prestito {
    char utente[50];
    int id_libro;
    time_t data_prestito;
    struct Prestito* next;
} Prestito;

typedef struct ListaPrestiti {
    Prestito* testa;
    int lunghezza;
} ListaPrestiti;

ListaPrestiti* lista_prestiti;

Libro* cercaLibroPerNomePrestiti(Lista* lista_libri, char* nome);
Libro* cercaLibroPerIDPrestiti(Lista* lista_libri, int id);
Libro* cercaLibroPerAutorePrestiti(Lista* lista_libri, const char* autore);

ListaPrestiti* crea_lista_prestiti() {
    ListaPrestiti* lp = (ListaPrestiti*)malloc(sizeof(ListaPrestiti));
    lp->lunghezza = 0;
    lp->testa = NULL;
    return lp;
}

void nuovoprestito(Prestito *prestito, ListaPrestiti *lista_prestiti, Lista *lista_libri) {
    printf("utente che prende in prestito: \n");
    char utente[50];
    scanf("%s",utente);
    getchar();
    printf("in che modo vuoi cercare il libro?(nome,id,autore): \n");
    char scelta[50];
    scanf("%s",scelta);
    getchar();
    Libro* libro = NULL;
    if(strcmp(scelta,"nome")==0){
        printf("inserisci il nome del libro: \n");
        char nome[100];
        scanf("%s",nome);
        getchar();
        libro = cercaLibroPerNomePrestiti(lista_libri, nome);
    }
    else if(strcmp(scelta,"id")==0){
        printf("inserisci l'id del libro: \n");
        int id;
        scanf("%d",&id);
        getchar();
        libro = cercaLibroPerIDPrestiti(lista_libri, id);
    }
    else if(strcmp(scelta,"autore")==0){
        printf("inserisci l'autore del libro: \n");
        char autore[100];
        scanf("%s",autore);
        getchar();
        libro = cercaLibroPerAutorePrestiti(lista_libri, autore);
    }
    else{
        printf("scelta non valida\n");
        return;
    }
    if(libro == NULL){
        printf("Libro non trovato\n");
        return;
    }
    if(libro->copie_disponibili > 0){
        libro->copie_disponibili--;
        printf("Prestito effettuato con successo. Copie rimanenti: %d\n", libro->copie_disponibili);
        Prestito* nuovo_prestito = (Prestito*)malloc(sizeof(Prestito));
        strcpy(nuovo_prestito->utente, utente);
        nuovo_prestito->id_libro = libro->id;
        nuovo_prestito->data_prestito = time(NULL);
        nuovo_prestito->next = lista_prestiti->testa;
        lista_prestiti->testa = nuovo_prestito;
        lista_prestiti->lunghezza++;
    } else {
        printf("Nessuna copia disponibile per questo libro\n");
    }
}

void restituzionePrestiti(Prestito *prestito, ListaPrestiti *lista_prestiti) {
    printf("utente che restituisce: \n");
    char utente[50];
    scanf("%s",utente);
    getchar();
    printf("in che modo vuoi cercare il libro?(nome,id,autore): \n");
    char scelta[50];
    scanf("%s",scelta);
    getchar();
    if(strcmp(scelta,"nome")==0){
        printf("inserisci il nome del libro: \n");
        char nome[100];
        scanf("%s",nome);
        getchar();
        cercaLibri_nome(nome);
    }
    else if(strcmp(scelta,"id")==0){
        printf("inserisci l'id del libro: \n");
        int id;
        scanf("%d",&id);
        getchar();
        cercaLibri_ID(lista_prestiti, id);
    }
    else if(strcmp(scelta,"autore")==0){
        printf("inserisci l'autore del libro: \n");
        char autore[100];
        scanf("%s",autore);
        getchar();
        cercaLibri_autore(autore);
    }
    else{
        printf("scelta non valida\n");
    }
}

void controllaPrestitiScaduti(ListaPrestiti *lista_prestiti, Lista *libri) {
    time_t ora_corrente = time(NULL);
    Prestito* temp = lista_prestiti->testa;
    while (temp != NULL) {
        time_t scadenza = temp->data_prestito + (30 * 24 * 3600); 
        //30 giorni in secondi (30 giorni,24 ore,3600 secondi)
        if (scadenza < ora_corrente) {
            printf("Prestito scaduto per l'utente %s, libro ID %d, data prestito: %s", temp->utente, temp->id_libro, ctime(&temp->data_prestito));
        }
        temp = temp->next;
    }
}

Libro* cercaLibroPerNomePrestiti(Lista* lista_libri, char* nome) {
    if (lista_libri == NULL || lista_libri->testa == NULL) {
        return NULL;
    }

    Libro* current = lista_libri->testa;

    while (current != NULL) {
        if (strcmp(current->titolo, nome) == 0) {
            return current;
        }
        current = current->next; 
    }
    // Se non troviamo il libro, restituiamo NULL
    return NULL; 
}

Libro* cercaLibroPerIDPrestiti(Lista* lista_libri, int id) {
    if (lista_libri == NULL || lista_libri->testa == NULL) {
        return NULL;
    }

    Libro* current = lista_libri->testa;

    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }

    return NULL; 
}

Libro* cercaLibroPerAutorePrestiti(Lista* lista_libri, const char* autore) {
    if (lista_libri == NULL || lista_libri->testa == NULL) {
        return NULL;
    }

    Libro* current = lista_libri->testa;

    while (current != NULL) {
        if (strcmp(current->autore, autore) == 0) {
            return current; 
        }
        current = current->next;
    }

    return NULL; // Libro non trovato
}