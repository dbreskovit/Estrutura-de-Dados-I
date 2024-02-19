
#ifndef LIB_H
#define LIB_H

/* Function takes an array of integers and returns the size of the array.
 *
 * Parameters:
 * - vtr: array of integers
 *
 * Return:
 * - vector size
 */
int len(int *vtr)
{
    int i = 0;
    while (vtr[i])
        i++;
    return i;
}

/* Function takes an array of integers and size and prints the elements of the array.
 *
 * Parameters:
 * - vtr: array of integers
 * - sz: vector size
 *
 * No return.
 */
void vtrPrintf(int *vtr, int sz)
{
    for (int i = 0; i < sz; i++)
        printf("%d ", vtr[i]);
    printf("\n");
}

/* Function takes an matrix of integers and size and prints the elements of the matrix.
 *
 * Parameters:
 * - vtr: matrix of integers
 * - sz: vector size
 *
 * No return.
 */
void mtxPrint(int mtx[][3], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
            printf("%d ", mtx[i][j]);
        printf("\n");
    }
}

/* Function reads an integer from the keyboard and returns the value read.
 *
 * Parameters:
 * - none
 *
 * Return:
 * - integer read from the keyboard
 */

int readInt(void)
{
    int x;
    scanf("%d", &x);
    return x;
}

/* Function reads a float from the keyboard and returns the value read.
 *
 * Parameters:
 * - none
 *
 * Return:
 * - float read from the keyboard
 */
float readFloat(void)
{
    float x;
    scanf("%f", &x);
    return x;
}




#endif