#pragma once
#include <map>

template <class T>
T* GetResourceById(int id, std::map<int, T*>* m)
{
	auto it = m->find(id);
	if (it == m->end())
		return nullptr;
	return it->second;
};

template <class T>
void ClearMap(std::map<int, T*>* m)
{
	auto it = m->begin();
	while (it != m->end())
	{
		delete it->second;
		++it;
	}
	delete m;
}