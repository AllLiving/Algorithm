#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;

int glob=1;
mutex trd_cvt;

void test(){
	while(glob <= 80){ // task make sure that the subthread's life period.
		trd_cvt.lock();
		printf("Thread%d :",this_thread::get_id());
		for(int i=1; i<=5; i++){
//			if(glob <= 100)
				cout << glob++ << ' ';
//			if(glob > 100)	break;	 
		}printf("\n");
		printf("Thread%d finish.\n\n",this_thread::get_id());
		trd_cvt.unlock();
	}
}

int main(){
	cout << "Main thread begin " << this_thread::get_id() <<endl;
	vector<int> v;
	v.push_back(3);
	v.push_back(3);
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<' ';
	}
	
//	vector<thread> thread_set;
//	
//	for(int i=0; i<5; i++)
//		thread_set.push_back(thread(test)); 
//	for(auto & subthread: thread_set)
//		subthread.join();
	
	cout << "Main thread finish.\n";
	return 0;
}
