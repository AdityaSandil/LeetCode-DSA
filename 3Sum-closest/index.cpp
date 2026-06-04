// Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

// Constraints:

// 3 <= nums.length <= 500
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104

#include <bits/stdc++.h>
#include <vector>
using namespace std;
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int result=0;
        int mindiff = INT_MAX;
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                int diff = abs(sum-target);
                if(diff<mindiff)
                {
                    mindiff=diff;
                    result=sum;
                }
                if(sum<target) j++;
                else if (sum>target) k--;
                else {
                    //exact sum==target
                    return sum;
                }
            }
        }
        return result;
    }