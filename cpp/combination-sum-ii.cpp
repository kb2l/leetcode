class Solution {
public:
    map<int, int> used;
    map<int, set<vector<int>>> memo;
    set<vector<int>> solve(const vector<int>& v, int a){
        set<vector<int>> res;
        for (int i : v) {
            if (i > a || used[i] == 0) continue;
            if (i == a) res.insert({ i });
            else {
                used[i]--;
                set<vector<int>> r = solve(v, a - i);
                used[i]++;
                vector<vector<int>> temp (r.begin(), r.end());
                if (temp.size()){
                    for (auto& d : temp){
                        d.push_back(i);
                        sort(d.begin(), d.end());
                    }
                }
                for (auto &e : temp) res.insert(e);
            }
        }
        return res;
    }

    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for(auto e : candidates) used[e]++;
        auto s =  solve(candidates, target);
        return vector<vector<int>>(s.begin(), s.end());
        
    }
};