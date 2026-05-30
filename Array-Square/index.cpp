// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

// Example 1:

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].
// Example 2:

// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]

#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> sortedSquares(vector<int> &nums)
{
    int size = nums.size();
    vector<int> neg;
    vector<int> pos;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] < 0)
            neg.push_back(nums[i]);
        else
            pos.push_back(nums[i]);
    }
    if (neg.size() == 0)
    {
        for (int i = 0; i < pos.size(); i++)
            pos[i] = pos[i] * pos[i];
        return pos;
    }
    if (pos.size() == 0)
    {
        for (int i = 0; i < neg.size(); i++)
            neg[i] = neg[i] * neg[i];
        reverse(neg.begin(), neg.end());
        return neg;
    }

    int i = 0, j = 0;
    int id = 0;
    int n = neg.size();
    int m = pos.size();
    vector<int> res(n + m);

    for (int i = 0; i < n; i++)
        neg[i] = neg[i] * neg[i];
    reverse(neg.begin(), neg.end());

    for (int i = 0; i < m; i++)
        pos[i] = pos[i] * pos[i];

    while (i < n and j < m)
    {
        if (neg[i] <= pos[j])
        {
            res[id] = neg[i];
            id++;
            i++;
        }
        else
        {
            res[id] = pos[j];
            id++;
            j++;
        }
    }
    while (i < n)
    {
        res[id] = neg[i];
        id++;
        i++;
    }
    while (j < m)
    {
        res[id] = pos[j];
        id++;
        j++;
    }

    return res;
}