#include <bits/stdc++.h>

int main() {
  int n = 3;
  char**** mat;
  mat = (char****)malloc(n * sizeof(char***)); 
  for (int i = 0; i < n; i++) {
    mat[i] = (char***) malloc(n* sizeof(char**));
    for (int j = 0; j < n; j++) {
    mat[i][j] = (char**) malloc(n* sizeof(char*));
      for (int k = 0; k < n; k++) {
        mat[i][j][k] = (char*) malloc(n* sizeof(char));
        mat[i][j][k] = "123";
      }
    }
  }
  printf("%s\n", mat[0][1][2]);
}
