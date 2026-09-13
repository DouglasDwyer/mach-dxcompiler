// Force-included (via -include) into every C++ translation unit when building a GNU target
// against libstdc++ instead of Zig's bundled libc++.
//
// libc++'s <stddef.h> (the C-header-style wrapper, as opposed to <cstddef>) injects a
// compatibility `nullptr_t` typedef into the *global* namespace as a courtesy for old code
// written against pre-standardization nullptr_t placement. DirectXShaderCompiler's
// include/dxc/Support/microcom.h relies on that unqualified `nullptr_t` existing. libstdc++'s
// headers don't provide it (nullptr_t is only ever `std::nullptr_t`, per the standard), so
// restore it here.
#ifndef MACH_DXCOMPILER_GNU_LIBSTDCXX_COMPAT_H
#define MACH_DXCOMPILER_GNU_LIBSTDCXX_COMPAT_H

#ifdef __cplusplus
#include <cstddef>
using nullptr_t = std::nullptr_t;
#endif

#endif
