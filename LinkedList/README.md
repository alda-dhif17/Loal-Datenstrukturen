# Linked List
- [Linked List](#linked-list)
	- [Definition](#definition)
	- [How to begin using it](#how-to-begin-using-it)
	- [Usage](#usage)
		- [Methods](#methods)
			- [int getSize()](#int-getsize)
			- [void add(Type param)](#void-addtype-param)
## Definition

The list itself is generic.<br>
It has a first and last pointer pointing to the first and last node respectively and a size attribute of type int<br>

## How to begin using it

You have to download the LinkedList.h and include it in our project/file

After downloading, put the .h file into the same directory as your sourcefile
```cpp
#include "LinkedList.h"
```

## Usage

You have to specify the type of the list
```cpp
// Type is the type you want to use
// List<Type> list;

// Example:
List<int> list;

// you can also initialize the List with an array and the length of that array

```

### Methods
#### int getSize()
```cpp
int getSize();
```

Gives back the size of the list as an int

Example:
```cpp
int size = list.getSize();
```

---

#### void add(Type param)
```cpp
// Type is the generic type of the list
void add(Type param)
```

Adds an element of the generic type to the list.

Example:
```cpp
List<int> list;
list.add(1);
```