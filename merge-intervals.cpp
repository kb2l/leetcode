class Solution {
public:
    static bool sortTwoIntervals(vector<int>& first, vector<int>& second){
        return (first[0] < second[0]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int flagged [10000] = {0};
        sort(intervals.begin(), intervals.end(), sortTwoIntervals);
        for(int i = 0; i < intervals.size() ; i++){
            if(flagged[i])continue;
            for(int j = i+1; j < intervals.size(); j++){
                if(flagged[j]) continue;
                if(intervals[i][1] >= intervals[j][0]) 
                    intervals[i][1] = max(intervals[i][1], intervals[j][1]),flagged[j]=1;    
            }
            
        }
        vector<vector<int>> ret;
        for(int i =0; i < intervals.size(); i++){
            if(flagged[i]) continue;
            ret.push_back(intervals[i]);
        }
        return ret;
    }
};