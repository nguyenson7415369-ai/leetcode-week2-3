#include<iostream>
#include<cmath>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
    // Tru?ng h?p co b?n: Danh sách r?ng ho?c ch? có 1 nút
    if (!head) return nullptr;
    if (!head->next) return new TreeNode(head->val);

    // BU?C 1: Tìm trung di?m (Slow & Fast)
    ListNode *slow = head, *fast = head;
    ListNode *prev = nullptr; // C?n prev d? ng?t k?t n?i danh sách

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // BU?C 2: T?o nút g?c t? trung di?m
    TreeNode* root = new TreeNode(slow->val);

    // BU?C 3: Ng?t k?t n?i d? chia dôi danh sách
    if (prev) prev->next = nullptr; 

    // BU?C 4: Ð? quy cho 2 n?a
    root->left = sortedListToBST(head);      // N?a trái t? d?u d?n tru?c slow
    root->right = sortedListToBST(slow->next); // N?a ph?i t? sau slow d?n h?t

    return root;
}
};
