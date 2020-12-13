#pragma once
#include "validparentheses.cpp"
#include "twosum.cpp"
#include "mergetwosortedlists.cpp"
#include "implementstrstr.cpp"
#include "searchinsertposition.cpp"
#include "isvalidsudoku.cpp"
#include "addtwonumbers.cpp"
#include "longestsubstrwithoutrepeatingcharacters.cpp"

#include <assert.h>
#include <stdio.h>


void testValidParentheses(void) {
    validparentheses::Solution s;

    assert(s.isValid("()") == true);
    assert(s.isValid("") == true);
    assert(s.isValid("(") == false);
    assert(s.isValid(")") == false);
    assert(s.isValid("[)") == false);
    assert(s.isValid("(]") == false);
    assert(s.isValid("[({})]") == true);
    assert(s.isValid("()[]{}") == true);
    assert(s.isValid("[({])}") == false);
    assert(s.isValid("[(])") == false);
    assert(s.isValid("[[") == false);
    assert(s.isValid("]]") == false);
}

void testTwoSum(void) {

    twosum::Solution s;
    vector<int> nums = { 1,2,3,5,0 };
    vector<int> ans = { 0, 3 };
    assert(s.twoSum(nums, 6) == ans);
    
}

void linkedlistequality(ListNode* l1, ListNode* l2) {
    while (l1->next != nullptr) {
        assert(l1->val == l2->val);
        l1 = l1->next;
    }
}

ListNode* arrtolinkedlist(int arr[]) {
    ListNode* dummy = new ListNode();
    ListNode* ptr = dummy;
    for (unsigned int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
        dummy->next = new ListNode(arr[i]);
        dummy = dummy->next;
    }
    ListNode* tmp = ptr->next;
    free(ptr);
    return tmp;
}

void freelinkedlist(ListNode* arr) {
    while (arr->next != nullptr) {
        ListNode* tmp = arr;
        arr = arr->next;
        free(tmp);
    }
}

void testProb21(void) {

    prob21::Solution s;
    int arr[3] = { -21, -5, -2 };
    int arr2[3] = { -20, -4, 0 };
    int arr3[6] = { -21, -20, -5, -4, -2, 0 };
    ListNode* one = arrtolinkedlist(arr);
    ListNode* two = arrtolinkedlist(arr2);
    ListNode* three = arrtolinkedlist(arr3);

    ListNode* ans = s.mergeTwoLists(one, two);
    linkedlistequality(ans, three);
    freelinkedlist(one);
    freelinkedlist(two);
    freelinkedlist(ans);
    freelinkedlist(three);

}

void testP28(void) {
    p28::Solution s;
    assert(s.strStr("abbabbbbabaaa", "aba") == 8);
}

void testP35(void) {
    p35::Solution s;
    vector<int> v {1, 2, 3, 4, 5, 6, 7, 9};
    assert(s.searchInsert(v, 0) == 0);
    assert(s.searchInsert(v, 1) == 0);
    assert(s.searchInsert(v, -1) == 0);
    assert(s.searchInsert(v, 5) == 4);
    assert(s.searchInsert(v, 10) == 8);
}

void testP36(void) {

    char row1[9] = {'.', '.', '.', '.', '5', '.', '.', '1', '.'};
    char row2[9] = {'.', '4', '.', '3', '.', '.', '.', '.', '.'};
    char row3[9] = {'.', '.', '.', '.', '.', '3', '.', '.', '1'};
    char row4[9] = {'8', '.', '.', '.', '.', '.', '.', '2', '.'};
    char row5[9] = {'.', '.', '2', '.', '7', '.', '.', '.', '.'};
    char row6[9] = {'.', '1', '5', '.', '.', '.', '.', '.', '.'};
    char row7[9] = {'.', '.', '.', '.', '.', '2', '.', '.', '.'};
    char row8[9] = {'.', '2', '.', '9', '.', '.', '.', '.', '.'};
    char row9[9] = {'.', '.', '4', '.', '.', '.', '.', '.', '.'};
    char* arr[9];
    arr[0] = row1;
    arr[1] = row2;
    arr[2] = row3;
    arr[3] = row4;
    arr[4] = row5;
    arr[5] = row6;
    arr[6] = row7;
    arr[7] = row8;
    arr[8] = row9;
    int colSize[9] = { 9,9,9,9,9,9,9,9,9 };
    p36::Solution s;
    assert(s.isValidSudoku(arr, 9, colSize) == false);
}

void testp2(void) {
    p2::Solution s;
    int arr[3] = { 1, 3, 4 };
    int arr2[3] = { 9, 9, 9};
    int arr3[4] = { 0, 3, 2, 1 };
    ListNode* one = arrtolinkedlist(arr);
    ListNode* two = arrtolinkedlist(arr2);
    ListNode* three = arrtolinkedlist(arr3);
    ListNode* ans = s.addTwoNumbers(one, two);
    linkedlistequality(three, ans);
    freelinkedlist(one);
    freelinkedlist(two);
    freelinkedlist(three);
    freelinkedlist(ans);
}

void testp3(void) {
    p3::Solution s;
    assert(s.lengthOfLongestSubstring("adslfj;sdnfewanadl") == 9);
}

void test(void) {
    std::unordered_set<int> x({ 1, 4, 6 });
    assert(x.find(2) == x.end());
    assert(*x.find(4) == 4);
    x.erase(x.begin(), x.end());
    assert(x.size() == 0);
    x.erase(x.begin(), x.end());
    x.emplace(1);
    x.emplace(1);
    printf("Size is %d\n", x.size());

    std::set<int> a = { 0, 2, 6, 1, 4 };
    for (const int i : a) {
        printf("%d ", i);
    }
    printf("\n");
    a.insert(4);
    a.insert(5);
    for (const int i : a) {
        printf("%d ", i);
    }

    printf("%d\n", *a.begin());

    while (*a.begin() < 5) {
        a.erase(a.begin());
    }

    for (const int i : a) {
        printf("%d ", i);
    }

    for (int i = 0; i < (1 << 10); ++i) {
        printf("%d ", i);
    }

}

int main()
{
    testValidParentheses();
    testTwoSum();
    testProb21();
    testP28();
    testP35();
    testP36();
    testp2();
    testp3();
    test();
    printf("Good job; no errors.\n");
    getchar();
}