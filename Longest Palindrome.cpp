class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mpp;
        for(char c:s){
           mpp[c]++;
        }
        int lenght = 0;
        int count = 0;
        for(auto& it : mpp){
            if((it.second)%2==0){
                lenght += it.second;
            }
            else{
                count++;
                lenght = lenght + (it.second-1);
            }
        }
        if(count !=0){
            return lenght+1;
        }
        return lenght;
    }
};
