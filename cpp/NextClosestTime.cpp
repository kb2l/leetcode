class Solution {
public:
    int compare(const string& time1, const string& time2)
    {
        string val1 = time1.substr(0, 2);
        string val2 = time1.substr(3);

        auto i = stoi(val1) * 60 + stoi(val2);

        auto j = stoi(time2.substr(0, 2)) * 60 + stoi(time2.substr(3));
        if (i > j) j += 24 * 60;
        auto diff = j - i;
        return diff;
    }

    string nextClosestTime(string time)
    {
        vector<string> cands;
        for (int i = 0; i <= 2; i++)
        {
            if (time.find(to_string(i)) == string::npos) continue;
            for (int j = 0; j <= 9; j++)
            {
                if (i * 10 + j > 23) continue;

                if (time.find(to_string(j)) == string::npos) continue;
                for (int k = 0; k <= 5; k++)
                {
                    if (time.find(to_string(k)) == string::npos) continue;
                    for (int l = 0; l <= 9; ++l)
                    {
                        if (k * 10 + l > 59) continue;
                        if (time.find(to_string(l)) == string::npos) continue;
                        string cand;
                        cand = to_string(i) + to_string(j);
                        cand += ":";
                        cand += to_string(k) + to_string(l);
                        cands.push_back(cand);
                    }
                }
            }
        }
        //for (auto& cand : cands) cout << cand << endl;
        string res = cands[0];
        int _min = 999999;
        for (auto& cand : cands)
        {
            if (cand == time) continue;
            auto diff = compare(time, cand);
            if (diff < _min)
            {
                _min = diff;
                res = cand;
            }
        }

        return res;
    }
};