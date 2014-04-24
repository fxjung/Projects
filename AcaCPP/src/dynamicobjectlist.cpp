#include "dynamicobjectlist.hpp"
#include "object.h"

DynamicObjectList::DynamicObjectList() :
m_capacity(10),
m_count(0)
	{
		m_list = new Object*[10];
		for (int i = 0; i < 10; i++) m_list[i] = nullptr;
		m_capacity = 10;
		m_count = 0;
	};

	/**
	DynamicObjectList::DynamicObjectList(DynamicObjectList& old) :
		m_count(old.m_count),
		m_capacity(old.m_capacity)
	{
		m_list = new Object*[old.m_capacity];

	} **/

	DynamicObjectList::~DynamicObjectList()
	{
		for (unsigned int i = 0; i < m_count; i++) delete m_list[i];
		delete[] m_list;
	};

	void DynamicObjectList::reserve(unsigned int capacity)
	{
		if (capacity < m_capacity) {
			Object** newlist = new Object*[capacity];
			for (unsigned int i = 0; i < m_capacity; i++) newlist[i] = m_list[i];
			delete[] m_list;
			m_list = newlist;
			m_capacity = capacity;
		}
	};

	Object* DynamicObjectList::createObject_back(char* name)
	{
		if (m_count == m_capacity) reserve(m_capacity * 2);
		Object* a = new Object(name);
		m_list[m_count++] = a;
		return a;
	};

	void DynamicObjectList::destroyObject(unsigned int position)
	{
		if (0 > position || position > m_capacity - 1) return;
		delete m_list[position];
		for (unsigned int i = position; i < m_capacity; i++)
		{
			m_list[i] = m_list[i+1];
		}
		m_list[m_capacity] = nullptr;
		m_count--;
	};

	Object* DynamicObjectList::getAt(unsigned int position) {
		if (0 > position || position > m_count- 1) return nullptr;
		return m_list[position];
	};