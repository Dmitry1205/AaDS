#include <stdio.h>
#include <stdlib.h>

#ifndef ELEM_H_INCLUDED
#define ELEM_H_INCLUDED

struct Elem {
    /* «Тег», описывающий тип значения в «головe» списка */
    enum {
        INTEGER,
        FLOAT,
        LIST
    } tag;

    /* Само значение в «голове» списка */
    union {
        int i;
        float f;
        struct Elem* list;
    } value;

    /* Указатель на «хвост» списка */
    struct Elem* tail;
};

#endif
struct Elem* searchlist(struct Elem* list, int k) {
    while (list!= NULL) {
        if (list->tag == INTEGER) {
            if (list->value.i == k)
                return list; 
        }
        if (list->tag == LIST) {
            struct Elem* otv = searchlist(list->value.list, k);
            if (otv != NULL)
                return otv;
        }
        list = list->tail;
    }
    return NULL;
}
