// dichiariamo le librerie

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/libri.h"
#include "libri.c"


void CercaLibro()
{
    int scelta=0;

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
            printf("Scelta non disponibile");
            break;
        }

    } while (scelta!=0);
    
    
}

void gestioneLibri()
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
                
            }
            else
                printf("L'id è gia stato usato");

            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 0:
            
            break;
        
        default:
            printf("La selezione è inesistente o non disponibile");
            break;
        }
    } while (scelta!=0);
    
}

void gestioneUtenti()
{
    int scelta=0;

    do
    {
        printf("______Menu______\n");
        printf("1. Registra un nuovo utente\n");
        printf("2. Elimina un utente\n");
        printf("3. Visualizza utenti\n");
        printf("4. Visualizza \n");
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
        case 4:
            /* code */
            break;
        case 0:
            break;
        
        default:
            printf("La selezione è inesistente o non disponibile");
            break;
        }
    } while (scelta!=0);
}

void gestionePrestiti()
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
    crea_lista(Libri);
    int scelta=0;
       
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
            gestioneLibri();
            break;
        case 2:
            gestioneUtenti();
            break;
        case 3:
            gestionePrestiti();
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

