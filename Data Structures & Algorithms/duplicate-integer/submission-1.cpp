class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size() == 0) {
            std::cout << "Array is empty!\n";
            return false;
        }
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] == nums[j]) {
                    return true;
                }
            }
            
        }
        return false;
    }
};