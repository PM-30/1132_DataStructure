#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Player {  /*玩家結構資料型態，包含string類型的玩家名稱以及int類型的玩家分數*/
    string name;
    int score;
};

int drawCard() {
    return rand() % 10 + 1; /*發牌功能，呼叫一次發一張數值在1-10之間的牌*/
}

// 初始化玩家
void initializePlayer(Player* player, string name) {//透過call by referemce的方式初始化
    player->name=name;//初始化腳色身分
    player->score=0;//初始化腳色的分數
    int num = 0;
    for(int i=0 ; i<2 ; i++){//發兩張牌初始化剛開始的分數
        num = drawCard();
        player->score += num;
    }
}
void displayScore(Player* player) {// 顯示玩家分數
    cout<<"目前總分:"<<player->score<<endl;
}
// 玩家回合
void playerTurn(Player* player) {
    char choice;
    while (player->score < 21) {
        cout << "要抽牌嗎？(h = 抽, s = 停) : ";
        cin >> choice;
        if (choice == 'h') {
            int num = drawCard();//設定變數儲存抽出的數值
            player->score = player->score + num;//使原本擁有的分數加上抽出的數值
            cout<<"抽到"<<num<<"點，" ;//展示抽到的點數
            displayScore(player);//展示加總後的總分
            cout<< player->score<<endl;
            if (player->score > 21) {
                cout << player->name << " 爆掉了！遊戲結束。\n";
                return;
            }
        }
        else if (choice == 's') {
            break;
        }
    }
}
// 莊家回合
void dealerTurn(Player* dealer) {
    while (dealer->score < 17) { // 莊家至少要到 17 點
        int newCard = drawCard();//設定變數儲存抽到的分數
        dealer->score = dealer->score + newCard ; //抽到的分數加上原有的
        cout << "莊家抽到" << newCard << "點，目前總分: " << dealer->score << endl;//展示總分
        if (dealer->score > 21) { // 如果莊家超過 21 點
            cout << "莊家爆了！玩家獲勝！" << endl;
            return; // 遊戲結束
        }
    }
}
// 判斷勝負
void determineWinner(Player* player, Player* dealer) {
    if (player->score > 21) {
        cout << "你爆了！莊家獲勝！\n";
    }
    else if (dealer->score > 21 || player->score > dealer->score) {
        cout << "你贏了！!\n";
    }
    else if (player->score == dealer->score) {
        cout << "平手！\n";
    }
    else {
        cout << "莊家贏了！\n";
    }
}

// 主程式
int main() {
    srand(time(0));

    Player player, dealer;
    initializePlayer(&player, "玩家");
    initializePlayer(&dealer, "莊家");

    displayScore(&player);
    playerTurn(&player);

    if (player.score <= 21) { // 如果沒爆才讓莊家回合
        cout << "\n莊家回合...\n";
        displayScore(&dealer);
        dealerTurn(&dealer);
        determineWinner(&player, &dealer);
    }

    return 0;
}
