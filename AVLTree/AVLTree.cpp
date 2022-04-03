//
// Created by lenovo on 2022/4/1.
//

#include "AVLTree.h"
template <typename T>
class AVLTree{
private:
    AVLTreeNode<T> *root;
    AVLTreeNode<T> _hot;
    AVLTreeNode<T> *Search(T ,AVLTreeNode<T>*);
    AVLTreeNode<T> *zag(AVLTreeNode<T> *);          //����
    AVLTreeNode<T> *zigzag(AVLTreeNode<T> *);       //��������
    AVLTreeNode<T> *zig(AVLTreeNode<T> *);          //��������
    AVLTreeNode<T> *zagzig(AVLTreeNode<T> *);       //��������
    int GetHeight(AVLTreeNode<T> *);
    AVLTreeNode<T> *Insert(int,AVLTreeNode<T> *);
    AVLTreeNode<T> *Delete(bool&,int,AVLTreeNode<T> *);

public:
    AVLTree();
    void Insert(T);
    bool Search(T);
    bool Delete(T);
    bool Updata(T,T);
    void PreOrderPrint();
    void InOrderPrint();
    void SufOrderPrint();
    void RotatePrint();
};
template <typename T>
AVLTree<T>::AVLTree()
{
    root=NULL;
}
/*���ؽڵ�߶�*/
/*********************************************
*��������ǰ�ڵ�
*����ֵ����ǰ�ڵ�߶�
*���ܣ����ص�ǰ�ڵ�߶�
**********************************************/
template <typename T>
int AVLTree<T>::GetHeight(AVLTreeNode<T> *tempNode) {
    return NULL==tempNode?-1:tempNode->height;
}
/*********************************************
*������������Ԫ�أ���ǰ�ڵ�
*����ֵ��Ԫ�����ڽڵ�
*���ܣ�����Ԫ�����ڽڵ�
**********************************************/
template <typename T>
AVLTreeNode<T> *AVLTree<T>::Search(T tempKey,AVLTreeNode<T>* tempNode) {
    if(NULL==tempNode)
        return NULL;
    else if(tempKey==tempNode->key)
        return tempNode;
    else if(tempKey<tempNode->key)
        return Search(tempKey,tempNode->rightChild);
}
template <typename T>
bool AVLTree<T>::Search(T tempKey) {
    if(Search(tempKey,root)==NULL){
        return false;
    }
    return true;
}
/*********************************************
*��������ǰ�ڵ�
*����ֵ����ǰ�������ڵ�
*���ܣ�������ƽ��   ��ʱ����ת
**********************************************/
