class Solution {
public:
vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
	vector<int> ret;
	deque<int> res(max(arr1.size(), arr2.size()));
	unordered_map<int, int> carry;
	int i, j;
	for (i = arr1.size() - 1, j = arr2.size() - 1; i >= 0 || j >= 0; i--, j--){
		int idx = max(i, j);
		int sum = carry[idx];
		if (i >= 0) sum += arr1[i];
		if (j >= 0) sum += arr2[j];
		if (sum == 0) res[idx] = 0;
		else if (sum == 1) res[idx] = 1;
		else if (sum == 2) res[idx] = 0, carry[idx - 1]++, carry[idx - 2]++;
		else if (sum == 3) res[idx] = 1, carry[idx - 1]++, carry[idx - 2]++;
		else res[idx] = 0, carry[idx - 2]++;
	}
	if (carry[-1] != 2 || carry[-2] != 1){
		if (carry[-1] == 1)res.push_front(1);
		if (carry[-2] == 1)res.push_front(1);
	}
	for (auto e : res) {
		if (!e) res.pop_front();
		else break;
	}
	if (res.size() == 0) return{ 0 };
	std::copy(res.begin(), res.end(), std::back_inserter(ret));
	return ret;
}
};