void shellsort(unsigned long nel,
    int (*compare)(unsigned long i, unsigned long j),
    void (*swap)(unsigned long i, unsigned long j)){
    if (nel < 2)
        return;
    long long a = 1, b = 1, dop;
    while (b < nel) {
        dop = a;
        a = b;
        b = dop + b;
    }
    long long d = a;
    while(d >= 1) {
        long long i = d;
        while(i < nel) {
            long long loc = i - d; 
            while(loc >= 0 && compare(loc, loc+d)==1){
                swap(loc, loc+d);
                loc -= d;
            }
            i++;
        }
        dop = a;
        a = b - a;
        b = dop;
        d = a;
    }
}
