/*******************************************************************
 * Author: Feyico
 * Date: 2020-12-16 19:08:06
 * LastEditors: Feyico
 * LastEditTime: 2020-12-17 13:44:27
 * Description: 自定义结构体求交集合集并集
 * FilePath: /setDiff/src/main.cpp
 *******************************************************************/
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct element
{
	int id;
	string name;
	double weight;

	element()
	{
		this->id = 1;
		this->name = "yeah";
		this->weight = 67.1;
	}

	element(const int ele_id, const string& ele_name, const double ele_weight)
	{
		this->id = ele_id;
		this->name = ele_name;
		this->weight = ele_weight;
	}

	bool operator<(const element &item) const
	{
		if (this->id < item.id)
		{
			return true;
		}
		else if (this->id == item.id)
		{
			return this->weight < item.weight ? true : false;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(const element &item) const
	{
		if (this->id != item.id)
		{
			return true;
		}
		else if (this->id == item.id)
		{
			return this->weight != item.weight ? true : false;
		}
	}
};

struct _Iter_less_iter
{
	template<typename _Iterator1, typename _Iterator2>
	bool operator()(_Iterator1 __it1, _Iterator2 __it2) const
	{ 
		return *__it1 < *__it2; 
	}
};

_Iter_less_iter __iter_less_iter()
{
	return _Iter_less_iter();
}

void printElementsSet(const string& name, const set<element>& items)
{
	if(items.size())
	{
		set<element>::const_iterator it = items.begin();
		for ( ; it != items.end(); ++it)
		{
			cout << name << " | items id: " << it->id << " | name: " << it->name << " | weight: " << it->weight << endl;
		}
		
	}
}

void printElementsVector(const string& name, const vector<element>& items)
{
	if(items.size())
	{
		vector<element>::const_iterator it = items.begin();
		for ( ; it != items.end(); ++it)
		{
			cout << name << " | items id: " << it->id << " | name: " << it->name << " | weight: " << it->weight << endl;
		}
		
	}
}

int main(int argc, char *argv[])
{
	set<string> a;
	set<string> b;
	a.insert("abc");
	a.insert("sdf");
	a.insert("asdf");
	
	b.insert("a");
	b.insert("asdf");
	b.insert("uuu");
	vector<string> r;
	set_difference(a.begin(),a.end(),b.begin(),b.end(),inserter(r, r.begin()));
	set_difference(b.begin(),b.end(),a.begin(),a.end(),inserter(r, r.begin()));
	for (vector<string>::const_iterator itor = r.begin(); itor != r.end(); itor++)
	{
		cout << "string: " << *itor << endl;
	}
	
	set<element> box_one;
	box_one.insert(element(1, "aaa", 12.2));
	box_one.insert(element(2, "aaa", 17.2));
	box_one.insert(element(2, "qwd", 11.2));
	printElementsSet("box_one", box_one);
	
	set<element> box_two;
	box_two.insert(element(3, "aaa", 12.2));
	box_two.insert(element(2, "aaa", 17.2));
	box_two.insert(element(3, "qwd", 11.2));
	printElementsSet("box_two", box_two);

	vector<element> box_result;
	//box_result.resize(box_one.size() + box_two.size() + 1);

	//__set_difference，结果集中包含所有属于第一个集合但不属于第二个集合的元素
	(void)__set_difference(box_one.begin(), box_one.end(), box_two.begin(), box_two.end(), inserter(box_result, box_result.begin()), __iter_less_iter());
	(void)__set_difference(box_two.begin(), box_two.end(), box_one.begin(), box_one.end(), inserter(box_result, box_result.begin()), __iter_less_iter());

	printElementsVector("box_result", box_result);

	return 0;
}