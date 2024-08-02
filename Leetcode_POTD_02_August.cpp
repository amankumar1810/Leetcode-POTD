// Conceptual Qusetion hai ye.
// Hints padhkar ban gaya ye.

// Yaha par circular rray ka concept samajhna hai ki 1st and last elemnt connected hai.
/*
    Logic ye hai ki jitna total 1 hai pure array mein hume utna size ke 
    subarray ka need hoga sab ko ek saath karne ke liye.

    Ab har subarray of length total me dekh lenge ki kitna 0 hai isme.
    Jitna 0, utni baar swap required.

    Sliding window ke use se optimize ho jayega.
*/
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        // No. of 1s count kar liye hai.
        for (auto& i : nums) {
            if (i == 1)
                cnt++;
        }

        // Circular array ke liye array ko khud se merge kar diye hai.
        for (int i = 0; i < n; i++)
            nums.push_back(nums[i]);

        int ans = 0;
        int i = 0, j = 0;
        // Initial sub-array.
        while (j < cnt) {
            if (nums[j] == 0)
                ans++;
            j++;
        }
        // Ab j=n ho chuka hai.

        // Itna initially lag raha hai.
        int temp = ans;
        // Ab har sub-array me dekho.
        while (j < (2 * n)) {
            // Hume 0 count karn ahi.

            // Agar ye 0 hai matlab count me add hoga.
            if (nums[j] == 0)
                temp++;
            j++;

            // Agar ye 0 tha to, count mein 1 loss ho gaya.
            if (nums[i] == 0)
                temp--;
            i++;

            // Minimum possible swap hi humara answer hoga.
            ans = min(ans, temp);
        }

        return ans;
    }
};
