/** Questa funzione crea e inizializza una nuova lista vuota di utenti.
 * @return restituisce il puntatore alla nuova lista creata
 */
Lista* crea_lista();

/** Questa funzione carica gli utenti da file CSV inserendoli nella lista.
 * @return non restituisce nulla
 */
void carica_lista();

/** Questa funzione cerca un utente all'interno della lista in base al nome.
 * @param Utente* puntatore all'utente da cercare
 * @return non restituisce nulla
 */
void cercaUtenti_ID(Utente* );

/** Questa funzione richiede all'utente i dati e li assegna alla struttura.
 * @param Utente* puntatore all'utente da inizializzare
 * @param int identificativo da assegnare all'utente
 * @return non restituisce nulla
 */
void set_utente(Utente* , int );

/** Questa funzione inserisce un nuovo utente all'interno della lista.
 * @param Lista* puntatore alla lista in cui inserire l'utente
 * @return non restituisce nulla
 */
void inserisci_Libro_lista(Lista* );

/** Questa funzione elimina un utente dalla lista in base all'ID inserito.
 * @param Utente* puntatore alla lista degli utenti
 * @return non restituisce nulla
 */
void cancella_utente(Utente* );

/** Questa funzione stampa a video i dati di un utente e la sua libreria associata.
 * @param Utente* puntatore all'utente da stampare
 * @param Lista* puntatore alla lista dei libri associati
 * @return non restituisce nulla
 */
void stampa_libreria(Utente* , Lista* );
