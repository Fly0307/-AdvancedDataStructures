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
    AVLTreeNode<T> *zag(AVLTreeNode<T> *);          //右旋
    AVLTreeNode<T> *zigzag(AVLTreeNode<T> *);       //左旋右旋
    AVLTreeNode<T> *zig(AVLTreeNode<T> *);          //右旋左旋
    AVLTreeNode<T> *zagzig(AVLTreeNode<T> *);       //右旋左旋
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
/*返回节点高度*/
/*********************************************
*参数：当前节点
*返回值：当前节点高度
*功能：返回当前节点高度
**********************************************/
template <typename T>
int AVLTree<T>::GetHeight(AVLTreeNode<T> *tempNode) {
    return NULL==tempNode?-1:tempNode->height;
}
/*********************************************
*参数：待查找元素，当前节点
*返回值：元素所在节点
*功能：返回元素所在节点
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
*参数：当前节点
*返回值：当前子树根节点
*功能：左旋调平衡   逆时针旋转
**********************************************/
