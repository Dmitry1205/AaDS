void bubblesort(unsigned long nel,
    int (*compare)(unsigned long i, unsigned long j),
    void (*swap)(unsigned long i, unsigned long j)){
    if (nel < 2)
        return 0;
    unsigned long l = 1;
    unsigned long r = nel - 1;
    while (l <= r) {
        for (unsigned long i = l; i <= r; i++) {
            if (compare(i-1, i) == 1)
                swap(i-1, i);
        }
        for (unsigned long i = r; i >= l; i--) {
            if (compare(i-1, i) == 1)
                swap(i-1, i);
        }
        l++;
        r--;
    }
    return 0;
}
