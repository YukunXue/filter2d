#include <stdio.h>

#define I_W 6
#define I_H 6

void main(){

    int A[6][6]={{0x23,0x25,0x27,0x85,0x86,0x87},
               {0x33,0x35,0x35,0x95,0x95,0x98},
               {0x44,0x45,0x44,0xA5,0xA6,0xA7},
               {0xD5,0xD6,0xD7,0x68,0x69,0x7A},
               {0xFD,0xFF,0xFE,0x42,0x43,0x43},
               {0xEA,0xEB,0xEC,0x55,0x56,0x56},};
    
    int B[3][3]={{1,2,1},{0,0,0},{-1,-2,-1}};

    int C[4][4]={0};

    int *img_in;

    // OR img_in = A;
    img_in = &A[0][0];
    printf("The address is %d \n",&A);

    int i = 0;
    int j = 0;
    int ki= 0;
    int kj= 0;

    for( i =0; i<I_W-2; i++ ){
            for( j=0; j<I_H-2;j++){
                for( ki=0; ki<3; ki++){
                    for( kj=0; kj<3;kj++){
                        C[i][j] += *(img_in + i*I_H +j+ki*I_H + kj ) * B[ki][kj];
                    }
                }
                printf(" %d ",C[i][j]);
            }
            printf("\n");
    }    
}


