#include <stdbool.h>
#include <string.h>
#include "bstree.h"
#include "utils.h"

void bst_insert(btree *bt, int data){
}

void bst_remove(btree *bt, int data){
}

void bst_merge(btree *bt1, btree *bt2){
}

void bst_search(btree *bt, int data){
}

/**
Takes in a copy of the structure to traverse (rather than the more common
pointer to a structure) because we don't ever want to modify that structure. On
one hand, assuming I understand C correctly, this is a good idea. On the other
hand, this is wasteful in memory---I should just assert that the btree is
unmodified after this function is called.

@param bt
    The binary tree to traverse. Note the caveats above.
@param inorder
    int array which, after this function is called, will hold the inorder
    traversal of the given binary tree. This is assumed to be allocated enough
    to hold all the nodes in bt.
*/
int* traverse_inorder(btree bt, int inorder[]){
    bool lvisited[bt.node_count];
    memset(lvisited, false, bt.node_count * sizeof(bool));
    bool rvisited[bt.node_count];
    memset(rvisited, false, bt.node_count * sizeof(bool));
    int inorder_idx = 0;
    btree *roamer = &bt;
    stack s;
    init_stack(&s, bt.node_count);

    while(inorder_idx != bt.node_count){
        if(roamer->lchild == NULL){
            // Visit self
            inorder[inorder_idx] = roamer->data;
            inorder_idx++;
            roamer = roamer->rchild;
        } else{
            roamer = roamer->lchild;
        }
    }

    return inorder;
}

void bt_eq(btree *bt1, btree *bt2){
}
