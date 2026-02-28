#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* list3 = new ListNode(0);
    ListNode* list4 = list3;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            list4->next = list1;
            list1 = list1->next;
        } else {
            list4->next = list2;
            list2 = list2->next;
        }
        list4 = list4->next;
    }
    if (list1 != nullptr) {
        list4->next = list1;
    }
    if (list2 != nullptr) {
        list4->next = list2;
    }
    return list3->next;
}

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        for (auto i = lists.begin() + 1; i != lists.end(); i++) {
            *i = mergeTwoLists(*i, *(i - 1));
        }
        return lists.back();
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
    int arr1[] = {1, 4, 5};
    int arr2[] = {1, 3, 4};
    int arr3[] = {2, 6};
    ListNode* list1 = ListAPI().createList(arr1, 3);
    ListNode* list2 = ListAPI().createList(arr2, 3);
    ListNode* list3 = ListAPI().createList(arr3, 2);
    ListAPI().print(list1);
    ListAPI().print(list2);
    ListAPI().print(list3);
    vector<ListNode*> lists = {list1, list2, list3};
    ListNode* list4 = Solution().mergeKLists(lists);
    ListAPI().print(list4);
    return 0;
}