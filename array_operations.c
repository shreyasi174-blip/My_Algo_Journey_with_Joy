#include <stdio.h>

void bubbleSortDescending(int arr[], int start, int end) {
    int temp;
    for (int i = start; i <= end; i++) {
        for (int j = start; j < end; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quickSortAscending(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high]; 
        int i = low - 1;
        int temp;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) { 
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
  
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1; 

        quickSortAscending(arr, low, pi - 1);
        quickSortAscending(arr, pi + 1, high);
    }
}

void quickSortDescending(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high]; 
        int i = low - 1;
        int temp;

        for (int j = low; j < high; j++) {
            if (arr[j] >= pivot) { 
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1; 

        quickSortDescending(arr, low, pi - 1);
        quickSortDescending(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {12, 34, 54, 2, 7, 9, 23, 45, 1};
    int target, i;
    int mid = 4; 

    printf("Original Array: ");
    for(i = 0; i < 9; i++) 
    printf("%d ", arr[i]);
    printf("\n");
    printf("Enter element to search: ");
    scanf("%d", &target);

    if (arr[mid] == target) {
        printf("Element found at the middle index: %d\n", mid);
        bubbleSortDescending(arr, 0, mid - 1);
        quickSortDescending(arr, mid + 1, 8);
    } 
    else {
        printf("Not found in middle! Inserting %d at index %d...\n", target, mid);
        arr[mid] = target;
        quickSortAscending(arr, 0, 8);
    }

    printf("Final Array: ");
    for(i = 0; i < 9; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
