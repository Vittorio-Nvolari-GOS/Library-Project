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




static void conta_prestiti_da_file(const char* path, int ids[], int conteggi[], int* n, int max)
{
    FILE* f = fopen(path, "r");
    if (f == NULL) return;

    char utente[100];
    int id_libro;
    // legge le prime 2 colonne, scarta il resto della riga
    while (fscanf(f, "%99[^,],%d%*[^\n]\n", utente, &id_libro) == 2) {
        int trovato = 0;
        for (int i = 0; i < *n; i++) {
            if (ids[i] == id_libro) {
                conteggi[i]++;
                trovato = 1;
                break;
            }
        }
        if (!trovato && *n < max) {
            ids[*n] = id_libro;
            conteggi[*n] = 1;
            (*n)++;
        }
    }

    fclose(f);
}

// Cerca il titolo del libro con dato id in libri.csv. Scrive in `titolo` (buffer ampio 100).
static void titolo_da_id(int id_cercato, char* titolo)
{
    FILE* f = fopen("../data/libri.csv", "r");
    if (f == NULL) { strcpy(titolo, "?"); return; }

    int id, anno;
    float prezzo;
    char t[100], autore[100], genere[100];
    while (fscanf(f, "%d,%99[^,],%99[^,],%99[^,],%d,%f\n",
                  &id, t, autore, genere, &anno, &prezzo) == 6) {
        if (id == id_cercato) {
            strcpy(titolo, t);
            fclose(f);
            return;
        }
    }
    strcpy(titolo, "?");
    fclose(f);
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
        case 1: {
            int ids[100], conteggi[100], n = 0;
            conta_prestiti_da_file("../data/prestiti.csv", ids, conteggi, &n, 100);
            conta_prestiti_da_file("../data/storico.csv",  ids, conteggi, &n, 100);
            if (n == 0) { printf("Nessun prestito registrato\n"); break; }
            int max_idx = 0;
            for (int i = 1; i < n; i++)
                if (conteggi[i] > conteggi[max_idx]) max_idx = i;
            char titolo[100];
            titolo_da_id(ids[max_idx], titolo);
            printf("Libro piu prestato: id=%d, titolo=%s, prestiti=%d\n",
                   ids[max_idx], titolo, conteggi[max_idx]);
            break;
        }
        case 2: {
            int ids[100], conteggi[100], n_attivi = 0, n_storico = 0;
            conta_prestiti_da_file("../data/prestiti.csv", ids, conteggi, &n_attivi, 100);
            int totale_attivi = 0;
            for (int i = 0; i < n_attivi; i++) totale_attivi += conteggi[i];

            int ids2[100], cont2[100];
            conta_prestiti_da_file("../data/storico.csv", ids2, cont2, &n_storico, 100);
            int totale_restituiti = 0;
            for (int i = 0; i < n_storico; i++) totale_restituiti += cont2[i];

            int totale = totale_attivi + totale_restituiti;
            if (totale == 0) { printf("Nessun prestito registrato\n"); break; }
            printf("Tasso di restituzione: %.2f%% (%d restituiti su %d totali)\n",
                   100.0f * totale_restituiti / totale, totale_restituiti, totale);
            break;
        }
        case 3: {
            int ids[100], conteggi[100], n = 0;
            conta_prestiti_da_file("../data/prestiti.csv", ids, conteggi, &n, 100);
            conta_prestiti_da_file("../data/storico.csv",  ids, conteggi, &n, 100);
            if (n == 0) { printf("Nessun prestito registrato\n"); break; }
            // ordinamento decrescente semplice (selection sort)
            for (int i = 0; i < n - 1; i++) {
                int max_j = i;
                for (int j = i + 1; j < n; j++)
                    if (conteggi[j] > conteggi[max_j]) max_j = j;
                int t = conteggi[i]; conteggi[i] = conteggi[max_j]; conteggi[max_j] = t;
                t = ids[i]; ids[i] = ids[max_j]; ids[max_j] = t;
            }
            int top = n < 5 ? n : 5;
            printf("Libri piu richiesti (top %d):\n", top);
            for (int i = 0; i < top; i++) {
                char titolo[100];
                titolo_da_id(ids[i], titolo);
                printf("  %d. id=%d, titolo=%s, prestiti=%d\n",
                       i+1, ids[i], titolo, conteggi[i]);
            }
            break;
        }
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

