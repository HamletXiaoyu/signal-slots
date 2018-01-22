/* object.h --- 
 * Filename: object.h
 * Author: Hamlet_Jiaxiaoyu
 * Created: Mon Jan 22 10:51:25 2018 (+0800)
 */

/* Copyright Hamlet_Jiaxiaoyu.
 * 
 * 允许免费使用，拷贝，修改，发布，但在所有的拷贝上必须保留上述
 * copyright部分和本使用声明部分，除非显示声明，copyright的持有者
 * 不得作为再发布软件的广告。copyright的持有者对使用本软件的适用范围不做任何声明，
 * 
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */
#ifndef DB_OBJECT_H_
#define DB_OBJECT_H_

#include <map>
#define db_slots
#define db_signals protected
#define db_emit
class Object;
struct MetaObject
{
    const char* sig_names;
    const char* slts_names;
    static void active(Object* sender, int idx);
};

struct Connection
{
    Object *receiver;
    int method;
};

typedef std::multimap<int, Connection> ConnectionMap;
typedef std::multimap<int, Connection>::iterator ConnectionMapIt;

class Object
{
    static MetaObject meta;
    void metacall(int idx);
public:
    Object();
    virtual ~Object();
    static void db_connect(Object*, const char*, Object*, const char*);
    void testSignal();

db_signals:
    void sig1();

public db_slots:
    void slot1();
    friend class MetaObject;

private:
    ConnectionMap connections;
    
};

#endif
