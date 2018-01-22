// object.cpp --- 
// Filename: object.cpp
// Author: Hamlet_Jiaxiaoyu
// Created: Mon Jan 22 11:04:10 2018 (+0800)
// 
// 
// Copyright Hamlet_Jiaxiaoyu.
// 
// 允许免费使用，拷贝，修改，发布，但在所有的拷贝上必须保留上述
// copyright部分和本使用声明部分，除非显示声明，copyright的持有者
// 不得作为再发布软件的广告。copyright的持有者对使用本软件的适用范围不做任何声明，
// 
// THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
// INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
// EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
// CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
// DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
// TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
// 
// 
#include <stdio.h>
#include <string.h>
#include "object.h"

Object::Object()
{

}

Object::~Object()
{

}

static int find_string(const char* str, const char* substr)
{
    if(strlen(str) < strlen(substr))
        return -1;
    int idx = 0;
    int len = strlen(substr);
    bool start = true;

    const char* pos  = str;
    while(*pos){
        if(start && !strncmp(pos, substr, len) && pos[len]=='\n')
            return idx;
        start = false;
        if(*pos == '\n'){
            idx++;
            start = true;
        }
        pos++;
    }
    return -1;
}

void Object::db_connect(Object* sender, const char* sig, Object* receiver, const char* slt)
{
    int sig_idx = find_string(sender->meta.sig_names, sig);
    int slt_idx = find_string(receiver->meta.slts_names, slt);
    if(sig_idx == -1 || slt_idx == -1){
        return;
    }else{
        Connection c = {receiver, slt_idx};
        sender->connections.insert(std::pair<int, Connection>(sig_idx, c));
    }
}

void Object::slot1()
{
    printf("hello world\n");
}

void MetaObject::active(Object* sender, int idx)
{
    ConnectionMapIt it;
    std::pair<ConnectionMapIt, ConnectionMapIt> ret;
    ret = sender->connections.equal_range(idx);
    for(it = ret.first; it != ret.second; ++it){
        Connection c = (*it).second;
        c.receiver->metacall(c.method);
    }
}

void Object::testSignal()
{
    db_emit sig1();
}

