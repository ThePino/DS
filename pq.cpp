#include <vector>
#include <algorithm>
#include <utility>
using std::vector;
using std::swap;

// i will add "remove by key"

class PQ{
	public :
		PQ(int S){
			// max size of the queue 
			v.resize(S);
		}
		inline int top(){
			return v[0];
		}
		inline void push(int &x){
			v[S] = x;
			i = S;
			p = PP(S);
			S++; 
			while(i >= 0 && v[i] < v[p]){
				swap(v[i],v[p]);
				i = p;
				p = PP(i);
			}
		}
		inline bool empty(){
			if(S == 0)return true;
				else return false;
		}
		inline void pop(){
			S--;
			v[0] = v[S];
			pos = 0;
			small;
			do{
				small = pos;
				lc = LC(pos);
				rc = RC(pos);
				if(lc < S  && v[lc] < v[small])small = lc;
				if(rc < S && v[rc] < v[small])small = rc;
				if(small != pos){
					swap(v[pos],v[small]);
					pos = small;
					small = -1;	
				}
			}while(small != pos);
		}
	;
	private :
		vector <int> v;
		int S = 0,small,lc,rc,pos,i,p;
		// utilities
		inline int LC(int &i){
			return i * 2 + 1;
		}
		inline int RC(int &i){
			return i * 2 + 2;
		}
		inline int PP(int &i){
			return (i - 1) / 2;
		}
	;
};

int main(){
	return 0;
}

