#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <fstream>
using namespace std;

// 商品類別
class Goods {
private:
    string goodname;//產品名稱
    int population;//產品人氣
    int deadline;//產品截止期限

public:
    //constructor:初始化為預設值
    Goods() : goodname("未命名"), population(0), deadline(0) {}

    //設定我的產品名稱/歡迎程度/截止日期
    Goods(string goodname, int population, int deadline){
        this->goodname = goodname;
        this->deadline = deadline;
        this->population = population;
    }

    int getPopulation() const { return population; }//population的Getter
    int getDeadline() const { return deadline; }//deadline的Getter
    
    //名稱輸出
    void print() const {
        cout << goodname << endl;
    }
};

//比較good的排列條件
//主條件:先比較截止日期
bool compareGoods(const Goods& a, const Goods& b) {
    //如果截止日期不同再看要不要交換
    if (a.getDeadline() != b.getDeadline()) {
        return a.getDeadline() < b.getDeadline();
    }
    //次要條件:如果截止日期相同再比較歡迎程度
    else {
        return a.getPopulation() > b.getPopulation();
    }
}

//使用bubble sort來對goodslist作排列
void bubbleSortGoods(vector<Goods>& goodsList) {
    int n = goodsList.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!compareGoods(goodsList[j], goodsList[j + 1])) {
                swap(goodsList[j], goodsList[j + 1]);
            }
        }
    }
}

int main() {
    ifstream file("C:/Users/aa098/OneDrive/桌面/1212/input1.txt");//讀取檔案
    if (!file.is_open()) {//如果無法讀取檔案會跳出:"無法讀取檔案"
        cerr << "無法開啟檔案" << endl;
        return 1;
    }

    int count = 0;
    file >> count;//讀取有多少個產品
    file.ignore();//忽略第一個數字後面的省略符號

    vector<Goods> goodsList;//建立商品列表

    //依照商品有多少個決定要讀取幾次
    for (int i = 0; i < count; i++) {
        string line;
        getline(file, line);//讀取商品資訊

        istringstream ss(line);//將讀取到的資料拆分為字串
        vector<string> tokens;
        string word;
        while (ss >> word) {
            tokens.push_back(word);//將儲存的資訊依序放入token當中
        }

        if (tokens.size() < 3) //最少需要名稱加兩個數值
            continue;

        int population = stoi(tokens[tokens.size() - 2]);//設定人氣
        int deadline = stoi(tokens[tokens.size() - 1]);//設定截止期限

        string name = "";
        //將產品的名稱組合起來
        for (int j = 0; j < tokens.size() - 2; ++j) {
            name += tokens[j];
            //補上產品名稱中間的空格
            if (j != tokens.size() - 3) name += " ";
        }

        goodsList.emplace_back(name, population, deadline);// 加入新商品資料到清單中
    }
    //進行排序    
    bubbleSortGoods(goodsList);
    //開始輸出已經排序後的商品名稱
    for (const auto g : goodsList) {
        g.print();
    }

    return 0;
}
