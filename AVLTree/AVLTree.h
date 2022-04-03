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
 * �����Һ�����ȡ������
 * ��AVLƽ�����ǰ�����ȷ���ع�����
 ******************************************************************************************/
#define tallerChild(x) ( \
   stature( (x)->lc ) > stature( (x)->rc ) ? (x)->lc : ( /*���*/ \
   stature( (x)->lc ) < stature( (x)->rc ) ? (x)->rc : ( /*�Ҹ�*/ \
   IsLChild( * (x) ) ? (x)->lc : (x)->rc /*�ȸߣ��븸��xͬ���ߣ�zIg-zIg��zAg-zAg������*/ \
   ) \
   ) \
)
#include "BST.h"
template <typename T>class AVL:public BST<T>{
protected:
    int _size; BinNodePosi<T> _root; //��ģ�����ڵ�
    BinNodePosi<T> _hot; //�����С��ڵ�ĸ���
public:
    BinNodePosi<T> insert ( const T& e ); //���루��д��
    bool remove ( const T& e ); //ɾ������д��
};