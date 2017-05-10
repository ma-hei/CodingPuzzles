#include <iostream>

using namespace std;

int main(){
	string s;
	cin>>s;
	int cnt = 0;
	for (int i=1;i<s.length();i++){
		if (s[i]=='K' && s[i-1]=='V') cnt++;
	}
	for (int i=0;i<s.length();i++){
		if (s[i]=='V' && i>0 && s[i-1]=='V' && (i==s.length()-1 || s[i+1]!='K')){
			cout<<(cnt+1)<<"\n";
			return 0;
		}
		if (s[i]=='K' && i<(s.length()-1) && s[i+1]=='K' && (i==0 || s[i-1]!='V')){
			cout<<(cnt+1)<<"\n";
			return 0;
		}
	}
	cout<<cnt<<"\n";
}
