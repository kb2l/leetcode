class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        set<vector<int>> ret;
        sort(v.begin(), v.end());
        unordered_map<int, int> m(v.size());
        for (int c = 0; c < v.size(); c++)
        {
            if (m[v[c]] == 1) continue;
            m[v[c]] = 1;
            int a = 0;
            int b = v.size() - 1;
            while (a < b)
            {
                if (a == c) a++;
                if (b == c) b--;
                if (a == b) break;
                if (v[a] + v[b] < -v[c]) a++;
                else if (v[a] + v[b] > -v[c]) b--;
                else
                {
                    vector<int> sol  {v[a], v[b], v[c]};
                    sort(sol.begin(), sol.end());
                    ret.insert(sol);
                    b--;
                    a++;
                }
            }
        }

        return vector<vector<int>>(ret.begin(), ret.end());
    }
};