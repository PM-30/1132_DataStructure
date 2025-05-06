#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

// 從文件中讀取數據並存入向量
vector<int> readFromFile(const string& filename) {
	vector<int> arr;
	ifstream file(filename);
	if (!file) {
		cerr << "Error opening file: " << filename << endl;
		return arr;
	}
	string line;
	while (getline(file, line)) { // 持續讀取整行內容
		stringstream ss(line); // 創建字符串流
		string value;
		while (getline(ss, value, ',')) { // 用逗號分隔值
			try {
				arr.push_back(stoi(value)); // 將字符串轉換為整數並存入向量
			}
			catch (exception& e) {
				cerr << "Invalid number format in file: " << value << endl;
			}
		}
	}
	file.close();
	return arr;
}

// Max Heap 類別
class MaxHeap {
public:
	vector<int> heap; // 儲存 Max Heap 的元素

	// 建立 Max Heap
	void buildMaxHeap(vector<int>& arr) { //建立 Max Heap
		heap = arr;
		for (int i = (heap.size() / 2) - 1; i >= 0; i--) { // 從最後一個非葉子節點開始向上執行 Max Heap
			heapify(i);
		}
	}

	void heapify(int i) { // 堆化函式(確保以 i 為根的子樹符合 Max Heap 性質)

		int largest = i; // 假設當前節點是最大的
		int left = 2 * i + 1; // 左子節點索引
		int right = 2 * i + 2; // 右子節點索引

		// if 判斷式,檢查左子節點是否為有效範圍且比當前節點(父節點)大
		// 如果判斷式成立,把 largest 設為 left
		if (heap.size() > left && heap[left] > heap[largest]) {
			largest = left;
		}
		// if 判斷式,檢查右子節點是否為有效範圍且比當前節點(父節點)大
		// 如果判斷式成立,把 largest 設為 right
		if (heap.size() > right && heap[right] > heap[largest]) {
			largest = right;
		}
		// if 判斷式,如果最大的不是父節點,交換並繼續堆化
		// 遞迴處理受影響的子樹
		if (largest != i) {
			int temp = heap[i]; // 暫存目前節點的值
			heap[i] = heap[largest]; // 把比較大的子節點移到父節點
			heap[largest] = temp; // 把原本父節點的值放到子節點
			heapify(largest);
		}
	}

	// 顯示 Heap 的內容(使用 BFS)
	void printHeap() {
		for (int val : heap) { // 遍歷 Max Heap 中的每個元素
			cout << val << " "; // 輸出元素
		}
		cout << endl;
	}
};

// Min Heap 類別
class MinHeap {
public:
	vector<int> heap; // 儲存 Min Heap 的元素

	// 建立 Min Heap
	void buildMinHeap(vector<int>& arr) { //建立 Min Heap
		heap = arr;
		for (int i = (heap.size() / 2) - 1; i >= 0; i--) { // 從最後一個非葉子節點開始向上執行 Min Heap
			heapify(i);
		}
	}

	void heapify(int i) { // 堆化函式(確保以 i 為根的子樹符合 Min Heap 性質)

		int smallest = i; // 假設當前節點是最小的
		int left = 2 * i + 1; // 左子節點索引
		int right = 2 * i + 2; // 右子節點索引

		// if 判斷式,檢查左子節點是否為有效範圍且比當前節點(父節點)小
		// 如果判斷式成立,把 smallest 設為 left
		if (heap.size() > left && heap[left] < heap[smallest]) {
			smallest = left;
		}
		// if 判斷式,檢查右子節點是否為有效範圍且比當前節點(父節點)小
		// 如果判斷式成立,把 smallest 設為 right
		if (heap.size() > right && heap[right] < heap[smallest]) {
			smallest = right;
		}
		// if 判斷式,如果最小的不是父節點,交換並繼續堆化
		// 遞迴處理受影響的子樹
		if (smallest != i) {
			int temp = heap[i]; // 暫存目前節點的值
			heap[i] = heap[smallest]; // 把比較小的子節點移到父節點
			heap[smallest] = temp; // 把原本父節點的值放到子節點
			heapify(smallest);
		}
	}

	// 顯示 Heap 的內容(使用 BFS)
	void printHeap() {
		for (int val : heap) { // 遍歷 Min Heap 中的每個元素
			cout << val << " "; // 輸出元素
		}
		cout << endl;
	}
};

int main() {
	// 從文件讀取輸入元素
	string filename = "C:/Users/aa098/Desktop/1564/0.txt"; //請貼上 input 檔案的正確路徑
	vector<int> arr = readFromFile(filename); //讀取數據

	if (arr.empty()) { // 如果數據為空
		cerr << "No valid data found in file." << endl; //輸出錯誤信息
		return -1;
	}

	cout << "Input Array: "; //輸出讀取的數據
	for (int val : arr) {
		cout << val << " "; //輸出每個元素
	}
	cout << endl;

	// 建立 Max Heap 並輸出
	MaxHeap maxHeap; // 創建 Max Heap 對象
	maxHeap.buildMaxHeap(arr); // 建立 Max Heap
	cout << "Max Heap(By BFS): ";
	maxHeap.printHeap();
	

	// 建立 Min Heap 並輸出
	MinHeap minHeap; // 創建 Min Heap 對象
	minHeap.buildMinHeap(arr); // 建立 Min Heap
	cout << "Min Heap(By BFS): ";
	minHeap.printHeap();
	cout << endl;

	system("pause");
	return 0;
}
