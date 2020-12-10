#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int* Copy(int* arr, int size) {
	int* new_arr = (int *)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) new_arr[i] = arr[i];
	return new_arr;
}

void FSFC(int n, int st, int* req) {
	printf("FSFC: %d", st);
	int sum = 0, cur = st;
	for (int i = 0; i < n; i++) {
		sum += abs(cur - req[i]);
		cur = req[i];
		printf(" %d", req[i]);
	}
	printf("; Sum: %d\n", sum);
}

int Comp(const void* elem1, const void* elem2) {
	int x = *((int*)elem1);
	int y = *((int*)elem2);
	return (x > y) - (x < y);
}

void SSF(int n, int st, int* req) {
	printf("SSF: %d", st);
	req = Copy(req, n);
	int cur = st, min = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (abs(cur - req[j]) < abs(cur - req[min])) {
				min = j;
			}
		}
		sum += abs(cur - req[min]);
		printf(" %d", req[min]);
		cur = req[min];
		req[min] = INT_MAX;
	}
	printf("; Sum: %d\n", sum);
	free(req);
}

void Elevator(int n, int st, int* req, bool dir) {
	printf("Elevator: %d", st);
	req = Copy(req, n);
	qsort(req, n, sizeof(int), Comp);
	int i, sum = 0, cur = st;
	for (i = 0; req[i] < st; i++);
	int incr = dir ? 1 : -1;
	i = dir ? i : i - 1;
	for (; i >= 0 && i < n; i += incr) {
		sum += abs(cur - req[i]);
		cur = req[i];
		printf(" %d", req[i]);
		req[i] = -1;
	}
	incr *= (-1); i += incr;
	for (; i >= 0 && i < n; i += incr) {
		if (req[i] == -1) continue;
		sum += abs(cur - req[i]);
		cur = req[i];
		printf(" %d", req[i]);
	}
	printf("; Sum: %d\n", sum);
	free(req);
}

int main() {
	int n, st;
	scanf("%d", &n);
	scanf("%d", &st);
	int* req = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &req[i]);
	}
	FSFC(n, st, req);
	SSF(n, st, req);
	Elevator(n, st, req, true);

	free(req);
	return 0;
}