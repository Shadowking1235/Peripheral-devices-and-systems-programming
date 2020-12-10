#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int main() {
	int n, m;
	scanf("%d %d", &m, &n);
	int* all = (int *)malloc(m * sizeof(int));
	int** used = (int **)malloc(n * sizeof(int*));
	int** need = (int **)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		used[i] = (int *)malloc(m * sizeof(int));
		need[i] = (int *)malloc(m * sizeof(int));
	}
	for (int i = 0; i < m; i++) scanf("%d", &all[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &used[i][j]);
			all[j] -= used[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &need[i][j]);
		}
	}
	bool changed = true;
	int* safe = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) safe[i] = -1;
	int k = 0;
	while (changed) {
		changed = false;
		for (int i = 0; i < n; i++) {
			bool avail = true;
			for (int j = 0; j < m; j++) {
				if (need[i] != NULL && need[i][j] > all[j]) avail = false;
			}
			if (avail && need[i] != NULL) {
				safe[k] = i; k++;
				free(need[i]);
				need[i] = NULL;
				for (int j = 0; j < m; j++) {
					all[j] += used[i][j];
				}
				changed = true;
			}
		}
	}
	bool notSafe = false;
	for (int i = 0; i < n; i++) {
		if (safe[i] < 0) notSafe = true;
	}
	if (notSafe) {
		printf("Cycle found");
		return 0;
	}
	printf("Safe sequence:");
	for (int i = 0; i < n; i++) {
		printf(" %d", safe[i] + 1);
	}
	for (int i = 0; i < n; i++) {
		free(used[i]);
		free(need[i]);
	}
	free(all);
	free(used);
	free(need);
	return 0;
}