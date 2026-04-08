class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int arr[nums.size()];

        
        for(int i = 0; i < nums.size(); i++){
            if(contains(arr, nums.size(), nums[i]))
                return true;
            
            arr[i] = nums[i];
        }
        return false;
    }

    bool contains(const int* arr, int size, int target){
        for(int i = 0; i < size; i++){
            if(arr[i] == target)
                return true;
        }

        return false;
    }

};