class Solution {
public:
    bool palindrome(int ind,int i,string& s){
        int left = ind;
        int right = i;
        while(left<=right){
            if(s[left++]!=s[right--]){
                return false;
            }
        }
        return true;
    }
    void solve(string& s,int ind,vector<string>& ans,vector<vector<string>>& path,int n){
        if(ind == n){
            path.push_back(ans);
            return;
        }
        for(int i = ind;i<n;i++){
            if(palindrome(ind,i,s)){
                ans.push_back(s.substr(ind,i-ind+1));
                solve(s,i+1,ans,path,n);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ans;
        vector<vector<string>> path;
        int n = s.size();
        solve(s,0,ans,path,n);
        return path;
    }
};
