class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        vector<vector<int>> ret;
        for (int e : v){
            if (e > target) continue;
            if (target == e) {
                vector<int> a = { e };
                ret.push_back(a);
            }
            else{
                auto res = combinationSum(v, target - e);
                for (auto e1 : res){
                    if (e >= e1.back()){
                        e1.push_back(e);
                        ret.push_back(e1);
                    }
                }
            }
        }
        return ret;
    }
};