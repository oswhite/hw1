#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val){
	//first case: if empty
  if(size_==0){
    Item* newitem = new Item();
    head_ = newitem;
    tail_ = newitem;
    newitem->val[0] = val;
    newitem->last = 1;
  }

  //second case: if last item has room in array
  else if(tail_->last < ARRSIZE){
    tail_->val[tail_->last] = val;
    tail_->last++;
  }

  //third case: if last item does not have room in array
  else{
    Item* newitem = new Item();
    newitem->prev = tail_;
    tail_->next = newitem;
    tail_ = newitem;
    tail_->val[0] = val;
    tail_->last = 1;
  }

  //update size
  size_++;

}

void ULListStr::push_front(const std::string& val){
	//first case: if empty
  if(size_==0){
    Item* newitem = new Item();
    head_ = newitem;
    tail_ = newitem;
    newitem->val[0] = val;
    newitem->last = 1;
  }

  //second case: if head has room in array
	else if(head_->first > 0){
		head_->val[head_->first-1] = val;
		head_->first--;
	}

	//third case: if head is full
	else{
		Item* newitem = new Item();
		newitem->next = head_;
		head_->prev = newitem;
		head_ = newitem;
		newitem->val[ARRSIZE-1]=val;
		newitem->first = ARRSIZE-1;
		newitem->last = ARRSIZE;
	}

	//update size
	size_++;
}

void ULListStr::pop_back(){
	//first case: if empty
	if(size_==0){
		return;
	}

	//second case: if list has one element left
  else if(size_==1){
    delete tail_;
    tail_ = NULL;
    head_ = NULL;
  }

  //third case: if last item has only one value in array
  else if(tail_->last == 1){
    Item* temp = tail_;
    tail_ = tail_->prev;
    tail_->next = NULL;
    delete temp;
  }

  //fourth case: everything else
  else{
    tail_->last = tail_->last -1;
  }

  //update size
  size_ = size_-1;
}

void ULListStr::pop_front(){
	//first case: if empty
	if(size_==0){
		return;
	}

	//second case: if list has one element left
  else if(size_ == 1){
    delete tail_;
    tail_=NULL;
    head_=NULL;
  }

  //third case: first item in list has one value in array
  else if(head_->first == (ARRSIZE - 1)){ 
		head_ = head_->next;
		delete head_->prev;
		head_->prev = NULL;
  }

  //fourth case: first item in list has multiple values
  else{
    head_->first++;
  }

	//update size
	size_--;
}
std::string const & ULListStr::back() const {
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  //first case, if loc is invalid 
  if(loc < 0 || loc > size_){
    return NULL;
  }
  //second case: if loc is valid
	else{
		unsigned int temploc = 0;
		unsigned int temparray = head_->first;
		Item* tempitem = head_;
		while(temploc != loc){
			temploc = temploc + 1;
			temparray = temparray + 1;
			if(temparray == tempitem->last){
				tempitem = tempitem->next;
				temparray = 0;
			}
		}
		//once the temploc finds loc, return value
		return &tempitem->val[temparray];
	}
	
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
