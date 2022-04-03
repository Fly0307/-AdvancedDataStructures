//
// Created by lenovo on 2022/4/3.
//

#include "BinNode.h"

using namespace std;


template <typename T> int BinNode<T>::size() { //ͳ�Ƶ�ǰ�ڵ���������������Ϊ����������ģ
    int s = 1; //���뱾��
    if ( lc ) s += lc->size(); //�ݹ������������ģ
    if ( rc ) s += rc->size(); //�ݹ������������ģ
    return s;
}
//��e��Ϊ��ǰ�ڵ�����Ӳ��������
template <typename T> BinNodePosi<T> BinNode<T>::insertAsLC(const T &e) {
    return  lc=new BinNode(e,this);
}
//��e��Ϊ��ǰ�ڵ���Һ��Ӳ��������
template <typename T> BinNodePosi<T> BinNode<T>::insertAsRC(const T &e) {
    return  rc=new BinNode(e,this);
}
template <typename T> template <typename VST> //Ԫ�����͡�������
void BinNode<T>::travLevel ( VST& visit ) { //��������α����㷨
    std::queue<BinNodePosi<T>> Q; //��������
    Q.enqueue ( this ); //���ڵ����
    while ( !Q.empty() ) { //�ڶ����ٴα��֮ǰ����������
        BinNodePosi<T> x = Q.dequeue(); visit ( x->data ); //ȡ�����׽ڵ㲢����֮
        if ( HasLChild ( *x ) ) Q.enqueue ( x->lc ); //�������
        if ( HasRChild ( *x ) ) Q.enqueue ( x->rc ); //�Һ������
    }
}

template <typename T> template <typename VST> //Ԫ�����͡�������
void BinNode<T>::travPre ( VST& visit ) { //��������������㷨ͳһ���
    travPre_R ( this, visit );
}
template <typename T, typename VST> //Ԫ�����͡�������
void travPre_R ( BinNodePosi<T> x, VST& visit ) { //��������������㷨���ݹ�棩
    if ( !x ) return;
    visit ( x->data );
    travPre_R ( x->lc, visit );
    travPre_R ( x->rc, visit );
}
template <typename T> template <typename VST> //Ԫ�����͡�������
void BinNode<T>::travIn ( VST& visit ) { //��������������㷨ͳһ���
    travIn_R ( this, visit );
}
template <typename T, typename VST> //Ԫ�����͡�������
void travIn_R ( BinNodePosi<T> x, VST& visit ) { //��������������㷨���ݹ�棩
    if ( !x ) return;
    travIn_R ( x->lc, visit );
    visit ( x->data );
    travIn_R ( x->rc, visit );
}

template <typename T> template <typename VST> //Ԫ�����͡�������
void BinNode<T>::travPost ( VST& visit ) { //��������������㷨ͳһ���
    travIn_R ( this, visit );
}
template <typename T, typename VST> //Ԫ�����͡�������
void travPost_R ( BinNodePosi<T> x, VST& visit ) { //��������������㷨���ݹ�棩
    if ( !x ) return;
    travPost_R ( x->lc, visit );
    travPost_R ( x->rc, visit );
    visit ( x->data );
}

/*����*/
template <typename T> BinNodePosi<T> BinNode<T>::zig() { //˳ʱ����ת
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
/*����*/
template <typename T> BinNodePosi<T> BinNode<T>::zag(){//��ʱ����ת
    BinNodePosi<T> rChild=rc;
    rChild->parent=this->parent;
    if(rChild->parent)
        ( ( this == rChild->parent->lc ) ? rChild->parent->lc : rChild->parent->rc ) = rChild;//�жϽ�P���븸�ڵ������������������
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