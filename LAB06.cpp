#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// 定義 Stack 的節點結構
struct Node {
    char data;  // 存儲字符 (運算子或括號)
    Node* next; // 指向下一個節點
};

// 使用 linked list 實作 Stack
class Stack {
private:
    Node* top; // 指向堆疊頂端
public:
    Stack() { top = nullptr; } // 初始化堆疊

    // Push 操作：將元素放入堆疊
    void push(char ch) {
        Node* newnode = new Node();//創建一個空白空間，並且資料型態是Node
        newnode->data = ch;//將資料傳到新創見的Node中
        newnode->next = top;//link連接到原本物件的開頭
        top = newnode;//將指標一向最上方的物件
    }

    // Pop 操作：移除並回傳頂端元素
    char pop() {
        if (top == nullptr) {//先判斷是否是空的如果是空的則無法pop出東西
            cout << "堆疊為空，無法取出元素。\n";
            return '\0';            
        }

        char poppedch = top->data; //暫存準備被刪除的資料
        Node* temp = top;//創建一個Node的資料指標處存目前最傷面資料的位子    
        top = top->next;//將指標移到要被移除資料的下一筆            
        delete temp;//釋放記憶體空間              
        return poppedch;//回傳準備被刪除的數值
    }

    // Peek 操作：取得頂端元素但不移除
    char peek() {
        return top->data ;//取得最頂端的數值
    }

    // 判斷堆疊是否為空
    bool isEmpty() {
        return top == nullptr;//如果最頂端的資料指向空的地方表示他是一個空的stack
    }
};

// 判斷運算子(加減乘除) 的優先順序
int precedence(char op) {//透過回傳的的數值多少決定它的優先順序，數值越高優先度越高
    if(op == '+' || op == '-' ) return 1;//回傳1，表示加減
    else if(op == '*' || op == '/') return 2;//回傳2，表示乘除
    else return 0;
}

// 將中序表達式 (infix) 轉換為後序表達式 (postfix)
void InfixToPostfix(const char* infix, char* postfix) {
    Stack temp;
    int j=0;
    for(int i = 0 ; infix[i] != '\0';i++){
        char ch = infix[i];
        if(isalnum(ch)){
            postfix[j++]= ch ;//如果是單純要加減的字元，直接加入postfix的陣列當中
        }
        else if(ch == '('){//如果輸入左括弧直接推入到我的stack當中
            temp.push(ch);
        }
        else if(ch == ')'){//如果輸入是右括弧
            while(!temp.isEmpty() && temp.peek() != '('){//開始pop直到接近左括弧為止
                postfix[j++]= temp.pop();//將pop的事物輸入進postfix的陣列當中
            }
            temp.pop();//輸出左括弧並且不進入postfix當中
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!temp.isEmpty() && precedence(temp.peek()) >= precedence(ch)) {//如果輸入的是運算符號的話，比較何者優先度較高優先輸出
                postfix[j++] = temp.pop();pop進postfix陣列當中
            }
        temp.push(ch);//如果以上都沒有則進入stack當中暫存
        }
    }
    while (!temp.isEmpty()) {
        postfix[j++] = temp.pop();//最終一次輸出
    }

    postfix[j] = '\0';//加上char陣列截止符號
   
}

int main() {
    char infix[100], postfix[100];
    cout << "Enter an Infix expression: ";
    cin >> infix; // 輸入中序表達式

    InfixToPostfix(infix, postfix); // 轉換為後序表達式
    cout << "Postfix expression: " << postfix << endl; // 輸出後序表達式

    return 0;
}
