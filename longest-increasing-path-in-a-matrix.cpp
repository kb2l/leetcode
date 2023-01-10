
class Solution
{
public:
    struct Point
    {
        int x;
        int y;
    };

    const vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    int dfs(vector<vector<int>>& m, vector<vector<int>>& vis, Point p)
    {
        if (vis[p.x][p.y] != 0)
            return vis[p.x][p.y];

        auto H = m[0].size();
        auto W = m.size();
        int ret = 1;
        for(auto &d : dir) {
            int x = p.x + d[0];
            int y = p.y + d[1];
            if(x >= 0 && x < W && y >= 0 && y < H && m[x][y] > m[p.x][p.y])
                ret = max(ret, 1 + dfs(m, vis, {x, y}));
        }
        vis[p.x][p.y] = ret;
        return ret;
    }

    int longestIncreasingPath(vector<vector<int>>& m)
    {
        auto H = m[0].size();
        auto W = m.size();
        int res = -1;
        vector<vector<int>> cache (W, vector<int>(H, 0));
        
        for (int i = 0; i < W; i++)
        {
            for (int j = 0; j < H; j++)
            {
                Point curr = { i, j };
                res = max(res, dfs(m, cache, curr));
            }
        }
        return res;
    }
};