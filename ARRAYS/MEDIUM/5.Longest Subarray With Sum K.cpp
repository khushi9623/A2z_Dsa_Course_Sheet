#include <bits/stdc++.h>
using namespace std;
// coding ninjas solution this is based on sliding window approach
int longestSubarrayWithSumK(vector<int> a, long long k)
{

  int j = 0;
  int i = 0;
  int len = 0;
  int n = a.size();
  int sum = a[0];

  while (j < n)
  {

    while (i <= j && sum > k)
    {
      sum -= a[i];
      i++;
    }
    if (sum == k)
    {
      len = max(len, j - i + 1);
    }
    j++;
    if (j < n)
      sum += a[j];
  }
  return len;
}