#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100000000

static void mergeSort(int items[], int lo, int hi);
static void merge(int items[], int lo, int mid, int hi);
static int min(int a, int b);
static void display(int items[], int lo, int hi);

int main(void)
{
	int *items = malloc(MAX_ITEMS * sizeof(int));
	if (items == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	// read input
	int n = 0;
	while (n < MAX_ITEMS && read(items[n]) == 1) {
		n++;
	}

	mergeSort(items, 0, n - 1);

	// display(items, 0, n - 1);
	(void) display;

	free(items);
}

static void mergeSort(int items[], int lo, int hi)
{
	for (int m = 1; m <= hi - lo; m *= 2) {
		for (int i = lo; i <= hi - m; i += 2 * m) {
			int end = min(i + 2 * m - 1, hi);
			merge(items, i, i + m - 1, end);
		}
	}
}

static void merge(int items[], int lo, int mid, int hi)
{
	int *tmp = malloc((hi - lo + 1) * sizeof(int));

	int i = lo;
	int j = mid + 1;
	int k = 0;

	// Scan both segments, copying to `tmp'.
	while (i <= mid && j <= hi) {
		if (le(items[i], items[j])) {
			tmp[k++] = items[i++];
		} else {
			tmp[k++] = items[j++];
		}
	}

	// Copy items from unfinished segment.
	while (i <= mid) tmp[k++] = items[i++];
	while (j <= hi) tmp[k++] = items[j++];

	// Copy `tmp' back to main array.
	for (i = lo, k = 0; i <= hi; i++, k++) {
		items[i] = tmp[k];
	}

	free(tmp);
}

static int min(int a, int b) {
	return a < b ? a : b;
}

static void display(int items[], int lo, int hi)
{
	for (int i = lo; i <= hi; i++) {
		show(items[i]);
		printf("\n");
	}
}