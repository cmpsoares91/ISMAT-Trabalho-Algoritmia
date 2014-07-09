/******************************************************/
/* ProxmapSort.c                                      */
/*                                                    */
/* Proxmap sort demonstration.                        */
/* Author: Rick Coleman                               */
/* Date: April 1998                                   */
/******************************************************/
#include <stdio.h>
#include <conio.h>
#include "sort.h"
#include <math.h>

#define ARRAYSIZE    32

/* Prototype sort function */
void ProxmapSort(StructType DataArray[], StructType DataArray2[],int count);
int Hash(int key, int KeyMax, int KeyMin, int count);
void ProxMapInsertionSort(StructType DataArray[], StructType *theStruct, int startIdx, int listLen);

int main(void)
{
    StructType  DataArray[32], DataArray2[32];
    int         count;

    count = ReadRecords(DataArray, 32);
    printf("Unsorted list of records.\n\n");
    PrintList(DataArray, count);

    ProxmapSort(DataArray, DataArray2, count);

    printf("Sorted list of records.\n\n");
    PrintList(DataArray2, count);
    printf("Sorting done...\n");
    getch();
    return(0);
}


/***************************************/
/* ProxmapSort()                       */
/*                                     */
/* Sort records on integer key using   */
/*  a proxmap sort.                    */
/***************************************/
void ProxmapSort(StructType DataArray[], StructType DataArray2[],int count)
{
    int i;
    int HitList[ARRAYSIZE];
    int Hidx;                  /* Hashed index */
    int ProxMap[ARRAYSIZE];
    int RunningTotal;          /* Number of hits */
    int Location[ARRAYSIZE];
    int KeyMax, KeyMin;        /* Used in Hash() */

    /* Initialize hit list and proxmap */
    for(i=0; i<count; i++)
    {
        HitList[i] = 0;           /* Init to all 0 hits */
        ProxMap[i] = -1;          /* Init to all unused */
        DataArray2[i].key = -1;   /* Init to all empty */
    }

    /* Find the largest key for use in computing the hash */
    KeyMax = 0;        /* Guaranteed to be less than the smallest key */
    KeyMin = 32767;    /* Guaranteed to be more than the largest key */
    for(i=0; i<count; i++)
    {
        if(DataArray[i].key > KeyMax) KeyMax = DataArray[i].key;
        if(DataArray[i].key < KeyMin) KeyMin = DataArray[i].key;
    }

    /* Compute the hit count list (note this is not a collision count, but
        a collision count+1 */
    for(i=0; i<count; i++)
    {
        Hidx = Hash(DataArray[i].key, KeyMax, KeyMin, count);    /* Calculate hash index */
        Location[i] = Hidx;                                      /* Save this for later. (Step 1) */
        HitList[Hidx]++;                                         /* Update the hit count (Step 2) */
    }

    /* Create the proxmap from the hit list. (Step 3) */
    RunningTotal = 0;        /* Init counter */
    for(i=0; i<count; i++)
    {
        if(HitList[i] > 0)    /* There were hits at this address */
        {
            ProxMap[i] = RunningTotal;    /* Set start index for this set */
            RunningTotal += HitList[i];
        }
    }

    // NOTE: UNCOMMENT THE FOLLOWING SECTION TO SEE WHAT IS IN THE ARRAYS, BUT
    //       COMMENT IT OUT WHEN DOING A TEST RUN AS PRINTING IS VERY SLOW AND
    //       WILL RESULT IN AN INACCURATE TIME FOR PROXMAP SORT.
/* ----------------------------------------------------
    // Print HitList[] to see what it looks like
    printf("HitList:\n");
    for(i=0; i<count; i++)
        printf("%d ", HitList[i]);
    printf("\n\n");
    getch();

    // Print ProxMap[] to see what it looks like
    printf("ProxMap:\n");
    for(i=0; i<count; i++)
        printf("%d ", ProxMap[i]);
    printf("\n\n");
    getch();

    // Print Location[] to see what it looks like
    printf("Location:\n");
    for(i=0; i<count; i++)
        printf("%d ", Location[i]);
    printf("\n\n");
    getch();
    ----------------------------------------------------  */

    /* Move the keys from A1 to A2 */
    /* Assumes A2 has been initialized to all empty slots (key = -1)*/
    for(i=0; i<count; i++)
    {
        if((DataArray2[ProxMap[Location[i]]].key == -1))  /* If the location in A2 is empty...*/
        {
            /* Move the structure into the sorted array */
            DataArray2[ProxMap[Location[i]]] = DataArray[i];
        }
        else    /* Insert the structure using an insertion sort */
        {
            ProxMapInsertionSort(DataArray2, &DataArray[i], ProxMap[Location[i]], HitList[Location[i]]);
        }
    }

}

/***************************************/
/* Hash()                              */
/*                                     */
/* Calculate a hash index.             */
/***************************************/
int Hash(int key, int KeyMax, int KeyMin, int count)
{
    float    keyFloat;

    /* Map integer key to float in the range 0 <= key < 1 */
    keyFloat = (float)(key - KeyMin) / (float)(1 + KeyMax - KeyMin);

    /* Map float key to indices in range 0 <= index < count */
    return((int)floor(count * keyFloat));
}

/***************************************/
/* ProxMapInsertionSort()              */
/*                                     */
/* Use insertion sort to insert a      */
/*   struct into a subarray.           */
/***************************************/
void ProxMapInsertionSort(StructType DataArray[], StructType *theStruct, 
                          int startIdx, int listLen)
{
    /* Args:    DataArray - Partly sorted array
                *theStruct - Structure to insert
                startIdx - Index of start of subarray
                listLen - Number of items in the subarray */
    int i;

    /* Find the end of the subarray */
    i = startIdx + listLen - 1;
    while(DataArray[i-1].key == -1) i--;
    
    /* Find the location to insert the key */ 
    while((DataArray[i-1].key > theStruct->key) && (i > startIdx))
    {
        DataArray[i] = DataArray[i-1];
        i--;
    }

    /* Insert the key */
    DataArray[i] = *theStruct;
}