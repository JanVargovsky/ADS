#include <iostream>

template <typename T>
class LinkedList
{
public:
	struct TwoWayLinkedListNode
	{
		TwoWayLinkedListNode *Previous, *Next;
		T Value;
		TwoWayLinkedListNode(T value)
			: Value(value), Previous(nullptr), Next(nullptr)
		{}
	};

	class LinkedListIterator
	{
		TwoWayLinkedListNode *current;

	public:
		LinkedListIterator(TwoWayLinkedListNode *x) :current(x) {}
		LinkedListIterator(const LinkedListIterator& mit) : current(mit.current) {}
		LinkedListIterator& operator++() { current = current->Next; return *this; }
		LinkedListIterator operator++(int) { LinkedListIterator tmp(*this); operator++(); return tmp; }
		bool operator==(const LinkedListIterator& rhs) const { return current == rhs.current; }
		bool operator!=(const LinkedListIterator& rhs) const { return current != rhs.current; }
		T& operator*() { return current->Value; }
	};

	typedef typename LinkedListIterator iterator;

private:
	TwoWayLinkedListNode *head;
	size_t size;

	TwoWayLinkedListNode* getInternal(size_t index)
	{
		auto current = head;
		while (index-- > 0) current = current->Next;
		return current;
	}

public:
	LinkedList();
	~LinkedList();

	T get(size_t index);

	void addFirst(T item);
	void addLast(T item);
	void insertAt(T item, size_t index);
	T remove(size_t index);
	void clear();

	// iterators
	iterator begin() { return iterator(this->head); }
	iterator end() { return iterator(nullptr); }
};

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0)
{
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template<typename T>
T LinkedList<T>::get(size_t index)
{
	return getInternal(index)->Value;
}

template<typename T>
void LinkedList<T>::addFirst(T item)
{
	auto node = new TwoWayLinkedListNode(item);
	if (head == nullptr)
		head = node;
	else
	{
		head->Previous = node;
		node->Next = head;
		head = node;
	}
	size++;
}

template<typename T>
void LinkedList<T>::addLast(T item)
{
	auto node = new TwoWayLinkedListNode(item);
	if (head == nullptr)
		head = node;
	else
	{
		auto current = head;
		while (current->Next != nullptr) current = current->Next;

		current->Next = node;
		node->Previous = current;
	}
	size++;
}

template<typename T>
void LinkedList<T>::insertAt(T item, size_t index)
{
	if (head == nullptr)
	{
		addFirst(item);
		return;
	}
	else if (index == size)
	{
		addLast(item);
		return;
	}

	auto current = getInternal(index);

	auto node = new TwoWayLinkedListNode(item);

	auto prev = current->Previous;
	auto next = current;

	prev->Next = node;
	node->Previous = prev;

	next->Previous = node;
	node->Next = next;
	size++;
}

template<typename T>
T LinkedList<T>::remove(size_t index)
{
	auto node = getInternal(index);
	auto previous = node->Previous;
	auto next = node->Next;

	previous->Next = next;
	next->Previous = previous;

	auto item = node->Value;
	delete node;
	return item;
}

template<typename T>
void LinkedList<T>::clear()
{
	auto current = head;
	while (current->Next != nullptr)
	{
		auto next = current->Next;
		delete current;
		current = next;
	}
}
