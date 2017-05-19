#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool sort_vals(int* a, int* b){
	return a[0]<b[0];
}

int min_changes(int ac, int aj, int** valsc, int** valsj){

	int** vals_combine = new int* [ac+aj+1];
	int time_left_c = 720;
	int time_left_j = 720;
	for (int i=0;i<ac;i++){
		vals_combine[i] = new int[3];
		vals_combine[i][0] = valsc[i][0];
		vals_combine[i][1] = valsc[i][1];
		vals_combine[i][2] = 1;
		time_left_j -= valsc[i][1] - valsc[i][0];
	}
	for (int i=0;i<aj;i++){
		vals_combine[ac+i] = new int[3];
		vals_combine[ac+i][0] = valsj[i][0];
		vals_combine[ac+i][1] = valsj[i][1];
		vals_combine[ac+i][2] = 2;
		time_left_c -= valsj[i][1] - valsj[i][0];
	}
	sort(vals_combine, vals_combine+ac+aj, sort_vals);
	vals_combine[ac+aj] = new int[3];
	vals_combine[ac+aj][0] = vals_combine[0][0]+1440;
	vals_combine[ac+aj][1] = vals_combine[0][1]+1440;
	vals_combine[ac+aj][2] = vals_combine[0][2];

	int count = 0;
	vector<int> i_c;
	vector<int> i_j;
	for (int i=0;i<ac+aj;i++){
		if (vals_combine[i][2]==1 && vals_combine[i+1][2]==1){ i_c.push_back(vals_combine[i+1][0]-vals_combine[i][1]); count+=2;}
		else if (vals_combine[i][2]==2 && vals_combine[i+1][2]==2){ i_j.push_back(vals_combine[i+1][0]-vals_combine[i][1]); count+=2;}
		else count++;
	}
	sort(i_c.begin(), i_c.end());
	sort(i_j.begin(), i_j.end());
	int i=0;
	while(i<i_j.size() && time_left_c - i_j[i] >= 0){
		time_left_c-=i_j[i];
		i++;
		count-=2;
	}
	i=0;
	while(i<i_c.size() && time_left_j - i_c[i] >= 0){
		time_left_j-=i_c[i];
		i++;
		count-=2;
	}
	return count;

}

int main(){
	ifstream in("B-large-practice.in");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	
	ofstream out("out.txt");
	streambuf *coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
	

	int t;
	cin>>t;
	for (int i=0;i<t;i++){
		int ac, aj;
		cin>>ac>>aj;
		int** i_c = new int*[ac];
		for (int j=0;j<ac;j++){
			i_c[j] = new int[2];
			cin>>i_c[j][0]>>i_c[j][1];
		}
		int** i_j = new int*[aj];
		for (int j=0;j<aj;j++){
			i_j[j] = new int[2];
			cin>>i_j[j][0]>>i_j[j][1];
		}
		cout<<"Case #"<<i+1<<": "<<min_changes(ac,aj,i_c,i_j)<<"\n";
	}
	
}
