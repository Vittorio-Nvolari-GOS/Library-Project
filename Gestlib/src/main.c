// dichiariamo le librerie

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libri.c"
#include "../include/libri.h"
#include "utenti.c"
#include "../include/utenti.h"
#include "prestiti.c"
#include "../include/prestiti.h"


void CercaLibro(Lista* _lib)
{
    int scelta=0;
    char titolo[100];
    char genere[100];
    char autore[100];


    do
    {
        printf("_____Menu_____\n");
        printf("1. Cerca per nome\n");
        printf("2. Cerca per autore\n");
        printf("3. Cerca per genere\n");
        printf("0. Exit\n");
        printf("_____________________\n");
        scanf("%d",&scelta);
        getchar();

        switch (scelta)
        {
        case 1:
            printf("Inserisci il titolo del libro che cercavi\n");
            fgets(titolo,100,stdin);
            cercaTitolo(_lib,titolo);
            break;
        case 2:
            printf("Inserisci il genere del libro che cercavi\n");
            fgets(autore,100,stdin);
            stampaAutore(_lib,autore);
            break;
        case 3:
            printf("Inserisci il genere del libro che cercavi\n");
            fgets(genere,100,stdin);
            stampaGenere(_lib,genere);
            break;
        case 0:
            break;
        
        default:
            printf("Scelta non disponibile");
            break;
        }

    } while (scelta!=0);
    
    
}

void gestioneLibri(Lista* _libri)
{
    Libro* lista_libri = crea_lista();
    
    int scelta=0;
    int id=0;

    do
    {
        printf("______Menu______\n");
        printf("1. Aggiungi un libro\n");
        printf("2. Modifica un libro\n");
        printf("3. Elimina un libro\n");
        printf("4. Cerca un libro\n");
        printf("5. Stampa lista libri");
        printf("0. Exit\n");
        printf("____________________\n");
        scanf("%d",&scelta);
        getchar();

        switch (scelta)
        {
        case 1:
            printf("Inserisci l'id del libro\n");
            scanf("%d",&id);
            getchar();
            if(cercalibri_id()==0)
            {
                inserisci_Libro_lista(_libri,id);
            }
            else
                printf("L'id è gia stato usato");
 
            break;
        case 2:
            modificalibro(_libri);
            break;
        case 3:
            eliminaLibro(_libri);
            break;
        case 4:
            CercaLibro(_libri);
            break;
        case 5:
            stampLista(_libri);
            break;
        case 0:
            ScriviSuFile(_libri);
            break;
        
        default:
            printf("La selezione è inesistente o non disponibile");
            break;
        }
    } while (scelta!=0);
    
}

void gestioneUtenti()
{
    int scelta = 0;
    int id = 0;
    char nome[100];

    Lista* utenti = crea_lista_utenti();
    carica_lista_utenti(utenti);

    do {
        printf("______Menu______\n");
        printf("1. Registra un nuovo utente\n");
        printf("2. Elimina un utente\n");
        printf("3. Visualizza utenti\n");
        printf("4. Cerca utente per nome\n");
        printf("0. Exit\n");
        printf("____________________\n");
        scanf("%d", &scelta);
        getchar();

        switch (scelta) {
            case 1:
                printf("Inserisci l'id del nuovo utente: \n");
                scanf("%d", &id);
                getchar();
                inserisci_utente_lista(utenti, id);
                break;
            case 2:
                printf("Inserisci l'id dell'utente da eliminare: \n");
                scanf("%d", &id);
                getchar();
                cancella_utente(utenti, id);
                break;
            case 3:
                stampa_utenti(utenti);
                break;
            case 4:
                printf("Inserisci il nome da cercare: \n");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                cercaUtenti_perNome(utenti, nome);
                break;
            case 0:
                ScriviSuFile_utenti(utenti);
                break;
            default:
                printf("La selezione è inesistente o non disponibile\n");
                break;
        }
    } while (scelta != 0);
}

void gestionePrestiti(Lista* _libri)
{
    int scelta=0;

    do
    {
        printf("______Menu______\n");
        printf("1. Crea un nuovo prestito\n");
        printf("2. Restituzione libri\n");
        printf("3. Lista prestiti scaduti\n");
        printf("0. Exit\n");
        printf("____________________\n");
        scanf("%d",&scelta);
        getchar();

        switch (scelta)
        {
        case 1:
            nuovoprestito(lista_prestiti);
            break;
        case 2:
            restituzionePrestiti(NULL, lista_prestiti);
            break;
        case 3:
            controllaPrestitiScaduti(lista_prestiti, _libri);
            break;
        case 0:
            break;

        default:
            printf("La selezione non è disponibile o inesistente\n");
            break;
        }
    } while (scelta!=0);
}

void statistica()
{
    int scelta=0;

    do
    {
        printf("______Menu______\n");
        printf("1. Libro piu prestato\n");
        printf("2. Tasso di restituzione\n");
        printf("3. Libri pu richiesti\n");
        printf("0. Exit\n");
        printf("____________________\n");
        scanf("%d",&scelta);
        getchar();

        switch (scelta)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 0:
            break;
        
        default:
            printf("La selezione non è disponibile o inesistente\n");
            break;
        }
    } while (scelta!=0);
}







int main()
{
    Lista* Libri=crea_lista();
    carica_lista(Libri);
    int scelta=0;

    Lista* l = crea_lista();
    lista_prestiti = crea_lista_prestiti();
    
    
    do
    {
        printf("____Menu_____");
        printf("1. Gestione dei libri\n");
        printf("2. Gestione Utenti\n");
        printf("3. Gestioe prestiti\n");
        printf("4. Statistiche\n");
        printf("0. Exit\n");
        printf("________________\n");
        scanf("%d",&scelta);
        getchar();

        switch (scelta)
        {
        case 1:
            gestioneLibri(Libri);
            break;
        case 2:
            gestioneUtenti();
            break;
        case 3:
            gestionePrestiti(Libri);
            break;
        case 4:
            statistica();
            break;
        case 0:
            break;
        
        default:
            printf("La selezione non è disponibile o non esistente");
            break;
        }

    }while(scelta!=0);
}

