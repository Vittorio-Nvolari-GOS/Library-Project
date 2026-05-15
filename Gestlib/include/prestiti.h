ListaPrestiti* crea_lista_prestiti();
/*
    @param: nessuno
    @return: un puntatore a una nuova lista di prestiti vuota
    Descrizione: Questa funzione crea e inizializza una nuova lista di prestiti, impostando la lunghezza a 0 e la testa a NULL,
    e restituisce un puntatore a questa lista.     
 */
void nuovoprestito(ListaPrestiti *lista_prestiti);
/*
    @param: lista_prestiti - un puntatore alla lista dei prestiti
    @return: nessuno
    Descrizione: Questa funzione gestisce il processo di prestito di un libro. 
    Chiede all'utente di inserire il nome dell'utente che prende in prestito il libro, e poi chiede come vuole cercare il libro (per nome, id o autore).
    In base alla scelta dell'utente, chiama la funzione di ricerca appropriata per trovare il libro desiderato.
    Se il libro viene trovato e ci sono copie disponibili, decrementa il numero di copie disponibili del libro e aggiunge un nuovo prestito alla lista dei prestiti con le informazioni dell'utente, del libro e della data di scadenza.
    Se il libro non viene trovato o non ci sono copie disponibili, stampa un messaggio di errore.
 */
void restituzionePrestiti(Prestito *prestito, ListaPrestiti *lista_prestiti);
/*
    @param: prestito - un puntatore al prestito da restituire
    @param: lista_prestiti - un puntatore alla lista dei prestiti
    @return: nessuno
    Descrizione: Questa funzione gestisce il processo di restituzione di un libro. 
    Chiede all'utente di inserire il nome dell'utente che restituisce il libro, e poi chiede come vuole cercare il libro (per nome, id o autore).
    In base alla scelta dell'utente, chiama la funzione di ricerca appropriata per trovare il libro desiderato.
    Se il libro viene trovato, incrementa il numero di copie disponibili del libro e rimuove il prestito dalla lista dei prestiti.
    Se il libro non viene trovato, stampa un messaggio di errore.
 */

void controllaPrestitiScaduti(ListaPrestiti *lista_prestiti, Lista *libri);
/*
    @param: lista_prestiti - un puntatore alla lista dei prestiti
    @param: libri - un puntatore alla lista dei libri
    @return: nessuno
    Descrizione: Questa funzione controlla i prestiti scaduti.
    Scorre la lista dei prestiti e confronta la data di scadenza di ogni prestito con la data corrente.
    Se un prestito è scaduto, stampa un messaggio di avviso con il nome dell'utente e il titolo del libro.

 */




