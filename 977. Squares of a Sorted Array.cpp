#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    	vector<int> tempt(nums.size());
    	int left=0,right=nums.size()-1;
    	for(int i=nums.size()-1;i>=0;i--){
    		if(abs(nums[left])>abs(nums[right])){
    			tempt[i]=nums[left]*nums[left];
    			left++;
			}
			else{
				tempt[i]=nums[right]*nums[right];
				right--;
			}
		}
		return tempt;
    }
};
 ostream& operator<<(ostream& o, const vector<int>& v){
    	o<<"[";
    	for(int x:v) o<<x<<",";
    	o<<"]";
    	return o;
	}
int main(){
	vector<int> nums={-4,-1,0,3,10};//{-4,-1,1,16,100}
	Solution sol;
	cout<<sol.sortedSquares(nums);
}
