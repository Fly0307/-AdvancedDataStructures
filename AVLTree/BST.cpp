//
// Created by lenovo on 2022/4/3.
//

#include "BST.h"

/******************************************************************************************
 * 按照“3 + 4”结构联接3个节点及其四棵子树，返回重组之后的局部子树根节点位置（即b）
 * 子树根节点与上层节点之间的双向联接，均须由上层调用者完成
 * 可用于AVL和RedBlack的局部平衡调整
 ******************************************************************************************/
template <typename T> BinNodePosi<T> BST<T>::connect34 (
        BinNodePosi<T> a, BinNodePosi<T> b, BinNodePosi<T> c,
        BinNodePosi<T> T0, BinNodePosi<T> T1, BinNodePosi<T> T2, BinNodePosi<T> T3
) {
    //*DSA*/print(a); print(b); print(c); printf("\n");
    a->lc = T0; if ( T0 ) T0->parent = a;
    a->rc = T1; if ( T1 ) T1->parent = a; updateHeight ( a );
    c->lc = T2; if ( T2 ) T2->parent = c;
    c->rc = T3; if ( T3 ) T3->parent = c; updateHeight ( c );
    b->lc = a; a->parent = b;
    b->rc = c; c->parent = b; updateHeight ( b );
    return b; //该子树新的根节点
}
/******************************************************************************************
 * BST节点旋转变换统一算法（3节点 + 4子树），返回调整之后局部子树根节点的位置
 * 注意：尽管子树根会正确指向上层节点（如果存在），但反向的联接须由上层函数完成
 ******************************************************************************************/
template <typename T> BinNodePosi<T> BST<T>::rotateAt ( BinNodePosi<T> v ) { //v为非空孙辈节点
    /*DSA*/if ( !v ) { printf ( "\a\nFail to rotate a null node\n" ); exit ( -1 ); }
    BinNodePosi<T> p = v->parent; BinNodePosi<T> g = p->parent; //视v、p和g相对位置分四种情况
    if ( IsLChild ( *p ) ) /* zig */
        if ( IsLChild ( *v ) ) { /* zig-zig */ //*DSA*/printf("\tzIg-zIg: ");
            p->parent = g->parent; //向上联接
            return connect34 ( v, p, g, v->lc, v->rc, p->rc, g->rc );
        } else { /* zig-zag */  //*DSA*/printf("\tzIg-zAg: ");
            v->parent = g->parent; //向上联接
            return connect34 ( p, v, g, p->lc, v->lc, v->rc, g->rc );
        }
    else  /* zag */
    if ( IsRChild ( *v ) ) { /* zag-zag */ //*DSA*/printf("\tzAg-zAg: ");
        p->parent = g->parent; //向上联接
        return connect34 ( g, p, v, g->lc, p->lc, v->lc, v->rc );
    } else { /* zag-zig */  //*DSA*/printf("\tzAg-zIg: ");
        v->parent = g->parent; //向上联接
        return connect34 ( g, v, p, g->lc, v->lc, v->rc, p->rc );
    }
}
//通过zag旋转调整，将BST子树x拉伸成最左侧通路
template <typename T> void stretchByZag ( BinNodePosi<T> & x ) {
    /*DSA*/   int c = 0; //记录旋转次数
    BinNodePosi<T> p = x; while ( p->rc ) p = p->rc; //最大节点，必是子树最终的根
    while ( x->lc ) x = x->lc; //转至初始最左侧通路的末端
    for ( ; x != p; x = x->parent ) { //若x右子树已空，则上升一层
        while ( x->rc ) //否则，反复地
            /*DSA*/{
            x->zag(); //以x为轴做zag旋转
            /*DSA*/c++;
            /*DSA*/}
    } //直到抵达子树的根
    /*DSA*/printf ( "\nsize = %d, height = %d, #zag = %d\n\n", x->size(), x->height, c );
}
//通过zig旋转调整，将BST子树x拉伸成最右侧通路
template <typename T> void stretchByZig ( BinNodePosi<T> & x ) {
    /*DSA*/   int c = 0; //记录旋转次数
    BinNodePosi<T> v = x;
    while ( x->lc ) x = x->lc;
    for ( ; v; v = v->rc ) {
        while ( v->lc )
            /*DSA*/{
            v = v->zig();
            /*DSA*/c++;
            /*DSA*/}
    }
    /*DSA*/printf ( "\nsize = %d, height = %d, #zig = %d\n\n", x->size(), x->height, c );
}
template <typename T> BinNodePosi<T> & BST<T>::search ( const T & e ) { //在BST中查找关键码e
    if ( !_root || e == _root->data ) { _hot = NULL; return _root; } //空树，或恰在树根命中
    for ( _hot = _root; ; ) { //否则，自顶而下
        BinNodePosi<T> & v = ( e < _hot->data ) ? _hot->lc : _hot->rc; //确定方向，深入一层
        if ( !v || e == v->data ) return v; _hot = v; //一旦命中或抵达叶子，随即返回
    } //返回目标节点位置的引用，以便后续插入、删除操作
} //无论命中或失败，_hot均指向v之父亲（v是根时，hot为NULL）

template <typename T> BinNodePosi<T> BST<T>::insert ( const T& e ) { //将关键码e插入BST树中
    BinNodePosi<T> & x = search ( e ); if ( x ) return x; //确认目标不存在（留意对_hot的设置）
    x = new BinNode<T> ( e, _hot ); //创建新节点x：以e为关键码，以_hot为父
    _size++; //更新全树规模
    updateHeightAbove ( x ); //更新x及其历代祖先的高度
    return x; //新插入的节点，必为叶子
} //无论e是否存在于原树中，返回时总有x->data == e


template <typename T> bool BST<T>::remove ( const T& e ) { //从BST树中删除关键码e
    BinNodePosi<T> & x = search ( e ); if ( !x ) return false; //确认目标存在（留意_hot的设置）
    removeAt ( x, _hot ); _size--; //实施删除
    updateHeightAbove ( _hot ); //更新_hot及其历代祖先的高度
    return true;
} //删除成功与否，由返回值指示

