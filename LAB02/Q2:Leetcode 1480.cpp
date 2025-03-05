class Solution {
public:
        vector<int> runningSum(vector<int>& nums) {
                int n =nums.size();//確認nums陣列長度
                vector<int> result(n);//用動態記憶體技術新增一個長度為n的陣列並且未初始化
                result[0]=nums[0];//初始化result陣列的第一個數值
                for(int i=1; i<n; i++){//使result陣列地i個數值等同於當前陣列nums的第i個加上陣列result陣列的第i-1個數值
                        result[i]=result[i-1]+nums[i];
                }
                return result;//輸出result陣列的數值
         }
};
