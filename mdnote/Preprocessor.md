# Preprocess

## #include

the #include directive must be the first non-whitespace text on its line.

## #define

## #undef

## 条件编译

``` c
#if statement
...
#elif another-statement
...
#else
...
#endif
```

``` c
#if defined(...)

#ifdef

#ifndef
```

## macro

好处：类似inline

inline function

``` c
inline int Max(int one, int two) {
        return one > two ? one : two;
    }
```

## Advanced Preprocessor Techniques

- 一些特殊宏
预处理时转换成相应字符串

__DATE__ 
__TIME__
__LINE__
__FILE__

- stringizing operator #

可将宏参数n转化为字符串后再替换

``` c
#define PRINTOUT(n) cout << #n << " has value  " << (n) << endl

int x = 137;
PRINTOUT(x * 42);
//预处理后
int x = 137;
    cout << "x * 42" << " has value " << (x * 42) << endl;
```

- string concatenation ##

注意参数不要有空格，容易出问题

``` c
#define DECLARE_MY_VAR(type) type my_##type

DECLARE_MY_VAR(int);
//预处理后
int my_int;
```

## X Macro trick

用于对一组词项需要多处重复操作的地方，
好处，便于集中修改

``` c
#define macroname(arguments) /* some use for the arguments */
#include "filename"
#undef macroname
```

example:

``` c
//file:color.h
DEFINE_COLOR(Red, Cyan)
DEFINE_COLOR(Cyan, Red)
DEFINE_COLOR(Green, Magenta)
DEFINE_COLOR(Magenta, Green)
DEFINE_COLOR(Blue, Yellow)
DEFINE_COLOR(Yellow, Blue)

//其他文件
enum Color {
        #define DEFINE_COLOR(color, opposite) color, // Name followed by comma
        #include "color.h"
        #undef DEFINE_COLOR
    };

Color GetOppositeColor(Color c) {
        switch(c) {
            #define DEFINE_COLOR(color, opposite) case color: return opposite;
            #include "color.h"
            #undef DEFINE_COLOR
            default: return c; // Unknown color, undefined result.
        }
    }

string ColorToString(Color c) {
        switch(c) {
            /* Convert something of the form DEFINE_COLOR(color, opposite)
             * into something of the form 'case color: return "color"';
             */
            #define DEFINE_COLOR(color, opposite) case color: return #color;
            #include "color.h"
            #undef DEFINE_COLOR
    
            default: return "<unknown>";
        }
    }
```