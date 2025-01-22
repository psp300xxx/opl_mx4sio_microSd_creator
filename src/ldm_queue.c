// mylib.c
#include <stdio.h>
#include "../include/ldm_queue.h"
#include <stdlib.h> // Per malloc e free

// Il resto del tuo codice...



LDM_QUEUE* create_empty(){
    LDM_QUEUE *p = (LDM_QUEUE *)malloc(sizeof(LDM_QUEUE));
    if (p == NULL) {
        // Gestione dell'errore di allocazione
        printf("Errore: memory not allocated for LDM_QUEUE\n");
        return NULL;
    }
    p->first = NULL;
    p->last = NULL;
    return p;
}

/**
 * @brief Crea una nuova coda con un elemento iniziale.
 * @param data Puntatore ai dati iniziali della coda.
 * @return Puntatore alla coda creata.
 */
LDM_QUEUE* create_with_data(void * data) {
    // Alloca memoria per la coda
    LDM_QUEUE *p = (LDM_QUEUE *)malloc(sizeof(LDM_QUEUE));
    if (p == NULL) {
        // Gestione dell'errore di allocazione
        printf("Errore: memory not allocated for LDM_QUEUE\n");
        return NULL;
    }

    // Alloca memoria per il primo nodo
    p->first = (LIST_NODE *)malloc(sizeof(LIST_NODE));
    if (p->first == NULL) {
        // Gestione dell'errore di allocazione
        printf("Errore: memoria non allocata per LIST_NODE\n");
        free(p); // Libera la memoria della coda
        return NULL;
    }

    // Inizializza i membri del nodo
    p->first->data = data;
    p->first->next = NULL;

    // Inizializza i puntatori della coda
    p->last = p->first;

    return p;
}

/**
 * @brief Legge il prossimo elemento nella coda senza rimuoverlo.
 * @param queue Puntatore alla coda.
 * @return Puntatore ai dati del prossimo elemento, o NULL se la coda è vuota.
 */
void* read_next(LDM_QUEUE * queue){
    if (queue==NULL){
        return NULL;
    }
    if(queue->first==NULL){
        return NULL;
    }
    return queue->first->data;
}

/**
 * @brief Rimuove il prossimo elemento nella coda e restituisce i suoi dati.
 * @param queue Puntatore alla coda.
 * @return Puntatore ai dati del prossimo elemento, o NULL se la coda è vuota.
 */
void* remove_next(LDM_QUEUE* queue){
    if (queue==NULL || queue->first==NULL){
        return NULL;
    }
    void* result = queue->first->data;
    LIST_NODE * next = queue->first->next;
    free( queue->first );
    queue->first = next;
    if(queue->first==NULL){
        queue->last = NULL;
    }
    return result;
}

/**
 * @brief Aggiunge un nuovo elemento alla fine della coda.
 * @param queue Puntatore alla coda.
 * @param data Puntatore ai dati da aggiungere.
 */
int add(LDM_QUEUE* queue, void * data){
    if(queue==NULL || data == NULL){
        return -1;
    }
    LIST_NODE * newNode = (LIST_NODE *) malloc( sizeof(LIST_NODE) );
    if(newNode==NULL){
        return -1;
    }
    newNode->next = NULL;
    newNode -> data = data;
    if(queue->first==NULL){
        queue->first = newNode;
        queue->last = newNode;
        return 0;
    }
    queue->last->next = newNode;
    queue->last = newNode;
    return 0;
}

void free_nodes(LIST_NODE * node){
    if(node==NULL){
        return;
    }
    free_nodes( node -> next );
    free( node );
}

void free_queue(LDM_QUEUE* queue){
    LIST_NODE * head = queue->first;
    free_nodes(head);
    free( queue );
}

/**
 * @brief Controlla se la coda è vuota.
 * @param queue Puntatore alla coda.
 * @return true se la coda è vuota, altrimenti false.
 */
int is_empty_queue(LDM_QUEUE* queue){
    if(queue==NULL || queue->first==NULL){
        return 1;
    }
    return 0;
}