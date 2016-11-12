/* source file: p4t7v1.c */
/* demo program on pointer arithmetic */
/* Output: 2559 */
#include <stdio.h>
int main() {
    char cbuf[10] = "123456789"; 
    char * cptr;
    int  * iptr;
    float * fptr;
    double * dptr;

    cptr = cbuf;
    iptr = (int *)cbuf; //force int pointer points at a char array 
    fptr = (float *)cbuf; //force float pointer points at a char array 
    dptr = (double *)cbuf; //force double pointer points at a char array 

    printf("0x%X\n", cptr);
    printf("0x%X, sizeof(char) = %d bytes\n", cptr + 1, sizeof(char));
    printf("0x%X, sizeof(int) = %d bytes\n", iptr + 1, sizeof(int));
    printf("0x%X, sizeof(float) = %d bytes\n", fptr + 1, sizeof(float));
    printf("0x%X, sizeof(double) = %d bytes\n", dptr + 1, sizeof(double));

    printf("%c \n",*(cptr+1));
    printf("%c \n",*(char *)(iptr+1));
    printf("%c \n",*(char *)(fptr+1));
    printf("%c \n",*(char *)(dptr+1));
}
