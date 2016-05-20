#include "stdafx.h"

#include<string>

using namespace std;

#include "test2_add_two_numbers.h"


ListNode* test2_add_two_numbers::addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    //convert nodes to string
    string result1 = "";
    getNumberFromList(l1,result1);
	std::reverse(result1.begin(), result1.end());
    //int l1num = atoi(result1.c_str());
        
    string result2 = "";
    getNumberFromList(l2,result2);
	std::reverse(result2.begin(), result2.end());
    //long l2num = strtol(result2.c_str(),NULL,10);
        
    //add two strings like numbers
    //long lsum = l1num + l2num;
	string lvalStr = AddToStringAsNumbers(result1,result2);
        
    //char lval[256] = "";
    //sprintf_s(lval,"%d",lsum);

	//reverse the string
	//string lvalStr = lval;

	std::reverse(lvalStr.begin(), lvalStr.end());
    const char * rvalPtr = lvalStr.c_str();

    //convert into list
     int ival= (char)*rvalPtr - (char)'0';
    ListNode * parent = new ListNode(ival);
	//char * lvalPtr = lval;
	rvalPtr++;
    convertNumberToList(rvalPtr, parent);
        
    return parent;
}
    
string test2_add_two_numbers::AddToStringAsNumbers(string num1Str, string num2Str)
{
	string resultStr = "";
	//start at ends and add
	string::reverse_iterator start1 = num1Str.rbegin();
	string::reverse_iterator start2 = num2Str.rbegin();

	string::reverse_iterator end1 = num1Str.rend();
	string::reverse_iterator end2 = num2Str.rend();
	
	int carry = 0;
	//Boolean bcarry = false;

	while(start1!=end1 || start2!=end2)
	{
		int val1 = 0;
		int val2 = 0;

		if(start1!=end1)
		{
			
			char letter = *start1;
			val1 = atoi(&letter);
		}
		if(start2!=end2)
		{
			//++start2;
			char letter = *start2;
			val2 = atoi(&letter);
		}


		int result = 0;

		result = val1 + val2 + carry;

		if(result > 9)
		{
			result = result - 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}

		char value[2] = "";
		sprintf_s(value,"%d",result);

		resultStr = value+ resultStr;

		if(start1!=end1)
		{
			++start1;
		}
		if(start2!=end2)
		{
			++start2;
		}
	}
	if(carry==1)
	{
		resultStr = "1" + resultStr;
	}

	return resultStr;
	
}

//retrieve number from linked list
void test2_add_two_numbers::getNumberFromList(ListNode* l1, string & result)
{
    //node always has a value
    // but might not have a child
        
    //we scale the value on return
    // from tail recursion
    char val[2] = "";
    sprintf_s(val,"%d",l1->val);
        
    result+=val;
        
    if(l1->next!=NULL)
    {
        getNumberFromList(l1->next,result);
    }

}
    
//convert number to linked list
void test2_add_two_numbers::convertNumberToList(const char * val, ListNode* parent)
{
    if(*val!=NULL)
    {
        int ival= (char)*val - (char)'0';
            
        ListNode * node = new ListNode(ival);
            
        parent->next = node;
            
        val++;
            
        convertNumberToList(val, node);
    }
        
}
