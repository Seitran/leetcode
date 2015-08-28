#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
    	int i, j, step;
    	string ans = "";
    	int total = (numRows - 1) * 2;

    	if (numRows ==  1)
    		return s;

    	for (i = 0; i < numRows; i++) {
    		step = i * 2;
    		if (!step) step = total - step;
    		for (j = i; j < s.size(); j += step) {
    			ans += s[j];
    			step = total - step;
    			if (!step) step = total - step;
    		}
    	}
    	return ans;
    }
};

int main(void)
{
	Solution s;
	cout << s.convert("ABCD", 4) << endl;
	cout << "PAHNAPLSIIGYIR" << endl;
	return 0;
}