#include <bits/stdc++.h>
using namespace std;
/*
1. Naive approach:-
just observe things between i/p and o/p you will see some hint then apply it!
#include<vector>

#include <vector>

void rotateMatrix(std::vector<std::vector<int>> &mat) {
    int n = mat.size();
    std::vector<std::vector<int>> ans(n, std::vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[j][n - 1 - i] = mat[i][j];
        }
    }

    mat = ans;
}
T.C - O(N^2);
S.C-  O(N^2);

2. Optimise solution;
steps:-
a)Transpose
b)reverse the row matrix;
T.C - O(N/2*N/2) --> Transpose array
T.C - O(N*(N/2)) --> reverse the matrix row;
S.C - O(1);
*/
class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    // it is already given it is square matrix;
    int n = matrix.size();
    // in order to write most efficicent solution
    /*
    1) Transpose the matrix;
    2) reverse the matrix;
    */
    // Transpose matrix;
    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        swap(matrix[i][j], matrix[j][i]);
      }
    }

    for (int i = 0; i < n; i++)
    {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};