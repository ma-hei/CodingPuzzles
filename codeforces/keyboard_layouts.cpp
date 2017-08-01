#include <iostream>

using namespace std;

int main(){
  int* mapping = new int[26];
  string a;
  string b;
  cin>>a;
  for (int i=0;i<26;i++){
    mapping[a[i]-'a']=i;
  }
  cin>>b;
  string c;
  cin>>c;
  for (char chr : c){
    if (chr-'0'>=0 && chr-'0'<=9) cout<<chr;
    else if (chr-'A'>=0 && chr-'A'<=25 ) cout<<(char)toupper(b[mapping[chr-'A']]);
    else cout<<b[mapping[chr-'a']];
  }
}
