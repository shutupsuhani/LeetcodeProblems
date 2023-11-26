#include <iostream>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return "";  // If the input array is empty, return an empty string
        }

        // Take the first string as a reference for comparison
        std::string prefix = strs[0];

        // Iterate through the remaining strings
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            
            // Compare characters until the end of the current prefix or the end of the current string
            while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
                ++j;
            }

            // Trim the prefix if necessary
            prefix = prefix.substr(0, j);

            // If the prefix becomes empty, no common prefix exists, so break the loop
            if (prefix.empty()) {
                break;
            }
        }

        return prefix;  // Return the longest common prefix
    }
};

int main() {
    Solution solution;

    // Example 1
    std::vector<std::string> strs1 = {"flower", "flow", "flight"};
    std::cout << "Example 1: " << solution.longestCommonPrefix(strs1) << std::endl;

    // Example 2
    std::vector<std::string> strs2 = {"dog", "racecar", "car"};
    std::cout << "Example 2: " << solution.longestCommonPrefix(strs2) << std::endl;

    return 0;
}
