#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > get_all_inds(int n, int p){
  
}


int find_range_in_row(vector<pair<int,int> >& intervals, pair<int,int>& range){
  for (int i=0;i<intervals.size();i++){
    if ((range.second>=intervals[i].first && range.second<=intervals[i].second) || (range.first>=intervals[i].first && range.first<=intervals[i].second)){
      return i;
    }
  }
  return -1;
}

bool find_range_in_remaining_rows(vector<vector<pair<int,int> > >& intervals, pair<int,int> &range){
  for (int i=1;i<intervals.size();i++){
    if (find_range_in_row(intervals[i], range)==-1){
      return false;
    }
  }
  return true;
}

void remove_range_in_remaining_rows(vector<vector<pair<int,int> > >&intervals, pair<int,int> &range){
 for (int i=1;i<intervals.size();i++){
    int temp = find_range_in_row(intervals[i], range);
    intervals[i][temp] = pair<int,int>(-1,-1);
  }

}

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
<<<<<<< HEAD
			sort(Q[n_].begin(), Q[n_].end());
=======
            sort(Q[n_].begin(), Q[n_].end());
>>>>>>> f6887fcf1aa0829e496eb4a0bbc7de4df1184fcd
		}
		vector<vector<pair<int, int> > > intervals(n, vector<pair<int,int> >(p,pair<int,int>(-1,-1))); 	
		calc_intervals(intervals, Q, R);

<<<<<<< HEAD
		int cnt=0;
		for (int p_=0;p_<p;p_++){
			if (intervals[0][p_].first!=-1 && remaining_rows_have(intervals, intervals[0][p_])){
				remove_from_rows(intervals, intervals[0][p_]);
				intervals[0][p_] = pair<int,int>(-1,-1);
				cnt++;
			}	
		}

		cout<<"Case #"<<t_+1<<": "<<cnt<<"\n";
=======
<<<<<<< HEAD
//		for (int n_=0;n_<n;n_++){
//			for (int p_=0;p_<p;p_++){
//				cout<<intervals[n_][p_].first<<" : "<<intervals[n_][p_].second<<"\n";
//			}
//			cout<<"\n";
//		}
		
		int max_cnt=0;
		if (n==1){
			for (int p_=0;p_<p;p_++){
				if (intervals[0][p_].first!=-1){
					max_cnt++;
				}
			}
		} else {
			int* myints = new int[p];
			for (int p_=0;p_<p;p_++){
				myints[p_] = p_;
			}
			do{
				int cnt = 0;
				//for (int p_=0;p_<p;p_++){
				//	cout<<myints[p_]<<" ";
				//}
				for (int p_=0;p_<p;p_++){
					pair<int,int> int1 = intervals[0][p_];
					pair<int,int> int2 = intervals[1][myints[p_]];
					if (int1.first!=-1 && ((int1.first>=int2.first && int1.first<=int2.second) || (int1.second>=int2.first && int1.second<=int2.second))){
						cnt++;
					}
				}
				max_cnt = max(max_cnt, cnt);
			}while(next_permutation(myints, myints+p));
		}
		cout<<"Case #"<<t_+1<<": "<<max_cnt<<"\n";
//		cout<<"\n";
=======
        int count=0;
        //for (int p_=0;p_<p;p_++){
        //  if(intervals[0][p_].first!=-1 && find_range_in_remaining_rows(intervals, intervals[0][p_])){
        //    remove_range_in_remaining_rows(intervals, intervals[0][p_]);
        //    intervals[0][p_]=pair<int,int>(-1,-1); 
        //    count++;
        //  }
        //}
        
        //for (int n_=0;n_<n;n_++){
        //  for (int p_=0;p_<p;p_++){
        //    cout<<"["<<intervals[n_][p_].first<<", "<<intervals[n_][p_].second<<"] ";
        //  }
        //  cout<<"\n";
        //}
        
        if (n==1){

        } else {

        }

		cout<<"Case #"<<t_+1<<": "<<count<<"\n";
>>>>>>> some stuff
>>>>>>> f6887fcf1aa0829e496eb4a0bbc7de4df1184fcd
	}
}
