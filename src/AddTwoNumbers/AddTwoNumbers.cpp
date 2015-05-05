#include <iostream>

using namespace std;

 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode    *ret_list_hdr, *list;
        int         tmp_sum, add_on;

        list = NULL;
        ret_list_hdr = NULL;
        
        add_on = 0;
        while (1) {
            tmp_sum = add_on;
            tmp_sum += l1 == NULL ? 0 : l1->val;
            tmp_sum += l2 == NULL ? 0 : l2->val;

            if (add_on == 0 && l1 == NULL && l2 == NULL)
                break;
            
            add_on = tmp_sum / 10;
            tmp_sum %= 10;
            if (!ret_list_hdr) {
                ret_list_hdr = new ListNode(tmp_sum);
                list = ret_list_hdr;
            } else {
                list->next = new ListNode(tmp_sum);
                list = list->next;
            }

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            
        }
        
        return ret_list_hdr;
    }
};

int main(void)
{
    ListNode *list_a = new ListNode(2);
    list_a->next = new ListNode(4);
    list_a->next->next = new ListNode(3);

    ListNode *list_b = new ListNode(5);
    list_b->next = new ListNode(6);
    //list_b->next->next = new ListNode(4);

    Solution *solution = new Solution;
    ListNode *ans = solution->addTwoNumbers(list_a, list_b);
    
    return 0;
}

