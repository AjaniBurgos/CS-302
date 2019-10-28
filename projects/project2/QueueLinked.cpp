/// Precompiler directives ////////////////////////////////////////////////////
#ifndef QUEUE_LINKED_CPP
#define QUEUE_LINKED_CPP

/// Header files //////////////////////////////////////////////////////////////
#include "QueueLinked.h"

/// Class/Data Implementation /////////////////////////////////////////////////

///Function: Default Constructor
///Requirements: None
///Results: Creates an empty queue
///Input/Parameters: None
///Output: None
///Description: Sets both front & back to NULL
template <typename DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber)
{
	front=NULL;
	back=NULL;
}
///Function: Copy Constructor
///Requirements: None
///Results: Creates a copy of the other object
///Input/Parameters: QueueLinked& other
///Output: None
///Description: Creates a new queue, which is initialized with the dataItem of the other.
///						  Generates a new QueueNode object each time we traverse through the other queue.
template <typename DataType>
QueueLinked<DataType>::QueueLinked(const QueueLinked& other)
{
	QueueNode* tmp_new;
	QueueNode* tmp_other=other.front;
	front=new QueueNode(tmp_other.dataItem,NULL);
	tmp_new=front;
	while(tmp_other!=NULL)
	{
		tmp_other=tmp_other->next;
		tmp_new->next=new QueueNode(tmp_other->next.dataItem,NULL);
		tmp_new=tmp_new->next;
	}
}
///Function: Overloaded Assignment Operator
///Requirements: None
///Results: Sets the queue to be equivalent to the other object
///Input/Parameters: QueueLinked<DataType>& , QueueLinked& other
///Output: Returns the calling object (this)
///Description: Like the copy constructor, instead of simply pointing front & back to the other.front & back, instead makes a
///						  new QueueNode object separate from the other queue, but shares equivalent (not the same) data
template <typename DataType>
QueueLinked<DataType>& QueueLinked<DataType>::operator=(const QueueLinked& other)
{
	QueueNode* tmp_new;
	QueueNode* tmp_other=other.front;
	this->clear();
	if(this!=other)
	{
		this->front=new QueueNode(tmp_other.dataItem,NULL);
		tmp_new=this->front;
		while(tmp_other!=NULL)
		{
			tmp_other=tmp_other->next;
			tmp_new->next=new QueueNode(tmp_other->next.dataItem,NULL);
			tmp_new=tmp_new->next;
		}
	}
	return this;
}
///Function: Destructor
///Requirements: None
///Results: Deallocates memory being used by a queue
///Input/Parameters: None
///Output: None
///Description: Essentially just calls clear(), since it accomplishes the same task (getting rid of the queue object)
template <typename DataType>
QueueLinked<DataType>::~QueueLinked()
{
	clear();
}

///Function: Enqueue
///Requirements: Queue is not full
///Results: Inserts a newDataItem at the end of the queue
///Input/Parameters: DataType& newDataItem
///Output: None
///Description: Checks to see if it's empty. if it is then it creates a new node to start off the list
///						  If the list isn't empty, then it creates a new node, which is then linked up to the list
///						  by having back's next pointer point at the new node
template <typename DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
QueueNode* temp=new QueueNode(newDataItem,NULL);
	if(front==NULL)
	{
		front=temp;
		back=front;
	}
	else
	{
		back->next=temp;
		back=back->next;
	}
}
/// Function: Dequeue
/// Requirements: Queue is not empty
/// Results: Gets rid of the data item in front and returns it
/// Input/Parameters: None
///Output: Returns a DataType variable
/// Description: Checks if it's empty, if it is, then it throws an error message
/// 						 Else, saves a copy of the dataItem and deletes it. Using a temp pointer, it traverses
/// 						 the queue until it gets to the object prior to the end, which is what back points to.
template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error)
{
	if(isEmpty())
	{
		throw logic_error("dequeue() queue empty");
	}
	else
	{
		DataType temp = front->dataItem;
		QueueNode* tmp_ptr = front;
		front=front->next;
		delete tmp_ptr;
		tmp_ptr=NULL;
		return temp;
	}
}

///Function: Clear
///Requirements: None
///Results: Removes all data items in the queue
///Input/Parameters: None
///Output: None
///Description: Runs a loop until the queue is empty, which dequeues every iteration.
template <typename DataType>
void QueueLinked<DataType>::clear()
{
	while(!isEmpty()){
		dequeue();
	}
}

///Function: isEmpty
///Requirements: None
///Results: Returns true if it is empty, else false
///Input/Parameters: None
///Output: Returns true/false
///Description: Checks if either front or back is NULL, indicating an empty list.
///							If it is, then true. Else, false.
template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const
{
	if(front==NULL || back==NULL)
	{
		return true;
	}
	return false;
}
///Function: isFull
///Requirements: None
///Results: Returns true if it is full, else false
///Input/Parameters: None
///Output: Returns false
///Description: Essentially always returns false, since a linked list can never
///						  be full since its objects are be dynamically allocated.
template <typename DataType>
bool QueueLinked<DataType>::isFull() const
{
	return false;
}

/// Programming Exercise 2 /////////////////////////////////////////////////////

///Function: putFront
///Requirements: None
///Results: Inserts newDataItem at the front of the queue, whilst leaving the original order unchanged
///Input/Parameters: DataType& newDataItem
///Output: None
///Description: Checks to see if the queue is empty first, if it is, then it generates a new
///							QueueNode object which front points to. Else, generates a new QueueNode object,
///						  with it's next pointer pointing at front in order to link the list.
///						  Front then points to the new object since it is now in the front.
template <typename DataType>
void QueueLinked<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
	if(isEmpty())
	{
		front=new QueueNode(newDataItem,NULL);
	}
	else
	{
		QueueNode* temp=new QueueNode(newDataItem,NULL);
		temp->next=front;
		front=temp;
	}
}
///Function: getRear
///Requirements: None
///Results: Gets rid of dataItem in the back and returns its, whilst leaving the original queue unchanged
///Input/Parameters: None
///Output: Returns a DataType variable
///Description: Checks to see if the queue is empty, if it is then it throws an error message.
///						  Else if there's only one object in the queue, saves the dataItem into a temp variable and clears the queue.
///						  Else, uses a temp pointer to get to the object prior to the back pointer, and then deletes back.
///						  Back then points to the temp pointer to go to the previous (now the new back) object.
template <typename DataType>
DataType QueueLinked<DataType>::getRear() throw (logic_error)
{
	DataType temp;
	if(isEmpty())
	{
		throw logic_error("getRear() queue empty");
	}
	if(front==back)
	{
		temp=front->dataItem;
		clear();
		return temp;
	}
	else
	{
		temp=back->dataItem;
		QueueNode* tmp_ptr=front;
		while(tmp_ptr!=NULL)
		{
			if(tmp_ptr->next==back)
			{
				back=tmp_ptr;
				delete tmp_ptr->next;
				tmp_ptr->next=NULL;
			}
			tmp_ptr=tmp_ptr->next;
		}
		return temp;
	}
}
/// Programming Exercise 3 /////////////////////////////////////////////////////

///Function: getLength
///Requirements: None
///Results: Returns the number of data items in the queue
///Input/Parameters: None
///Output: Returns an int (the length)
///Description: Uses an index variable that is incremented each time a temp pointer traverses through the queue.
///						  Once that temp pointer reaches NULL, it returns the value of the index variable.
template <typename DataType>
int QueueLinked<DataType>::getLength() const
{
	int index=0;
	QueueNode* temp=front;
	while(temp!=NULL)
	{
		index++;
		temp=temp->next;
	}
	return index;
}

///Function: showStructure
///Requirements: None
///Results: Prints the contents of the queue
///Input/Parameters: None
///Output: None (prints the queue)
///Description: Checks to see if the list is empty, which simply prints out "Empty queue"
///						  Else, prints out the contents of the queue.
///						  The object in the front is formatted with '[]', whilst the reset are formatted normally
template <typename DataType>
void QueueLinked<DataType>::showStructure() const
{
	QueueNode* p;
    if ( isEmpty() )
	cout << "Empty queue" << endl;
    else
    {
	cout << "Front\t";
	for ( p = front ; p != NULL ; p = p->next )
	{
	    if( p == front )
	    {
		cout << '[' << p->dataItem << "] ";
	    }
	    else
	    {
		cout << p->dataItem << " ";
	    }
	}
	cout << "\trear" << endl;
    }
}

///Function: Parameterized Constructor
///Requirements: None
///Results: Creates a new Node initialized to nodeData
///Input/Parameters: DataType& nodeData, QueueNode* nextPtr
///Output: None
///Description: Initializes the dataItem variable to nodeData, and the next pointer points to nextPtr.
template <typename DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& nodeData, QueueNode* nextPtr)
{
	dataItem=nodeData;
	next=nextPtr;
}

/// Terminating precompiler directives  /////////////////////////////
#endif
