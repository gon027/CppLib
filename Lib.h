#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <set>
#include <numeric>
using namespace std;
using ll = long long;
using ld = long double;
#define PI acos((long double)(-1))

// コンテナ用のデバッグ関数
template<class T>
void debugContainer(const T& _container){
	cout << "[ ";
	for(const auto& _c : _container){
		cout << _c << ", ";
	}
	cout << "]" << endl;
}

// 文字列を分割してvector型にして返す関数
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

// 数値を2進数の文字列する関数
string to_binaryString(const int n){
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

// 素数判定関数
template <class T>
bool isPrime(T num){
    if(num <= 1) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;

    for(int i = 3; i * i <= num; i += 2){
        if(num % i == 0){
            return false;
        }
    }

    return true;
}

// 素数の値の可変長配列を作成
template <class T>
void primeVector(vector<T>& v, T start, T end){
    for(int i = start; i <= end; ++i){
        if(isPrime(i)){
            v.push_back(i);
        }
    }
}

// 素数のbool型の可変長配列を作成
template <class T>
void primeVector(vector<bool> &v, T start, T end){
    for (int i = start; i <= end; ++i){
        v.push_back(isPrime(i));
    }
}

template <class T>
void primeVector(T* a, T start, T end){
    for (int i = start; i <= end; ++i){
        if(isPrime(i)){
            a[i] = true;
        }
    }
}

// 約数を求める
set<ll> divisor(ll n){
	set<ll> result;
	
	for(ll i = 0; i * i <= n; ++i){
	  if(n % i == 0){
	    result.insert(i);
	    result.insert(n / i);
	  }
	}
	
	return result;
}

// ２点の距離を計算する
double dist(double x1, double y1, double x2, double y2){
    double x = std::abs(x2 - x1);
    double y = std::abs(y2 - y1);
    double dist = sqrt((x * x) + (y * y));
    return dist;
}

// 最大公約数
ll gcd(ll a, ll b){
    if(a < b) std::swap(a, b);

    ll result = b;
    while(a % result != 0){
        result = a % b;
        a = b;
        b = result;
    }

    return result;
}

// 最小公倍数
ll gcm(ll a, ll b){
    return (a * b) / gcd(a, b);
}

ll num(ll n, ll c, ll d){
    ll g = gcd(c, d);
    ll l = c / g * d;
    // 全体 - Cの倍数 - Dの倍数 + C,Dの倍数
    ll res = n - (n / c) - (n / d) + (n / l);
    return res;
}

// 一番上の桁の値を求める
int upperNum(int _num){
    while(_num / 10 != 0){
        _num /= 10;
    }

    return _num;
}

// 桁数を数える
int countDigit(int n){
    int ans = 1;
    while(n / 10 != 0){
        n /= 10;
        ans++;
    }

    return ans;
}

int getDigit(int n){
    string s = to_string(n);

    return s.size();
}

// aで与えた数で何回で割れるか調べる関数
int func(int n, int a){
    if(n == 0) return 0;

    int count = 0;
    while(n % a == 0){
        n /= 2;
        count++;
    }

    return count;
}

// ２つの時計の針から角度を取得する
ld getAngle(ld _h, ld _m){
    // 時針の角度を求める
    ld alpha = ((ld)_h * 60.0 + (ld)_m) / 720.0;

    // 短針の角度を求める
    ld beta = ((ld)_m / 60.0);

    // 時針と短針の角度を求める
    ld theta = alpha - beta;

    return theta * 2 * PI;
}

// 素因数分解の数を数える
vector<pair<ll, int>> factorize(ll n){
    vector<pair<ll, int>> res;
    for(ll i = 2; i * i <= n; ++i){
        if(n % i){
            continue;
        }

        res.emplace_back(i, 0);
        while(n % i == 0){
            n /= i;
            res.back().second++;
        }
    }

    if(n != 1){
        res.emplace_back(n, 1);
    }

    return res;
}

// 余弦定理
ld cosTheorem(ld a, ld b, ld theta){
    return sqrt(a * a + b * b - (2 * a * b * cos(theta * PI / 180)));
}

// 平均値
ld average(const vector<ld>& v){
    int len = v.size();
    ld sum = 0;
    for(int i = 0; i < len; ++i){
        sum += v[i];
    }

    return sum / (ld)len;
}

// 分散
ld variance(const vector<ld>& v, const ld avr){
    int len = v.size();
    ld sum = 0;
    for(int i = 0; i < len; ++i){
        sum += (v[i] - avr) * (v[i] - avr);
    }

    return sum / (ld)len;
}

// ミンコフスキー距離
ld minkowski(const vector<ld>& x, const vector<ld>& y, const int n){
    ld dist = 0;
    return 0;
}

