class Solution {
public:
struct group {
	group(string& m) {
		for (char c : m) {
			hash[int(c) - int('a')] = 1;
		}
		_max = m.length();
		members.push_back(m);
	}
	int hash[26] = { 0 };
	int _max = 0;
	vector<string> members;
	bool is_a_member(string& s) {
		for (char c : s) {
			if (hash[int(c) - int('a')] == 1)
				return true;
		}
		return false;
	}
	bool intersect(string&s1, string&s2) {
		int hash[26] = { 0 };
		for (char c : s1) hash[int(c) - int('a')] = 1;
		for (char c : s2) {
			if (hash[int(c) - int('a')] == 1) return true;
		}
		return false;
	}
	void update_max(string&s) {
		_max = max(_max, int(s.length()));
		vector<string> add;
		for (string&m : members) {
			if (!intersect(s, m)) {
				_max = max(_max, int(s.length() + m.length()));
				add.push_back(s + m);
			}
		}
		for (string a : add) members.push_back(a);
	}
	void add_to_group(string& s) {
		update_max(s);
		members.push_back(s);
		for (char c : s) {
			hash[int(c) - int('a')] = 1;
		}
		
	}
};

bool has_duplication(string& s) {
	int hash[26] = { 0 };
	for (char c : s) {
		if (hash[int(c) - int('a')] == 1)
			return true;
		hash[int(c) - int('a')] = 1;
	}
	return false;
}

struct compare {
	inline bool operator()(const std::string& first,
		const std::string& second) const
	{
		return first.size()> second.size();
	}
};

int solve(vector<string>& v) {
	compare c;
	sort(v.begin(), v.end(), c);

	vector<group> gv;
	
	for (int i = 0; i < v.size(); i++) {
		string current = v[i];
		if (has_duplication(current)) continue;

		bool group_found = false;
		for (group& g : gv) {
			if (g.is_a_member(current)) {
				g.add_to_group(current);
				group_found = true;
				break;
			}
		}
		if (!group_found)
			gv.push_back(group(current));
	}
	int ret = 0;
	for (group&g : gv)
		ret += g._max;
	return ret;
}

    int maxLength(vector<string>& arr) {
        return solve(arr);
    }
};