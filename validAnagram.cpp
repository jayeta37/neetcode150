#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        for(auto char_s : s){
            if(s_map.find(char_s) != s_map.end()){
                s_map[char_s]++;
            }
            else{
                s_map[char_s] = 0;
            }
        }
        for(auto char_t : t){
            if(t_map.find(char_t) != t_map.end()){
                t_map[char_t]++;
            }
            else{
                t_map[char_t] = 0;
            }
        }
        if(s_map == t_map){
            return true;
        }
        return false;
    }
};

void testIsAnagram(string s, string t, bool expected) {
    Solution solution;
    bool result = solution.isAnagram(s, t);
    cout << "Test s = \"" << s << "\", t = \"" << t << "\" - Expected: " << (expected ? "true" : "false")
         << ", Got: " << (result ? "true" : "false") << endl;
}

int main() {
    testIsAnagram("anagram", "nagaram", true);
    testIsAnagram("rat", "car", false);
    testIsAnagram("listen", "silent", true);
    testIsAnagram("hello", "billion", false);

    return 0;
}