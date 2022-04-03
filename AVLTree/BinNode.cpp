//
// Created by lenovo on 2022/4/3.
//

#include "BinNode.h"

using namespace std;


template <typename T> int BinNode<T>::size() { //统计当前节点后代总数，即以其为根的子树规模
    int s = 1; //计入本身
    if ( lc ) s += lc->size(); //递归计入左子树规模
    if ( rc ) s += rc->size(); //递归计入右子树规模
    return s;
}
//将e作为当前节点的左孩子插入二叉树
template <typename T> BinNodePosi<T> BinNode<T>::insertAsLC(const T &e) {
    return  lc=new BinNode(e,this);
}
//将e作为当前节点的右孩子插入二叉树
template <typename T> BinNodePosi<T> BinNode<T>::insertAsRC(const T &e) {
    return  rc=new BinNode(e,this);
}
template <typename T> template <typename VST> //元素类型、操作器
void BinNode<T>::travLevel ( VST& visit ) { //二叉树层次遍历算法
    std::queue<BinNodePosi<T>> Q; //辅助队列
    Q.enqueue ( this ); //根节点入队
    while ( !Q.empty() ) { //在队列再次变空之前，反复迭代
        BinNodePosi<T> x = Q.dequeue(); visit ( x->data ); //取出队首节点并访问之
        if ( HasLChild ( *x ) ) Q.enqueue ( x->lc ); //左孩子入队
        if ( HasRChild ( *x ) ) Q.enqueue ( x->rc ); //右孩子入队
    }
}

template <typename T> template <typename VST> //元素类型、操作器
void BinNode<T>::travPre ( VST& visit ) { //二叉树先序遍历算法统一入口
    travPre_R ( this, visit );
}
template <typename T, typename VST> //元素类型、操作器
void travPre_R ( BinNodePosi<T> x, VST& visit ) { //二叉树先序遍历算法（递归版）
    if ( !x ) return;
    visit ( x->data );
    travPre_R ( x->lc, visit );
    travPre_R ( x->rc, visit );
}
template <typename T> template <typename VST> //元素类型、操作器
void BinNode<T>::travIn ( VST& visit ) { //二叉树中序遍历算法统一入口
    travIn_R ( this, visit );
}
template <typename T, typename VST> //元素类型、操作器
void travIn_R ( BinNodePosi<T> x, VST& visit ) { //二叉树中序遍历算法（递归版）
    if ( !x ) return;
    travIn_R ( x->lc, visit );
    visit ( x->data );
    travIn_R ( x->rc, visit );
}

template <typename T> template <typename VST> //元素类型、操作器
void BinNode<T>::travPost ( VST& visit ) { //二叉树中序遍历算法统一入口
    travIn_R ( this, visit );
}
template <typename T, typename VST> //元素类型、操作器
void travPost_R ( BinNodePosi<T> x, VST& visit ) { //二叉树后序遍历算法（递归版）
    if ( !x ) return;
    travPost_R ( x->lc, visit );
    travPost_R ( x->rc, visit );
    visit ( x->data );
}

/*右旋*/
template <typename T> BinNodePosi<T> BinNode<T>::zig() { //顺时针旋转
    BinNodePosi<T> lChild = lc;
    lChild->parent = this->parent;
    if ( lChild->parent )
        ( ( this == lChild->parent->rc ) ? lChild->parent->rc : lChild->parent->lc ) = lChild;
    lc = lChild->rc; if ( lc ) lc->parent = this;
    lChild->rc = this; this->parent = lChild;
// update heights ()
    height = 1 + max ( stature ( lc ), stature ( rc ) );
    lChild->height = 1 + max ( stature ( lChild->lc ), stature ( lChild->rc ) );
    for ( BinNodePosi<T> x = lChild->parent; x; x = x->parent )
        if ( HeightUpdated( *x ) )
            break;
        else
            x->height = 1 + max ( stature ( x->lc ), stature ( x->rc ) );
    return lChild;
}
/*左旋*/
template <typename T> BinNodePosi<T> BinNode<T>::zag(){//逆时针旋转
    BinNodePosi<T> rChild=rc;
    rChild->parent=this->parent;
    if(rChild->parent)
        ( ( this == rChild->parent->lc ) ? rChild->parent->lc : rChild->parent->rc ) = rChild;//判断将P接入父节点的左子树还是右子树
    rc = rChild->lc; if ( rc ) rc->parent = this;
    rChild->lc=this;
    this->parent=rChild;

    height=1+max(stature(lc), stature(rc));
    rChild->height=1+max(stature(rChild->lc),stature(rChild->rc));
    for(BinNode<T>x=rChild->parent;x;x=x.parent)
        if((HeightUpdated(*x)))
            break;
        else
            x.height=1+max(stature(x->lc),stature(x->rc));
    return rChild;
}