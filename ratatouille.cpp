#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void calc_intervals(vector<vector<pair<int, int> > >& intervals, vector<vector<int> > Q, int* R){
	int n = Q.size();
	int p = Q[0].size();
	for (int n_=0;n_<n;n_++){
		for (int p_=0;p_<p;p_++){
			int have = Q[n_][p_];
			int need = R[n_];
			int temp = (10*have)/(11*need);
			int lower_limit = ((temp*need*11)/10>=have) ? temp : -1;
			lower_limit = lower_limit==-1 ? ((((temp+1)*need*9)/10<=have) ? temp+1 : -1) : lower_limit;
			if (lower_limit!=-1){
				temp = (10*have)/(9*need);
				int upper_limit = (temp*need*11)/10>=have ? temp : lower_limit;
				intervals[n_][p_] = pair<int,int>(lower_limit,upper_limit);
			}
		}
	}

}

int row_has(vector<pair<int, int> >& intervals, pair<int,int> &interval){
	int p = intervals.size();
	for (int p_=0;p_<p;p_++){
		if ((interval.first>=intervals[p_].first && interval.first<=intervals[p_].second) || (interval.second>=intervals[p_].first && interval.second<=intervals[p_].second)){
			return p_;
		}
	}
	return -1;	
}

bool remaining_rows_have(vector<vector<pair<int, int> > >& intervals, pair<int,int>& interval){

	int n = intervals.size();
	for (int n_=1;n_<n; n_++){
		if (row_has(intervals[n_], interval)==-1){
			return false;
		}
	}
	return true;
}	

void remove_from_rows(vector<vector<pair<int,int> > >& intervals, pair<int,int>& interval){
	int n = intervals.size();
	for (int n_=1;n_<n;n_++){
		int temp = row_has(intervals[n_], interval);
		intervals[n_][temp] = pair<int,int>(-1,-1);
	}
}

int main(){
	
	ifstream in("B-small-practice.in");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	
	ofstream out("out.txt");
	streambuf *coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
	
	int t;
	cin>>t;
	for (int t_=0;t_<t;t_++){
		cout<<t_<<"\n";
		int n,p;
		cin>>n>>p;
		int* R = new int[n];
		for (int n_=0;n_<n;n_++){
			cin>>R[n_];
		}
		vector<vector<int> > Q(n, vector<int>(p,0));
		for (int n_=0;n_<n;n_++){
			for (int p_=0;p_<p;p_++){
				cin>>Q[n_][p_];	
			}
			sort(Q[n_].begin(), Q[n_].end());
		}
		vector<vector<pair<int, int> > > intervals(n, vector<pair<int,int> >(p,pair<int,int>(-1,-1))); 	
		calc_intervals(intervals, Q, R);

		int cnt=0;
		for (int p_=0;p_<p;p_++){
			if (intervals[0][p_].first!=-1 && remaining_rows_have(intervals, intervals[0][p_])){
				remove_from_rows(intervals, intervals[0][p_]);
				intervals[0][p_] = pair<int,int>(-1,-1);
				cnt++;
			}	
		}

		cout<<"Case #"<<t_+1<<": "<<cnt<<"\n";
	}
}
