#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    /* Approach :-
    1. T.C-O(n^2)  S.C-O(1);
    2. Use Map container and maintain frequency
       T.C - O(NlogN)  S.C - O(N)
    3. Moore voting Algorithm
    T.C - O(N), S.C- O(1);
    */
    int count = 0;
    int candidate = 0;

    for (int num : nums)
    {
      if (count == 0)
      {
        candidate = num;
      }
      if (num == candidate)
        count += 1;
      else
        count -= 1;
    }

    return candidate;
  }
};