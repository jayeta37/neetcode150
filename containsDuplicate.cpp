#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(auto num : nums){
            if(seen.find(num) != seen.end()){
                return true;
            }
            else{
                seen.insert(num);
            }
        }
        return false;
    }
};

void testContainsDuplicate(vector<int> nums, bool expected){
    Solution solution;
    bool result = solution.containsDuplicate(nums);
    cout << "Expected: " << (expected ? "true" : "false") << ", Got: " << (result ? "true" : "false") << endl;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    testContainsDuplicate(nums1, true);  
    testContainsDuplicate(nums2, false);
    testContainsDuplicate(nums3, true);

    return 0;
}