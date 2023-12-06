//Banker's Algorithm
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> max_demand = {
	{7, 5, 3},
	{3, 2, 2},
	{9, 0, 2},
	{2, 2, 2},
	{4, 3, 3}
};
vector<vector<int>> allocation = {
	{0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};
vector<int> arrsafe;
vector<int> available = { 4,3,5};
int  NUM_PROCESSES = max_demand.size();
int  NUM_RESOURCES = max_demand[0].size();

vector<vector<int>> need(NUM_PROCESSES,vector<int>(NUM_RESOURCES,0));
void calcNeed() {
	cout << "需要的资源" << endl;
	for (int i = 0; i < NUM_PROCESSES; i++) {
		for (int j = 0; j < NUM_RESOURCES; j++) {
			need[i][j] = max_demand[i][j] - allocation[i][j];
			cout << need[i][j] << " ";
		}
		cout << endl;
	}
}

bool isSafe() {
	int flag = 1;//当flag=1的时候，它是不安全的
	int flag1 = 1;//定义是否是已经分配出去的资源

	while (NUM_PROCESSES--) {  //得到一个可以分配的资源后再次便利
		flag = 1;
		
		for (int i = 0; i < allocation.size(); i++) {//遍历allocation need数组的列
			flag = 1;
			flag1 = 1;
			for (int l = 0; l < arrsafe.size(); l++) {
				if (i == arrsafe[l]) {
					flag1 = 0;
				}
			}
			for (int j = 0; j < NUM_RESOURCES; j++) {
				if (flag1 == 0) {
					break;
				}
				if (need[i][j] > available[j]) {
					//此时已经不可能是安全序列了，直接退出
					break;
				}
				if (j == NUM_RESOURCES - 1 && need[i][j] <= available[j]) {
					flag = 0;
					arrsafe.push_back(i);
				}
			}
			if (flag == 0) {
				for (int k = 0; k < NUM_RESOURCES; k++) {
					available[k] += allocation[i][k];
				}
				
				break;
			}
		}
		if (flag == 1) {
			return false;
		}
	}
	
	return true;
}
void display() {
	cout << "最大需要的资源" << endl;
	for (int i = 0; i < max_demand.size(); i++) {
		for (int j = 0; j < max_demand[0].size(); j++) {
			cout << max_demand[i][j] << " ";
		}
		cout << endl;
	}
	cout << "已经分配的资源" << endl;
	for (int i = 0; i < allocation.size(); i++) {
		for (int j = 0; j < allocation[0].size(); j++) {
			cout << allocation[i][j] << " ";
		}
		cout << endl;
	}
	cout<<"我们手中有的资源"<<endl;
	for (int i = 0; i < available.size(); i++) {
		cout << available[i] << " ";
		}
	cout << endl;
}
int main() {
	
	display();
	calcNeed();
	if (isSafe()) {
		cout << "此时系统是安全的，安全序列为:";
		for (int i = 0; i < arrsafe.size(); i++) {
			cout << arrsafe[i];
		}
	}
	else {
		cout << "此时系统是不安全的";
	}
}