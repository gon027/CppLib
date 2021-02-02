#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <sstream>
using namespace std;
using llong = long long;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(vec) (vec).begin(), (vec).end()

// �R���e�i�p�̃f�o�b�O�֐�
template<class T>
void debugContainer(const T& _container){
	cout << "[ ";
	for(const auto& _c : _container){
		cout << _c << ", ";
	}
	cout << "]" << endl;
}

// ������𕪊�����vector�^�ɂ��ĕԂ��֐�
std::vector<string> split(const string& _line, const char _sp) {
	vector<string> result;

	std::stringstream ss(_line);
	std::string item;
	while (std::getline(ss, item, _sp)) {
		if (!item.empty()) {
			result.emplace_back(item);
		}
	}
	return result;
}


// ���l��2�i���̕����񂷂�֐�
string to_binary(const int n){
	string result = "";
	
	int d = n;
	do{
		int t = d % 2;
		result += to_string(t);
		d /= 2;
	}while(d != 0);
	
	reverse(result.begin(), result.end());
	
	return result;
}

void Main(){
	cout << 1 << endl;
}

int main(){
	Main();
	return 0;
}

