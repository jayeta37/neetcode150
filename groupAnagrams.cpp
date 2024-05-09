// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
    public:
    vector<vector<string>> groupAnagrams(vector<string> &strs){
        unordered_map<string, vector<string>> stringMap; 
        for (auto s : strs){
            string key = s;
            sort(key.begin(), key.end());
            stringMap[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto &sm : stringMap){
            result.push_back(sm.second);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result1 = solution.groupAnagrams(strs1);
    
    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : result1) {
        cout << "[";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}