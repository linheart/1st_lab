#include "../include/tree.h"

int height(TNode *node) { return node ? node->height : 0; }

int bFactor(TNode *node) { return height(node->right) - height(node->left); }

void fixHeight(TNode *node) {
  int hl = height(node->left);
  int hr = height(node->right);

  node->height = (hl > hr ? hl : hr) + 1;
}

TNode *rotateRight(TNode *node) {
  TNode *tmp = node->left;
  node->left = tmp->right;
  tmp->right = node;
  fixHeight(node);
  fixHeight(tmp);

  return tmp;
}

TNode *rotateLeft(TNode *node) {
  TNode *tmp = node->right;
  node->right = tmp->left;
  tmp->left = node;
  fixHeight(node);
  fixHeight(tmp);

  return tmp;
}

TNode *balance(TNode *node) {
  fixHeight(node);
  if (bFactor(node) == 2) {
    if (bFactor(node->right) < 0) {
      node->right = rotateRight(node->right);
    }
    return rotateLeft(node);
  }

  if (bFactor(node) == -2) {
    if (bFactor(node->left) > 0) {
      node->left = rotateLeft(node->left);
    }
    return rotateRight(node);
  }

  return node;
}

TNode *insert(TNode *node, const string value) {
  if (!node) {
    return new TNode{value, 1, nullptr, nullptr};
  }

  if (value < node->key) {
    node->left = insert(node->left, value);
  } else {
    node->right = insert(node->right, value);
  }

  return balance(node);
}

TNode *findValue(TNode *node, const string value) {
  if (!node || node->key == value) {
    return node;
  }

  if (value < node->key) {
    return findValue(node->left, value);
  }

  return findValue(node->right, value);
}

TNode *removeValue(TNode *node, const string value) {
  if (!node) {
    return nullptr;
  }

  if (value < node->key) {
    node->left = removeValue(node->left, value);
  } else if (value > node->key) {
    node->right = removeValue(node->right, value);
  } else {
    TNode *left = node->left;
    TNode *right = node->right;

    delete node;

    if (!right) {
      return left;
    }

    TNode *min = findMin(right);
    min->right = removeMin(right);
    min->left = left;

    return balance(min);
  }

  return balance(node);
}

TNode *findMin(TNode *node) { return node->left ? findMin(node->left) : node; }

TNode *removeMin(TNode *node) {
  if (!node->left) {
    return node->right;
  }

  node->left = removeMin(node->left);
  return balance(node);
}

void printTree(TNode *node) {
  if (node) {
    printTree(node->left);
    cout << node->key << " ";
    printTree(node->right);
  }
}

void freeTree(TNode *node) {
  if (!node) {
    return;
  }

  freeTree(node->left);
  freeTree(node->right);
  delete node;
}
