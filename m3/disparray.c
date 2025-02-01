#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct HashTable {
    long long key;
    long long value;
    struct HashTable* next;
} HashTable;

long long hash(long long key, long long size) {
    unsigned long long K = (unsigned long long)key;
    return K % size;
}

HashTable* search(long long key, HashTable** hashTable, long long size){
    long long index = hash(key, size);
    HashTable* cur = hashTable[index];
    while(cur != NULL){
        if(cur->key == key){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void Assign(long long key, long long value, HashTable** hashTable, long long size){
    long long index = hash(key, size);
    HashTable* ex = search(key, hashTable, size);
    if(ex != NULL) {
        if(value == 0){
            HashTable* cur = hashTable[index];
            HashTable* prev= NULL;
            while(cur != NULL){
                if(cur->key == key){
                    if(prev == NULL){
                        hashTable[index] = cur->next;
                    }
                    else{
                        prev->next = cur->next;
                    }
                    free(cur);
                    return;
                }
                prev=cur;
                cur = cur->next;
            }
        }
        else{
            ex->value = value;
        }
        return;
    }
    if(value != 0){
        HashTable* new_el = (HashTable*)malloc(sizeof(HashTable));
        new_el->key = key;
        new_el->value = value;
        new_el->next = NULL;
        if(hashTable[index] != NULL){
            new_el->next = hashTable[index];
        }
        hashTable[index] = new_el;
    }
}

long long At(long long key, HashTable** hashTable, long long size){
    HashTable* res = search(key, hashTable, size);
    if(res == NULL)
        return 0;
    else
        return res->value;
}

int main() {
    long long m;
    scanf("%lld", &m);
    HashTable** hashTable = (HashTable**)malloc(m * sizeof(HashTable*));
    for(long long i = 0; i < m; i++){
        hashTable[i] = NULL;
    }
    char op[7];
    scanf("%s", op);
    while(op[0] != 'E'){
        if(op[1] == 'S'){
            long long i, v;
            scanf("%lld %lld", &i, &v);
            Assign(i, v, hashTable, m);
        }
        else if(op[1] == 'T'){
            long long i;
            scanf("%lld", &i);
            printf("%lld\n", At(i, hashTable, m));
        }
        scanf("%s", op);
    }
    if(hashTable == NULL)
        return 0;
    for (long long i = 0; i < m; i++) {
        HashTable* now = hashTable[i];
        while(now != NULL){
            HashTable* cur = now;
            now = now->next;
            free(cur);
        }
    }
    free(hashTable);
    return 0;
}
