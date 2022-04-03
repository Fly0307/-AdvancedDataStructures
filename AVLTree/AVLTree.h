/*
//
// Created by lenovo on 2022/4/1.
//
#include "iostream"
using namespace  std;
#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H
template<typename T>
struct AVLTreeNode
{
    int key;
    T   val;
    int height;
    AVLTreeNode *leftChild;
    AVLTreeNode *rightChild;
    AVLTreeNode(int tempKey,T value=NULL)
    {
        height=0;
        key=tempKey;
        val=value;
        leftChild=NULL;
        rightChild=NULL;
    }
};

#endif //AVLTREE_AVLTREE_H
*/
/******************************************************************************************
 * 在左、右孩子中取更高者
 * 在AVL平衡调整前，借此确定重构方案
 ******************************************************************************************/
#define tallerChild(x) ( \
   stature( (x)->lc ) > stature( (x)->rc ) ? (x)->lc : ( /*左高*/ \
   stature( (x)->lc ) < stature( (x)->rc ) ? (x)->rc : ( /*右高*/ \
   IsLChild( * (x) ) ? (x)->lc : (x)->rc /*等高：与父亲x同侧者（zIg-zIg或zAg-zAg）优先*/ \
   ) \
   ) \
)
#include "BST.h"
template <typename T>class AVL:public BST<T>{
protected:
    int _size; BinNodePosi<T> _root; //规模、根节点
    BinNodePosi<T> _hot; //“命中”节点的父亲
public:
    BinNodePosi<T> insert ( const T& e ); //插入（重写）
    bool remove ( const T& e ); //删除（重写）
};