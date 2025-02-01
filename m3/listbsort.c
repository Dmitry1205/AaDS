#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Elem {
    struct Elem* next;
    char* word;
} Elem;
Elem* InsertBeforeHead(Elem* l, Elem* x) {
    x->next = l;
    return x;
}
int Length(Elem* l){
    int col=0;
    Elem* p=l;
    while(p!=NULL){
        col++;
        p=p->next;
    }
    return col;
}
Elem* bsort(Elem* l) {
    int n=Length(l);
    if (n < 2)
        return l;
    Elem* new_el = (Elem*)malloc(sizeof(Elem));
    if (new_el == NULL) {
      return l;
    }
    l = InsertBeforeHead(l, new_el);
    for (int i = 0; i < n; i++) {
        Elem* p = l;
        while (p->next->next!=NULL) {
            if (strlen(p->next->word) > strlen(p->next->next->word)) {
                Elem* cur = p->next->next->next;
                Elem* a = NULL;
                Elem* b = NULL;
                a = p->next;
                b = p->next->next;
                p->next = b;
                b->next = a;
                a->next = cur;
            }
            p = p->next;
        }
    }
    Elem* pr=l->next;
    free(l);
    return pr;
}
int main() {
    Elem* list = NULL;
    char** words = (char**)malloc(1001 * sizeof(char*));
    char c;
    int col = 0;
    do {
        char* word = (char*)malloc(1001 * sizeof(char));
        scanf("%s%c", word, &c);
        words[col] = word;
        col++;
    } while (c != '\0' && c != '\n');

    for (int i = col - 1; i >= 0; i--) {
        Elem* new_el = (Elem*)malloc(sizeof(Elem));
        new_el->word = words[i];
        list = InsertBeforeHead(list, new_el);
    }

    Elem* sorted_list = bsort(list);
    Elem* p = sorted_list;

    while (p != NULL) {
        printf("%s ", p->word);
        Elem* pr = p;
        p = p->next;
        free(pr->word);
        free(pr);

    }
    free(words);
    return 0;
}
