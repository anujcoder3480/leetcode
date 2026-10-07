#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node *head;
    Node *tail;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *cache = malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;

    cache->head = malloc(sizeof(Node));
    cache->tail = malloc(sizeof(Node));

    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;
    cache->head->prev = NULL;
    cache->tail->next = NULL;

    return cache;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node *curr = obj->head->next;

    while (curr != obj->tail) {
        if (curr->key == key) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;

            curr->next = obj->head->next;
            curr->prev = obj->head;
            obj->head->next->prev = curr;
            obj->head->next = curr;

            return curr->value;
        }
        curr = curr->next;
    }

    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node *curr = obj->head->next;

    while (curr != obj->tail) {
        if (curr->key == key) {
            curr->value = value;

            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;

            curr->next = obj->head->next;
            curr->prev = obj->head;
            obj->head->next->prev = curr;
            obj->head->next = curr;

            return;
        }
        curr = curr->next;
    }

    if (obj->size == obj->capacity) {
        Node *last = obj->tail->prev;

        last->prev->next = obj->tail;
        obj->tail->prev = last->prev;

        free(last);
        obj->size--;
    }

    Node *newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;

    newNode->next = obj->head->next;
    newNode->prev = obj->head;

    obj->head->next->prev = newNode;
    obj->head->next = newNode;

    obj->size++;
}

void lRUCacheFree(LRUCache* obj) {
    Node *curr = obj->head;

    while (curr) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }

    free(obj);
}
/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/