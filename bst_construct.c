#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


struct node* bst_construct(int in[], int post[], int inStart, int inEnd, int *postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    int data = post[*postIndex];
    (*postIndex)--;
    int i;
    for (i = inStart; i <= inEnd; i++) {
        if (in[i] == data) {
            break;
        }
    }

    struct node* root = newNode(data);
    root->right = bst_construct(in, post, i + 1, inEnd, postIndex);
    root->left = bst_construct(in, post, inStart, i - 1, postIndex);

    return root;
}

void inOrder(struct node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(struct node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    int in[] = {5, 10, 15, 20, 25, 30, 45};
    int post[] = {5, 15, 10, 25, 45, 30, 20};
    int inStart = 0, inEnd = sizeof(in) / sizeof(in[0]) - 1;
    int postIndex = sizeof(post) / sizeof(post[0]) - 1;

    struct node* root = bst_construct(in, post, inStart, inEnd, &postIndex);
    
    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");



    return 0;
}