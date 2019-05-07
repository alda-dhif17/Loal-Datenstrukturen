#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdexcept>
#include "LinkedList.h"

using namespace std;


class Car{
	public:
		int age;
		int km;

		Car(int _age, int _km){
			age = _age;
			km = _km;
		}

		void setAge(int _age){
			age = _age;
		}

		void setKM(int _km){
			km = _km;
		}
};


bool myEquals(Car a, Car b){
	if(a.age == b.age && a.km == b.km){
		return true;
	}

	return false;
}

template <class Type>
void printList(List<Type> *list){
	for(int i = 0; i < (*list).getSize(); i++){
		printf("[%d] => %d\n", i, (*list).getValueByCopy(i));
	}
}

int main()
{
	List<int> list; 
	list.equals = &defaultEquals;
	list.add(5);
	printList(&list);

	return 0;
}
