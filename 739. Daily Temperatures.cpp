#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
    int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
		for(int i=0;i<n;i++){
			while(!st.empty()&&temperatures[i]>temperatures[st.top()]){
				int pre=st.top();
				st.pop();
				ans[pre]=i-pre;
			}
			st.push(i);
		}
		return ans; 
		} 
}; 
ostream& operator<<(ostream& o, const vector<int>& v){
    	o<<"[";
    	for(int x:v) o<<x<<",";
    	o<<"]";
    	return o;
    }
int main(){
	Solution sol;
	vector<int> temperatures={73,74,75,71,69,72,76,73};
	cout<<sol.dailyTemperatures(temperatures);
}
