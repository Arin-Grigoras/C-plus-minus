#ifndef CPM_H
#define CPM_H

#include <stdio.h>

#ifndef NULL
    #error "C+-.h Requires NULL to be defined"
#endif

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <errno.h>

#ifndef UINT32_MAX
    #error "C+-.h Requires UINT32_MAX to be defined"
#endif


#include "./errors.h"
#include "./parser.h"
#include "./token.h"
#include "./util.h"
#include "./compiler.h"
#include "./colors.h"
#include "./keywords.h"

#endif //C+-_h
