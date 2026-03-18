#include<iostream>
#include<string>
#include<stack>
using namespace std;
class MyQueue {
	stack<int> st_i,st_o;
public:
    MyQueue() {
    }
    void trans(){
		if(st_o.empty()){
			while(!st_i.empty()){
				st_o.push(st_i.top());
				st_i.pop();
			}
		}
	}
    void push(int x) {
        st_i.push(x);
    }
    
    int pop() {  
     	trans();
     	int a=st_o.top();
     	st_o.pop();
     	return a; 
    }
    
    int peek() {
       	trans();
        return st_o.top(); 
    }
    
    bool empty() {
        if(st_i.empty()&&st_o.empty()){
        	return true;
		}
		else return false;
    }
};
int main(){
	 MyQueue myqueue;
	 myqueue.push(1);
	 myqueue.push(2);
	 myqueue.push(3);
	 myqueue.push(4);
	 cout<<myqueue.pop()<<endl;
	 cout<<myqueue.pop()<<endl;
	 cout<<myqueue.pop()<<endl;
	 cout<<myqueue.pop()<<endl;
}

