#include <iostream>
#include <unordered_map>

using namespace std;

void fill_table(string a, string b, unordered_map<char,char>& m, int* t){
	for (int i=0;i<a.length();i++)
		if (a[i]!=' '){
			m[a[i]] = b[i];
			if (b[i]>='A' && b[i]<='Z'){
				t[b[i]-'A'] = 1;
			}
		}
}

int main(){
	int n;
	cin >> n;
	string result;
	string temp;
	unordered_map<char,char> m;
	int t[26];
	for (int i=0;i<26;i++) t[i]=0;
	fill_table("IuVEJxTXs UvOHhng yZKfAYmaqolM","vpVZzBNtL SCubWma ocIYneAPqxDs",m,t);
	fill_table("NtGQibw djPrCpek FWzL","hRkMGgJ fHrFUQTj XOwd",m,t);
	fill_table("aySBaPyb RM gzYMynY","PolyProg is awesome",m,t);
	fill_table("cars", "EPFL",m,t);
	m['D']='K';

	for (int i=0;i<n;i++){
		cin>>temp;
		for (char c : temp) result+= m[c];
		result += ' ';
	}
	cout<<result<<"\n";

	//for (int i=0;i<26;i++) cout<<i<<": "<<m['a'+i]<<"\n";
	//for (int i=0;i<26;i++) cout<<i<<": "<<m['A'+i]<<"\n";
	//for (int i=0;i<26;i++) if (t[i]==0) cout<<i<<"\n";
	//J is not 
}	
