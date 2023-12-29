// mymap.hn
// TODO: it's to write a MyMAP abstraction in a tree through an array with
// hashing implementation through the self balancing rthreaded binary search
// tree
#pragma once

#include <iostream>
#include <sstream>

using namespace std;

template <typename keyType, typename valueType>
class mymap {
 private:
  struct NODE {
    keyType key;      // used to build BST
    valueType value;  // stored data for the map
    NODE* left;       // links to left child
    NODE* right;      // links to right child
    int nL;           // number of nodes in left subtree
    int nR;           // number of nodes in right subtree
    bool isThreaded;
  };
  NODE* root;  // pointer to root node of the BST
  int size;    // # of key/value pairs in the mymap

  void recus_string(NODE* cur, string& pos) {
    // BASE CASE, NODE IS NULL, DO NOTHING
    if (cur != nullptr) {
      // if facing left is not a nullptr
      if (cur->left != nullptr) {
        recus_string(cur->left, pos);
      }
      // Since this is inorder it goes from left to right and to root so it will
      // check the left first
      stringstream key_1;
      string temp = "";
      pos += "key: ";
      key_1 << cur->key;
      key_1 >> temp;
      pos += temp;

      pos += " value: ";
      temp = "";
      stringstream key_2;
      key_2 << cur->value;
      key_2 >> temp;
      pos += temp + "\n";

      if (cur->right != nullptr && !cur->isThreaded) {
        // chnaged cur = (cur->isThreaded) ? nullptr : cur->right; from
        // cur->right
        recus_string(cur = (cur->isThreaded) ? nullptr : cur->right, pos);
      }
    }
  }
  
  // recursive function for deleting the 
  void _deleteTree(NODE* cur) {
    if (cur == nullptr) {
      return;
    } else {
      _deleteTree(cur->left);

      if (cur->isThreaded == false) {
        _deleteTree(cur->right);
      }
      delete cur;
    }
  }
  
  // recursive function for copy from jumpstart
  void _deepCopy(NODE* other) {
    if (other == nullptr)
      return;
    else {
      // put into this tree
      put(other->key, other->value);
      // copy left
      _deepCopy(other->left);
      // copy right
      if (other->isThreaded == false) {
        _deepCopy(other->right);
      }
    }
  }
  
  // recursvie function for the tovector
  void toVector(NODE* cur, vector<pair<keyType, valueType>>& tempVec) {
    if (cur == nullptr) {
      return;
    }

    toVector(cur->left, tempVec);

    // now make the duplicate
    pair<keyType, valueType> duplicate(cur->key, cur->value);
    tempVec.push_back(duplicate);

    if (cur->isThreaded == false) {
      toVector((cur->isThreaded) ? nullptr : cur->right, tempVec);
    }
  }

  // recursive function for the checkbalance
  void checkBalanceRecur(NODE* cur, ostream& ans) {
    if (cur == nullptr) {
      return;
    }

    ans << "key: " << cur->key << ", nL: " << cur->nL << ", nR: " << cur->nR
        << endl;
    checkBalanceRecur(cur->left, ans);
    if (cur->isThreaded) {
      checkBalanceRecur(nullptr, ans);
    } else {
      checkBalanceRecur((cur->isThreaded) ? nullptr : cur->right, ans);
    }
  }

  //
  // iterator:
  // This iterator is used so that mymap will work with a foreach loop.
  //
  struct iterator {
   private:
    NODE* curr;  // points to current in-order node for begin/end

   public:
    iterator(NODE* node) { curr = node; }

    keyType operator*() { return curr->key; }

    bool operator==(const iterator& rhs) {
      if (curr == nullptr && rhs.curr == nullptr) {
        return this == &rhs;
      }
      return curr == rhs.curr;
    }

    bool operator!=(const iterator& rhs) {
      if (curr == nullptr && rhs.curr == nullptr) {
        return this == &rhs;
      }
      return curr != rhs.curr;
    }

    bool isDefault() { return !curr; }

    //
    // operator++:
    //
    // This function should advance curr to the next in-order node.
    // O(logN)
    //
    iterator operator++() {
      // to check if it's in the right place to lead the next direction
      if (!curr->isThreaded) {
        curr = curr->right;
        while (curr != nullptr) {
          curr = curr->left;
        }
      } else if (curr->isThreaded) {
        curr = curr->right;
      }

      return iterator(curr);
    }
  };

 public:
  //
  // default constructor:
  //
  // Creates an empty mymap.
  // Time complexity: O(1)
  //
  mymap() {
    // TODO: write this function.
    root = nullptr;
    size = 0;
  }

  //
  // copy constructor:
  //
  // Constructs a new mymap which is a copy of the "other" mymap.
  // Sets all member variables appropriately.
  // Time complexity: O(n), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  mymap(const mymap& other) {
    this->root = nullptr;
    this->size = 0;
    _deepCopy(other.root);

    // TODO: write this function.
  }

  //
  // operator=:
  //
  // Clears "this" mymap and then makes a copy of the "other" mymap.
  // Sets all member variables appropriately.
  // Time complexity: O(n), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  mymap& operator=(const mymap& other) {
    if (&other == this) {
      return *this;
    }
    // if the input is before then we clear the input and put the new input
    this->clear();
    NODE* overall = other.root;
    // function from Prof Hummel week 10
    // what kind of tree traversal shluld be used for copy
    _deepCopy(overall);
    return *this;  // TODO: Update this return.
  }

  // clear:
  //
  // Frees the memory associated with the mymap; can be used for testing.
  // Time complexity: O(n), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  void clear() {
    // if you delete node, can you access its subtress
    _deleteTree(this->root);
    root = nullptr;
    size = 0;
  }

  //
  // destructor:
  //
  // Frees the memory associated with the mymap.
  // Time complexity: O(n), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  ~mymap() { this->clear(); }

  //
  // put:
  //
  // Inserts the key/value into the threaded, self-balancing BST based on
  // the key.
  // Time complexity: O(logn + mlogm), where n is total number of nodes in the
  // threaded, self-balancing BST and m is the number of nodes in the
  // sub-tree that needs to be re-balanced.
  // Space complexity: O(1)
  //
  void put(keyType key, valueType value) {
    // inserting a new node into the Binary Search Tree

    // Prov reckinger's slide
    // create a new node, initialize values
    NODE* prev = nullptr;
    NODE* cur = root;

    // 1. search for key, return if found
    while (cur != nullptr) {
      if (key == cur->key) {
        cur->nL = 0;
        cur->nR = 0;
        cur->value = value;
        return;
      }
      if (key < cur->key) {
        prev = cur;
        cur = cur->left;
      } else {
        prev = cur;
        //           cur = cur->right;
        cur = (cur->isThreaded) ? nullptr : cur->right;
      }
    }

    // 2. if not found, insert where we fell out of the tree:

    NODE* n = new NODE();
    n->key = key;        // used to build BST
    n->value = value;    // stored data for the map
    n->left = nullptr;   // links to left child
    n->right = nullptr;  // links to right child
    n->nL = 0;           // number of nodes in left subtree
    n->nR = 0;           // number of nodes in right subtree
    n->isThreaded = false;

    // compare the keys between the current and new nodes
    if (prev == nullptr) {
      root = n;
    } else if (key < prev->key) {
      prev->left = n;
      n->right = prev;
      n->isThreaded = true;
    } else if (key > prev->key) {
      n->right = prev->right;
      prev->right = n;
      n->isThreaded = true;
      prev->isThreaded = false;
    }
    // increase the size of the linked list
    // when you have hit a leaf, link the tree to the new node
    size++;
  }

  //
  // contains:
  // Returns true if the key is in mymap, return false if not.
  // Time complexity: O(logn), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  bool contains(keyType key) {
    // TODO: write this function.
    NODE* cur = root;
    while (cur != nullptr) {
      if (key == cur->key) {
        return true;
      } else if (key > cur->key) {
        //                                                      cur =
        // cur->right;
        cur = (cur->isThreaded) ? nullptr : cur->right;
      } else if (key < cur->key) {
        cur = cur->left;
      }
    }
    return false;  // TODO: Update this return.
  }

  //
  // get:
  //
  // Returns the value for the given key; if the key is not found, the
  // default value, valueType(), is returned (but not added to mymap).
  // Time complexity: O(logn), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  valueType get(keyType key) {
    NODE* cur = root;
    while (cur != nullptr) {
      if (key == cur->key) {
        return cur->value;
      } else if (key > cur->key) {
        //                                                      cur =
        // cur->right;
        cur = (cur->isThreaded) ? nullptr : cur->right;
      } else if (key < cur->key) {
        cur = cur->left;
      }
    }

    return valueType();
  }

  //
  // operator[]:
  //
  // Returns the value for the given key; if the key is not found,
  // the default value, valueType(), is returned (and the resulting new
  // key/value pair is inserted into the map).
  // Time complexity: O(logn + mlogm), where n is total number of nodes in the
  // threaded, self-balancing BST and m is the number of nodes in the
  // sub-trees that need to be re-balanced.
  // Space complexity: O(1)
  //
  valueType operator[](keyType key) {
    NODE* cur = root;
    while (cur != nullptr) {
      if (key == cur->key) {
        return cur->value;
      } else if (key < cur->key) {
        cur = cur->left;
      } else if (key > cur->key) {
        //               cur = cur->right;
        cur = (cur->isThreaded) ? nullptr : cur->right;
      }
    }
    this->put(key, valueType());
    return valueType();
  }

  //
  // Size:
  //
  // Returns the # of key/value pairs in the mymap, 0 if empty.
  // O(1)
  //
  int Size() {
    // TODO: Update this return
    return this->size;
  }

  //
  // begin:
  //
  // returns an iterator to the first in order NODE.
  // Time complexity: O(logn), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  iterator begin() {
    NODE* cur = root;

    if (cur != nullptr) {
      while (cur->left != nullptr) {
        cur = cur->left;
      }
    } else if (cur == root) {
      return iterator(root);
    } else if (cur == nullptr) {
      return iterator(cur);
    }

    return iterator(cur);  // TODO: Update this return.
  }

  //
  // end:
  //
  // returns an iterator to the last in order NODE.
  // this function is given to you.
  //
  // Time Complexity: O(1)
  //
  // provided project
  iterator end() { return iterator(nullptr); }

  //
  // toString:
  //
  // Returns a string of the entire mymap, in order.
  // Format for 8/80, 15/150, 20/200:
  // "key: 8 value: 80\nkey: 15 value: 150\nkey: 20 value: 200\n
  // Time complexity: O(n), where n is total number of nodes in the
  // threaded, self-balancing BST
  //

  string toString() {
    NODE* cur = root;
    // use stringstreams to build the string recursively
    string pos = "";
    recus_string(cur, pos);
    // has to be recursion
    // RETURN THE STRING OF THE ENTIRE MAP IN ORDER
    return pos;  // TODO: Update this return.
  }

  //
  // toVector:
  //
  // Returns a vector of the entire map, in order.  For 8/80, 15/150, 20/200:
  // {{8, 80}, {15, 150}, {20, 200}}
  // Time complexity: O(n), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  vector<pair<keyType, valueType>> toVector() {
    // toVector() function just like to string, returns vecotr>pair<K,V>>
    // once done, copy-paste the function, change to return vector<NODE*>
    vector<pair<keyType, valueType>> tempVec;
    NODE* cur = root;
    toVector(cur, tempVec);
    return tempVec;  // TODO: Update this return.
  }

  //
  // checkBalance:
  //
  // Returns a string of mymap that verifies that the tree is properly
  // balanced.  For example, if keys: 1, 2, 3 are inserted in that order,
  // function should return a string in this format (in pre-order):
  // "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
  // Time complexity: O(n), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  string checkBalance() {
    // TODO: write this function.
    stringstream ans;
    // call it recursively
    NODE* cur = root;
    checkBalanceRecur(cur, ans);
    return ans.str();  // TODO: Update this return.
  }
};