#include <bits/stdc++.h>
using namespace std;

/*
1.Naive Approach:-
T.C - O(N^2);
S.C - O(N);
for(int i =0; i<n; i++) {
  leader = true;
  for(int j =i +1; j<n; j++) {
    if(arr[j]>arr[i]) {
      leader = false;
      break;
    }
  }
  if(leader) ans.push_back(arr[i]);
}
*/

// optimal Approach :-
// coding ninjas solution:-
vector<int> superiorElements(vector<int> &a)
{
  vector<int> v;
  int n = a.size();
  v.push_back(a[n - 1]);
  int longestele = a[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    if (a[i] > longestele)
    {
      v.push_back(a[i]);
      longestele = a[i];
    }
  }
  sort(v.begin(), v.end());
  return v;
}
// T.C - O(N)+O(NLOGN)
// S.C - O(N);