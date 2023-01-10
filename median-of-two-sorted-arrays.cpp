class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        int stopIndex = (num1.size() + num2.size()) / 2;
        int i = 0, j = 0;
        vector<int> mergedVec;
        while(mergedVec.size() <= stopIndex && i < num1.size() && j < num2.size())
        {
            if(num1[i] <= num2[j]) mergedVec.push_back(num1[i++]);
            else mergedVec.push_back(num2[j++]);
        }
        for(; i < num1.size()&& mergedVec.size() <= stopIndex; i++) mergedVec.push_back(num1[i]);
        for(; j < num2.size()&& mergedVec.size() <= stopIndex; j++) mergedVec.push_back(num2[j]);
        
        for(auto& e: mergedVec) cout << e << " "; cout << endl;
        if((num1.size() + num2.size()) % 2) return (double)mergedVec[stopIndex];
        return double(mergedVec[stopIndex] + mergedVec[stopIndex -1])/2.0;    
    }
};