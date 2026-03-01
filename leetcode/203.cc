#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode node(0, head);
        ListNode* list = &node;
        while (list->next != nullptr) {
            auto next = list->next;
            if (next->val == val) {
                list->next = next->next;
                delete next;
            } else {
                list = next;
            }
        }
        return node.next;
    }
};

class ListAPI {
   public:
    ListNode* createList(int arr[], int n) {
        if (n == 0)
            return nullptr;
        ListNode* head = new ListNode(arr[0]);
        ListNode* list4 = head;
        for (int i = 1; i < n; ++i) {
            list4->next = new ListNode(arr[i]);
            list4 = list4->next;
        }
        return head;
    }
    void print(ListNode* list) {
        while (list != nullptr) {
            cout << list->val << " ";
            list = list->next;
        }
        cout << endl;
    }
};

int main() {
    int arr1[] = {7, 7, 7, 7, 7, 7, 7};
    ListNode* list1 = ListAPI().createList(arr1, 7);
    int val = 7;
    ListNode* list2 = Solution().removeElements(list1, val);
    ListAPI().print(list2);
    return 0;
}