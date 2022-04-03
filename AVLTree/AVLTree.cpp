
//
// Created by lenovo on 2022/4/1.
//

#include "AVLTree.h"
template <typename T>
BinNodePosi<T> AVL<T>::insert (const  T& e ) { //���ؼ���e����AVL����
    BinNodePosi<T> & x = search ( e ); if ( x ) return x; //ȷ��Ŀ��ڵ㲻����
    BinNodePosi<T> xx = x = new BinNode<T> ( e, _hot ); _size++; //�����½ڵ�x
// ��ʱ��x�ĸ���_hot�����ߣ������游�п���ʧ��
    for ( BinNodePosi<T> g = _hot; g; g = g->parent ) //��x֮���������ϣ�������������g
        if ( !AvlBalanced ( *g ) ) { //һ������gʧ�⣬�򣨲��á�3 + 4���㷨��ʹ֮���⣬��������
            FromParentTo ( *g ) = rotateAt ( tallerChild ( tallerChild ( g ) ) ); //���½���ԭ��
            break; //�ֲ���������󣬸߶ȱ�Ȼ��ԭ�������������ˣ��ʵ�������
        } else //����g��ƽ�⣩
            updateHeight ( g ); //ֻ�������߶ȣ�ע�⣺����gδʧ�⣬�߶���������ӣ�
    return xx; //�����½ڵ�λ��
} //����e�Ƿ������ԭ���У�����AVL::insert(e)->data == e

template <typename T> bool AVL<T>::remove ( const T& e ) { //��AVL����ɾ���ؼ���e
    BinNodePosi<T> & x = search ( e ); if ( !x ) return false; //ȷ��Ŀ����ڣ�����_hot�����ã�
    removeAt ( x, _hot ); _size--; //�Ȱ�BST����ɾ��֮���˺�ԭ�ڵ�֮��_hot�������Ⱦ�����ʧ�⣩
    for ( BinNodePosi<T> g = _hot; g; g = g->parent ) { //��_hot�������ϣ�������������g
        if ( !AvlBalanced ( *g ) ) //һ������gʧ�⣬�򣨲��á�3 + 4���㷨��ʹ֮���⣬��������������
            g = FromParentTo ( *g ) = rotateAt ( tallerChild ( tallerChild ( g ) ) ); //ԭ����
        updateHeight ( g ); //���¸߶ȣ�ע�⣺����gδʧ����ѻָ�ƽ�⣬�߶Ⱦ����ܽ��ͣ�
    } //��������Omega(logn)�ε������������Ƿ�����������ȫ���߶Ⱦ����ܽ���
    return true; //ɾ���ɹ�
}
/*template <typename T>
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
*/
/*���ؽڵ�߶�*//*

*/
/*********************************************
*��������ǰ�ڵ�
*����ֵ����ǰ�ڵ�߶�
*���ܣ����ص�ǰ�ڵ�߶�
**********************************************//*

template <typename T>
int AVLTree<T>::GetHeight(AVLTreeNode<T> *tempNode) {
    return NULL==tempNode?-1:tempNode->height;
}
*/
/*********************************************
*������������Ԫ�أ���ǰ�ڵ�
*����ֵ��Ԫ�����ڽڵ�
*���ܣ�����Ԫ�����ڽڵ�
**********************************************//*

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
*/
/*********************************************
*��������ǰ�ڵ�
*����ֵ����ǰ�������ڵ�
*���ܣ�������ƽ��   ��ʱ����ת
**********************************************/

