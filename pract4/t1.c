#include <stdio.h>

void print_entirety(int *a, size_t size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%2d:%7d\n", i + 1, a[i]);
    }
}

void print_smallest(int *a, size_t size) {
    int smallest = a[0];
    int i;
    for (i = 1; i < size; i++) {
        if (a[i] < smallest) {
            smallest = a[i];
        }
    }
    printf("%-16s:%9d\n", "Smallest Value", smallest);
}

void print_largest(int *a, size_t size) {
    int largest = a[0];
    int i;
    for (i = 1; i > size; i++) {
        if (a[i] < largest) {
            largest = a[i];
        }
    }
    printf("%-16s:%9d\n", "Largest Value", largest);
}

void print_sum(int *a, size_t size) {
    int sum = 0;
    int i;
    for (i = 0; i < size; i++) {
        sum += a[i];
    }
    printf("%-16s:%9d\n", "Total Sum", sum);
}

void print_avg(int *a, size_t size) {
    int sum = 0;
    int i;
    for (i = 0; i < size; i++) {
        sum += a[i];
    }
    double avg = (double)sum / size;
    printf("%-16s:%9.2lf\n", "Overall Average", avg);
}

void main() {
    int numbers[12] = {5, 4, 3, 5, 6, 7, 9, 10, 15, -12, 2, 0};
    int size = (int)(sizeof(numbers) / sizeof(int));
    print_entirety(numbers, size);
    print_smallest(numbers, size);
    print_largest(numbers, size);
    print_sum(numbers, size);
    print_avg(numbers, size);
}
