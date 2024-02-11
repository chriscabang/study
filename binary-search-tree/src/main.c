#include <stdio.h>
#include <stdlib.h>

struct node_t {
  int value;
  struct node_t* left;
  struct node_t* right;
};

struct node_t* create_node(int value) {
  struct node_t* node = (struct node_t*) malloc(sizeof(struct node_t));
  node->value = value;
  node->left = 0;
  node->right = 0;

  return node;
}

struct node_t* insert_node(struct node_t* root, int value) {
  if (root == 0) {
    return create_node(value);
  }

  if (value < root->value) {
    root->left = insert_node(root->left, value);
  } else if(value > root->value) {
    root->right = insert_node(root->right, value);
  }

  return root;
}

int search(struct node_t* root, int value) {
  if (root == 0) {
    return 0;
  }

  if (root->value == value) {
    return 1;
  }

  if (value < root->value) {
    return search(root->left, value);
  } else {
    return search(root->right, value);
  }
}

void printTreeUtil(struct node_t* root, int space) {
    if (root == NULL) {
        return;
    }

    int increment = 6;

    printTreeUtil(root->right, space + increment);

    for (int i = increment; i < space; i++) {
        printf(" ");
    }

    if (root->right) {
        printf(" /");
    }

    printf("___%d\n", root->value);

    for (int i = increment; i < space; i++) {
        printf(" ");
    }

    if (root->left) {
        printf(" \\");
    }

    printf("\n");

    printTreeUtil(root->left, space + increment);
}

void printTree(struct node_t* root) {
    printTreeUtil(root, 0);
}

void print_in_order(struct node_t* root) {
  if (root != 0) {
    print_in_order(root->left);
    printf("%d ", root->value);
    print_in_order(root->right);
  }
}

void delete_tree(struct node_t* root) {
  if (root != 0) {
    delete_tree(root->left);
    delete_tree(root->right);
    
    free(root);
  }
}

int main() {
  struct node_t* root = 0;

  root = insert_node(root, 4);
  root = insert_node(root, 2);
  root = insert_node(root, 1);
  root = insert_node(root, 3);
  root = insert_node(root, 6);
  root = insert_node(root, 5);
  root = insert_node(root, 7);

  //printf("In order traversal for binary search tree: ");
  //print_in_order(root);
  printTree(root);

  int _value = 3;
  printf("\n%d ", _value);
  printf(search(root, _value) ? " found!\n" : "not found!\n");

  delete_tree(root);

  return 0;
}