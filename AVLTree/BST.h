//
// Created by lenovo on 2022/4/3.
//

#ifndef AVLTREE_BST_H
#define AVLTREE_BST_H
#include "BinTree.h"
template <typename T> class BST : public BinTree<T> { //��BinTree����BSTģ����
protected:
    int _size; BinNodePosi<T> _root; //��ģ�����ڵ�
    BinNodePosi<T> _hot; //�����С��ڵ�ĸ���
    BinNodePosi<T> connect34 ( //���ա�3 + 4���ṹ������3���ڵ㼰�Ŀ�����
            BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>,
            BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T> );
    BinNodePosi<T> rotateAt ( BinNodePosi<T> x ); //��x���丸�ס��游��ͳһ��ת����
public: //�����ӿڣ���virtual���Σ�ǿ��Ҫ�����������ࣨBST���֣����ݸ��ԵĹ��������д
    virtual BinNodePosi<T> & search ( const T& e ); //����
    virtual BinNodePosi<T> insert ( const T& e ); //����
    virtual bool remove ( const T& e ); //ɾ��
    /*DSA*/
    /*DSA*/void stretchToLPath() { stretchByZag (_root ); } //����zag��ת��ת��Ϊ������
    /*DSA*/void stretchToRPath() { stretchByZig (_root ); } //����zig��ת��ת��Ϊ������
    ///*DSA*/void stretch();
};
#endif //AVLTREE_BST_H
