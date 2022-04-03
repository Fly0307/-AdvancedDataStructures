//
// Created by lenovo on 2022/4/3.
//

#include "BST.h"

/******************************************************************************************
 * ���ա�3 + 4���ṹ����3���ڵ㼰���Ŀ���������������֮��ľֲ��������ڵ�λ�ã���b��
 * �������ڵ����ϲ�ڵ�֮���˫�����ӣ��������ϲ���������
 * ������AVL��RedBlack�ľֲ�ƽ�����
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
    return b; //�������µĸ��ڵ�
}
/******************************************************************************************
 * BST�ڵ���ת�任ͳһ�㷨��3�ڵ� + 4�����������ص���֮��ֲ��������ڵ��λ��
 * ע�⣺��������������ȷָ���ϲ�ڵ㣨������ڣ�������������������ϲ㺯�����
 ******************************************************************************************/
template <typename T> BinNodePosi<T> BST<T>::rotateAt ( BinNodePosi<T> v ) { //vΪ�ǿ��ﱲ�ڵ�
    /*DSA*/if ( !v ) { printf ( "\a\nFail to rotate a null node\n" ); exit ( -1 ); }
    BinNodePosi<T> p = v->parent; BinNodePosi<T> g = p->parent; //��v��p��g���λ�÷��������
    if ( IsLChild ( *p ) ) /* zig */
        if ( IsLChild ( *v ) ) { /* zig-zig */ //*DSA*/printf("\tzIg-zIg: ");
            p->parent = g->parent; //��������
            return connect34 ( v, p, g, v->lc, v->rc, p->rc, g->rc );
        } else { /* zig-zag */  //*DSA*/printf("\tzIg-zAg: ");
            v->parent = g->parent; //��������
            return connect34 ( p, v, g, p->lc, v->lc, v->rc, g->rc );
        }
    else  /* zag */
    if ( IsRChild ( *v ) ) { /* zag-zag */ //*DSA*/printf("\tzAg-zAg: ");
        p->parent = g->parent; //��������
        return connect34 ( g, p, v, g->lc, p->lc, v->lc, v->rc );
    } else { /* zag-zig */  //*DSA*/printf("\tzAg-zIg: ");
        v->parent = g->parent; //��������
        return connect34 ( g, v, p, g->lc, v->lc, v->rc, p->rc );
    }
}
//ͨ��zag��ת��������BST����x����������ͨ·
template <typename T> void stretchByZag ( BinNodePosi<T> & x ) {
    /*DSA*/   int c = 0; //��¼��ת����
    BinNodePosi<T> p = x; while ( p->rc ) p = p->rc; //���ڵ㣬�����������յĸ�
    while ( x->lc ) x = x->lc; //ת����ʼ�����ͨ·��ĩ��
    for ( ; x != p; x = x->parent ) { //��x�������ѿգ�������һ��
        while ( x->rc ) //���򣬷�����
            /*DSA*/{
            x->zag(); //��xΪ����zag��ת
            /*DSA*/c++;
            /*DSA*/}
    } //ֱ���ִ������ĸ�
    /*DSA*/printf ( "\nsize = %d, height = %d, #zag = %d\n\n", x->size(), x->height, c );
}
//ͨ��zig��ת��������BST����x��������Ҳ�ͨ·
template <typename T> void stretchByZig ( BinNodePosi<T> & x ) {
    /*DSA*/   int c = 0; //��¼��ת����
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
template <typename T> BinNodePosi<T> & BST<T>::search ( const T & e ) { //��BST�в��ҹؼ���e
    if ( !_root || e == _root->data ) { _hot = NULL; return _root; } //��������ǡ����������
    for ( _hot = _root; ; ) { //�����Զ�����
        BinNodePosi<T> & v = ( e < _hot->data ) ? _hot->lc : _hot->rc; //ȷ����������һ��
        if ( !v || e == v->data ) return v; _hot = v; //һ�����л�ִ�Ҷ�ӣ��漴����
    } //����Ŀ��ڵ�λ�õ����ã��Ա�������롢ɾ������
} //�������л�ʧ�ܣ�_hot��ָ��v֮���ף�v�Ǹ�ʱ��hotΪNULL��

template <typename T> BinNodePosi<T> BST<T>::insert ( const T& e ) { //���ؼ���e����BST����
    BinNodePosi<T> & x = search ( e ); if ( x ) return x; //ȷ��Ŀ�겻���ڣ������_hot�����ã�
    x = new BinNode<T> ( e, _hot ); //�����½ڵ�x����eΪ�ؼ��룬��_hotΪ��
    _size++; //����ȫ����ģ
    updateHeightAbove ( x ); //����x�����������ȵĸ߶�
    return x; //�²���Ľڵ㣬��ΪҶ��
} //����e�Ƿ������ԭ���У�����ʱ����x->data == e


template <typename T> bool BST<T>::remove ( const T& e ) { //��BST����ɾ���ؼ���e
    BinNodePosi<T> & x = search ( e ); if ( !x ) return false; //ȷ��Ŀ����ڣ�����_hot�����ã�
    removeAt ( x, _hot ); _size--; //ʵʩɾ��
    updateHeightAbove ( _hot ); //����_hot�����������ȵĸ߶�
    return true;
} //ɾ���ɹ�����ɷ���ֵָʾ

