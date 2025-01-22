#ifndef LDMQUEUE_H
#define LDMQUEUE_H

#include <stdbool.h> // Per il tipo bool

// Nodo della lista
typedef struct ListNode {
    void * data;               // Puntatore ai dati
    struct ListNode * next;    // Puntatore al prossimo nodo
} LIST_NODE;

// Struttura della coda
typedef struct LdmQueue {
    LIST_NODE * first;         // Primo elemento della coda
    LIST_NODE * last;          // Ultimo elemento della coda
} LDM_QUEUE;

/**
 * @brief Crea una nuova coda con un elemento iniziale.
 * @param data Puntatore ai dati iniziali della coda.
 * @return Puntatore alla coda creata.
 */
LDM_QUEUE* create_with_data(void * data);

/**
 * @brief Crea una nuova coda con un elemento iniziale.
 * @param data Puntatore ai dati iniziali della coda.
 * @return Puntatore alla coda creata.
 */
LDM_QUEUE* create_empty();

void free_queue(LDM_QUEUE* queue);

/**
 * @brief Legge il prossimo elemento nella coda senza rimuoverlo.
 * @param queue Puntatore alla coda.
 * @return Puntatore ai dati del prossimo elemento, o NULL se la coda è vuota.
 */
void* read_next(LDM_QUEUE * queue);

/**
 * @brief Rimuove il prossimo elemento nella coda e restituisce i suoi dati.
 * @param queue Puntatore alla coda.
 * @return Puntatore ai dati del prossimo elemento, o NULL se la coda è vuota.
 */
void* remove_next(LDM_QUEUE* queue);

/**
 * @brief Aggiunge un nuovo elemento alla fine della coda.
 * @param queue Puntatore alla coda.
 * @param data Puntatore ai dati da aggiungere.
 */
int add(LDM_QUEUE* queue, void * data);

/**
 * @brief Controlla se la coda è vuota.
 * @param queue Puntatore alla coda.
 * @return true se la coda è vuota, altrimenti false.
 */
int is_empty_queue(LDM_QUEUE* queue);

#endif // LDMQUEUE_H
