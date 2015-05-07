#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[256];
        int i;
        int basePos = 0;
        int maxLength = -1;
        int curLength = 0;
        
        for (i = 0; i < 256; i++) {
            pos[i] = -1;
        }

        for(i = 0; i < s.length(); i++) {
            if (pos[s[i]] < basePos) {
                curLength++;
            } else {
                if (curLength > maxLength)
                    maxLength = curLength;
                curLength = 0;
                basePos = pos[s[i]] + 1;
            }
            pos[s[i]] = i;
        }
        
        if (curLength > maxLength)
            maxLength = curLength;
        
        return maxLength;
    }
};


int main(void)
{
    Solution *solution = new Solution;
    
    solution->lengthOfLongestSubstring("bbbb");
    solution->lengthOfLongestSubstring("abcdabc");

    return 0;
}
