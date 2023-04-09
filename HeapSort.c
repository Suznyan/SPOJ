#include <stdbool.h>
#include <stdio.h>

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void max_heapify(int *a, int heapSize, int i) {
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    int largest = i;

    if (L <= heapSize && a[L] > a[i]) largest = L;
    if (R <= heapSize && a[R] > a[largest]) largest = R;
    if (largest != i) {
        swap(&a[i], &a[largest]);
        max_heapify(a, heapSize, largest);
    }
}

void min_heapify(int *a, int heapSize, int i) {
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    int smallest = i;

    if (L <= heapSize && a[L] < a[i]) smallest = L;
    if (R <= heapSize && a[R] < a[smallest]) smallest = R;
    if (smallest != i) {
        swap(&a[i], &a[smallest]);
        min_heapify(a, heapSize, smallest);
    }
}

void build_max_heap(int *a, int aSize) {
    for (int i = aSize / 2; i >= 0; i--) max_heapify(a, aSize, i);
}

void build_min_heap(int *a, int aSize) {
    for (int i = aSize / 2; i >= 0; i--) min_heapify(a, aSize, i);
}

void HeapSort(int *a, int n, bool order) {
    if (order) {
        build_max_heap(a, n);
        for (int i = n; i > 0; i--) {
            swap(&a[0], &a[i]);
            max_heapify(a, --n, 0);
        }
    } else {
        build_min_heap(a, n);
        for (int i = n; i > 0; i--) {
            swap(&a[0], &a[i]);
            min_heapify(a, --n, 0);
        }
    }
}

int main() {
    int a[] = {99, 0, 5, 20, 123, 0, -1, 72, 21, 22, 13, 8, 7, 67, 29, 1, 2, 4};
    int *p = &a[0];
    int size = sizeof(a) / sizeof(*a);

    HeapSort(p, size - 1, false);
    for (int i = 0; i < size; i++) printf("%d ", a[i]);

    return 0;
}
