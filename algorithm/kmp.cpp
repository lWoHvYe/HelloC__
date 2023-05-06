//
// Created by lWoHvYe on 2023/5/6.
//

#include "kmp.h"

// 下标从1开始
unsigned long Index_KMP(String S, String T, const int *next) {
    int i = 1, j = 1;
    while (i <= S.length() && j <= T.length()) {
        //a) =,assign() //赋以新值
        //b) swap() //交换两个字符串的内容
        //c) +=,append(),push_back() //在尾部添加字符
        //d) insert() //插入字符
        //e) erase(int nStart,int nEnd) //删除nStart—nEnd位置字符
        //f) clear() //删除全部字符
        //g) replace() //替换字符
        //h) + //串联字符串
        //i) ==,!=,<,<=,>,>=,compare() //比较字符串
        //j) size(),length() //返回字符数量
        //k) max_size() //返回字符的可能最大个数
        //l) empty() //判断字符串是否为空
        //m) capacity() //返回重新分配之前的字符容量
        //n) reserve() //保留一定量内存以容纳一定数量的字符
        //o) [ ], at() //存取单一字符
        //p) >>,getline() //从stream读取某值
        //q) << //将谋值写入stream
        //r) copy() //将某值赋值为一个C_string
        //s) c_str() //将内容以C_string返回
        //t) data() //将内容以字符数组形式返回
        //u) substr() //返回某个子字符串
        //v)查找函数
        //w)begin() end() //提供类似STL的迭代器支持
        //x) rbegin() rend() //逆向迭代器
        //y) get_allocator() //返回配置器
        if (j == 0 || S.at(i) == T.at(j)) {
            ++i, ++j; // 继续比较后继字符
        } else j = next[j]; // 回溯/模式串向右移动
    }
    return j > T.length() ? i - T.length() : 0;
}


void get_next(String T, int *next) {
    int i = 0, j = 0;
    next[1] = 0;
    while (i < T.length()) {
        if (j == 0 || T.at(i) == T.at(j)) {
            // 当2个字符相同时，表示在模式串中前i个字符有j个字符前缀和后缀是一样的，所以next[i+1] = j + 1
            // next[j] 表示首尾重合串的长度 + 1，因为从重合部分之后开始比较
            // 这里 用 next[i + 1] = next[i] + 1; i++; j++; 也可以，没有下面简洁但容易理解
            next[++i] = ++j; // 若pi = pj，则 next[j+1] = next[j] + 1; 这里卡了好久，我一直试图弄清next[i]与j的关系，实际上next[i]=1
        } else j = next[j]; // 否则，令j=next[j],回溯，因为j处失配，所以回溯到next[j]再尝试
    }
}


void get_next_val(String T, int *next_val) {
    int i = 0, j = 0;
    next_val[1] = 0;
    while (i < T.length()) {
        if (j == 0 || T.at(i) == T.at(j)) {
            if (T.at(++i) != T.at(++j))
                next_val[i] = j; // 若pi = pj，则 next[j+1] = next[j] + 1;
            else next_val[i] = next_val[j]; //kmp next数组优化为next_val数组
        } else j = next_val[j]; // 否则，令j=next[j],回溯
    }
}
