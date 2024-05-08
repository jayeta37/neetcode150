#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }

        int s_array[26] = {0};
        int t_array[26] = {0};

        for(int i = 0; i<s.length(); i++){
            s_array[s[i] - 'a']++;
            t_array[t[i] - 'a']++;
        }

        for(int i=0; i < 26; i++){
            if(s_array[i] != t_array[i]){
                return false;
            }
        }
        return true;
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