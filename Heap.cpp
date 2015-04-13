//--------------------------------------------------------------------
//
//  Laboratory 11                                            Heap.cpp
//
//
//--------------------------------------------------------------------

#ifndef HEAP_CPP
#define HEAP_CPP

#include "Heap.h"

//#include <new>

using namespace std;

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>:: Heap ( int maxNumber )

// Creates an empty heap. Allocates enough memory for maxNumber
// data items.

  : maxSize(maxNumber),
    size(0)
{
    dataItems = new DataType [ maxSize ];
}

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>:: Heap ( const Heap& other )

// Copy constructor

  : maxSize(other.maxSize),
    size(other.size)
{
    dataItems = new DataType [ maxSize ];
    for( int i=0; i<size; i++ ) {
	  dataItems[i] = other.dataItems[i];
    }
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>& Heap<DataType,KeyType,Comparator>:: operator= ( const Heap& other )

{
    if( this == &other ) { return *this; }	// Self-assignment

    if( other.maxSize > maxSize ) {
	delete[] dataItems;
	dataItems = new DataType [other.maxSize];
    }
    maxSize = other.maxNumber;
    size = other.size;
    for( int i=0; i<size; i++ ) {
	dataItems[i] = other.dataItems[i];
    }

    return *this;
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>:: ~Heap ()

// Frees the memory used by a heap.

{
    delete [] dataItems;
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType,KeyType,Comparator>:: insert ( const DataType &newDataItem ) throw ( logic_error )

// Inserts newDataItem into a heap. This data item is initially
// inserted as the bottom rightmost data item in the heap. It is then
// moved upward until a valid heap is produced.

{
    int parentj,   // Array indices that move together up the heap
        j;

    // Requires that heap is not full
    if ( size >= maxSize )
        throw logic_error ("heap is full");

	// YOUR CODE GOES HERE
    // Hint: you may want to use the 2 variables declared above (but you don't have to)
	// Hint: call getPriority() to get the priority of a data item (e.g. newDataItem.getPriority())

    else(size<maxSize && size>=0){
        DataType parent;
        DataType temp;
        dataItems[size]=newDataItem;
        parent = dataItems[(size-1)/2];

        for(int i = size; size>=0; size --){
            if(newDataItem.getPriority() > parent.getPriority()){
                temp=dataItems[size];
                dataItems[size]=parent;
                parent = temp;
                dataItems[(size-1)/2]=parent;
            }
        }
    }






}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
DataType Heap<DataType,KeyType,Comparator>:: remove () throw ( logic_error )

// Removes the data item with the highest priority (the root) from a
// heap and returns it. This data item is replaced with the bottom
// rightmost data item, which is moved downward until a valid heap is
// produced.

{
    DataType oldMax,    // Data item removed (old root)
             insertDataItem;  // Data item to insert as root (bottom right)
    bool stop;          // (Re)insertion point found
    int j;              // Array index that moves down the heap

    // Requires that heap is not empty
    if ( size == 0 )
        throw logic_error("heap is empty");

	// YOUR CODE GOES HERE
	// Hint: you may want to use some of the variables declared above (but you don't have to)
	// Hint: call getPriority() to get the priority of a data item (e.g. insertDataItem.getPriority())












}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType,KeyType,Comparator>:: clear ()

// Removes all the data items from a heap.

{
    size = 0;
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType,KeyType,Comparator>:: isEmpty () const

// Returns true if a heap is empty. Otherwise, returns false.

{
    return ( size == 0 );
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType,KeyType,Comparator>:: isFull () const

// Returns true if a heap is full. Otherwise, returns false.

{
    return ( size == maxSize );
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType,KeyType,Comparator>:: showStructure () const

// Outputs the priorities of the data items in a heap in both array
// and tree form. If the heap is empty, outputs "Empty heap". This
// operation is intended for testing/debugging purposes only.

{
    int j;   // Loop counter

    cout << endl;
    if ( size == 0 )
       cout << "Empty heap" << endl;
    else
    {
       cout << "size = " << size << endl;       // Output array form
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       for ( j = 0 ; j < size ; j++ )
           cout << dataItems[j].getPriority() << "\t";
       cout << endl << endl;
       showSubtree(0,0);                        // Output tree form
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType,KeyType,Comparator>:: showSubtree ( int index, int level ) const

// Helper function for the showStructure() function. Outputs the
// subtree (subheap) whose root is stored in dataItems[index]. Argument
// level is the level of this dataItems within the tree.

{
     int j;   // Loop counter

     if ( index < size )
     {
        showSubtree(2*index+2,level+1);        // Output right subtree
        for ( j = 0 ; j < level ; j++ )        // Tab over to level
            cout << "\t";
        cout << " " << dataItems[index].getPriority();   // Output dataItems's priority
        if ( 2*index+2 < size )                // Output "connector"
           cout << "<";
        else if ( 2*index+1 < size )
           cout << "\\";
        cout << endl;
        showSubtree(2*index+1,level+1);        // Output left subtree
    }
}



#endif	// #ifndef HEAP_CPP

