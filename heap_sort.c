#include <stdio.h>

int create_heap(int* a, int n) {
    int i = 0;
    int exchange = 1;
    int tmp = 0;

    while (exchange) {
        exchange = 0;

        for (i = n - 1; i > 0; i--) {
            if (a[i] > a[(i - 1) / 2]) {
                tmp = a[i];
                a[i] = a[(i - 1) / 2];
                a[(i - 1) / 2] = tmp;
                exchange = 1;
            }
        }
    }

    return 0;
}

/*@params:
 * a: the primary heap
 * b: the sorted array to be returned
 * n: total count
 * */
int heap_sort(int* a, int* b, int n) {
    int b_index = 0;
    int a_index = 0;
    int i = 0;

    for (b_index = 0; b_index < n; b_index++) {
        b[b_index] = a[0];
        //Reconstructure heap
        a_index = 0;

        while (1) {
            if (a_index * 2 + 1 < n) { //left child exist
                if (a_index * 2 + 2 < n) { //right child exist
                    if ((a[a_index * 2 + 1] == -1) && (a[a_index * 2 + 2] == -1)) {
                        break;
                    }

                    if (a[a_index * 2 + 1] > a[a_index * 2 + 2]) {
                        a[a_index] = a[a_index * 2 + 1];
                        //if a node is deleted, it is set to -1
                        a[a_index * 2 + 1] = -1;
                        a_index = a_index * 2 + 1;
                        continue;
                    } else {
                        a[a_index] = a[a_index * 2 + 2];
                        a[a_index * 2 + 2] = -1;
                        a_index = a_index * 2 + 2;
                        continue;
                    }
                } else { //right child not exist
                    if (a[a_index * 2 + 1] == -1) {
                        break;
                    } else {
                        a[a_index] = a[a_index * 2 + 1];
                        a[a_index * 2 + 1] = -1;
                        a_index = a_index * 2 + 1;
                        continue;
                    }
                }
            } else {
                break;
            }
        }
    }

    return 0;
}

int main() {
    int i = 0;
    int a[100];
    int b[100];

    for (i = 0; i < 100; i++) {
        a[i] = i * 2;
    }

    create_heap(a, 100);
    heap_sort(a, b, 100);

    for (i = 0; i < 100; i++) {
        printf("%d ", b[i]);
    }

    printf("\n");

    return  0;
}
