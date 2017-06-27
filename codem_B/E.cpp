#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstdio> 
using namespace std;

const int maxn = 50000 + 10;
const int maxt = 1000000 + 1;

const char alphabet[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}; 

char tmp[20]; 
string itoa(int n, int k) {
	int c;
	for (c = 0; n; c ++) tmp[c] = alphabet[n % k], n /= k; 
	tmp[c] = 0;
	for (int i = 0; i < c / 2; ++ i) swap(tmp[i], tmp[c-1-i]); 
	string str (tmp); 
	return str; 
}

string seq(int n, int k) {
	string str = ""; 
	for (int i = 1; i <= n; i ++)
		str = str + itoa(i, k);
	return str; 
}

string s, t; 
int nx[maxt]; 

int main() {
	int n;
	cin >> n;
	cin >> t; 
	nx[0] = 0;
	for (int i = 0; i < t.length() - 1; i ++) {
		int j = nx[i]; 
		while (j && t[i + 1] != t[j]) j = nx[j - 1];
		nx[i + 1] = (t[i + 1] == t[j]) ? j + 1 : 0; 
	}
	for (int k = 2; k <= 16; k ++)  {
		s = seq(n, k);
		int j = 0; 
		bool matched = false; 
		for (int i = 0; i < s.length(); i ++ ) {
			while (j && s[i] != t[j]) j = nx[j - 1];
			j = (s[i] == t[j]) ? j + 1 : 0; 
			if (j == t.length()) {
				matched = true;
				break; 
			}
		}
		if (matched) {
			cout << "yes\n";
			return 0; 
		}
	}
	cout << "no\n"; 
	return 0; 
}