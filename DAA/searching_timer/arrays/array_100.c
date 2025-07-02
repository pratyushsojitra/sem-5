#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

void write_best_case() {
    FILE *f = fopen("best_100000.txt", "w");
    for (int i = 1; i <= N; i++)
    {
        fprintf(f, "%d ", i);
    }
    fclose(f);
}

void write_worst_case() {
    FILE *f = fopen("worst_100000.txt", "w");
    for (int i = N; i >= 1; i--)
    {
        fprintf(f, "%d ", i);
    }
    fclose(f);
}

void write_average_case() {
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = i+1;
    }
    srand(time(NULL));
    for(int i=0; i< N; i++) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    FILE *f = fopen("average_100000.txt", "w");
    for(int i=0; i<N; i++) {
        fprintf(f, "%d ", arr[i]);
    }
    fclose(f);
}

int main() {
    write_best_case();
    write_average_case();
    write_worst_case();
    return 0;
}