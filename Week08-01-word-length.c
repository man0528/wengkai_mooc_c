/*================================================================
*   Copyright (C) 2018 Navin Xu. All rights reserved.
*   
*   Filename    ：Week08-01-word-length.c
*   Author      ：Navin Xu
*   E-Mail      ：admin@navinxu.com
*   Create Date ：2018年12月30日
*   Description ：
单词长度（4分）
题目内容：

你的程序要读入一行文本，其中以空格分隔为若干个单词，以‘.’结束。你要输出这行文本中每个单词的长度。这里的单词与语言无关，可以包括各种符号，比如“it's”算一个单词，长度为4。注意，行中可能出现连续的空格。



输入格式:

输入在一行中给出一行文本，以‘.’结束，结尾的句号不能计算在最后一个单词的长度内。



输出格式：

在一行中输出这行文本对应的单词的长度，每个长度之间以空格隔开，行末没有最后的空格。



输入样例：

It's great to see you here.



输出样例：

4 5 2 3 3 4

时间限制：500ms内存限制：32000kb
================================================================*/
#include <stdio.h>

int main() {


    int c, word_length = 0;
    unsigned char is_word = 0, is_first = 1;;

    // It's great to see you here.
    // Hello, world.
    // Hello.
    while ((c = getchar()) != EOF) {
        if (c == '.') {
            if (is_first && !is_word) {
                break;
            } else if (is_first) {
                printf("%d", word_length);
                is_first = 0;
            } else if (is_word)
                printf(" %d", word_length);
            break;
        }

        if (c == ' ') {
            if (is_word) {
                if (is_first)
                    printf("%d", word_length);
                else
                    printf(" %d", word_length);
                is_word = 0;
                is_first = 0;
                word_length = 0;
            }

            continue;
        }

        // 防止空行被计入单词长度
        if (c == '\n')
            continue;

        word_length ++;
        if (c != '\n')
            is_word = 1;
    }

    return 0;
}

