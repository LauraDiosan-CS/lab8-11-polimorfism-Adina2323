#pragma once

#include <vector>
#include <algorithm>
using namespace std;

template <class T> class IRepository {
protected:
	vector<T> elem;
public:
	IRepository();
	void add(T&);
	int find(T&);
	void update(T&, T&);
	int remove(T&);
	int size();
	vector<T> getAll();
};

template<class T>
inline IRepository<T>::IRepository()
{
}

template<class T>
inline void IRepository<T>::add(T& e)
{
	elem.push_back(e);
}

template<class T>
inline int IRepository<T>::find(T& e)
{
	auto it = std::find(elem.begin(), elem.end(), e);
	if (it != elem.end()) return distance(elem.begin(), it);
	return -1;
}

template<class T>
inline void IRepository<T>::update(T& vechi, T& nou)
{
	std::replace(elem.begin(), elem.end(), vechi, nou);
}

template<class T>
inline int IRepository<T>::remove(T& e)
{
	auto last = std::remove(elem.begin(), elem.end(), e);
	if (last != elem.end()) {
		elem.erase(last, elem.end());
		return 0;
	}
	return -1;
}

template<class T>
inline int IRepository<T>::size()
{
	return elem.size();
}

template<class T>
inline vector<T> IRepository<T>::getAll()
{
	return elem;
}