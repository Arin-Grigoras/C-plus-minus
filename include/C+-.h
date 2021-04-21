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

#ifndef UINT32_MAX
    #error "C+-.h Requires UINT32_MAX to be defined"
#endif


#include "./errors.h"
#include "./parser.h"
#include "./token.h"
#include "./util.h"
#include "./compiler.h"
#include "./cnpython.h"
#include "./colors.h"

#ifndef not
    #error "C+-.h Requires not to be defined in cnpython.h"
#endif


#ifndef isnt
    #error "C+-.h Requires isnt to be defined in cnpython.h"
#endif

#ifndef and
    #error "C+-.h Requires and to be defined in cnpython.h"
#endif

#ifndef or
    #error "C+-.h Requires or to be defined in cnpython.h"
#endif

#ifndef is
    #error "C+-.h Requires is to be defined in cnpython.h"
#endif

#ifndef True
    #error "C+-.h Requires True to be defined in cnpython.h"
#endif

#ifndef False
    #error "C+-.h Requires False to be defined in cnpython.h"
#endif

#ifndef elif
    #error "C+-.h Requires elif to be defined in cnpython.h"
#endif

#endif //C+-_h