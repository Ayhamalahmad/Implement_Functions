#include <iostream>
using namespace std;
class Array {
private:
	int size;
	int length;
	int* items;
public:
	Array(int arrSize) {
		size = arrSize;
		length = 0;
		items = new int[arrSize];
	}
	void fill() {
		int numOfItems;
		cout << "How many items you want to fill ? \n";
		cin >> numOfItems;
		if (numOfItems > size) {
			cout << " you can not exceed the array size \n";
		}
		else
		{
			for (int i = 0; i < numOfItems; i++) {
				cout << "Enter item on " << i << "\n";
				cin >> items[i];
				length++;
			}

		}
	}
	void display() {
		cout << "display array items \n";
		cout << "[ ";
		for (int i = 0; i < length; i++) {
			cout << items[i];
			if (i != length - 1) {
				cout << ", ";
			}
		}
		cout << " ]";
		cout << "\n";
	}
	int getSize() {
		return size;
	}
	int getLength() {
		return length;
	}
	int search(int key) {
		int index = -1;
		for (int i = 0; i < length; i++) {
			if (key == items[i]) {
				index = i;
				break;
			}
		}
		if (index == -1) {
			cout << "item not found \n";
		}
		else
		{
			cout << "item found  at position " << index << "\n";
		}
		return index;
	}
	void append(int newItem) {

		if (length < size) {

			items[length] = newItem;
			length++;
		}
		else {
			cout << "Size of thArray is full \n";
		}
	}
	void insert(int index, int item) {
		if (index >= 0 && index < size) {
			for (int i = length; i > index; i--) {
				items[i] = items[i - 1];
			}
			items[index] = item;
			length++;
		}
		else
		{
			cout << "Error Index out of range \n";
		}
	}
	void deleteItem(int index) {
		if (index >= 0 && index < size) {
			for (int i = index; i < length - 1; i++) {
				items[i] = items[i + 1];
				length--;
			}
		}
		else
		{
			cout << "Error Index out of range \n";
		}
	};
	void enlarge(int newSize) {
		if (newSize <= size) {
			cout << "New size must be larger than current size \n";
			return;
		}
		else
		{
			size = newSize;
			int* temp = items;
			items = new int[newSize];
			for (int i = 0; i < length; i++) {
				items[i] = temp[i];
			}
			delete[]temp;

		}
	}
	void marge(Array other) {
		int newsize = size + other.getSize();
		size = newsize;
		int* oldArray = items;
		items = new int[newsize];
		int i;
		for (i = 0; i < length; i++) {
			items[i] = oldArray[i];
		}
		delete[] oldArray;
		int j = i;
		for (; j < other.getLength(); i++) {
			items[j++] = other.items[i];
			length++;
		}

	}
};
void run() {
	cout << "this is Array demo \n";
	// Size
	int arraySize;
	cout << "Enter the size of the array : ";
	cin >> arraySize;
	Array newArray(arraySize);
	newArray.fill();
	newArray.display();
	// Search
	/*int key;
	cout << "Enter the key to search it : ";
	cin >> key;
	newArray.search(key);*/
	// Append
	/*int itemToAppend;
	cout << "Enter the item to append it : ";
	cin >> itemToAppend;
	newArray.append(itemToAppend);
	newArray.display();*/

	// Insert
	/*int toInsert;
	cout << "Enter the item to insert it : ";
	cin >> toInsert;
	int itemIndex;
	cout << "Enter the index (0 to " << arraySize << ") to insert the item " << toInsert << ": ";
	cin >> itemIndex;
	newArray.insert(itemIndex, toInsert);
	newArray.display();*/

	// Delete 
	//int toDeleteItem;
	//cout << "Enter  index to delete its  item : ";
	//cin >> toDeleteItem;
	//newArray.deleteItem(toDeleteItem);
	//newArray.display();

	//  Enlarge 
	//int newSizeArray;
	//cout << "Enter new size \n";
	//cin >> newSizeArray;
	//newArray.enlarge(newSizeArray);
	//cout << "array size is : " << newArray.getSize() << " array length is : " << newArray.getLength() << endl;
	//newArray.display();

	Array other(3);
	other.fill();
	newArray.marge(other);
	cout << "array size is : " << newArray.getSize() << " array length is : " << newArray.getLength() << endl;
	newArray.display();

}
int main() {
	run();
	//system("pause");
	return 0;
}
