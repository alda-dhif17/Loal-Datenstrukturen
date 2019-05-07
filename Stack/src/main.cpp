#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

template <class Type>
class Stack{    //stapel
    private:
        int size;
        Type *data;

    public:
        Stack(){
            this->size = 0;
        }

        // pusht dinge
        void push(Type param){
            if(size == 0){
                this->data = (Type*)malloc(sizeof(Type));
                this->data[this->size] = param;
            }else{
                this->data = (Type*)realloc(this->data, sizeof(Type) * (this->size + 1));
                this->data[this->size] = param;
            }

            this->size++;
        }
        //löscht dinge und gibt NULL zurück
        Type pop(){
            if(this->size == 0){
                return NULL;
            } else {
                Type result = seek();
                this->data[this->size - 1] = NULL;
                this->data = (Type*)realloc(this->data, sizeof(Type) * (this->size - 1));
                
                this->size--;
                   
                return result;
            }
        }
        
        // gibt letztes Element zurück ohne es zu löschen
        Type seek(){
            if(this->size == 0) {
                return NULL;
            } else {
                return this->data[this->size - 1];
            }
        }

        //LET IT GOOOOOOOO LET IT GOOOOOOOOOO
        void clear(){
            if(this->size > 0) {
                free(this->data);
                this->size = 0;
            }
        }
};

int main(int argc, char *argv[]) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);

    printf("%d\n", stack.seek());
    printf("%d\n", stack.pop());
    printf("%d\n", stack.seek());
    stack.pop();
    stack.pop();
    stack.pop();
}