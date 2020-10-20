#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#if 0
// 时间：36ms，击败51.43%
// 内存：9.6MB，击败99.50%
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        // 两个链表的都有的部分
        while (l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            if (tail == nullptr) {
                head = new ListNode(sum);
                tail = head;
            }
            else {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }

            // 不要忘了l1和l2需要往前走
            l1 = l1->next;
            l2 = l2->next;
        }

        // 长的那条链表剩下的部分
        l1 = (l1 != nullptr) ? l1 : l2;
        while (l1 != nullptr) {
            sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            tail->next = new ListNode(sum);
            tail = tail->next;

            // 不要忘了l1需要往前走
            l1 = l1->next;
        }

        // 千万不要忘记这部分 - 处理最后的进位
        if (carry > 0) {
            tail->next = new ListNode(carry);
            tail = tail->next;
        }

        return head;
    }
};
#endif

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0, carry = 0;
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            tail->next = new ListNode(sum);
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *left = l1 == nullptr ? l2 : l1;
        while (left != nullptr) {
            sum = left->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            tail->next = new ListNode(sum);
            tail = tail->next;
            left = left->next;
        }

        if (carry > 0) tail->next = new ListNode(carry);
        return dummy.next;
    }
};

int main()
{
    /*
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    */

    /*
    ListNode* l1 = new ListNode(5);
    ListNode* l2 = new ListNode(5);
    */

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(8);

    ListNode* l2 = new ListNode(0);

    Solution s;
    ListNode* result = s.addTwoNumbers(l1, l2);

    return 0;
}