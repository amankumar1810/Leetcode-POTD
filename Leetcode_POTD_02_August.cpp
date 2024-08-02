class Solution {
  public:
    // Ye khud se banaye the, POTD mein to ban gaya.
    int celebrity(vector<vector<int> >& mat) {
        /*
            Logic ye hai ki celebrity wale row mein ek bhi 1 nahi hoga.
            Aur us column mein usko chhor kar sabhi 1 honge.
            matlab n-1 one honge total.
        */
        vector<int> temp;
        int n = mat.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1)
                    cnt++;
            }
            if(cnt==0)
                temp.push_back(i);
        }
        int ans = -1;
        if(temp.size()==0)
            return -1;
        for(auto &element:temp){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(mat[i][element]==1)
                    cnt++;
            }
            if(cnt==n-1){
                ans = element;
                break;// Sirf 1 hi celebrity hoga.
            }
        }
        return ans;
    }
};

class Solution {
  public:
    // Ye stack wala method Naman Sir Padhaye the.
    /*
      Isme basically hum log andaaz laga kar O(N) me reduce kar diye.
      Agar usko koi jaanta hai to wo pakka celebrity nahi hai.
    */
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        stack<int> stk;
        for(int i=0;i<n;i++)
            stk.push(i);
        while(stk.size()>=2){
            int i=stk.top();stk.pop();
            int j=stk.top();stk.pop();
            // Agar ye kisi ko nahi jaanta hai to ye may be ho sakta hai.
            if(mat[i][j]==0)
                stk.push(i);
            // Ye kisi ko jaanta hai to pakka ye nahi hone wala.
            else if(mat[i][j]==1)
                stk.push(j);
        }
        int ans = stk.top();
        for(int i=0;i<n;i++){
            // Cross verify kiye hai isse.
            // Usko koi nahi jaane ya ye kisi ko jaan le.
            if(i!=ans){
                if(mat[i][ans]== 0||mat[ans][i]==1)
                    return -1;
            }
        }
        return ans;
    }
};

class Solution {
  public:
    // Isme O(1) space use hua hai.
    int celebrity(vector<vector<int> >& mat) {
        // Same whi approach hai stack wala but isme two pointer se nikaale hai.
        int n = mat.size();
        int i=0,j=n-1;
        while(i<j){
            // Agar ye kisi ko nahi jaanta hai to baaki persons ke liye check kar liye hai. 
            if(mat[i][j]==0)
                j--;
            // Agar ye kisi ko jaanta hai to ye pakka nahi hoga.
            // Tab hum next person ko check karenge anwer ke liye.
            else if(mat[i][j]==1)
                i++;
        }
        int ans = i;
        // Phir se cross verification.
        for(int i=0;i<n;i++){
            if(i!=ans){
                if(mat[i][ans]==0 || mat[ans][i]==1)
                    return -1;
            }
        }
        return ans;
    }
};