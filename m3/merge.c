#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int index;
    int element;
};
typedef struct Pair Pair;

struct PriorityQueue {
    struct Pair* heap;
    int cap;
    int count;
};
typedef struct PriorityQueue PQ;

void swap(Pair* a, Pair* b) {
    Pair buf = *a;
    *a = *b;
    *b = buf;
}

void InitPriorityQueue(PQ* q, int n) {
    q->heap = (Pair*)malloc(n * sizeof(Pair));
    q->cap = n;
    q->count = 0;
}

void Insert(PQ* q, Pair ptr) {
    if (q->count == q->cap) {
        printf("Error");
        return;
    }

    int i = q->count++;
    q->heap[i] = ptr;

    while (i > 0 && q->heap[(i - 1) / 2].element > q->heap[i].element) {
        swap(&q->heap[(i - 1) / 2], &q->heap[i]);
        i = (i - 1) / 2;
    }
}

void Heapify(int i, int n, Pair* heap) {
    int j = -1;
    while (i != j) {
        int l = 2 * i + 1;
        int r = l + 1;
        j = i;
        if (l < n && heap[i].element > heap[l].element) {
            i = l;
        }
        if (r < n && heap[i].element > heap[r].element) {
            i = r;
        }
        Pair a = heap[i];
        heap[i] = heap[j];
        heap[j] = a;
    }
}


Pair ExtractMin(PQ* q) {
     if (q->count == 0) {
        printf("Error");
        Pair el={-1, -1};
        return el;
    }

    Pair ptr = q->heap[0];
    q->count--;

    if (q->count > 0) {
        q->heap[0] = q->heap[q->count];
        Heapify(0, q->count, q->heap);
    }
    return ptr;
}


int main() {
    int n;
    scanf("%d", &n);
    int raz[100000];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &raz[i]);
        sum += raz[i];
    }
    int** list = (int**)malloc(n * sizeof(int*));
    int* l = (int*)malloc(sum * sizeof(int));
    int index = 0;
    for (int i = 0; i < n; i++) {
        list[i] = &l[index];
        for (int j = 0; j < raz[i]; j++) {
            scanf("%d", &l[index + j]);
        }
        index += raz[i];
    }
    PQ pq;
    InitPriorityQueue(&pq, n);
    Pair a;
    for (int i = 0; i < n; i++) {
        a.element = list[i][0];
        a.index = i;
        Insert(&pq, a);
    }
    int* list_ind = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        list_ind[i] = 0;
    }
    for (int i = 0; i < sum; i++) {
        a = ExtractMin(&pq);
        printf("%d ", a.element);
        list_ind[a.index]++;
        if (list_ind[a.index] < raz[a.index]) {
            a.element = list[a.index][list_ind[a.index]];
            Insert(&pq, a);
        }
    }
    free(list_ind);
    free(l);
    free(list);
    free(pq.heap);
}
