/**
 *
 * Given an array of distinct integers  and a target integer
 *
 * return all list of unique combinations of candidates whose chosen numbers sum to target
 *
 *
 * combinations are unique
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<vector<int>> ans;

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        ans.clear();
        vector<int> temp;
        solve(0, candidates, temp, target);
        return ans;
    }
    void solve(int i, vector<int> &nums, vector<int> &temp, int target)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (target < 0)
            return;
        if (i == nums.size())
            return;

        solve(i + 1, nums, temp, target);

        temp.push_back(nums[i]);
        solve(i, nums, temp, target - nums[i]);
        temp.pop_back();
    }

    
};
int main()
{
    vector<int> nums{2, 3, 6, 7};
    int target = 7;
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum(nums, target);
    for (auto it : ans)
    {
        for (auto jt : it)
        {
            cout << jt << " ";
        }
        cout << endl;
    }
    return 0;
}

/**
 * Store the unique possible combinations
 * that sums upto the target
 *
 * for a particular element we have a unlimited choice
 * we can choose a element as many times as we want
 *
 * if sum reaches to zero then we found the sum we have store this possible combination
 * in the array
 *
 * in case if sum is neagative we will start not exlporing this combination
 *
 * we have two options to go to choose the current element
 * or go don;t choose the current element and go with the other one
 *
 * in backtracking we do undo , the choice , to build the new choice 
 * 
 * in  recurion and backtracking give birth to a descion and let it live the life 
 * until the desion is no longer valid (by the form of base cases or some other else )
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */