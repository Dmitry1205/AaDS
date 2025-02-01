unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)){
	unsigned long left = 0;
	unsigned long right = nel-1;
	unsigned long mid = 0;
	while (left+1<right) {
		mid = (left + right) / 2;
		if (compare(mid) == 0)
			return mid;
		if (compare(mid) == 1)
			right = mid;
		else
			left = mid;
	}
	if (compare(left) == 0)
		return left;
	else if (compare(right) == 0)
		return right;
	return nel;
}
