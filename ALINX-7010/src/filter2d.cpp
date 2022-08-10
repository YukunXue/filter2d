#include <iostream>
using namespace std;
#include <math.h>
#include "filter2d.h"




void filter2d_accel(int *img_in,int *kernel,int *img_out,int rows,int cols)
{
#pragma HLS INTERFACE m_axi port=img_in offset=slave depth=128*128
#pragma HLS INTERFACE m_axi port=kernel offset=slave depth=3*3
#pragma HLS INTERFACE m_axi port=img_out offset=slave depth=126*126
#pragma HLS INTERFACE s_axilite port=rows  bundle=CTRL
#pragma HLS INTERFACE s_axilite port=cols  bundle=CTRL
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL
	int out_rows=rows-2;
	int out_cols=cols-2;
	 int in=0;
	int filter=0;

	int temp=0;
	 for (int i = 0; i < rows-2; i++)
	 {
#pragma HLS PIPELINE II=1
		 for (int j=0; j < cols-2; j++)
		 {
			 for (int ki=0;ki<3;ki++)
			 {
				 	 for (int kj=0;kj<3;kj++)
				 	 {

				 		 in=*(img_in+i*cols+j+ki*cols+kj);
				 		 filter=*(kernel+ki*3+kj);
				 		 *(img_out+i*out_cols+j)+=in*filter;

				 	 }
			 }

	 }
	}

}













