// de_object.cpp --- 
// Filename: de_object.cpp
// Author: Hamlet_Jiaxiaoyu
// Created: Mon Jan 22 11:23:27 2018 (+0800)
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

#include "object.h"

static const char sig_names[] = "sig1\n";
static const char slts_names[] = "slots\n";

MetaObject Object::meta = {sig_names, slts_names};
void Object::sig1()
{
    MetaObject::active(this, 0);
}

void Object::metacall(int idx)
{
    switch (idx) {
    case 0:
        slot1();
        break;
    default:
        break;
    };
}
