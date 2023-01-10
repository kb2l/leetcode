class Solution
{
public:
    /// <summary>
    ///  s = [content] [[content]] [[[content]]]
    /// </summary>
    /// <param name="s"></param>
    /// <returns></returns>
    pair<string, int> extract(string& s)
    {
        int count1 = 0, count2 = 0;
        string res = "";
        int i = 0;
        while (true)
        {
            if (s[i] == '[') count1++;
            else if (s[i] == ']') count2++;
            res += s[i];
            i++;
            if (count1 == count2)
            {
                res = res.substr(1, res.size() - 2);
                return make_pair(res, i);
            }
        }
    }

    string decodeString(string s)
    {
        string res;
        while(!s.empty())
        {
            char c = s[0];
            if (isalpha(c))
            {
                res += c;
                s = s.substr(1);
            }
            else
            {
                auto pos = s.find('[');
                string extacted_nu = s.substr(0, pos);
                int d = stoi(extacted_nu);

                //int d = int((int)c - 48);
                s = s.substr(pos);

                auto s1 = extract(s);
                s = s.substr(s1.second);
                auto d1 = decodeString(s1.first);
                for (int i = 0; i < d; i++)
                    res += d1;
            }
        }
        return res;
    }
};