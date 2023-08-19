#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  void sortColors(vector<int> &arr)
  {
    /* Approach
    1. Sort function T.C -O(nlogn) S.C - o(1);
    2. Counting approach  T.C - o(4n) S.C - o(1);
    3. Dutch national Algorithm DFA
       consider three ptr low, mid , high;
       a[0.....low-1] ----> 0
       a[high+1.....n]----> 2
       the algo stops when mid passes the high
       so all things move around mid only

       Three condition, mid pointing

       0--> swap(a[low],a[mid]) low++, mid++;

       1-->  low++;

       2--> swap(a[low], a[high]) low++, high--;

       for eg:-  0 1 1 0 1 2 1 2 0 0 0 1
                 ^                     ^
                 |                     |
                 mid,low               high

                 after applying the algorithm ptr position
                 lloks like this

                           low    high   mid
                 0 0 0 0 0 1  1 1  1  1   2 2

       */
    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {

      if (arr[mid] == 0)
      {
        swap(arr[mid++], arr[low++]);
      }

      else if (arr[mid] == 1)
      {
        mid++;
      }
      else
      {
        swap(arr[mid], arr[high--]);
      }
    }
  }
};