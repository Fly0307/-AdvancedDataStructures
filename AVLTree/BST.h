//
// Created by lenovo on 2022/4/3.
//

#ifndef AVLTREE_BST_H
#define AVLTREE_BST_H
#include "BinTree.h"
template <typename T> class BST : public BinTree<T> { //由BinTree派生BST模板类
protected:
    int _size; BinNodePosi<T> _root; //规模、根节点
    BinNodePosi<T> _hot; //“命中”节点的父亲
    BinNodePosi<T> connect34 ( //按照“3 + 4”结构，联接3个节点及四棵子树
            BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>,
            BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T> );
    BinNodePosi<T> rotateAt ( BinNodePosi<T> x ); //对x及其父亲、祖父做统一旋转调整
public: //基本接口：以virtual修饰，强制要求所有派生类（BST变种）根据各自的规则对其重写
    virtual BinNodePosi<T> & search ( const T& e ); //查找
    virtual BinNodePosi<T> insert ( const T& e ); //插入
    virtual bool remove ( const T& e ); //删除
    /*DSA*/
    /*DSA*/void stretchToLPath() { stretchByZag (_root ); } //借助zag旋转，转化为左向单链
    /*DSA*/void stretchToRPath() { stretchByZig (_root ); } //借助zig旋转，转化为右向单链
    ///*DSA*/void stretch();
};
#endif //AVLTREE_BST_H
