#include<iostream>
using namespace std;
  struct ListNode {//khai bao 1 struct moi ten ListNode
      int val;//gia tri cua ListNode
      ListNode *next;//khai bao con tro kieu ListNode
      ListNode() : val(0), next(nullptr) {}//neu khoi tao ListNode node1() thi node1 co node1.val=0, ko tro den dau ca
      ListNode(int x) : val(x), next(nullptr) {}// neu khoi tao node2(10) thi node2.val=10, ko tro den dau ca 
      ListNode(int x, ListNode *next) : val(x), next(next) {}//neu khoi tao node3(20,node2) thi node3.val=20, con tro next cua node3 tro den node 2
  };
ListNode* nodeA=new ListNode(10);
ListNode* nodeB=new ListNode(20,nodeA);
ListNode* nodeC=new ListNode(30,nodeB);
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyNode= new ListNode(0,head);
        ListNode* crr=dummyNode;
        while(crr->next!=nullptr){
        	if(crr->next->val==val){
        		crr->next=crr->next->next;
			}
			else crr=crr->next;
		}
		return dummyNode->next;
    }
};
