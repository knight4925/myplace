#include <stdio.h>
#include <iostream>

using namespace std;

//int array[] = {1, 3, 5, 7, 2, 4, 6, 8};
int array[] = {3,5,7,8,1,2,4,6};
void display(int array[], int n)
{
     for (int i = 0; i < n; ++i)
     {
         printf("%d ", array[i]);
     }
     printf("\n");
}

/**
* 算法: 交换二对象
**/
template<typename T>
void t_swap( T& v1, T& v2 )
{
    T t = v1; v1 = v2; v2 = t;
}

/**
* 算法: 反转序列
**/
template<typename T>
void t_reverse( T* v, size_t size )
{
    size_t s = 0, e = size-1;
    while( s < e && s < size && e > 0 )
        t_swap( v[s++], v[e--] );
}

/**
* 算法: 手摇算法,从指定位置旋转序列(见编程珠玑第二章)
**/
template<typename T>
void t_exchange( T* v, size_t size, size_t n )
{
    t_reverse( v, n );
    t_reverse( v + n, size - n );
    t_reverse( v, size );
}

/**
* 算法: 合并二已排序的连续序列
**/
template<typename T>
void t_merge( T& v, size_t size, size_t pos )
{
    size_t fir = 0, sec = pos;
    while ( fir < sec && sec < size )
    {
        while ( fir < sec && v[fir] <= v[sec] ) fir++;
        size_t maxMove = 0;
        while ( sec < size && v[fir] > v[sec] ) maxMove++, sec++;
        t_exchange( &v[fir], sec - fir, sec - fir - maxMove );
        fir += maxMove;

        display(array, sizeof(array)/sizeof(int));
    }
}

/**
* 算法: 归并排序
**/
template<typename T>
void t_merge_sort( T* v, size_t size )
{
    if ( size <= 1 ) return;
    t_merge_sort( v, size/2 );
    t_merge_sort( v + size/2, size - size/2 );
    t_merge( v, size, size/2 );
}

int main()
{
     display(array, sizeof(array)/sizeof(int));

     t_merge(array, sizeof(array) / sizeof(int), (sizeof(array)/sizeof(int))/2);
     //t_merge_sort(array, sizeof(array) / sizeof(int));

     display(array, sizeof(array)/sizeof(int));
     return 0;
}