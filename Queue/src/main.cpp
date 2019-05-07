#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

template <class Type>
class Queue{
	private:
		Type *data;
		int size;

		/**
			Deletes the first item and shrinks the Queue (array) 
		*/
		void deleteFirst(){
			for(int i = 0; i < this->size - 1; i++){
				data[i] = data[i + 1];
			}

			data = (Type*)realloc(data, sizeof(Type) * (this->size - 1));
			this->size--;
		}

	public:
		/**
			constructor for creating an empty Queue
		*/
		Queue(){
			this->size = 0;
		}

		/**
			Second constructor for initializing the Queue with an array of type Type and the length of the array as an int
		*/
		explicit Queue(Type* array, int length) {
			for(int i = 0; i < length; i++){
				push(array[i]);
			}
		}

		/**
			adds an Element of type Type as the last element
		*/
		void push(Type toAdd) {
			if(this->size > 0){
				data = (Type*)realloc(data, sizeof(Type)*(this->size+1));
			}else{
				data = (Type*)malloc(sizeof(Type)*(this->size+1));
			}
			data[size] = toAdd;
			this->size++;
		}

		/**
			removes the first elements of the queue
		*/
		void pop() {
			deleteFirst();
		}

		/**
			returns the first element of the Queue

			@return Element of type Type
		*/
		Type getFirst(){
			Type result = data[0];
			return result;
		}
		
		/**
			returns the last added Element of the Queue

			@return Element of type Type
		*/
		Type getLast(){
			Type result = data[this->size - 1];
			return result;
		}

		/**
			gives back the Size of the Queue

			@return size of array (int)
		*/
		int getSize(){
			return this->size;
		}
};

int main(int argc, char *argv[]) {
	
	Queue<int> q;
	
	q.push(1);
	q.push(2);
	q.push(3);

	for(int i = 0; i < q.getSize(); i++){
		printf("%d First ==> %d | Last ==> %d\n",i , q.getFirst(), q.getLast());
		q.pop();
		i--;
	}
	
	return 0;
}