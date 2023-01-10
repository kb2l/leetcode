class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        if(arr1.empty() || arr2.empty() || arr3.empty()) return {};
        vector<int> ret;
        
        int i = 0, j = 0, k = 0;
        // first test
        vector<int> temp;
        while(i < arr1.size() && j < arr2.size()){
            if(arr1[i] < arr2[j]) i++;
            else if(arr1[i] > arr2[j]) j++;
            else temp.push_back(arr1[i]), i++, j++;
        }
        if(temp.empty()) return {};
        i =0; j = 0;
        while(i < temp.size() && j < arr3.size()){
            if(temp[i] < arr3[j]) i++;
            else if(temp[i] > arr3[j]) j++;
            else ret.push_back(temp[i]), i++, j++;
        }
        return ret;
    }
};