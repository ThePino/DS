#include <deque>
#include <utility>
	
using std::deque;
using std::pair;
using std::make_pair;

// the largest number in a consecutive set

class KQ{
	public :
		inline int top(){
			return q.front().first;
		}
		void push(int val,int pos){
			while(!q.empty() && q.back().first < val)q.pop_back();
			q.push_back(make_pair(val,pos));
		}
		void pop(int pos){
			while(!q.empty() && q.front().second <= pos )q.pop_front();
		}
	;
	private :
		deque <pair<int,int>> q;
	;
};
int main(){
	return 0;
}

