class Solution {
public:
    int findLucky(vector<int>& arr) {
        int temp=0;//設定最大值變數
        for(int i : arr){//尋找最大值以temp變數表示
            if(temp < i)
                temp=i;
        }
        vector<int> frequency( temp + 1,0);//創建一個整數陣列計算次數長度為temp+1因為陣列第一個是從0開始計算
        for(int i : arr)//計算每一個元素出現的次數來去做計算
            frequency[i]++;
        for(int i=temp;i>0;i--){//從最大的數值開始選擇是否有達成條件如果有舊書出該數值
            if(i==frequency[i])//條件為數值等於它出現的頻率
                return i;
        }        
        return -1; //未達成條件輸出-1
    }
};

