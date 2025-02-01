#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 115249

typedef struct HashTable {
    int key;
    int count;
    struct HashTable* next;
} HashTable;

HashTable* hashTable[SIZE];

int hash(int key) {
    unsigned int K = (unsigned int)key;
    unsigned int otv = (K>>16)^K+(K>>8)^K+(K>>4)^K;
    return otv % SIZE;
}

HashTable* search(int key) {
    int index = hash(key);
    HashTable* cur = hashTable[index];
    while (cur != NULL) {
        if (cur->key == key) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void TableInsert(int key) {
    int index = hash(key);
    HashTable* ex = search(key);
    if (ex != NULL) {
        ex->count++;
        return;
    }
    HashTable* new_el = (HashTable*)malloc(sizeof(HashTable));
    new_el->key = key;
    new_el->count = 1;
    new_el->next = NULL;
    if (hashTable[index] != NULL) {
        new_el->next = hashTable[index];
    }
    hashTable[index] = new_el;
}

int main() {
    int n;
    scanf("%d", &n);
    int now = 0;
    long long count = 0;
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
    TableInsert(0);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        now ^= num;
        HashTable* p = search(now);
        if (p != NULL) {
            count += p->count;
        }
        TableInsert(now);
    }
    printf("%lld", count);
    for (int i = 0; i < SIZE; i++) {
        HashTable* cur = hashTable[i];
        while (cur != NULL) {
            HashTable* next = cur->next;
            free(cur);
            cur = next;
        }
    }
    return 0;
}
