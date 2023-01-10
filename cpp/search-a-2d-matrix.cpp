class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0) return false;
	int h = matrix.size();
	int w = matrix[0].size();
	if (w == 0) return false;

	int i = 0;
	for (;;){
		if (i >= h) return false;
		int last = matrix[i][w - 1];
		if (target > last){
			i++;
		}
		else if (target == last) {
			return true;
		}
		else break;
	}
	return binary_search(matrix[i].begin(), matrix[i].end(), target);
}
};