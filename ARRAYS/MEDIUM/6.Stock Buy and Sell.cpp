#include <bits/stdc++.h>
using namespace std;

/*
Approaches:-
1) Naive approach
T.C - O(N^2) S.C - O(1);
int n = prices.size();
        int maxi = 0;
        for(int i =0; i<n; i++) {
            for(int j =i; j<n; j++) {
                int diff = prices[j]-prices[i];
                maxi = max(maxi,diff);
            }
        }
        cout<<maxi<<endl;

2) Recursion approach
here we can use recursion bcoz the problems is based on decision and choices

3)optimal Approach
 T.C - O(N) S.C - O(1);
*/
// leetcode solution
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int profit = 0;
    int mini = INT_MAX;

    int n = prices.size();

    for (int i = 0; i < n; i++)
    {
      mini = min(mini, prices[i]);
      profit = max(profit, prices[i] - mini);
    }

    return profit;
  }
};