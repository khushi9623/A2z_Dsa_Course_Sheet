#include <bits/stdc++.h>
using namespace std;
/*
1. Naive approach:-
T.C - O(N^3) S.C- O(1);
void row(int i,vector<vector<int>>&arr, int m) {
  for(int j =0; j<m; j++) {
    if(arr[i][j]!=0) {
      arr[i][j]=-1;
    }
  }
}
void col(int j,vector<vector<int>>&arr,int n) {
  for(int i =0; i<n; i++) {
    if(arr[i][j]!=0) {
      arr[i][j]=-1;
    }
  }
}
vector<vector<int>> zeroMatrix(vector<vector<int>> &arr, int n, int m) {
    for(int i =0; i<n; i++) {
      for(int j =0; j<m; j++) {
        if(arr[i][j]==0) {
                   row(i,arr,m);
           col(j,arr,n);
        }
      }
    }

    for(int i =0; i<n; i++) {
      for(int j =0; j<m; j++) {
        if(arr[i][j]==-1) {
          arr[i][j]=0;
        }
      }
    }
    return arr;
}

2) Traversing 2-D array takes o(N^2) can we make it O(n^3)---> O(n^2)

yes, will take extra row and col will marke it and later will mark respective rows and column element

vector<vector<int>> zeroMatrix(vector<vector<int>> &arr, int n, int m) {
      int row[n]= {0};
      int col[m]= {0};

    for(int i =0; i<n; i++) {
      for(int j =0; j<m; j++) {
        if(arr[i][j]==0) {
          row[i]=1;
          col[j]=1;
        }
      }
    }

    for(int i =0; i<n; i++) {
      for(int j =0; j<m; j++) {
        if(row[i]==1 || col[j]==1) {
          arr[i][j]=0;
        }
      }
    }
    return arr;
}

T.C -O(2*N*M) S.C-O(N)+O(M);

3)Optimal approach;
T.C - O(2*N*M) S.C - O(1);
*/
// Leetcode solution
class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    // Rows length is given by:-
    int n = matrix.size();
    // column length is given by:-
    int m = matrix[0].size();

    int col0 = 1;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (matrix[i][j] == 0)
        {
          // mark the rows and column;
          matrix[i][0] = 0;
          if (j != 0)
          {
            matrix[0][j] = 0;
          }
          else
          {
            col0 = 0;
          }
        }
      }
    }
    for (int i = 1; i < n; i++)
    {
      for (int j = 1; j < m; j++)
      {
        if (matrix[i][j] != 0)
        {
          if (matrix[0][j] == 0 || matrix[i][0] == 0)
          {
            matrix[i][j] = 0;
          }
        }
      }
    }

    if (matrix[0][0] == 0)
    {
      for (int j = 0; j < m; j++)
      {
        matrix[0][j] = 0;
      }
    }

    if (col0 == 0)
    {
      for (int i = 0; i < n; i++)
      {
        matrix[i][0] = 0;
      }
    }
  }
};