#include <iostream>
#include <string>
#include <time.h>
#include "AVL.h"
#include <vector>
#include <set>

vector<int> vct;
set<int> sett;
using namespace std;
AVL<int> randomTree(int numberNodes){
    AVL<int> tree = AVL<int>();

    while(numberNodes){

        int insert = rand() % numberNodes;
        tree.insert(insert);
        sett.insert(insert);
        vct.push_back(insert);
        numberNodes--;
    }
    return tree;
}

void testLots(int times, int numberNodes){
    for(int i = 0; i < times; i++){
        AVL<int> tree = randomTree(numberNodes);
        bool testOK = tree.testAVL();
        if(!testOK){
            cout << "set: " << endl;
            for(auto i : sett)
                cout << i << " ,";

            cout << "vector: " << endl;
            for(int i : vct)
                cout << i << " ,";

            cout << endl;
            cout << "there was an error on AVL property" << endl;
            tree.print();
            return;
        } else {
            cout << "AVL property OK" << endl;
        }
    }
    cout << "AVL property OK" << endl;
}

int main() {

    srand( (unsigned)time(NULL) );
    AVL<int> tree = AVL<int>();
    testLots(100, 20);
    //vector<int> vect{ 25,27,24,21,1,4,11,20,15,7,14,17,8,12,3,2,9,6,0,5,13,10,18,19,26,23,14,13,22,16};
    //vector<int> vect{ 25,27,24,21,1,4,11,20,15,7,14,17,8,12,3,2,9,6,0,5,13,10,18,19,26,23,14,13,22,16};
    //vector<int> vect{ 25,27,24,21,1,4,11,20,15,7,14,17,8,12,3,2,9,6,0,5,13,10,18,19,26,23,14,13,22,16};
    //vector<int> vect{ 25,27,24,21,1,4,11,20,15,7,14,17,8,12,3,2,9,6,0,5,13,10,18,19,26,23,14,13,22,16};
    //vector<int> vect{ 10 ,16 ,0 ,11 ,6 ,10 ,5 ,8 ,7 ,4 ,1 ,2 ,3 ,1 ,0 ,1 ,1 ,0 };//creates error
    //vector<int> vect{ 10,16,0,11,6,5,8,7,4,1,2,3};



    //vector<int> vect2{ 10,16,0,11,6,5,8,7,4,1};

    /**
     * IMPORTANT : the error is in the update of the heights @todo
     * !!child has same height as parent!!
     */
/*    for(int i : vect){

        tree.insert(i);

    }*/
/*    tree.print();
    cout << "---------------------------------------------" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "---------------------------------------------" << endl;
    AVL<int> tree2 = AVL<int>();
    for(int i : vect2)
        tree2.insert(i);
    tree2.print();
       bool testOK = tree.testAVL();
       if(testOK){
           tree.print();
           cout << "AVL property OK" << endl;
       } else {
           tree.print();
           cout << "there was an error on AVL property" << endl;
       }*/
   /*  tree.insert(7);
        tree.insert(6);
        tree.insert(5);
        tree.insert(4);
        tree.insert(45);
        tree.insert(49);

       tree.insert(50);
        tree.insert(51);
        tree.insert(60);
        tree.insert(70);
        tree.insert(9);
        tree.insert(11);*/
    //for(int i = 2; i< 10 ; i++)
        //tree.insert(i);
/*    tree.print();
    if(tree.testBST()){
        cout << "proper BST" << endl;
    } else {
        cout << "BST error" << endl;
    }
    cout << "BST max" << tree.findMax() << endl;
    cout << "BST min" << tree.findMin() << endl;

    bool test = tree.testAVL();

    if(!test)
    {
        for(int i : vct)
            cout << i << " ,";
    }
    cout << endl;*/
    return 0;
}
