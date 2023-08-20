#include <bits/stdc++.h>
using namespace std;
/*
1. Naive Approach
As given that array contain equal no of pos and neg element you have to arrange it in alternate way without changing its
order

for eg :- arr[] = {3,1,-2,-5,2,-4}
          o/p - {3,-2,1,-5,2,-4};
         collect pos and neg element in different array and iterate from 0 to n/2 as per
         observation at even pos element to placed and neg element in odd pos follow this;
         and we will get output!

         leetcode solution :-
         class Solution {
    public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>pos;
        vector<int>neg;

        for(int i =0; i<n; i++) {
            if(nums[i]>0) {
                pos.push_back(nums[i]);
            }
            else {
                neg.push_back(nums[i]);
            }
        }

        for(int i =0; i<(n/2); i++) {
            nums[2*i]=pos[i];
            nums[2*i+1]= neg[i];
        }

        return nums;

    }
};
here T.C - O(2N)   S.C-O(N);

Can we make O(2N)-----> O(N);
yes one can observe that eve position pos and at odd neg ;
*/
// leetcode solution:-
class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {
    // if you observe the vector carefully you will see that pos element is at even places
    // and negative number is at odd places
    int n = nums.size();
    vector<int> ans(n, 0);
    int i = 0, j = 1;

    for (auto num : nums)
    {
      if (num > 0)
      {
        ans[i] = num;
        i += 2;
      }
      else if (num < 0)
      {
        ans[j] = num;
        j += 2;
      }
    }
    return ans;
  }
};

/*there will be follow up question if pos!= neg arrange it alternate order without disturbing there sequence
case 1 :- pos>neg
case 2 :- pos<neg
we will fall back to brute force approach that we will take two array and will place pos and neg element in their
respective order they are in array

for eg :-
 arr[] = {1,2,-4,-5,3,6};
 o/p :- {1,-4,2,-5,3,6};

 here pos = {1,2,3,6};
      neg = {-4,-5};
      smallest size is 2 i.e we will get 4 length in which element are alternate placed.

      we will iterate from 0 to smallest size i.e neg.size() and will place according to given condition

      array will be {1,-4,2,-5};

  now we have to place a remaining element i.e 3 6  it should be placed at indx 4

  indx = neg.size()*2 ;
  iterate looop from neg.size()---> pos.size() placed eleement at indx and increment it;

  */
// follow up question :-
vector<int> alternateNumbers(vector<int> &a)
{
  vector<int> pos, neg;
  int n = a.size();

  for (int i = 0; i < n; i++)
  {
    if (a[i] > 0)
    {
      pos.push_back(a[i]);
    }
    else
    {
      neg.push_back(a[i]);
    }
  }

  int n1 = pos.size();
  int n2 = neg.size();

  if (n1 < n2)
  {
    for (int i = 0; i < n1; i++)
    {
      a[i * 2] = pos[i];
      a[i * 2 + 1] = neg[i];
    }
    int idx = n1 * 2;
    for (int i = n1; i < n2; i++)
    {
      a[idx] = neg[i];
      idx++;
    }
  }
  else
  {
    for (int i = 0; i < n2; i++)
    {
      a[i * 2] = pos[i];
      a[i * 2 + 1] = neg[i];
    }
    int idx = n2 * 2;
    for (int i = n2; i < n1; i++)
    {
      a[idx] = pos[i];
      idx++;
    }
  }
  return a;
}
