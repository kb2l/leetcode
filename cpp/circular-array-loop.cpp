class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        const int size = nums.size();
        map<int, int> visited;
        for(int i = 0; i < nums.size(); i++){
            int k = nums[i];
            visited.clear();
            visited[i] = 1;
            if(k<0){
                int next = (i + k + size) % size;
                if(next < 0) continue;
                if(next == i || nums[next] > 0) continue;
                while(next >= 0 && nums[next] < 0 && !visited[next] && next != i){
                    visited[next] = 1;
                    k = nums[next];
                    k  = k % size;
                    next = (next + k + size) % size;
                }
                if(next == i) {
                    return true;
                }
            }
            else{
                int next = (i + k) % size;
                if(next < 0) continue;
                if(next == i || nums[next] < 0) continue;
                while(next >= 0 && nums[next] > 0 && !visited[next] && next != i){
                    visited[next] = 1;
                    k = nums[next];
                    k  = k % size;
                    next = (next + k) % size;
                }
                if(next == i) {
                    return true;
                }
            }
        }
        
        return false;
    }
};