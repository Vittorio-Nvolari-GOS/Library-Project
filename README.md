# Library-Project

Library-Project è un software in linguaggio C pensato per la gestione base di una piccola biblioteca scolastica. Il progetto include funzioni per registrare libri, utenti, prestiti e storico delle operazioni tramite semplici file CSV.

## Caratteristiche principali

- gestione dei libri: inserimento, ricerca e aggiornamento dei dati di ciascun libro
- gestione degli utenti: registrazione, ricerca e memorizzazione dei dati anagrafici
- gestione dei prestiti: associare un libro a un utente e registrare la data del prestito
- storico: tracciare le operazioni passate per audit e controllo
- archiviazione su file CSV: tutti i dati sono memorizzati nei file sotto `Gestlib/data/`

## Struttura del progetto

Il progetto è organizzato in modo modulare:

- `Gestlib/src/` contiene il codice sorgente in C
  - `main.c` è il punto di ingresso dell'applicazione
  - `libri.c` gestisce le operazioni sui libri
  - `utenti.c` gestisce le operazioni sugli utenti
  - `prestiti.c` gestisce i prestiti e lo storico
- `Gestlib/include/` contiene le intestazioni (`.h`) utilizzate dai moduli
  - `libri.h`
  - `utenti.h`
  - `prestiti.h`
- `Gestlib/data/` contiene i file CSV usati per conservare i dati
  - `libri.csv`
  - `utenti.csv`
  - `prestiti.csv`
  - `storico.csv`

## Come compilare il progetto

Il progetto è sviluppato in C standard e può essere compilato con GCC. Esempio di comando:

```bash
gcc -I Gestlib/include Gestlib/src/main.c Gestlib/src/libri.c Gestlib/src/utenti.c Gestlib/src/prestiti.c -o library-app
```

## Come eseguire

Dopo la compilazione, avvia l'eseguibile generato:

```bash
./library-app
```

L'applicazione dovrebbe quindi permettere di interagire con i dati dei libri, degli utenti e dei prestiti.

## Scopo del progetto

Questo progetto è una prova pratica per apprendere la programmazione strutturata in C, lavorare con file di testo CSV e organizzare un sistema semplice di gestione dati in un'applicazione console.

## Note aggiuntive

- I file CSV sono usati come archivio persistente e devono essere leggibili e scrivibili dal programma.
- La struttura modulare facilita l'estensione futura: si possono aggiungere nuove funzionalità con nuovi file di codice e intestazioni.
- Per un utilizzo reale, è consigliabile aggiungere controlli di validità sui dati e gestione degli errori più robusta.
