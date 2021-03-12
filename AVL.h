#include "BST.h"
using namespace std;

template<typename comparable>
class AVL : public BST<comparable> {

public:
    /**
     * inserts a node and verifies/fixes
     * AVL property
     * @param value
     * @return
     */
    AVL insert(comparable value) {
        node<comparable>* currentNode = BST<comparable>::insert(value);
       if(!currentNode)
           return *this;

       /**
        *  if the height of the parent
        *  of the new node
        *  has just changed
        */
       if(currentNode != this->root){
           int lastHeight = currentNode->parent->height;
           updateImmediateHeight(currentNode->parent);
           if(lastHeight != currentNode->parent->height)
               checkAVL(currentNode);
       }

       return *this;
   }


    node<comparable>* errorNode;
    /**
     * removes a node and verifies/fixes
     * the AVL property
     * @param value
     * @return
     */
    AVL remove(comparable value){
        node<comparable> *currentNode = BST<comparable>::remove(value);
        checkAVL(currentNode);

        return *this;
    }
    bool testAVL(){
        getHeight(this->root);
        if(AVLpropertyDidNotFail){/*
            cout << "This tree has AVL property" << endl;*/
            AVLpropertyDidNotFail = true;
            return true;
        } else {
            AVLpropertyDidNotFail = true;/*
            cout << "This tree does not have AVL property" << endl;*/
            return false;
        }

    }


private:
    /**
     * variable used to check AVL property
     * only used in testing
     */
    bool AVLpropertyDidNotFail = true;
    int const COUNT = 10;

    /**
     * from the node provided it runs up the tree
     * rotating if necessary to keep the AVL property holding
     * it also updates heights
     * @param currentNode
     */
    void checkAVL(node<comparable>* currentNode){
        while(currentNode){

            updateImmediateHeight(currentNode);

            int leftHeight  = currentNode->left  ? currentNode->left->height + 1 : 0;
            int rightHeight = currentNode->right ? currentNode->right->height + 1 : 0;


            int imbalance = leftHeight - rightHeight;

            if(imbalance > 1 || imbalance < -1){
                performRotations(currentNode, imbalance);
                return;
            }


            currentNode = currentNode->parent;
        }

    }

    /**
     * checks if node needs rotation
     * if it does it rotates in the needed direction
     * @param currentNode
     */
    void performRotations(node<comparable>* currentNode, int imbalance){

        if(imbalance == 2){
            node<comparable> *child  = currentNode->left;

            int leftHeight  = child->left  ? child->left->height + 1 : 0;
            int rightHeight = child->right ? child->right->height + 1 : 0;

            if(leftHeight - rightHeight == -1){
                rotateLeft(child);
                updateImmediateHeight(child);

            }

            rotateRight(currentNode);
            updateImmediateHeight(currentNode);

        }

        if(imbalance == -2){

            node<comparable> *child  = currentNode->right;


            int leftHeight  = child->left  ? child->left->height + 1 : 0;
            int rightHeight = child->right ? child->right->height + 1 : 0;

            if(leftHeight - rightHeight == 1){
                rotateRight(child);
                updateImmediateHeight(child);

            }

            rotateLeft(currentNode);
            updateImmediateHeight(currentNode);
        }
    }

    /**
     * IN THIS CONVENTION THE FUNCTION LIFTS THE CHILD NODE
     * the standard left rotation
     * but it also updates heights
     * @param currentNode
     */
    void rotateLeft (node<comparable>* currentNode){

        node<comparable> *child  = currentNode->right;
        node<comparable> *parent = currentNode->parent;


        child->parent = parent;
        currentNode->right = child->left;
        currentNode->parent = child;
        child->left = currentNode;

        if(currentNode == this->root){
            updateImmediateHeight(currentNode);
            updateImmediateHeight(child);
            this->root = child;
            return;
        } else {
            if(parent->right == currentNode){
                parent->right = child;
            } else {
                parent->left = child;
            }
            updateImmediateHeight(currentNode);
            updateImmediateHeight(child);
        }

    }

    /**
     * IN THIS CONVENTION THE FUNCTION LIFTS THE CHILD NODE
     * the standard right rotation
     * but it also updates heights
     * @param currentNode
     */
    void rotateRight (node<comparable>* currentNode){

        node<comparable> *child  = currentNode->left;
        node<comparable> *parent = currentNode->parent;

        child->parent = parent;
        currentNode->left = child->right;
        currentNode->parent = child;
        child->right = currentNode;

        if(currentNode == this->root){
            this->root = child;
            updateImmediateHeight(currentNode);
            updateImmediateHeight(child);
            return;
        } else {
            if(parent->right == currentNode){
                parent->right = child;
            } else {
                parent->left = child;
            }
            updateImmediateHeight(currentNode);
            updateImmediateHeight(child);

        }

    }

    /**
     * updates the height of the node
     * according to the heights of the lower nodes
     * @param currentNode
     */
    void updateImmediateHeight(node<comparable>* currentNode){
        int leftHeight  = currentNode->left  ? currentNode->left->height + 1 : 0;
        int rightHeight = currentNode->right ? currentNode->right->height + 1 : 0;

        int newHeight = leftHeight > rightHeight ? leftHeight : rightHeight;
        currentNode->height = newHeight;
    }

    /**
    * helper function for testing
    * or just for general checking of height
    *
    */
    int getHeight(node<comparable>* node){

        if(!node){
            return 0;
        }
        int leftHeight  = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        if(leftHeight - rightHeight > 1 || leftHeight - rightHeight < -1){
            AVLpropertyDidNotFail = false;
            errorNode = node;
        }
        int max = leftHeight > rightHeight ? leftHeight : rightHeight;

        return max + 1;
    }

};
