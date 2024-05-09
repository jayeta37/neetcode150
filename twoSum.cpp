// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
    public:
    vector<int> twoSum(vector<int> &nums, int target){
        unordered_map<int, int> indexMap;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];

            if(indexMap.find(complement) != indexMap.end()){
                return {indexMap[complement], i};
            }
            indexMap[nums[i]] = i;
        }
        return {};
    }
};

void testTwoSums(vector<int> &nums, int target, vector<int> &expected){
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    cout << "Expected: " << expected[0] << ", " << expected[1] << "\t" << "Result: " << result[0] << ", " << result[1] << endl;
}

int main(){
    vector<int> nums1, res1, nums2, res2, nums3, res3;
    nums1 = {2, 7, 11, 15};
    res1 = {0, 1};

    nums2 = {3,2,4};
    res2 = {1,2};

    nums3 = {3,3};
    res3 = {0,1};

    testTwoSums(nums1, 9, res1);
    testTwoSums(nums2, 6, res2);
    testTwoSums(nums3, 6, res3);
    return 0;
}