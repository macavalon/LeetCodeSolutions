struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class test2_add_two_numbers {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    
    //retrieve number from linked list
    void getNumberFromList(ListNode* l1, string & result);
    
    //convert number to linked list
    void convertNumberToList(const char * val, ListNode* parent);

	string AddToStringAsNumbers(string num1Str, string num2Str);

};