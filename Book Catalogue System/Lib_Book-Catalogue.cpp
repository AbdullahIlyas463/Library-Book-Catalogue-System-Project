#include<iostream>
#include<string>
#include<limits>
using namespace std;

class Book
{
public:

	string title;
	int id;
	int copies;

	Book(int i = 0, string t = "", int copy = 0)
	{
		title = t;
		id = i;
		copies = copy;
	}


	bool operator <(const Book& obj) const
	{
		return id < obj.id;
	}
	bool operator >(const Book& obj) const
	{
		return id > obj.id;
	}
	bool operator ==(const Book& obj) const
	{
		return id == obj.id;
	}
};

ostream& operator <<(ostream & out, const Book & obj)
{
	out << "Id: " << obj.id << " | Title: " << obj.title << " | Copies: " << obj.copies;
	return out;
}


template<typename T>
class BST
{
	class Node
	{
	public:

		T data;
		Node* left, * right;

		Node(T val)
		{
			data = val;
			left = nullptr;
			right = nullptr;
		}
	};

	Node* root;


	void clear(Node* d)
	{
		if (d == nullptr) return;

		clear(d->left);
		clear(d->right);

		delete d;
	}

	Node* insert(Node* node, T& d, bool& ins)
	{
		if (node == nullptr)
		{
			ins = true;
			return new Node(d);
		}

		if (d < node->data)
			node->left = insert(node->left, d, ins);
		else if (d > node->data)
			node->right = insert(node->right, d, ins);
		else ins = false;               // duplicate

		return node;
	}

	void inorder(Node* d)
	{
		if (d == nullptr) return;
		inorder(d->left);
		cout << d->data << endl;
		inorder(d->right);
	}
	void preorder(Node* d)
	{
		if (d == nullptr) return;

		cout << d->data << endl;
		preorder(d->left);
		preorder(d->right);
	}
	void postorder(Node* d)
	{
		if (d == nullptr) return;
		postorder(d->left);
		postorder(d->right);
		cout << d->data << endl;
	}

	int countNodes(Node* d)
	{
		if (d == nullptr) return 0;

		return 1 + countNodes(d->left) + countNodes(d->right);
	}

	Node* findMin(Node* d)
	{
		if (d == nullptr || d->left == nullptr) return d;
		return findMin(d->left);
	}
	Node* findMax(Node* d)
	{
		if (d == nullptr || d->right == nullptr) return d;
		return findMax(d->right);
	}

	int countLeafNodes(Node* d)
	{
		if (d == nullptr) return 0;
		if (d->left == nullptr && d->right == nullptr) return 1;

		return countLeafNodes(d->left) + countLeafNodes(d->right);
	}

	Node* copyHelper(Node* node)
	{
		if (node == nullptr) return nullptr;
		Node* n = new Node(node->data);
		n->left = copyHelper(node->left);
		n->right = copyHelper(node->right);
		return n;
	}

	T* searchHelper(Node* node, const T& data)
	{
		if (node == nullptr) return nullptr;
		if (data == node->data) return &node->data;
		if (data < node->data) return searchHelper(node->left, data);
		return searchHelper(node->right, data);
	}

	int height(Node* node)
	{
		if (node == nullptr) return 0;
		int l = height(node->left);
		int r = height(node->right);
		return 1 + (l > r ? l : r);
	}

	bool isBalanced(Node* node, int& h)
	{
		if (node == nullptr)
		{
			h = 0;
			return true;
		}
		int lh = 0, rh = 0;
		bool lOk = isBalanced(node->left, lh);
		bool rOk = isBalanced(node->right, rh);

		h = 1 + (lh > rh ? lh : rh);

		int diff = lh - rh;
		return lOk && rOk && diff >= -1 && diff <= 1;
	}

	Node* remove(Node* node, const T& d, bool& removed)
	{
		if (node == nullptr)
		{
			removed = false;
			return nullptr;
		}

		if (d < node->data)
			node->left = remove(node->left, d, removed);
		else if (d > node->data)
			node->right = remove(node->right, d, removed);
		else
		{
			removed = true;


			if (node->left == nullptr && node->right == nullptr)
			{
				delete node;
				return nullptr;
			}

			if (node->left == nullptr)
			{
				Node* child = node->right;
				delete node;
				return child;
			}
			if (node->right == nullptr)
			{
				Node* child = node->left;
				delete node;
				return child;
			}

			Node* succ = findMin(node->right);
			node->data = succ->data;
			bool dummy = false;
			node->right = remove(node->right, succ->data, dummy);
		}
		return node;
	}

public:

	BST()
	{
		root = nullptr;
	}
	~BST()
	{
		clear();
	}

	BST(const BST& obj)
	{
		root = copyHelper(obj.root);
	}

	BST& operator=(const BST& obj)
	{
		if (this != &obj)
		{
			clear();
			root = copyHelper(obj.root);
		}
		return *this;
	}

	bool insert(T data)
	{
		bool inserted = false;

		root = insert(root, data, inserted);

		return inserted;
	}

	T* search(const T& data)
	{
		return searchHelper(root, data);
	}

	bool remove(const T& data)
	{
		bool removed = false;
		root = remove(root, data, removed);
		return removed;
	}

	void inorder()
	{
		inorder(root);
	}
	void preorder()
	{
		preorder(root);
	}
	void postorder()
	{
		postorder(root);
	}

	int countNodes()
	{
		return countNodes(root);
	}

	T* findMin()
	{
		Node* n = findMin(root);
		if (!n) return nullptr;
		return &n->data;
	}
	T* findMax()
	{
		Node* n = findMax(root);
		if (!n) return nullptr;
		return &n->data;
	}

	int countLeafNodes()
	{
		return countLeafNodes(root);
	}

	BST clone()
	{
		BST copy;
		copy.root = copyHelper(root);
		return copy;
	}

	int height()
	{
		return height(root);
	}

	bool isBalanced()
	{
		int h = 0;
		return isBalanced(root, h);
	}

	void clear()
	{
		clear(root);
		root = nullptr;
	}

	bool isEmpty()
	{
		return root == nullptr;
	}
};

int menu()
{

	cout << "\nLIBRARY BOOK CATALOG\n";
	cout << "1: Add a Book\n2: Remove Book\n3: Search Book\n4: Display inorder\n5: Display preorder\n6: Display postorder\n7: Catalog Depth\n8: Total Books\n9: Find Highest/Lowest Id Book\n10: Balance Check\n11: Count Leaf Nodes\n12: Copy Catalog\n13: Clear Catalog\n0: Exit\n";

	int c;
	cout << "Enter your choice: ";
	cin >> c;
	while (c < 0 || c>13)
	{
		cout << "Invalid Choice\n";
		cout << "Enter your choice: ";
		cin >> c;

	}
	return c;
}

void AddingBook(int& i, string & ttl, int& cpy)
{
	cout << "ADDING A BOOK\n";
	cout << "Enter id: ";
	cin >> i;
	cin.ignore();
	cout << "Enter Title: ";
	getline(cin, ttl);
	cout << "Enter number of Copies: ";
	cin >> cpy;
}

int main()
{

	BST<Book> catalog;

	while (true)
	{
		int choice = menu();

		switch (choice)
		{
		case 1:
		{
			int ID = 0;
			int COPIES = 0;
			string TITLE = "";
			AddingBook(ID, TITLE, COPIES);
			if (COPIES < 0)
				cout << "Copies cannot be negative. Record rejected.\n";
			else if (catalog.insert(Book(ID, TITLE, COPIES)))
				cout << "Book Added Successfully!\n";
			else
				cout << "Book ID already exists. Record rejected.\n";
			break;
		}

		case 2:
		{
			int id;
			cout << "Enter id: ";
			cin >> id;
			if (catalog.remove(Book(id)))
				cout << "Book removed successfully.\n";
			else
				cout << "Book with ID " << id << " was not found.\n";
			break;
		}

		case 3:
		{
			int id;
			cout << "Enter id: ";
			cin >> id;
			Book* found = catalog.search(Book(id));
			if (found)
				cout << "Book found: " << *found << endl;
			else
				cout << "Book with ID " << id << " was not found.\n";
			break;
		}

		case 4:
			if (catalog.isEmpty()) cout << "The catalog is empty.\n";
			else catalog.inorder();
			break;

		case 5:
			if (catalog.isEmpty()) cout << "The catalog is empty.\n";
			else catalog.preorder();
			break;

		case 6:
			if (catalog.isEmpty()) cout << "The catalog is empty.\n";
			else catalog.postorder();
			break;

		case 7:
			cout << "Catalog depth: " << catalog.height() << endl;
			break;

		case 8:
			cout << "Total books: " << catalog.countNodes() << endl;
			break;

		case 9:
			if (catalog.isEmpty())
				cout << "The catalog is empty.\n";
			else
			{
				cout << "Highest: " << *catalog.findMax() << endl;
				cout << "Lowest : " << *catalog.findMin() << endl;
			}
			break;

		case 10:
			if (catalog.isBalanced())
				cout << "The catalog is height-balanced.\n";
			else
				cout << "The catalog is NOT height-balanced.\n";
			break;

		case 11:
			cout << "Number of leaf books: " << catalog.countLeafNodes() << endl;
			break;

		case 12:
		{
			if (catalog.isEmpty())
				cout << "The catalog is empty. Nothing to copy.\n";
			else
			{
				BST<Book> copy = catalog.clone();
				cout << "Copy created. Contents of the copy (inorder):\n";
				copy.inorder();
			}
			break;
		}

		case 13:
			catalog.clear();
			cout << "All book records deleted.\n";
			break;

		case 0:
			cout << "Goodbye!\n";
			return 0;       // catalog's destructor frees everything
		}
	}

	return 0;
}