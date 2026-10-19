class Solution {
public:
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> output;
    int product = 1;
    int num_0s = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            product *= 1;
            num_0s++;
        }else
            product *= nums[i];
    }

    for(int i = 0; i < nums.size(); i++){
        if((nums[i] != 0 && num_0s) || num_0s == nums.size() || num_0s > 1)
            output.push_back(0);
        else if (nums[i] == 0 && num_0s > 1)
            output.push_back(0);
        else if (nums[i] == 0)
            output.push_back(product);
        else
            output.push_back(product/nums[i]);

    }
    return output;
}
};
