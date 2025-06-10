class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr(m + n);//創建一個長度可以容下兩個陣列的佔存陣列
        int i = 0, j = 0, a = 0;

        //比較兩個陣列內容的大小數值較小的優先放入剛剛創建的陣列當中
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                arr[a++] = nums1[i++];
            } else {
                arr[a++] = nums2[j++];
            }
        }

        //將剩下未比較完的數值依序放入佔存的陣列當中
        while (i < m) arr[a++] = nums1[i++];
        while (j < n) arr[a++] = nums2[j++];

        //將所有儲存得內容放入第一個陣列當中
        for (int k = 0; k < m + n; k++) {
            nums1[k] = arr[k];
        }
    }
};
