class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            if (nums.empty()) return 0;
    
        set<int> s(nums.begin(), nums.end());  
        int maxLength = 0, currentStreak = 0;
    
        for (int num : s) {
            if (s.find(num - 1) == s.end()) {
                int currentNum = num;
                currentStreak = 1;
                
                while (s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    currentStreak++;
                }
    
                maxLength = max(maxLength, currentStreak);
            }
        }
        
        return maxLength;
        }
    };
