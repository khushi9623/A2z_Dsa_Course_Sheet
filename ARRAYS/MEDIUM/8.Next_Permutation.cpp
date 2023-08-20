#include <bits/stdc++.h>
using namespace std;
/*
int arr[] = {3,1,2}
    o/p :- {3,2,1};

    possible permutation which are lexicography arranged
    {1,2,3}
    {1,3,2}
    {2,1,3}
    {2,3,1}
    {3,1,2}
    {3,2,1}

1)Naive approach :-
   1) Generate all possible permutation in a sorted order // Recursion is required
   2)Do linear search
   3)Next permutation

T.C - O(N!*N)

2)Better Approach:-
in C++ we have STL lib which will return next permutation of given sequence
syntax :-
   next_permutation (A.begin(), A.end());

3) Optimal Approach :-
in dictionary we place word s according to longest prefix
i.e 1) raj;
    2) rax;
    3) rbx;
  this how the words are placed so this observation we will take carry forward
  finding longest prefix match

  arr[]= { 2,1,5,4,3,0,0};

  we will take longest prefix match as 2 1 5 4 3 and will rearrrange  0 0 element such that we will get next
  permutation but it is not possible with this match

  so we will do same process

  we find out 2 would be longest prefix match and by swapping 1 with greater number and which is smallest among alll possible option

  so next permutation 2 3 5 4 1 0 0 but this is not optimal then sort the remain
          ans 2 3 0 0 1 4 5

  steps :-
  1) longer prefix array
     find a[i]<a[i+1]
  2) find >A but the smallest one so that you stay close
  3) try to sort the remain element

  edge case: - if ar[] = {5,4,3,2,1,0,0} therev is no fall array is increase
    next permutation is 0 0 1 2 3 4 5

    T.C - O(3N);
    S.C- O(1);
*/
class Solution
{
public:
  void nextPermutation(vector<int> &A)
  {
    int idx = -1;
    int n = A.size();
    for (int i = n - 2; i >= 0; i--)
    {
      if (A[i] < A[i + 1])
      {
        idx = i;
        break;
      }
    }

    if (idx == -1)
    {
      reverse(A.begin(), A.end());
    }
    else
    {
      for (int i = n - 1; i >= idx; i--)
      {
        if (A[i] > A[idx])
        {
          swap(A[i], A[idx]);
          break;
        }
      }
      reverse(A.begin() + idx + 1, A.end());
    }
  }
};