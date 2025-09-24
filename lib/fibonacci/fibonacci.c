#include <stdio.h>
#include <stdlib.h>

int *fib_loop(int n) {
  int *fib_seq = malloc(n * sizeof(int));

  if (fib_seq == NULL) {
    return NULL;
  }

  if (n <= 2) {
    for (int i = 0; i < 2; i++) {
      fib_seq[i] = i;
    } 
    return fib_seq;
  }

  for (int i = 0; i < 2; i++) {
    fib_seq[i] = i; 
  }

  int a = 0;
  int b = 1;
  int begin_seq = 2;

  while (n != 1) {
    fib_seq[begin_seq] = a + b;
    a = b;
    b = fib_seq[begin_seq];
    begin_seq++;
    n--;
  }

 return fib_seq; 
}

int fib_rec(int n, int *prev_seq) {
  int result = 0;

  if (prev_seq[n]) {
    result = prev_seq[n];
    return result;
  }

  if (n <= 2) {
    result = 1;
  } else {
    result = fib_rec(n - 1, prev_seq) + fib_rec(n - 2, prev_seq);
  }

  prev_seq[n] = result;
  return result;
}

int main() {
  int num = 40;
  int *prev_seq = malloc(num * sizeof(int));
  int *seq_loop = fib_loop(num);
  
  if (prev_seq == NULL) {
    return 1;
  }
  
  int fib_seq = fib_rec(num, prev_seq);

  printf("Fibonacci sequence implemented recursion technique.\n");
  for (int i = 0; i <= num; i++) {
    printf("the fibonacci of %d is %d\n", i, prev_seq[i]); 
  } 

  printf("Fibonacci sequence implemented using while loop.\n");
  for (int j = 0; j <= num; j++) {
    printf("the fibonacci of %d is %d\n", j, seq_loop[j]); 
  } 
  
  free(prev_seq);
  free(seq_loop);

  return 0;
}
