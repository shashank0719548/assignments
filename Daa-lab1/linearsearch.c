#include <stdio.h>

int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int binary_search(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key, result;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter key to search: ");
    scanf("%d", &key);
    result = linear_search(arr, n, key);
    if (result != -1)
        printf("Linear Search: Found at index %d\n", result);
    else
        printf("Linear Search: Not found\n");
    result = binary_search(arr, n, key);
    if (result != -1)
        printf("Binary Search: Found at index %d\n", result);
    else
        printf("Binary Search: Not found\n");
    return 0;
}