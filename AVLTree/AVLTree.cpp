
//
// Created by lenovo on 2022/4/1.
//

#include "AVLTree.h"
template <typename T>
BinNodePosi<T> AVL<T>::insert (const  T& e ) { //将关键码e插入AVL树中
    BinNodePosi<T> & x = search ( e ); if ( x ) return x; //确认目标节点不存在
    BinNodePosi<T> xx = x = new BinNode<T> ( e, _hot ); _size++; //创建新节点x
// 此时，x的父亲_hot若增高，则其祖父有可能失衡
    for ( BinNodePosi<T> g = _hot; g; g = g->parent ) //从x之父出发向上，逐层检查各代祖先g
        if ( !AvlBalanced ( *g ) ) { //一旦发现g失衡，则（采用“3 + 4”算法）使之复衡，并将子树
            FromParentTo ( *g ) = rotateAt ( tallerChild ( tallerChild ( g ) ) ); //重新接入原树
            break; //局部子树复衡后，高度必然复原；其祖先亦必如此，故调整结束
        } else //否则（g仍平衡）
            updateHeight ( g ); //只需更新其高度（注意：即便g未失衡，高度亦可能增加）
    return xx; //返回新节点位置
} //无论e是否存在于原树中，总有AVL::insert(e)->data == e

template <typename T> bool AVL<T>::remove ( const T& e ) { //从AVL树中删除关键码e
    BinNodePosi<T> & x = search ( e ); if ( !x ) return false; //确认目标存在（留意_hot的设置）
    removeAt ( x, _hot ); _size--; //先按BST规则删除之（此后，原节点之父_hot及其祖先均可能失衡）
    for ( BinNodePosi<T> g = _hot; g; g = g->parent ) { //从_hot出发向上，逐层检查各代祖先g
        if ( !AvlBalanced ( *g ) ) //一旦发现g失衡，则（采用“3 + 4”算法）使之复衡，并将该子树联至
            g = FromParentTo ( *g ) = rotateAt ( tallerChild ( tallerChild ( g ) ) ); //原父亲
        updateHeight ( g ); //更新高度（注意：即便g未失衡或已恢复平衡，高度均可能降低）
    } //可能需做Omega(logn)次调整——无论是否做过调整，全树高度均可能降低
    return true; //删除成功
}
/*template <typename T>
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
*/
/*返回节点高度*//*

*/
/*********************************************
*参数：当前节点
*返回值：当前节点高度
*功能：返回当前节点高度
**********************************************//*

template <typename T>
int AVLTree<T>::GetHeight(AVLTreeNode<T> *tempNode) {
    return NULL==tempNode?-1:tempNode->height;
}
*/
/*********************************************
*参数：待查找元素，当前节点
*返回值：元素所在节点
*功能：返回元素所在节点
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
*参数：当前节点
*返回值：当前子树根节点
*功能：左旋调平衡   逆时针旋转
**********************************************/

