#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashTable {
    int size;
    Node** table;
} HashTable;

HashTable* createHashTable(int size) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = size;
    ht->table = (Node**)malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

int hashFunction(int key, int size) {
    return key % size;
}

void insert(HashTable* ht, int key, int value) {
    int index = hashFunction(key, ht->size);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

int search(HashTable* ht, int key) {
    int index = hashFunction(key, ht->size);
    Node* current = ht->table[index];
    while (current) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Key not found
}

void delete(HashTable* ht, int key) {
    int index = hashFunction(key, ht->size);
    Node* current = ht->table[index];
    Node* prev = NULL;
    while (current) {
        if (current->key == key) {
            if (prev) {
                prev->next = current->next;
            } else {
                ht->table[index] = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void printHashTable(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        Node* current = ht->table[i];
        printf("Index %d: ", i);
        while (current) {
            printf("(%d, %d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    HashTable* ht = createHashTable(10);
    insert(ht, 10, 20);
    insert(20, 40);
    insert(10, 30); // Overwrites the value for key 10
    printf("Value of key 10: %d\n", search(ht, 10));
    delete(ht, 20);
    printHashTable(ht);
    return 0;
}
