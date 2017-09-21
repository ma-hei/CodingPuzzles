#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <unordered_set>

using namespace std;

struct Set{
  Set* p;
  int rank;
  bool cycle;
  Set () {
    p = this;
    rank = 0;
    cycle = false;
  }
};

unordered_map<int, Set*> sets;
unordered_map<int, int> G;

void unite(Set* a, Set* b){
  bool cycle = a->cycle || b->cycle;
  if (a->rank > b->rank) b->p = a;
  else{
    a->p = b;
    if (a->rank == b->rank){
      b->rank = b->rank+1;
    }
  }
  a->cycle=cycle;
  b->cycle=cycle;
}

Set* find_set(Set* x){
  if (x!=x->p)
    x->p = find_set(x->p);
  return x->p;
}

int main(){
  int N;
  cin>>N;
  for (int i=0;i<N;i++){
    int x,y;
    cin>>x>>y;
    G[x]=(y);
    sets[x] = new Set();
    sets[y] = new Set();
  }
  for (auto it = G.begin(); it!=G.end(); it++){
    if (find_set(sets[it->first]) != find_set(sets[it->second]))
      unite(sets[it->first], sets[it->second]);
    else{ 
      Set* s = find_set(sets[it->first]);
      s->cycle = true;
    }
  }    
  unordered_map<Set*, unordered_set<int> > ccs;
  for (auto it = G.begin(); it!=G.end(); it++){
    ccs[find_set(sets[it->first])].insert(it->first);
    ccs[find_set(sets[it->second])].insert(it->second);
  }
  cout<<"n of sets: "<<ccs.size()<<"\n";
  for (auto it = ccs.begin(); it!=ccs.end(); it++){
    for (int i : it->second){
      cout<<i<<" ";
    }
    cout<<"... "<<it->first->cycle<<"\n";
  }
}
