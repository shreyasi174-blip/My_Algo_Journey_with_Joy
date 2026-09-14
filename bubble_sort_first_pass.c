#include <stdio.h>
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;

        for (j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int main() {

    int arr[10] = {64, 25, 12, 22, 11, 90, 34, 7, 56, 18};
    int n = 10;
    int i, j, temp;

    printf("Original Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    for (j = 0; j < n - 1; j++) {

        if (arr[j] > arr[j + 1]) {

            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }

    printf("\n\nIntermediate Array after 1st pass:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    bubbleSort(arr, n);

    printf("\n\nFinal Sorted Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
