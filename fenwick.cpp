#include <iostream>
#include <vector>
using std::vector;

class fenwick{
	public :
		fenwick(int S){
			this->S = S;
			v.resize(S + 2,0);
		}
		void update(int i,int val){
			for(; i < S; i += LowBit(i))v[i] += val;
		}
		int query(int i){
			int cont = 0;
			for(; i > 0; i -= LowBit(i))cont += v[i];
			return cont;
		}
		static inline int LowBit(int i){
			return i & -i;
		}
	;
	private :
		vector <int> v;
		int S;
	;
};

int main(){
	return 0;
}

