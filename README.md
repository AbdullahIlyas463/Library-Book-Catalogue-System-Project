# Library-Book-Catalogue-System-Project
A robust, template-based Binary Search Tree (BST) implementation in C++ designed to manage a library book catalog efficiently. This project demonstrates advanced object-oriented programming, generic programming using templates, custom memory management, and recursive data structure algorithms.

## Features

- **Generic BST Template (`BST<T>`)**: Fully reusable template class capable of managing any comparable data type.
- **Custom `Book` Entity**: Stores book records with unique IDs, titles, and copy counts, featuring overloaded comparison operators (`<`, `>`, `==`) and stream insertion (`<<`).
- **Dynamic Tree Operations**:
  - **Insertion**: Adds books in sorted order with automatic duplicate prevention.
  - **Deletion**: Removes nodes cleanly, handling all three BST removal cases (zero children, one child, and two children using the minimum successor from the right subtree).
  - **Search**: Fast $O(\log n)$ average-case lookups by book ID.
- **Traversals & Analytics**:
  - **Tree Traversals**: In-order (sorted order), Pre-order, and Post-order displays.
  - **Catalog Metrics**: Track total node count, leaf node count, and tree height/depth.
  - **Balance Validation**: Check whether the BST is height-balanced.
- **Memory Safety**: Implements proper deep copying, copy constructors, copy assignment operators, custom cloning (`clone()`), and a recursive destructor (`clear()`) to prevent memory leaks.
- **Interactive CLI Menu**: Real-time user interface to test all catalog features seamlessly.

SIMPLY: 

Generic BST Template: Implemented as a reusable template class (BST<T>) capable of storing any data type that supports comparison operators.

Custom Book Entity: Manages Book objects with unique ID, title, and copies, utilizing overloaded comparison operators (<, >, ==) and stream insertion (<<).

Comprehensive Operations:

Insertion & Deletion: Insert new books (with duplicate prevention) and remove books using node-removal strategies (handling 0, 1, or 2 children).

Searching & Traversal: Search by ID and traverse the catalog using In-order, Pre-order, and Post-order traversals.

Tree Analytics: Check tree height (depth), total node count, leaf node count, and whether the tree is height-balanced.

Advanced Utilities: Deep copying via copy constructors, assignment operators, cloning functions, and safe memory deallocation using destructors.

Interactive Console Menu: An intuitive user interface to test and interact with all catalog management features in real time.

_**Code Architecture**_

└── Main Application Loop (Interactive CLI Menu)

      └── BST<Book> Catalog
      
           ├── Node Structure (Data + Left/Right Pointers)
           
           └── Book Object (ID, Title, Copies)

**_Interactive Menu Options_**

When you run the program, you can interact with the system using the following options:

LIBRARY BOOK CATALOG

1: Add a Book

2: Remove Book

3: Search Book

4: Display inorder

5: Display preorder

6: Display postorder

7: Catalog Depth

8: Total Books

9: Find Highest/Lowest Id Book

10: Balance Check

11: Count Leaf Nodes

12: Copy Catalog

13: Clear Catalog

0: Exit


