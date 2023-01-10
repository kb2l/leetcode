class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int zero =0, one =0, two =0;
        for(int i : nums){
            if(i == 0) zero++;
            if(i == 1) one++;
            if(i ==2) two++;
        }
        int i = 0;
        for(; i < zero; i++){
            nums[i] =0;
        }
        for(; i < zero + one; i++){
            nums[i] =1;
        }
        for(; i < zero + one + two; i++){
            nums[i] =2;
        }
    }
};