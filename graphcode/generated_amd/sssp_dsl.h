#ifndef GENCPP_SSSP_DSL_H
#define GENCPP_SSSP_DSL_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <CL/cl.h>
#include "../graph.hpp"

void Compute_SSSP(graph& g,int src);

#endif
