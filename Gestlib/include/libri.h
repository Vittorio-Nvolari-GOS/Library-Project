/** Questa funzione scrive su file CSV tutti i libri presenti nella lista.
 * @param Lista* puntatore alla lista dei libri
 * @return non restituisce nulla
 */
void ScriviSuFile(Lista* lista);

/** Questa funzione carica i libri da file CSV inserendoli nella lista.
 * @param Lista* puntatore alla lista in cui caricare i libri
 * @return non restituisce nulla
 */
void carica_lista(Lista* l);

/** Questa funzione crea e inizializza una nuova lista vuota.
 * @return restituisce il puntatore alla nuova lista creata
 */
Lista* crea_lista();

/** Questa funzione cerca un libro all'interno della lista in base al suo ID.
 * @param Lista* puntatore alla lista dei libri
 * @param int identificativo del libro da cercare
 * @return restituisce 1 se il libro è stato trovato, 0 altrimenti
 */
int cercaLibri_ID(Lista* l, int _id);

/** Questa funzione seleziona ed elimina dalla lista il libro con l'ID specificato.
 * @param Lista* puntatore alla lista dei libri
 * @param int identificativo del libro da eliminare
 * @return non restituisce nulla
 */
void selezionaID(Lista* l, int _id);

/** Questa funzione seleziona ed elimina dalla lista il libro con il titolo specificato.
 * @param Lista* puntatore alla lista dei libri
 * @param char titolo del libro da eliminare
 * @return non restituisce nulla
 */
void selezionaTitolo(Lista* lista, char* _titolo);

/** Questa funzione richiede all'utente i dati di un libro e li assegna alla struttura.
 * @param Libro* puntatore al libro da inizializzare
 * @param int identificativo da assegnare al libro
 * @return non restituisce nulla
 */
void set_Libro(Libro* c, int id);

/** Questa funzione inserisce un nuovo libro all'interno della lista.
 * @param Lista* puntatore alla lista in cui inserire il libro
 * @param int identificativo del libro da inserire
 * @return non restituisce nulla
 */
void inserisci_Libro_lista(Lista* lista, int _id);

/** Questa funzione stampa a video tutti i libri presenti nella lista.
 * @param Lista* puntatore alla lista dei libri
 * @return non restituisce nulla
 */
void stampLista(Lista* lista);

/** Questa funzione cerca un libro nella lista in base al titolo.
 * @param Lista* puntatore alla lista dei libri
 * @param char titolo del libro da cercare
 * @return non restituisce nulla
 */
void cercaTitolo(Lista* lista, char* _titolo);

/** Questa funzione stampa tutti i libri di un determinato autore e richiede un ID.
 * @param Lista* puntatore alla lista dei libri
 * @param char autore da cercare
 * @return restituisce l'ID inserito dall'utente
 */
int stampaAutore(Lista* lista, char* _autore);

/** Questa funzione stampa tutti i libri di un determinato genere e richiede un ID.
 * @param Lista* puntatore alla lista dei libri
 * @param char genere da cercare
 * @return restituisce l'ID inserito dall'utente
 */
int stampaGenere(Lista* lista, char* _genere);

/** Questa funzione gestisce il menu di eliminazione dei libri dalla lista.
 * @param Lista* puntatore alla lista dei libri
 * @return non restituisce nulla
 */
void eliminaLibro(Lista* lista);

/** Questa funzione permette di modificare i dati di un libro presente nella lista.
 * @param Lista* puntatore alla lista dei libri
 * @return non restituisce nulla
 */
void modificalibro(Lista* lista);

/** Questa funzione libera la memoria occupata dalla lista e dai suoi libri.
 * @param Lista* puntatore alla lista da deallocare
 * @return non restituisce nulla
 */
void libera_memoria(Lista* l);

