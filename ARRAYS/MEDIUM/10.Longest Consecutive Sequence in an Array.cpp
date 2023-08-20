#include <bits/stdc++.h>
using namespace std;
/*
1. Naive approach:-
  arr[] = {102,4,100,1,101,3,2,1,1};
  Consecutive sequence is 1 2 3 4 5 6
  i.e x , x+1, x+2, x+3 ................ are consecutive sequence

  we  will take x and will say my consecutive seq start from this element and will see for x+1 ...

bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); //size of array
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size(); //size of array
    int longest = 1;
    //pick a element and search for its
    //consecutive numbers:
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        //search for consecutive numbers
        //using linear search:
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}
T.C - O(N^2) S.C- O(1);

2)Better Approach :-
sort the array
arr[] = {100,102,100,101,101,4,3,2,3,2,1,1,1};
sort the array = {1,1,1,2,2,2,3,3,4,100,100,101,101,102};

take

cntcurr = 0;  lastsmallest = INT_MIN;  longest =1;

1 to be part of sequenece smallest element must be 0 but it is not as it is not part
of sequence, it will say i will start sequenec from my self;

code :-

sort(arr, arr+n);
int longest =1;
int countcurr=0;
int last_smaller = INT_MIN;
for(int i =0; i<n; i++) {
  if(arr[i]-1 == last_smaller) {
    countcurr++;
    last_smaller = arr[i];
  }
  else if(arr[i]==last_smaller) {
    //kuch nhi karna hai;
  }
  else if(arr[i]!= last_element) {
    countcurr=1;
    last_smaller = arr[i];
  }
  longest = max(longest,countcurr);
}
cout<<longest<<endl;
T.C - O(NLOGN)+O(N);
S.C - O(1);

3)Optimal Approach :-
arr[] = {102,4,100,1,101,3,2,1,1};
we will place all element in unordered_set

set {102,4,100,1,101,3,2};
      ^
      |

      we are heading from 102 is 101 present so that will not be a start of sequence will move to 4 and so on

      for 102 --> 101
      for  4  --> 3
      for 100 --> 99 not present
          101 -->102 iteration is 3
      for  1--> 0 not present
           1-->2-->3-->4 iteration is 4

      O(N) --> INSERTING IN SET;
      IN SEARCHING IT DOESNT TAKE O(N^2) BCOZ ITERATIONS ARE IN WHILE 3+4 =7 THEREFORE O(2N);

      T.C - O(N)+O(2N);
      S.C - O(N);
*/
// leetcode :- optimal
class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    int n = nums.size();
    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
      st.insert(nums[i]);
    }
    int longest = 0;
    for (auto it : st)
    {
      if (st.find(it - 1) == st.end())
      {
        int cnt = 1;
        int x = it;
        while (st.find(x + 1) != st.end())
        {
          cnt++;
          x++;
        }
        longest = max(longest, cnt);
      }
    }
    return longest;
  }
};