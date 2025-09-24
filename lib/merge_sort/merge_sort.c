#include <stdio.h>
#include <stdlib.h>

int *merge(int start, int mid, int end, int *array) {
  // store array item in a temp array to compare them
  int n1 = mid - start + 1;   
  int n2 = end - mid;

  int *a = malloc(n1 * sizeof(int));
  int *b = malloc(n2 * sizeof(int));
  
  if (a == NULL || b == NULL) {
    printf("malloc failed on merge *function");
    return array;
  }
  a[0] = n1;
  b[0] = n2;

  for (int i = 0; i < n1; i++) {
    a[i] = array[start + i]; 
  }
  for (int i = 0; i < n2; i++) {
    b[i] = array[mid + 1 + i];
  }

  int i, j, k;
  i = 0;
  j = 0;
  k = start;

  while (i < n1 && j < n2) {
    if (a[i] >= b[j]) {
      array[k++] = b[j++];
    } else {
      array[k++] = a[i++];
    }
  }

  while (i < n1) {
    array[k++] = a[i++];
  }

  while (j < n2) {
    array[k++] = b[j++]; 
  }

  free(a);
  free(b);

  return array;
}

int *merge_sort(int start, int end, int *array) {
  if (start < end) {
    int mid = (start + end) / 2;

    merge_sort(start, mid, array);
    merge_sort(mid + 1, end, array);

    merge(start, mid, end, array);
  }

  return array;
}

int main() {
  int usorted_items = 8;
  int usorted_arr_first[] = { 13, 10, 5, 3, 4, 1, 1, 0 };
  int usorted_arr_second[] = { 105, 79, 100, 110 };

  int *sort_first = merge_sort(0, 7, usorted_arr_first);
  int *sort_second = merge_sort(0, 3, usorted_arr_second);

  printf("first unsorted array to sort\n");
  for (int i = 0; i < 8; i++) {
    printf("index at %d is %d\n", i, sort_first[i]); 
  }

  printf("second unsorted array to sort\n");
  for (int j = 0; j < 4; j++) {
    printf("index at %d is %d\n", j, sort_second[j]);
  }

  return 0;
}


