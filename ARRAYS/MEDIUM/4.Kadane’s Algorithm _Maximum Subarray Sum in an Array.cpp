#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    /*
    for eg :- {5,4,-1,7,8};
    Brute force approach find all possible array
     {5}               {4}            {-1}          {7}       {8}
     {5,4}             {4,-1}         {-1,7}        {7,8}
     {5,4,-1}          {4,-1,7}       {-1,7,8}
     {5,4,-1,7}        {4,-1,7,8}
     {5,4,-1}
     {5,4,-1,7}
     {5,4,-1,7,8}

     maximum subarray sum 23  {5,4,-1,7,8}
     T.C - O(n^3)  S.C- o(1)
     for(i from 0 to n) {
         for(j from i to n) {
             subarrayloop
             for(k from i to j) {
                 add wala loop
             }
         }
     }

     o(n^3) ---> o(n^2)
      for(i from 0 to n) {
          int sum =0;
         for(j from i to n) {
             sum+=a[i];

         }
     }

     o(n^2) ---> o(n) Kadanes algorithm

     Kadanes algorithm
     initially
     sum =0;
     maxi = a[0]
     after linear traversal
     procedure must be follow :-

     1.sum=sum+a[i];
     2.maxi update maxi = max(sum,maxi);
     3.if (sum<0)sum=0;

     for eg :- nums = [-2,1,-3,4,-1,2,1,-5,4]
     i=0   sum= 0+(-2)=-2   maxi= max(-2,-2)=-2 sum=0;
     i=1   sum= 0+(1) = 1   maxi= max(-2,1)=1   sum=1;
     i=2   sum= 1+(-3)=-2   maxi= max(1,-2)=1   sum=0;
     i=3   sum= 0+(4)=4     maxi= max(1,4)=4    sum=4;
     i=4   sum= 4+(-1)=3    maxi= max(3,4)=4    sum=3;
     i=5   sum= 3+(2)=5     maxi= max(4,5)=5    sum=5;
     i=6   sum= 5+(1)=6     maxi= max(5,6)=6    sum=6;
     i=7   sum= 6+(-5)=1    maxi= max(6,1)=6    sum=1;
     i=8   sum= 1+(4)=5     maxi= max(5,6)=6    sum=5;

     after all iteration we get maxi sum = 6;

     ans :-  The subarray [4,-1,2,1] has the largest sum 6.

    */

    int sum = 0;
    int n = nums.size();
    int maxi = nums[0];
    for (int i = 0; i < n; i++)
    {
      sum = sum + nums[i];
      maxi = max(maxi, sum);
      if (sum < 0)
      {
        sum = 0;
      }
    }
    return maxi;
  }
};