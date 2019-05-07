#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdexcept>

using namespace std;

template <class Type>
struct Node {
	Node *next;
	Type data;
};

template <class Type>
class List {
private:
	int size;
	Node<Type> *first;
	Node<Type> *last;

	/**
	 * gets the node data by the index
	 * */
	Type getRecursive(int index, int counter, Node<Type> *currentNode) {
		if (index == counter) {
			return (*currentNode).data;
		}
		else {
			if ((*currentNode).next == NULL) {
				Type *type = (Type*)malloc(sizeof(Type));
				return (*type);
			}
			else {
				return getRecursive(index, counter + 1, (*currentNode).next);
			}
		}
	}
	/**
	 * Gets you the Node<Type> with an index and startNode from where you should start
	 * */
	Node<Type> *getNodeByIndex(int index, Node<Type> *startNode) {
		if (index == 0) {
			return startNode;
		}

		struct Node<Type> *help = startNode;

		for (int i = 1; i <= index; i++) {
			help = (*help).next;
		}

		return help;
	}

	Node<Type> *getFirst(){
		return this->first;
	}

	Node<Type> *getLast(){
		return this->last;
	}

public:
	bool (*equals)(Type a, Type b);

	List() { 
		first = NULL;
		last = NULL;
		size = 0;
		equals = NULL;
	}

	explicit List(Type *array, int _size) {
		this->first = NULL;
		this->last = NULL;
		this->size = 0;
		this->equals = NULL;
		this->addArray(array, _size);
	}

	int getSize() {
		return this->size;
	}

	bool isEquals(Type a, Type b){
		if(this->equals == NULL){
			cout << "\n\n\n===================================\nEXCEPTION: You must set the Equals-Function\n===================================\n\n" << endl;
			throw exception();
			return false;
		}

		return this->equals(a, b);
	}

	void add(Type param) {
		if (size == 0) {
			//add first element to list
			struct Node<Type> *element = (struct Node<Type>*)malloc(sizeof(struct Node<Type>));
			(*element).next = NULL;
			(*element).data = param;
			this->first = element;
			this->last = element;
			this->size++;
		}
		else {
			//add element at the end
			struct Node<Type> *element = (struct Node<Type>*)malloc(sizeof(struct Node<Type>));
			(*element).next = NULL;
			(*element).data = param;
			//umpointen
			this->last->next = element;
			this->last = element;
			this->size++;
		}
	}

	void addAt(Type param, int index) {
		if (index < 0) {
			return;
		}
		else if (index >= this->size) {
			add(param);
		}
		else {
			if (index == 0) {
				//add at first position
				struct Node<Type> *element = (struct Node<Type>*)malloc(sizeof(struct Node<Type>));
				(*element).next = this->first;
				(*element).data = param;
				this->first = element;
			}
			else {
				//add further back
				//getValueByCopy node before the index on which a new one should added
				struct Node<Type> *node = getNodeByIndex(index - 1, this->first);
				struct Node<Type> *element = (struct Node<Type>*)malloc(sizeof(struct Node<Type>));
				(*element).data = param;
				(*element).next = (*node).next;
				(*node).next = element;
				this->size++;
			}
		}
	}

    void addListByReference(List<Type> *param){
        this->last.next = (*param).getFirst();
        this->last = (*param).getLast();
    }

    void addListAtByReference(List<Type> *param, int index){
        if(index == 0){
            //add on first position
            this->first = (*param).getFirst();
            this->last->next = (*param).getLast();
            return;
        }

        if(index >= this->size){
            return;
        }
    
        struct Node<Type> *before = getNodeByIndex(index - 1, this->first);
        struct Node<Type> *current = (*before).next;
        (*before).next = (*param).getFirst();
        param->last->next = current;
    }

    void addListByCopy(List<Type> param) {
        int size = param.getSize();
        struct Node<Type> *toAdd = param.getFirst();

        for(int i = 0;i<size;i++){
            this->add(toAdd->data);
            toAdd = toAdd->next;
        }
    }

    void addListAtByCopy(List<Type> param, int index) {
        int size = param.getSize();
		if(index < 0 || index >= this->size) {
			return;
		}
        
        struct Node<Type> *toAdd = param.getFirst();
        
        for(int i = 0, j = index; i<size;i++, j++) {
            this->addAt(toAdd->data,j);
            toAdd = toAdd->next;
        }
    }
    
    bool contains(Type param){
        for(int i = 0; i < this->size; i++){
			if(isEquals(getValueByCopy(i), param)){
				return true;
			}
            // if(this.getValueByCopy(i) == param){
            // if(this.getValueByCopy(i).equals(param))
            //     return true;
            // }
        }
        return false;
    }

	Type getValueByCopy(int index) {
		if (index >= this->size || index < 0) {
			Type *type = (Type*)malloc(sizeof(Type));
			return (*type);
		}

		return getRecursive(index, 0, this->first);
	}

	Type *getValueByReference(int index){
		struct Node<Type> *node = getNodeByIndex(index, this->first);
		Type *type = &(*node).data;

		return type;
	}

	void remove(int index) {
		if (index >= this->size) {
			return;
		}
		else if (index == 0) {
			struct Node<Type> *help = this->first;
			this->first = (*help).next;
			free(help);
			this->size--;
		}
		else {
			//getValueByCopy node before the index on which the node should be removed
			struct Node<Type> *before = getNodeByIndex(index - 1, this->first);
			//check if it's last one
			if (index == (this->size - 1)) {
				struct Node<Type> *helpToLast = this->last;
				this->last = before;
				(*before).next = NULL;
				this->size--;
				free(helpToLast);
				return;
			}

			//otherwise remove node inbewteen
			struct Node<Type> *help = (*before).next;
			(*before).next = (*help).next;
			free(help);
			this->size--;
		}
	}

    void removeFirstByValue(Type param){
        for(int i = 0; i < this->size; i++){
			if(isEquals(this.getValueByCopy(i), param)){
				remove(i);
				return;
			}
		}
    }

    void removeAllByValue(Type param){
		for(int i = 0; i < this->size;){

			if(isEquals(this->getValueByCopy(i), param)){
				remove(i);
				continue;
			}
			i++;
		}
    }

	int indexOf(Type param) {
		for (int i = 0; i < this->size; i++) {
			struct Node<Type> *current = getNodeByIndex(i, this->first);

			if(isEquals((*current).data, param)){
				return i;
			}
		}

		return -1;
	}

	int *indexesOf(Type param) {
		int *result = (int*)malloc(sizeof(int) * 2);
		int counter = 1;

		for (int i = 0; i < this->size; i++) {
			struct Node<Type> *current = getNodeByIndex(i, this->first);

			if(isEquals((*current).data, param)){
				result[counter] = i;
				counter++;
				realloc(result, (sizeof(int) * counter) + 1);
			}
		}

		result[0] = counter - 1;

		return result;
	}

	void replaceByIndex(int index, Type param) {
		if (index < -1 || index >= this->size) {
			return;
		}

		struct Node<Type> *node = getNodeByIndex(index, this->first);
		(*node).data = param;
	}

	void replaceFirstByValue(Type param, Type replace) {
		for(int i = 0; i < this->size; i++) {
			struct Node<Type> *current = getNodeByIndex(i, this->first);	
			
			if(isEquals((*current).data, param)){
				(*current).data = replace;
				return;
			}
		}
	}

	void replaceAllByValues(Type param, Type replace) {
		for(int i = 0; i < this->size; i++){
			struct Node<Type> *current = getNodeByIndex(i);

			if(isEquals((*current).data, param)){
				(*current).data = replace;
			}
		}
	}

    void clear() {
        struct Node<Type> *toRemove = this->first;
        
        for(int i = 0; i++ < (this->size)-1;) {
            struct Node<Type> *save = toRemove->next;
            free(toRemove);
            toRemove = save;
        }

        this->first = NULL;
        this->last = NULL;
        this->size = 0;
    }

	Type* toArray(){
		Type *array = (Type *)malloc(this->size * sizeof(Type));
		for(int i = 0; i < this.size; i++){
			array[i] = this.getNodeByIndex(i).data;
		}
		return array;
	}

	void addArray(Type* array, int size){
		for(int i = 0; i < size; i++){
			this->add(array[i]);
		}
	}

	List<Type> getSublistAsCopy(int startIndex, int endIndex){
		//including start & end index
		List<Type> result;
		
		if(startIndex < 0 || endIndex >= this->size){
			return result;
		}

		for(int i = startIndex; i <= endIndex; i++){
			result.add(getValueByCopy(i));
		}

		return result;
	}

	List<Type> sortListByCopy(List<Type> param) {
		int size = param->getSize();
		struct Node<Type> *min = NULL;

		for(int i = 0; i<size; i++) {
			min = param->getNodeByIndex(i);
			for(int j = i; j<size; j++) {
				if(param->getNodeByIndex(j)->data < min->data) {
					min = param->getNodeByIndex(j);
				}
			}
			for(int k = 0; k<=i; k++) {
				
			}
		}

	}
};

template <class Type>
bool defaultEquals(Type a, Type b){

	if(a == b){
		return true;
	}

	return false;
}