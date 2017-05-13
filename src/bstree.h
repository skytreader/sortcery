typedef struct BTREE {
    int node_count;
    int data;
    struct BTREE* lchild;
    struct BTREE* rchild;
} btree;

void bst_insert(btree *bt, int data);
void bst_remove(btree *bt, int data);
void bst_merge(btree *bt1, btree *bt2);
void bst_search(btree *bt, int data);

void bt_eq(btree *bt1, btree *bt2);
