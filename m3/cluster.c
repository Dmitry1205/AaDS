#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Pair {
    int start;
    int end;
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

Pair ExtractMin(PQ* q);

void Insert(PQ* q, Pair ptr) {
    if (q->count == q->cap) {
        Pair min = ExtractMin(q);
        ptr.start = (ptr.start - min.end >= 0) ? ptr.start - min.end : 0;
        ptr.end += ptr.start + min.end;
    } else {
        ptr.end += ptr.start;
    }
    int i = q->count++;
    q->heap[i] = ptr;

    while (i > 0 && q->heap[(i - 1) / 2].end > q->heap[i].end) {
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
        if (l < n && heap[i].end > heap[l].end) {
            i = l;
        }
        if (r < n && heap[i].end > heap[r].end) {
            i = r;
        }
        if (i != j) {
          Pair a = heap[i];
          heap[i] = heap[j];
          heap[j] = a;
        }
    }
}

bool QueueEmpty(PQ* q) {
    return (q->count == 0);
}

Pair ExtractMin(PQ* q) {
    if (q->count == 0) {
        printf("ERROR");
        Pair el = {-1, -1};
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
    int m;
    scanf("%d", &m);

    PQ* pq = (PQ*)malloc(sizeof(PQ));
    InitPriorityQueue(pq, n);

    for (int i = 0; i < m; i++) {
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        Pair a;
        a.start = t1;
        a.end = t2;
        Insert(pq, a);
    }

    Pair min = {-1, 0};
    while (!QueueEmpty(pq)) {
        min = ExtractMin(pq);
    }
    printf("%d", min.end);

    free(pq->heap);
    free(pq);
    return 0;
}
