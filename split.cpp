/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"


/* Add a prototype for a helper function here if you need */
bool isEven(Node*& noi);

void split(Node*& in, Node*& odds, Node*& evens)
{

//base case: if all nodes have been split
if(in == nullptr){
	return;
}


//case one, if element is odd
if(!isEven(in)){
	//if odds does not have elements yet, need to create new item first
	if(odds == nullptr){
		odds = in;
		in = in->next;
		odds->next = nullptr;
		split(in,odds,evens);
	}
	//if odds already has elements
	else{
		odds->next = in;
		in = in->next;
		odds->next->next = nullptr;
		split(in,odds->next,evens);
	}
}

//case two, if element is even
if(isEven(in)){
	//if evens does not have elements yet
	if(evens == nullptr){
		evens = in;
		in = in->next;
		evens->next = nullptr;
		split(in,odds,evens);
	}
	//if evens already has elements
	else{
		evens->next = in;
		in = in->next;
		evens->next->next = nullptr;
		split(in,odds,evens->next);
	}
}

}

/* If you needed a helper function, write it here */
bool isEven(Node*& noi){
	if(noi == nullptr){
		return false;
	}
  int curr = noi->value;
  if(curr%2 == 0){
    return true;
  }
  else{
    return false;
  }
}
