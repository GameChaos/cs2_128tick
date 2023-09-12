/* date = October 12th 2020 6:33 pm */

#include <stdint.h>
#include <float.h>

#ifndef COMMON_H
#define COMMON_H

#define internal static
#define local_persist static
#define global static

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
typedef s32 b32;
typedef s16 b16;
typedef s8 b8;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

#define S8_MIN ((s8)0x80)
#define S16_MIN ((s16)0x8000)
#define S32_MIN ((s32)0x80000000)
#define S64_MIN ((s64)0x8000000000000000LL)

#define U8_MAX 0xffU
#define S8_MAX 0x7f
#define U16_MAX 0xffffU
#define S16_MAX 0x7fff
#define U32_MAX 0xffffffffU
#define S32_MAX 0x7fffffff
#define U64_MAX 0xffffffffffffffffULL
#define S64_MAX 0x7fffffffffffffffLL

#define F32_MAX FLT_MAX
#define F64_MAX DBL_MAX

#define KILOBYTES(value) ((value) * 1024)
#define MEGABYTES(value) (KILOBYTES(value) * 1024)
#define GIGABYTES(value) (MEGABYTES(value) * 1024ULL)
#define TERABYTES(value) (GIGABYTES(value) * 1024ULL)

#define ARRAYCOUNT(array) (sizeof(array) / sizeof((array)[0]))

#ifdef GC_DEBUG
#define ASSERT(expression) do {if (!(expression)) { *(volatile int *)0 = 0; }} while(0)
#else
#define ASSERT(expression)
#endif
#define ASSERT_RANGE(value, min, max) ASSERT((value) > (min) && (value) < (max))
#define ASSERT_EQ(a, b) ASSERT((a) == (b))

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define CLAMP(min, val, max) (MAX(MIN(val, max), min))
#define ABS(value) ((value) < 0 ? -(value) : (value))
#define ROUND_UP_BY_POWER_OF_2(value, powerOf2) (((value) + (powerOf2) - 1) & ~((powerOf2) - 1))
#define ROUND_DOWN_BY_POWER_OF_2(value, powerOf2) ((value) & ~((powerOf2) - 1))

#define MEMBER(type, member) (((type *)0)->member)
#define MEMBER_SIZE(type, member) (sizeof(((type *)0)->member))

#define TOKENPASTE_(a, b) a##b
#define TOKENPASTE(a, b) TOKENPASTE_(a, b)

#endif //COMMON_H
