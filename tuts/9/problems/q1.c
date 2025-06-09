int hash(char *key, int N) {
	int h = 0;
	char *c;
    int pos = 1;
	for (c = key; *c != '\0'; c++) {
		h = h + (*c * pos);
        pos++;
	}
	return h % N;
}