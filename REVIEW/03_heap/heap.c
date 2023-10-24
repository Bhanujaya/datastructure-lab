#include <stdio.h>

// Function to return the left child index of a node
int Left(int i) {
    return 2 * i + 1;
}

// Function to return the right child index of a node
int Right(int i) {
    return 2 * i + 2;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the Max Heap property
void MaxHeapify(int A[], int i, int n) {
    int l = Left(i);
    int r = Right(i);
    int swap_position = i;

    if (l <= n && A[l] > A[i]) {
        swap_position = l;
    }
    if (r <= n && A[r] > A[swap_position]) {
        swap_position = r;
    }

    if (swap_position != i) {
        // Swap A[i] and A[swap_position]
        swap(&A[i], &A[swap_position]);
        MaxHeapify(A, swap_position, n);
    }
}

// Function to build a Max Heap from an array
void BuildMaxHeap(int A[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        MaxHeapify(A, i, n);
    }
}




// void MaxHeapDelete(int A[], int* n) {
//     if (*n < 1) {
//         printf("Heap is empty. Cannot delete.\n");
//         return;
//     }
    
//     swap(&A[0], &A[*n]);
//     (*n)--;
//     MaxHeapify(A, 0, *n);
// }




void MaxHeapInsert(int A[], int k, int* n) {
    A[++(*n)] = k;
    int i = *n;
    
    while (i > 1 && A[i] > A[i / 2]) {
        swap(&A[i], &A[i / 2]);
        i = i / 2;
    }
}





int main() {
    int A[100];  // Assuming you have a Max Heap array
    int n = 0;    // Current heap size

    MaxHeapInsert(A, 30, &n);
    MaxHeapInsert(A, 20, &n);
    MaxHeapInsert(A, 42, &n);
    MaxHeapInsert(A, 10, &n);
    MaxHeapInsert(A, 40, &n);

    // int size = sizeof(A) / sizeof(A[0]); //size


    printf("Max Heap after insertions: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", A[i]);
    }

    // MaxHeapDelete(A, &n);


    printf("\nMax Heap after deletion: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
