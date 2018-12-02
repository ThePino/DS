#include <iostream>
#include <vector>
using std::vector;

class st{
	public :
		st(int N){
			tree.resize(N * 4);
			S = N;
		}
		st(int N,int *v){
			tree.resize(N * 4);
			S = N;
			this->v = v;
			build(0,0,S - 1);
		}
		void update(int sq, int eq,int val){
			this->sq = sq;
			this->eq = eq;
			this->val = val;
			updateUtil(0,0,S - 1);
		}
		int query(int sq,int eq){
			this->sq = sq;
			this->eq = eq;
			return queryUtil(0,0,S - 1);
		}
	;
	private :
		struct _node{
			int val = 0,
				lazy = 0;
		};
		vector <_node> tree;
		int S,*v = NULL;
		// utilities
		inline int get_mid(int s,int e){
			return (s + e) / 2;
		}
		inline int RC(int i){
			return i * 2 + 1;
		}
		inline int LC(int i){
			return i * 2 + 2;
		}
		// builder
		void build(int node,int s,int e){
			if(s == e){
				tree[node].val = v[s];
			}else{
				int lc = LC(node);
				int rc = RC(node);
				int mid = get_mid(s,e);
				build(lc,s,mid);
				build(rc,mid + 1,e);
				tree[node].val = tree[lc].val + tree[rc].val;
			}
		}
		int sq,eq,val;
		// update
		void updateUtil(int node,int s,int e){
			int rc = RC(node);
			int lc = LC(node);
			int mid = get_mid(s,e);
			// propagation
			if(tree[node].lazy){
				tree[node].val += tree[node].lazy;
				if(s != e){
					tree[rc].lazy += tree[node].lazy;
					tree[lc].lazy += tree[node].lazy ; 
				}
				tree[node].lazy = 0;
			}
			// out of range
			if(s > eq || e < sq)return;
			// nel range
			if(s >= sq && e <= eq){
				tree[node].val += val;
				if(s != e){
					tree[rc].lazy += val;
					tree[lc].lazy += val; 
				}
				return;
			}
			// overlaps 
			updateUtil(lc,s,mid);
			updateUtil(rc,mid + 1,e);
			tree[node].val = tree[lc].val + tree[rc].val;
		}
		// query
		int queryUtil(int node,int s,int e){
			int rc = RC(node);
			int lc = LC(node);
			int mid = get_mid(s,e);
			// propagation
			if(tree[node].lazy){
				tree[node].val += tree[node].lazy;
				if(s != e){
					tree[rc].lazy += tree[node].lazy;
					tree[lc].lazy += tree[node].lazy ; 
				}
				tree[node].lazy = 0;
			}
			// out of range
			if(s > eq || e < sq)return 0;
			// total
			if(s >= sq && e <= eq)return tree[node].val;
			// overlaps
			return queryUtil(lc,s,mid) + queryUtil(rc,mid + 1,e);
		}
	;
};

int main(){
	return 0;
}

