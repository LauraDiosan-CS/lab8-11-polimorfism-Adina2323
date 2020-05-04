#pragma once
#include <vector>
#include <algorithm>
using namespace std;

template <class T> class Repo {
protected:
	vector<T> elem;
public:
	Repo();
	void add(T&);
	int find(T&);
	void update(T&, T&);
	int remove(T&);
	int size();
	vector<T> getAll();
};

template<class T>
inline Repo<T>::Repo()
{
}

template<class T>
inline void Repo<T>::add(T& e)
{
	elem.push_back(e);
}

template<class T>
inline int Repo<T>::find(T& e)
{
	auto it = std::find(elem.begin(), elem.end(), e);
	if (it != elem.end()) return distance(elem.begin(), it);
	return -1;
}

template<class T>
inline void Repo<T>::update(T& vechi, T& nou)
{
	std::replace(elem.begin(), elem.end(), vechi, nou);
}

template<class T>
inline int Repo<T>::remove(T& e)
{
	auto last = std::remove(elem.begin(), elem.end(), e);
	if (last != elem.end()) {
		elem.erase(last, elem.end());
		return 0;
	}
	return -1;
}

template<class T>
inline int Repo<T>::size()
{
	return elem.size();
}

template<class T>
inline vector<T> Repo<T>::getAll()
{
	return elem;
}
