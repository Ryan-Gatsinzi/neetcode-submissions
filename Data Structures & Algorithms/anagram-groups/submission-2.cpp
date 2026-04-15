#include <algorithm>

class Solution {
public:
    bool isAnagram(string str1, string str2){
    sort(str1.begin(), str1.end()); sort(str2.begin(), str2.end());

    return str1 == str2;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    set<vector<string>> group_set;
    vector<vector<string>> group;

    for(int i = 0; i < strs.size(); i++){
        vector<string> anagram;

        for(int j = 0; j < strs.size(); j++){
            if (isAnagram(strs[i], strs[j])){
                // cout << strs[i] << " : " << strs[j] << endl;
                anagram.push_back(strs[j]);                
            }
        }
        // strs.erase(strs.begin()+i);

        group_set.emplace(anagram);
    }


    for(auto &elem : group_set){
        group.push_back(elem);

    }

    return group;
}
};
