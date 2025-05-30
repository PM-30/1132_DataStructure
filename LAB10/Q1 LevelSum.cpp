
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
const int EMPTY = NULL; // 用 NULL 代表沒有節點
class TreeNode {
public:
    int value;// 節點值
    TreeNode* left;// 左子節點
    TreeNode* right;// 右子節點

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}//初始化節點
};

class BinaryTree {
public:
    TreeNode* root;// 樹根節點

    BinaryTree() : root(nullptr) {}

    TreeNode* buildTree(const vector<int>& arr) {// 建立樹
        if (arr.empty() || arr[0] == EMPTY) return nullptr;

        queue<TreeNode**> q;//建立queue儲存待處理的節點指標
        root = new TreeNode(arr[0]);// 建立根節點 (陣列第一個元素)
        q.push(&root);// 將根節點的指標加入queue

        size_t i = 1;// 陣列索引
        while (!q.empty() && i < arr.size()) {
            TreeNode** nodePtr = q.front();// 取出queue的第一個節點指標
            q.pop();// 將該節點從queue中刪除

            // 左子節點
            if (i < arr.size()) {
                if (arr[i] != EMPTY) {
                    (*nodePtr)->left = new TreeNode(arr[i]);// 添加左子節點
                    q.push(&((*nodePtr)->left));// 將左子節點的指標加入queue
                }
                i++;
            }
            // 右子節點
            if (i < arr.size()) {
                if (arr[i] != EMPTY) {
                    (*nodePtr)->right = new TreeNode(arr[i]);// 添加右子節點
                    q.push(&((*nodePtr)->right));// 將右子節點的指標加入queue
                }
                i++;
            }
        }
        return root;
    }

    void Depth_first_search(TreeNode* node) {//深度優先搜尋
        if (node == nullptr) return;
        cout << node->value << " ";// 訪問當前節點的值A
        Depth_first_search(node->left);// 遞迴遍歷左子樹
        Depth_first_search(node->right);// 遞迴遍歷右子樹
    }

    void Breadth_first_search(TreeNode* root) {
        if (root == nullptr) return;
        queue<TreeNode*> q;//建立queue儲存待處理的節點指標
        q.push(root); // 將根節點的指標加入queue

        while (!q.empty()) {
            TreeNode* current = q.front();// 取出queue的第一個節點指標
            q.pop();// 將該節點從queue中刪除
            cout << current->value << " ";
            if (current->left) q.push(current->left);  // 將左子節點的指標加入queue
            if (current->right) q.push(current->right);// 將右子節點的指標加入queue
        }
    }
    int LevelSum(TreeNode* node, int num) {
        if (!node)//如果節點為空回傳0
            return 0;
        queue<TreeNode* > q;//建立一個空的Queue以儲存同一level尚未處理的節點
        q.push(node);//將現在所在的節點推入Queue中
        int level = 0;//從根節點開始計算(Level0)

        while (!q.empty()) {//如果Queue不為空的開始動作
            int size = q.size();//當前層級的節點數量
            //若達到目標的level開始動作
            if (level == num) {
                int sum = 0;//總和歸0
                for (int i = 0; i < size; ++i) {
                    TreeNode* current = q.front();//將Queue中的頂端取出
                    q.pop();//刪除被取出的節點，以免重複選取
                    sum += current->value;//加總當前節點的數值配上原先有的數值
                }
                return sum;//回傳總和
            }
            //如果未達到目標的level，將下一層所有節點加入Queue中
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();//取出當前節點
                q.pop();//刪除當前節點怕重複選取
                //將選出的節點所擁有的子樹EnQueue
                if (current->left)
                    q.push(current->left);//EnQueue當前節點的左子樹
                if (current->right)
                    q.push(current->right);//EnQueue當前節點得右子樹
            }
            level++;//進入下一層
        }
        //若整棵樹小於num回傳0
        return 0;
    }
    int maxlevel(TreeNode* node) {//尋找樹高最大值
        if (!node)//如果節點是空的回傳0表示樹高為0
            return 0;
        //左右子樹遞迴尋找樹高最大值
        int L = maxlevel(node->left);
        int R = maxlevel(node->right);
        return 1 + max(L, R);//比較左右子樹決定該層的level為多少輸出較大數值
    }
};


int main() {
    BinaryTree tree;
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, NULL, NULL, 10, 11, NULL, NULL };
    tree.buildTree(arr);

    cout << "DFS Result: ";
    tree.Depth_first_search(tree.root);
    cout << endl;

    cout << "BFS Result: ";
    tree.Breadth_first_search(tree.root);
    cout << endl;
    cout << "請輸入要查詢的層數(從0開始):" << endl;
    int num = 0;
    cin >> num;
    int max = tree.maxlevel(tree.root) - 1;//判斷輸入的樹的level
    if (num > max) {//如果超過數高直接輸出"超過數高:"
        cout << "超過樹高。" << endl;
    }
    else if (num < 0) {//樹沒有小於0的層級
        cout << "請輸入大於0的數值。" << endl;
    }
    else {//如果鎖鑰查詢的LevelSum府和規定開始動作
        int result = tree.LevelSum(tree.root, num);
        cout << "第" << num << "層總和為:" << result << endl;
    }

    system("pause");
    return 0;
}
