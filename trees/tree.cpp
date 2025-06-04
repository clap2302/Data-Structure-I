    #include <cstdlib>
    #include <iostream>

    struct node
    {
        int info;
        struct node *left, *right;
    };

    class Tree
    {

    public:
        node *root;

        Tree();
        node *insert(node *&root, int n);
        void order(node *root);
        int search(node *root, int n);
        int countNodes(node *root);
        int countLeaf(node *root);
        bool isFullBinaryTree(node *root);
        bool fixNonFullBinaryTree(node *root);
    };

    Tree::Tree()
    {
        this->root = nullptr;
    }

    node *Tree::insert(node *&root, int n)
    {
        /* Creating the first root */
        if (root == nullptr)
        {
            root = new node();

            if (root == nullptr)
                exit(1);

            root->info = n;
            root->left = nullptr;
            root->right = nullptr;
            
            return root;
        }

        if (n > root->info)
            root->right = this->insert(root->right, n);

        else if (n < root->info)
            root->left = this->insert(root->left, n);

        else
            std::cout << "The number 'n' already exists in the Tree";

        return root;
    }

    void Tree::order(node *root)
    {
        if (root == nullptr) return;

        this->order(root->left);
        std::cout << root->info << std::endl;
        this->order(root->right);
    }

    int Tree::search(node *root, int n)
    {
        if (root == nullptr)
            return -1;
        
    if (root->info == n)
            return root->info;

        if (root->info > n)
            return search(root->left, n);

        else
            return search(root->right, n);
    }

    int Tree::countNodes(node *root)
    {
        if (root == nullptr)
            return 0;

        return (1 + countNodes(root->left) + countNodes(root->right));   
    }

    int Tree::countLeaf(node *root)
    {
        if (root == nullptr)
            return 0;

        if (root->left == nullptr && root->right == nullptr)
            return 1;

        return (countLeaf(root->left) + countLeaf(root->right));
    }

    bool Tree::isFullBinaryTree(node *root)
    {
        if (root == nullptr)
            return true;

        if (root->left == nullptr && root->right == nullptr)
            return true;

        if (root->left != nullptr && root->right == nullptr ||
            root->left == nullptr && root->right != nullptr)
            return false;

        return (this->isFullBinaryTree(root->left) && this->isFullBinaryTree(root->right));
    }

    bool Tree::fixNonFullBinaryTree(node *root)
    {
        if (root == nullptr)
            return true;

        if (root->left == nullptr && root->right == nullptr)
            return true;

        if (root->left != nullptr && root->right == nullptr ||
            root->left == nullptr && root->right != nullptr)
            
            if (root->left == nullptr)
                this->insert(root, root->info - 1);
            else
                this->insert(root, root->info + 1);

        return (this->fixNonFullBinaryTree(root->left) && this->fixNonFullBinaryTree(root->right));
    }

    int main()
    {
        Tree tree = Tree();

        tree.insert(tree.root, 8);
        tree.insert(tree.root, 2);
        tree.insert(tree.root, 9);
        tree.insert(tree.root, 10);
        
        tree.order(tree.root);

        std::cout << "Tree Size: " << (tree.countNodes(tree.root)) << std::endl;
        std::cout << "Amount of leaves: " << (tree.countLeaf(tree.root)) << std::endl;
        std::cout << "Is Tree Full Binary: " << (tree.isFullBinaryTree(tree.root)) << std::endl;
        std::cout << "Fixed Tree as Full Binary: " << (tree.fixNonFullBinaryTree(tree.root)) << std::endl;
    }
