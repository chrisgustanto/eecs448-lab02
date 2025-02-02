/**
*	@author
*	@date
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	/** TODO
		Fix this method
	*/
	return(m_size);
	//return(0);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	/** TODO
		Fix this method
	*/
	// Iterate through entire list
	// worst case is value is found in last node
	// make sure list is not empty, if so return false
	if (!isEmpty())
	{
		while (temp != nullptr) // while not at nullptr
		{
			if (value == temp->getValue())
			{
				isFound = true;
				break;
			}
			else
			{
				temp = temp->getNext();
			}
		}
	}

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	/** TODO
		Fix this method
	*/

	// if list is not empty, go thru list

	if (!isEmpty())
	{
		secondintoLast = m_front;
		// iterate to penultimate node, 2nd to last
		while(secondintoLast->getNext()->getNext()!= nullptr)
		{
			secondintoLast = secondintoLast->getNext();
		}
		// once there, set last node to penultimate->getNext
		lastNode = secondintoLast->getNext();
		secondintoLast->setNext(nullptr);
		// delete last node
		delete lastNode;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
