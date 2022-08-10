#include "ap_int.h"
#include <hls_stream.h>
#include "ap_axi_sdata.h"
#include <stdint.h>

typedef int DTYPE;

#ifndef FILTER2D_H_
#define FILTER2D_H_

#define WIDTH  128
#define HEIGHT 128

void filter2d_accel(DTYPE* img_in, DTYPE* kernel, DTYPE* img_out, int rows, int cols);


#endif
