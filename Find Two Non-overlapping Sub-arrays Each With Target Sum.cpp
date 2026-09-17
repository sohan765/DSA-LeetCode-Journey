class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        const int INF = 1e9;
        int n = arr.size();
        vector<int> prefix(n,INF);
        vector<int> suffix(n,INF);
        int left = 0;
        int sum = 0;
        int best = INF;
        
        for(int i= 0;i<n;i++){
            sum += arr[i];
            while(sum>target){
                sum -= arr[left++];
            }
            if(sum == target){
                best = min(best,i-left+1);
            }
        prefix[i] = best;   
        }
        int right = n-1;
        sum = 0;
        best = INF;
        for(int i = n-1;i>=0;i--){
            sum += arr[i];
            while(sum> target){
                sum -= arr[right--];
            }
            if(sum == target){
                best = min(best,right-i+1);
            }
            suffix[i] = best;
        }
        int ans = INF;
        for(int i = 0;i<n-1;i++){
            if(suffix[i+1] != INF && prefix[i]!=INF){
                ans = min(ans,prefix[i]+suffix[i+1]);
            }
        }
        if(ans == INF){
            return -1;
        }
        return ans;
    }
};
