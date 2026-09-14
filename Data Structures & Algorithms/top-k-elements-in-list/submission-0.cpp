#include <unordered_map>
#include <utility>
#include <algorithm>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_occurences;
        for(size_t i = 0; i < nums.size(); i++){
            if(num_occurences.find(nums[i]) == num_occurences.end())
                num_occurences.emplace(nums[i], 1);
            else
                num_occurences[nums[i]]++; // e.g from {1, 0} to {1,1}
        }

        vector<std::pair<int, int>> vec;
        for(std::pair<int, int> occurences : num_occurences){
            vec.push_back(occurences);
        }

        // sort in descending order based on the number of appearnaces, i.e the second element in the pair
        std::sort(vec.begin(), vec.end(), [](std::pair<int, int>& a, std::pair<int, int>& b){
            return a.second > b.second;
        });

        vector<int> output;

        for(size_t i = 0; i < k && k <= vec.size(); i++)
            output.push_back(vec[i].first);
        
        return output;
    }
};
