#include <iostream>
#include <queue>
#include <vector>
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
        cout << node->value << " ";// 訪問當前節點的值
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
    void Search(TreeNode* root,int target ) {
        TreeNode* found = FindNode(root, target);//確認是否有找到目標節點
        if (!found) {//如果未找到目標節點回傳"未找到指定節點"
            cout << "未找到指定節點" << endl;
            return;           
        }
        if (!found->left && !found->right) {//如果該葉節點沒有左右子樹迴傳"該節點為葉節點，沒有子樹"
            cout << "該節點為葉節點，沒有子樹" << endl;
            return;
        }
        int leftsum = Sum(found->left);//計算目標節點的左子樹的總和
        int rightsum = Sum(found->right);//計算目標節點的右子樹的總和
        cout << "左子樹總和為: " << leftsum << endl;//輸出左子樹總和
        cout << "右子樹總和為: " << rightsum << endl;//輸出右子樹總和
        cout << (leftsum > rightsum ? "左子樹總和較大\n" : "右子樹總和較大\n");//比較左右子樹總和大小決定輸出誰
    }
    //計算該節點子樹的總和
    int Sum(TreeNode* node) {
        if (!node)//如果該節點為空節點回傳0
            return 0;
        return node->value + Sum(node->right) + Sum(node->left);//迴傳節點的子樹和
    }
    //尋找目標是否存在於樹中
    TreeNode* FindNode(TreeNode* node,int target) {
        if (!node)//如果是空節點迴傳nullptr
            return nullptr;
        queue<TreeNode*> q;//創建一個Queue用於儲存未訪問的節點
        q.push(node);//將當前節點EnQueue
        while (!q.empty()) {//如果Queue不為空的開始動作
            TreeNode* current = q.front();//取出Queue頂端的節點
            q.pop();//刪除已經取出的節點
            if (current->value == target)//如果節點的數值等於目標回傳節點
                return current;
            if (current->left)//繼續尋找當前節點的左子樹是否為我的目標
                q.push(current->left);
            if (current->right)//繼續尋找當前節點的右子樹是否為我的目標
                q.push(current->right);
        }
        return nullptr;//如果尋遍Queue都沒有回傳空的節點
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
    cout << "輸入欲檢查的檢點值" << endl;
    int target = 0;
    cin >> target;//設定要查詢的數值
    tree.Search(tree.root,target);


    system("pause");
    return 0;
}
