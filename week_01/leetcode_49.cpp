class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> categories;
        for (string &str : strs) {
            string clone = str;
            sort(str.begin(), str.end());
            if (categories.find(str) != categories.end()) {
                categories[str].push_back(clone);
            } else {
                categories[str] = vector<string>(1, clone);
            }
        }
        vector<vector<string>> rest;
        for (auto it = categories.begin(); it != categories.end(); ++it) {
            rest.push_back(it->second);
        }
        return rest;
    }
};
