#include <stdio.h>
int maxElement(int arr[], int left, int right) {
    if (left == right) {
        return arr[left];
    }
    int mid = (left + right) / 2;
	    int left_max = maxElement(arr, left, mid);
    int right_max = maxElement(arr, mid + 1, right);
    return (left_max > right_max) ? left_max : right_max;
}
int main() {
    int arr[] = {2, 8, 6, 10, 3, 5, 9};
    int n = sizeof(arr);
    int max_val = maxElement(arr, 0, n - 1);
    printf("Maximum element in the array is %d\n", max_val);
    return 0;
}
