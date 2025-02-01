unsigned long peak(unsigned long nel,
	int (*less)(unsigned long i, unsigned long j)) {
	for (int i = 1; i < nel-1; i++) {
		if (!less(i, i - 1) && !less(i, i + 1)) {
			return i;
		}
	}
	if (nel == 1)
		return 0;
	if (nel == 2)
		return (less(0, 1)) ? 1 : 0;
	if(!less(0, 1))
		return 0;
	return nel-1;
}
