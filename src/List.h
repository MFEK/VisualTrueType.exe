// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#include <cstdint>
#include <memory>

#ifndef List_dot_h
#define List_dot_h

class ListMessage {
public:
	ListMessage(void);
	virtual ~ListMessage(void);
	int32_t type; // application specific poor people's type tag...
private:
};

class ListElem {
public:
	ListElem(void);
	virtual void Clone(ListElem **into); // sort of a copy constructor
	virtual ~ListElem(void);
	virtual void Receive(ListMessage *message, bool forward);
	ListElem *prev,*next; // to be considered read-only for clients
};

class ListStruct {
public:
	ListStruct(void);
	virtual void Clone(ListStruct **into); // sort of a copy constructor
	virtual ~ListStruct(void);
	virtual void InsertAtStart(ListElem *that); // abstract
	virtual void InsertBefore(ListElem *that, ListElem *before); // abstract
	virtual void InsertAfter (ListElem *that, ListElem *after);  // abstract
	virtual void InsertAtEnd(ListElem *that); // abstract
	virtual void Remove(ListElem *that); // abstract
	virtual void Broadcast(ListMessage *message, bool forward);
	static void Delete(ListStruct **list);
	int32_t elems;			   // to be considered read-only for clients
	ListElem *first,*last; // to be considered read-only for clients
};

class LinearListStruct : public ListStruct {
public:
	LinearListStruct(void);
	virtual void Clone(ListStruct **into); // sort of a copy constructor
	virtual ~LinearListStruct(void);
	virtual void InsertAtStart(ListElem *that);
	virtual void InsertBefore(ListElem *that, ListElem *before);
	virtual void InsertAfter (ListElem *that, ListElem *after);
	virtual void InsertAtEnd(ListElem *that);
	virtual void Remove(ListElem *that);
};

class CircularListStruct : public ListStruct {
public:
	CircularListStruct(void);
	virtual void Clone(ListStruct **into); // sort of a copy constructor
	virtual ~CircularListStruct(void);
	virtual void InsertAtStart(ListElem *that);
	virtual void InsertBefore(ListElem *that, ListElem *before);
	virtual void InsertAfter (ListElem *that, ListElem *after);
	virtual void InsertAtEnd(ListElem *that);
	virtual void Remove(ListElem *that);
	virtual void Reverse(void);
};

#endif // List_dot_h
