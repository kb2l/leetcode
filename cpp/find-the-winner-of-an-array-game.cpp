class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k > arr.size() * arr.size()) k = arr.size() * arr.size();
        if(k == 0 || arr.size() == 1) return 0;
        if(k == 1 || arr.size() == 2) return max(arr[0], arr[1]);
        const int INF = -1e5;
        int size = arr.size();
        int i = 0, j = 1;
        unordered_map<int, int > win;
        while(true) {
            if(arr[i] == INF){i = j; j++;}
            else if(arr[j] == INF) j++;
            if(!(i != j && i < size && j < size && arr[i] != INF && arr[j] != INF)){
                return max(arr[i], arr[j]);
            }
            if(arr[i] < arr[j]){
                arr[i] = INF;win[arr[i]] = 0;win[arr[j]]++;
            }
            else{
                arr[j] = INF;win[arr[j]] = 0;win[arr[i]]++ ;
            }
            if(win[arr[j]] == k) return arr[j];
            if(win[arr[i]] == k) return arr[i];  
        }
        
        return 0;
    }
};