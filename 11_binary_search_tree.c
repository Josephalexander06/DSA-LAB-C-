#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Find inorder successor (smallest in right subtree)
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// DELETE FUNCTION
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);

    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data; // copy successor's value
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1.Insert 2.Search 3.Display 4.Delete 5.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d\n", value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL)
                    printf("%d found\n", value);
                else
                    printf("%d not found\n", value);
                break;

            case 3:
                printf("BST (inorder): ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Deleted %d (if existed)\n", value);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}


// Output: Binary Search Tree Implementation in C
// This code implements a simple binary search tree (BST) in C.
// It allows insertion of values, searching for values, and displaying the BST in inorder traversal.

// Example usage:

// 1.Insert 2.Search 3.Display 4.Exit
// Choice: 1
// Enter value: 50
// Inserted 50

// 1.Insert 2.Search 3.Display 4.Exit
// Choice: 1
// Enter value: 30
// Inserted 30

// 1.Insert 2.Search 3.Display 4.Exit
// Choice: 1
// Enter value: 70
// Inserted 70

// 1.Insert 2.Search 3.Display 4.Exit
// Choice: 1
// Enter value: 20
// Inserted 20

// 1.Insert 2.Search 3.Display 4.Exit
// Choice: 3
// BST (inorder): 20 30 50 70

// 1.Insert 2.Search 3.Display 4.Exit
// Choice: 2
// Enter value to search: 30
// 30 found

// 1.Insert 2.Search 3.Display 4.Exit
// Choice: 2
// Enter value to search: 25
// 25 not found

// 1.Insert 2.Search 3.Display 4.Exit
// Choice: 4