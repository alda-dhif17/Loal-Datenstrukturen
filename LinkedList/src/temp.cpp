/*List<int> list;
	list.add(0);
	list.add(2);
	list.add(3);
	list.add(3);
	list.add(3);
	list.add(3);
	list.add(2);
	list.add(5);
	list.add(7);
	list.add(3);
	list.add(4);

	for (int i = 0; i < list.getSize(); i++) {
		printf("[%d] -> %d\n", i, list.get(i));
	}

	printf("\n\nAdd Node inbetween\n");
	list.addAt(1, 1);
	printf("\n\n");

	for (int i = 0; i < list.getSize(); i++) {
		printf("[%d] -> %d\n", i, list.get(i));
	}

	printf("\n\nRemove on index 1\n");
	list.remove(1);
	printf("\n\n");

	for (int i = 0; i < list.getSize(); i++) {
		printf("[%d] -> %d\n", i, list.get(i));
	}

	printf("\n\nIndex of 3 => [%d]\n\n", list.indexOf(3));

	//indexesof => an 1. Stelle Anzahl wie oft gefunden
	int *indexes = list.indexesOf(3);
	printf("sizeof => %d\n", indexes[0]);
	for (int i = 0; i < indexes[0]; i++) {
		printf("3 was found on => [%d]\n", indexes[i + 1]);
	}

	printf("\n\nReplace the before last element with number '9'\n");
	list.replaceByIndex(list.getSize() - 2, 9);

	for (int i = 0; i < list.getSize(); i++) {
		printf("[%d] -> %d\n", i, list.get(i));
	}

	//add list
	List<int> list2;
	printf("Size -> %d\nList: \n", list.getSize());

	for (int i = 0; i < list.getSize(); i++) {
		printf("[%d] -> %d\n", i, list.get(i));
	}

	list2.add(5);
	list.addListByCopy(list2);

	printf("\nSize -> %d\nList: \n", list.getSize());

	for (int i = 0; i < list.getSize(); i++) {
		printf("[%d] -> %d\n", i, list.get(i));
	}

	//add list at
	List<int> list3;
	printf("Size -> %d\nList: \n", list.getSize());

	for (int i = 0; i < list.getSize(); i++) {
		printf("[%d] -> %d\n", i, list.get(i));
	}

	list3.add(-11);
	list3.add(-11);
	list3.add(-13);
	list.addListAtByReference(&list3, 3);

	printf("\nSize -> %d\nList: \n", list.getSize());

	for (int i = 0; i < list.getSize(); i++) {
		printf("[%d] -> %d\n", i, list.get(i));
	}

	list.removeAllByValue(-11);

	printf("\nRemove All:\n");
	for (int i = 0; i < list.getSize(); i++) {
		printf("[%d] -> %d\n", i, list.get(i));
	}

	list.clear();
	printf("\nSize after Clear -> %d\n", list.getSize());*/

	/*List<int> list;
	list.add(0);
	list.add(1);
	list.add(2);
	list.add(2);

	//list.equals = &myEquals;
	List<int> list2 = list.getSublistAsCopy(1, 2);
	printf("Size list2 -> %d\n", list2.getSize());

	list.replaceFirstByValue(2, -5);

	for(int i = 0; i < list.getSize(); i++){
		printf("%d\n", list.get(i));
	}*/