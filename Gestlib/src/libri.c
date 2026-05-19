#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Libro
{
    int id;
    char titolo[100];
    char autore[100];
    char genere[100];
    int anno;
    float prezzo;
    int copie_disponibili;
    struct Libro* next;
    struct Libro* prev;
}Libro;

typedef struct Lista 
{
    Libro* testa;
    Libro* coda;
    int lunghezza;
} Lista;

    
void ScriviSuFile(Lista *lista)
{

    FILE *f = fopen("libri.csv", "w");
    if (f == NULL) {
        printf("Errore apertura file\n");
        return;
    }

    Libro *temp = lista->testa;
    while (temp != NULL)
    {
        fprintf(f, "%d,%s,%s,%s,%d,%.2f\n",
                temp->id,
                temp->titolo,
                temp->autore,
                temp->genere,
                temp->anno,
                temp->prezzo);
        temp = temp->next;
    }

    fclose(f);

}


void carica_lista(Lista *l)
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
    while (fscanf(f, "%d,%99[^,],%99[^,],%99[^,],%d,%f\n",&id, titolo, autore, genere, &anno, &prezzo) == 6)
    {
        Libro *c = (Libro*)malloc(sizeof(Libro));
        c->id = id;
        c->anno = anno;
        c->prezzo = prezzo;
        strcpy(c->titolo, titolo);
        strcpy(c->autore, autore);
        strcpy(c->genere, genere);
        c->next = l->testa;
        c->prev = NULL;
        if (l->testa != NULL)
            l->testa->prev = c;
        else
            l->coda = c;
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
    l->coda=NULL;
    return l;
}

int cercaLibri_ID(Lista *l,int _id)
{
    Libro* temp = l->testa;
    int trovata = 0;
    printf("Ricerca dei libri con id: %d.......\n", temp->id);
    while (temp != NULL) 
    {
        if (temp->id == _id) 
        {
            trovata = 1;
            return 1;
        }
        temp = temp->next;
    }
    if(trovata == 0) 
        return 0;
}

void selezionaID(Lista* l,int _id)
{
    Libro* temp = l->testa;
    Libro* temp2;
    int trovata = 0;
    while (temp != NULL) 
    {
        if (temp->id == _id) 
        {
            trovata=1;
            temp= temp->prev;
            temp2=temp->next;
            temp->next=temp2->next;
            free(temp2);

            
        }
        else
            temp = temp->next;
    }
    if(trovata==0)
        printf("Libro non trovato");
}

void selezionaTitolo(Lista* l,char* _titolo)
{
    Libro* temp = l->testa;
    Libro* temp2;
    int trovata = 0;
    while (temp != NULL) 
    {
        if (strcmp(temp->titolo, _titolo) == 0) 
        {
            trovata=1;
            temp= temp->prev;
            temp2=temp->next;
            temp->next=temp2->next;
            free(temp2);

            
        }
        else
            temp = temp->next;
    }
    if(trovata==0)
        printf("Libro non trovato");
}

void set_Libro(Libro *c,int id) 
{
    c->id = id;
    printf("---- Inserimento libro con id %d ----\n", c->id);
    printf("Inserisci titolo : \n");
    fgets(c->titolo, 100, stdin);
    printf("Inserisci autore : \n");
    fgets(c->autore, 100, stdin);
    printf("inserisci il genere: \n");
    fgets(c->genere,100,stdin);
    printf("inserisci anno di pubblicazione: \n");
    scanf("%d", &c->anno);
    getchar();
    printf("Inserisci prezzo del libro: ");
    scanf("%f",&c->prezzo);
    getchar();
    printf("Inserisci numero di copie disponibili: ");
    scanf("%d",&c->copie_disponibili);
    getchar();
}

void inserisci_Libro_lista(Lista *l,int _id) 
{
    Libro* c = (Libro*)malloc(sizeof(Libro));
    set_Libro(c,_id);
    c->next = l->testa;
    c->prev = NULL;
    if (l->testa != NULL)
        l->testa->prev = c;
    else
        l->coda = c;
    l->testa = c;
    l->lunghezza++;
}

void stampLista(Lista *l)
{
    Libro* temp = l->testa; 
    printf("----------Lista Libri---------\n");   
    while (temp != NULL) 
    {
        printf("-----------------------------\n");
        printf("Titolo: %s\n",temp->titolo);
        printf("Autore: %s\n",temp->autore);
        printf("Genere: %s\n",temp->genere);
        printf("Anno: %d\n",temp->anno);
        printf("Prezzo: %f\n",temp->prezzo);   
        printf("------------------------------\n");                     
        
        temp = temp->next;
    }
    
}

void cercaTitolo(Lista *l,char* _titolo)
{
    Libro* temp = l->testa;
    int trovata = 0;
    printf("Ricerca dei libri con id: %d.......\n", temp->id);
    while (temp != NULL) 
    {
        if (strcmp(temp->titolo,_titolo)==0) 
        {
            trovata = 1;
            printf("Libro trovato!!!");
            printf("-----------------------------\n");
            printf("Titolo: %s\n",temp->titolo);
            printf("Autore: %s\n",temp->autore);
            printf("Genere: %s\n",temp->genere);
            printf("Anno: %d\n",temp->anno);
            printf("Prezzo: %f\n",temp->prezzo);   
            printf("------------------------------\n");                     
        }
        temp = temp->next;
    }
    if(trovata == 0)
        return;
}

int stampaAutore(Lista* l,char* _autore)
{
    Libro* temp = l->testa;
    int id=0;
    while (temp != NULL)
    {
        if(strcmp(temp->autore,_autore)==0)
        {
            printf("-----------------------------\n");
            printf("Titolo: %s\n",temp->titolo);
            printf("Autore: %s\n",temp->autore);
            printf("Genere: %s\n",temp->genere);
            printf("Anno: %d\n",temp->anno);
            printf("Prezzo: %f\n",temp->prezzo);   
            printf("------------------------------\n"); 
        }
                            
        
        temp = temp->next;
    }
    printf("Inserisci l'id del libro interessa\n");
    scanf("%d",&id);
    getchar();
    return id;
}

int stampaGenere(Lista* l,char* _genere)
{
    Libro* temp = l->testa;
    int id=0;
    while (temp != NULL)
    {
        if(strcmp(temp->genere,_genere)==0)
        {
            printf("-----------------------------\n");
            printf("Titolo: %s\n",temp->titolo);
            printf("Autore: %s\n",temp->autore);
            printf("Genere: %s\n",temp->genere);
            printf("Anno: %d\n",temp->anno);
            printf("Prezzo: %f\n",temp->prezzo);   
            printf("------------------------------\n"); 
        }
                            
        
        temp = temp->next;
    }
    printf("Inserisci l'id del libro interessa\n");
    scanf("%d",&id);
    getchar();
    return id;
}

void eliminaLibro(Lista* l)
{
    int scelta=0;
    int id=0;
    char titolo[100];
    char autore[100];
    char genere[100];
    do
    {
        printf("_____Menu Eliminazioe______");
        printf("1. Selezioba libro per ID");
        printf("2. Seleziona libro per Titolo");
        printf("3. Selezioba libro per Autore");
        printf("4. Seleziona librp per Genere");
        printf("5. Stampa lista libri");
        printf("0. Exit");
        printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
        
        switch (scelta)
        {
        case 1:
            printf("Inserisci l'id del libro da eliminare\n");
            scanf("%d",&id);
            getchar();
            selezionaID(l,id);
            break;
        case 2:
            printf("Inserisci il titolo del libro da eliminare\n");
            fgets(titolo,100,stdin);
            selezionaTitolo(l,titolo);
            break;
        case 3:
            printf("Inserisci il autore del libro da eliminare\n");
            fgets(autore,100,stdin);
            selezionaID(l,stampaAutore(l,autore));
            break;
        case 4:
            printf("Inserisci il genere del libro da eliminare\n");
            fgets(genere,100,stdin);
            selezionaID(l,stampaGenere(l,genere));
            break;
        case 5:
            stampLista(l);
            break;
        case 0:
            break;
        
        
        default:
            printf("Seleione non dispoibile");
            break;
        }
    } while (scelta!=0);
    
    

}

void modificalibro(Lista* l)
{
    Libro* temp;
    int trovato=0;
    int id=0;
    stampLista(l);
    printf("Inseisci l'id del libro da modificare\n");
    scanf("%d",&id);
    getchar();
    while (temp!=NULL)
    {
        if(temp->id==id)
        {
            temp->id = id;
            printf("---- Inserimento libro con id %d ----\n", temp->id);
            printf("Inserisci titolo : \n");
            fgets(temp->titolo, 100, stdin);
            printf("Inserisci autore : \n");
            fgets(temp->autore, 100, stdin);
            printf("inserisci il genere: \n");
            fgets(temp->genere,100,stdin);
            printf("inserisci anno di pubblicazione: \n");
            scanf("%d", &temp->anno);
            getchar();
            printf("Inserisci prezzo del libro: ");
            scanf("%f",&temp->prezzo);
            getchar();
            printf("Inserisci numero di copie disponibili: ");
            scanf("%d",&temp->copie_disponibili);
            getchar();
            trovato=1;
        }
        else
            temp=temp->next;
    }
    if(trovato==0)
        printf("Libro non trovato");
    
    
    
}

void libera_memoria(Lista* l) 
{
    Libro* temp = l->testa;
    while (temp != NULL) {
        Libro* l = temp;
        temp = temp->next;
        free(temp);
    }
    free(l);
}