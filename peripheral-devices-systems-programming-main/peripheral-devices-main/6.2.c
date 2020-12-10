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

void FCFS(int n, int* burst) {
	printf("FCFS:\t\t");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < burst[i]; j++) {
			printf("%d", i);
		}
	}
	printf("\n");
}

void SJF(int n, int* burst, int* arrival) {
	printf("SJF:\t\t");
	burst = Copy(burst, n);
	int time = 0, current = 0, count = 0;
	while (true) {
		for (int i = 0; i < n; i++) if (burst[i] != 0 && arrival[i] <= time) { current = i; break; }
		for (int i = current + 1; i < n; i++) {
			if (burst[i] != 0 && arrival[i] <= time && burst[i] < burst[current]) {
				current = i;
			}
		}
		printf("%d", current);
		burst[current]--;
		if (burst[current] == 0) count++;
		time++;
		if (count == n) break;
	}
	printf("\n");
	free(burst);
}

void RR(int n, int* burst, int q) {
	printf("RR,%d:\t\t",q);
	burst = Copy(burst, n);
	int count = 0, current = 0;
	while (true) {
		if (burst[current] == 0) {
			current = (current + 1) % n;
			continue;
		}
		for (int i = 0; i < q; i++) {
			printf("%d", current);
			burst[current]--;
			if (burst[current] == 0) {
				count++;
				break;
			}
		}
		current = (current + 1) % n;
		if (count == n) break;
	}
	printf("\n");
	free(burst);
}

void Priority(int n, int* burst, int* priority) {
	printf("Priority:\t");
	burst = Copy(burst, n);
	int current = 0;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) if (burst[i] != 0) { current = i; break; }
		for (int i = current + 1; i < n; i++) {
			if (burst[i] != 0 && priority[i] < priority[current]) current = i;
		}
		for (int i = 0; i < burst[current]; i++) {
			printf("%d", current);
		}
		burst[current] = 0;
	}
	printf("\n");
	free(burst);
}

int main() {
	int n;
	scanf("%d", &n);
	int* burst = (int *)malloc(n * sizeof(int));
	int* arrival = (int *)malloc(n * sizeof(int));
	int* priority = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &burst[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &arrival[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &priority[i]);
	}
	FCFS(n, burst);
	SJF(n, burst, arrival);
	RR(n, burst, 2);
	Priority(n, burst, priority);
	free(burst);
	return 0;
}