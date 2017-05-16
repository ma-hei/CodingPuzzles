#include <iostream>
#include <fstream>

using namespace std;

void spread_row_left(char** grid, int r_, int c_, char initial){
	for (int c__=c_; c_>=0; c_--){
		if (grid[r_][c_]=='?'){
			grid[r_][c_] = initial;
		} else if (grid[r_][c_]!=initial){
			return;
		}
	}
}

void spread_initial(char** grid, int r_, int c_, int r){
	char initial = grid[r_][c_];
	spread_row_left(grid, r_, c_, initial);
	for (int r__=r_-1;r__>=0;r__--){
		if (grid[r__][c_]=='?')
			spread_row_left(grid,r__,c_, initial);	
		else
			break;
	}
	for (int r__=r_+1; r__<r; r__++){
		if (grid[r__][c_]=='?')
			spread_row_left(grid,r__,c_,initial);
		else break;
	}
}

int main(){
	ifstream in("A-large-practice.in");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	int t;
	cin>>t;
	char*** grids = new char** [t];
	int** dims = new int*[t];

	for (int t_=0;t_<t;t_++){
		int r,c;
		cin>>r>>c;
		dims[t_] = new int[2];
		dims[t_][0] = r;
		dims[t_][1] = c;
		grids[t_] = new char*[r];
		for (int r_=0;r_<r;r_++){
			grids[t_][r_] = new char[c];
			cin>>grids[t_][r_];
		}
	}
	ofstream out("out.txt");
	streambuf *coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
	for (int t_=0;t_<t;t_++){
		int r,c;
		r = dims[t_][0];
		c = dims[t_][1];
		bool last_col_empty=true;
		for (int c_=0;c_<c;c_++){
			for (int r_=0;r_<r;r_++){
				last_col_empty = true;
				if (grids[t_][r_][c_]!='?'){
					last_col_empty = false;
					spread_initial(grids[t_], r_, c_, r);
				}
			}
		}
		if (last_col_empty){
			for (int c_ = c-2; c_>=0;c_--){
				if (grids[t_][0][c_]!='?'){
					for (int r_=0;r_<r;r_++){
						char initial = grids[t_][r_][c_];
						for (int c__=c_+1;c__<c;c__++){
							grids[t_][r_][c__] = initial;
						}	
					}
					break;
				}
			} 	
		}

		cout<<"Case #"<<(t_+1)<<":\n";
		for (int r_=0;r_<r;r_++){
			cout<<grids[t_][r_]<<"\n";
		}
	}
}
