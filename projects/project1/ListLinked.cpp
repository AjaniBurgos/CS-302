#ifndef LIST_LINKED_CPP
#define LIST_LINKED_CPP

#include "ListLinked.h"
		template <typename DataType>
    List<DataType>::List(int ignored){
			head=NULL;
			cursor=NULL;
		}
		template <typename DataType>
    List<DataType>::List(const List& other){
			head=other.head;
			cursor=other.cursor;
		}
		template <typename DataType>
    List<DataType>& List<DataType>::operator=(const List& other){
			this.clear();
			this->head=other.head;
			this->cursor=other.cursor;
			return this;
		}
		template <typename DataType>
    List<DataType>::~List(){
			clear();
		}

		template <typename DataType>
    void List<DataType>::insert(const DataType& newDataItem) throw (logic_error){
			if(cursor!=NULL){
			ListNode* temp = new ListNode(newDataItem,cursor->next);
			cursor->next=temp;
			cursor=temp;
			}
			else{
				head = new ListNode(newDataItem,NULL);
				cursor=head;
			}
		}
		template <typename DataType>
    void List<DataType>::remove() throw (logic_error){
			ListNode* temp=cursor;
			if(head!=NULL){
				if(cursor!=head){
					gotoPrior();
					cursor->next=temp->next;
					delete temp;
					temp=NULL;
					if(cursor->next==NULL){
						cursor=head;
					}
				}
				else{
					head=cursor->next;
					delete cursor;
					cursor=head;
				}
			}
		}
		template <typename DataType>
    void List<DataType>::replace(const DataType& newDataItem) throw (logic_error){
			if(!isEmpty()){
				cursor->dataItem=newDataItem;
			}
		}
		template <typename DataType>
    void List<DataType>::clear(){
			if(isEmpty()==false){
				while(head->next!=NULL){
					cursor=head;
					head=head->next;
					delete cursor;
				}
				delete head;
				head=NULL;
				cursor=NULL;
			}
		}
		template <typename DataType>
    bool List<DataType>::isEmpty() const{
			if(head==NULL){
				return true;
			}
			return false;
		}
		template <typename DataType>
    bool List<DataType>::isFull() const{
			return false;
		}

		template <typename DataType>
    void List<DataType>::gotoBeginning() throw (logic_error){
			if(!isEmpty()){
				cursor=head;
			}
		}
		template <typename DataType>
    void List<DataType>::gotoEnd() throw (logic_error){
			if(!isEmpty()){
				while(cursor->next!=NULL)
				{
					gotoNext();
				}
			}
		}
		template <typename DataType>
    bool List<DataType>::gotoNext() throw (logic_error){
			if(!isEmpty()){
				if(cursor->next!=NULL){
					cursor=cursor->next;
					return true;
				}
			}
			return false;
		}
		template <typename DataType>
    bool List<DataType>::gotoPrior() throw (logic_error){
			ListNode* temp=cursor;
			cursor=head;
			if(!isEmpty()){
				while(cursor!=temp)
				{
					if(cursor->next==temp){
						cursor->next=temp;
						return true;
					}
					else{
						cursor=cursor->next;
					}
				}
			}
			return false;
		}
		template <typename DataType>
    DataType List<DataType>::getCursor() const throw (logic_error){
			if(cursor!=NULL){
				return cursor->dataItem;
			}
		}

    // Programming exercise 2
		template <typename DataType>
		void List<DataType>::moveToBeginning () throw (logic_error){
			ListNode* temp;
			if(!isEmpty()){
				if(cursor!=NULL){
					gotoPrior();
					temp=cursor;
					cursor=cursor->next;
					temp->next=cursor->next;
					cursor->next=head;
					head=cursor;
				}
			}
		}

    // Programming exercise 3
		template <typename DataType>
    void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error){
			ListNode* temp=new ListNode(newDataItem,cursor);
			gotoPrior();
			cursor->next=temp;
			cursor=temp->next;
		}

		template <typename DataType>
    void List<DataType>::showStructure() const{
			ListNode* temp=head;
			if(temp==NULL){
			    cout << "Empty list" << endl;
			    return;
			}
			while(temp!=NULL){
				if(cursor==temp){
					cout << "[" << temp->dataItem << "]" << " ";
				}
				else{
					cout << temp->dataItem << " ";
				}
				temp=temp->next;
			}
			delete temp;
			temp=NULL;
		}

		template <typename DataType>
		List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr){
			dataItem=nodeData;
			next=nextPtr;
		}

#endif
