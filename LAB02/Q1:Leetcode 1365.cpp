//Method1
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int count[101] = {0}; // initial時間複雜度 O(1)
        int n = nums.size(); // initial時間複雜度 O(1)
        vector<int> result(n); // 設定結果陣列，時間複雜度 O(n)，因為它的大小會根據 nums 的大小動態分配
        
        // 計算每個數字出現的次數
        for (int num : nums) { // loop nums，時間複雜度 O(n)
            count[num]++;
        }
        for (int i = 1; i < 101; i++) { // loop 100 次，所以時間複雜度是 O(100)，因為常數時間不隨 n 變動
            count[i] += count[i – 1]; // O(3)，每次更新 count 陣列，這部分可以忽略
        }
        for (int i = 0; i < n; i++) { // loop nums 時間複雜度 O(n)
            result[i] = (nums[i] == 0) ? 0 : count[nums[i] – 1]; // 判斷和賦予數值都是 O(1)
        }
        return result; // O(1)，返回結果陣列
    }
};
//O(1)+O(1)+O(n)+O(n)+O(300)+O(n)+O(1)=O(n)
/////////////////////////////////////////////////////////////////////////////
Method2
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result; // 存結果 O(1)
        int count; // 計數器 O(1)
        for (int i = 0; i < nums.size(); i++) { // O(n) up 因為是loop並且因為判定是用輸入陣列的大小
            count = 0; // O(1) assignment
            for (int j = 0; j < nums.size(); j++) { // O(n)，對每個 nums[i] 進行比對，所以整段loop is O(n^2)，忽略if裡面因為是常數
                if (nums[j] < nums[i]) { // O(1)，檢查 nums[j] 是否小於 nums[i]
                    count++; // O(1) use ++
                }
            }
            result.push_back(count); // O(1)將 count 加入 result
        }

        return result; // O(1)，返回 result
    }
};

//O(1)+[(n^2)+O(1)]+O(1)=O(n^2)
