#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

// 表示單張撲克牌的類別
class Card {
public:
    string colors; // 儲存撲克牌的花色
    string rank;   // 儲存撲克牌的數值

    Card(string s, string r) : colors(s), rank(r) {} // 建立 constructor 來初始化物件

    void display() const { // 顯示撲克牌的資訊
        cout << rank << " of " << colors << endl;
    }
};

// 實作 Stack
class Stack {
private:
    vector<Card> stack; // 表示 stack 是一個能存放 Card 類別物件的 vector

public:
    void push(const Card& card) {
        stack.push_back(card);//將新加入的卡排放入最後面
    }

    Card pop() {
        stack.pop_back();//移除最後面的卡牌
    }

    bool isEmpty() const {//判斷我的Stack是否是空的
        if (stack.size() != 0)//如果大小不為0的話代表是空的
            return false;//如果不為0的話回傳否
        return true;//如果為0的話回傳是
    }
};

// 代表一副撲克牌的類別
class Deck {
private:
    vector<Card> cards; // 存放未洗牌的撲克牌
    Stack shuffledDeck; // 存放洗過的牌, 用實作的 stack 來管理

public:
    Deck() { // 建立 constructor 來初始化物件
        string colors[] = { "Hearts", "Diamonds", "Clubs", "Spades" }; // 儲存撲克牌的花色
        string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" }; // 儲存撲克牌的數值

        // 利用迴圈將 52 張牌加入 cards 這個 vector 裡面
        for (int i = 0; i < 4; i++) { // 四種花色
            for (int j = 0; j < 13; j++) { // 13 種點數
                cards.push_back(Card(colors[i], ranks[j]));
            }
        }
    }

    // 洗牌 (Hint: 使用 shuffle 函數)
    void shuffleDeck() {//洗牌系統
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();//以程式跑的時間當作系統隨機參數的參考數值，加以實行隨機運算
        shuffle(cards.begin(), cards.end(), default_random_engine(seed)); // 隨機洗牌
    }

    // 發牌
    void drawAllCards() {
        for (auto& card : cards) {//用auto自動去設定我的資料型態，再尋遍所有cards內所有變數
            card.display(); // 顯示每一張牌
        }
    }
};

int main() {
    Deck deck; // 建立 deck 產生 52 張撲克牌
    deck.shuffleDeck(); // 進行洗牌
    cout << "Shuffled deck:" << endl;
    deck.drawAllCards(); // 依序顯示洗過的牌
    return 0;
}
