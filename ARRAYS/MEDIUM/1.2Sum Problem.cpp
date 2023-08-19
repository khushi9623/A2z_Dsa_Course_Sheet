#include <bits/stdc++.h>
using namespace std;
/*
1.Naive Approach
   T.C - O(N^2)  S.C -O(1);
    bool flag = false;
    int ele1 =0;
    int ele2 =0;
   for(int i =0; i<n; i++) {
      for(int j =0; j<n; j++) {
        if(i==j) continue;
        else if(arr[i]+arr[j]==target) {
             ele1 = i;
             ele2 = j;
             flag = true;
        }
      }
      if(flag) break;
   }
   cout<<ele1<<" "<<ele2<<endl;


2. Optimal Approach
    we are using unordered map  in this insertion and deletion occur
         o(1) i.e is linear time so
         T.C o(N) - linear time
         S.C o(N) - map storage extra space taken
        for eg:-   2 6 5 8 11 target= 14;
         index     0 1 2 3  4

      case 1:   2 6 5 8 11
                i

                14-2 = 12, as 12 is not present in a map then put (2,0)
                in a map and so on..

       case 4 :  2 6 5 8 11   map{{2,0} {6,1} {5,2} {8,3} {11,4} }
                       i
        as 14-8 = 6 present in a map
        ans : - (3,1)

*/
// Leetcode solution
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    vector<int> ans;
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      if (mp.find(target - nums[i]) != mp.end())
      { // find returns a ptr of key
        ans.push_back(mp[target - nums[i]]);
        ans.push_back(i);
      }
      mp[nums[i]] = i;
    }
    return ans;
  }
};
