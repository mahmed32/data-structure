#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <math.h>
class hash_table
{
 public:
    hash_table();
    ~hash_table();
    size_t hash(int key, size_t size) const;
    void add(int key, int value);
    size_t exists(int key) const;
    int get(int key) const;
    void remove(int key);
 private:
    struct slot
    {
        enum class state
        {
            EMPTY, OCCUPIED, DELETED
        } slotState = state::EMPTY;
        int key;
        int data;
    };
    slot* table;
    size_t numOfElments;
    size_t numOfSlots;
    static constexpr size_t DEFULT_SIZE = 8;
};

void hash_table::remove(int key)
{
    size_t pos = exists(key);
    if(table[pos].slotState != slot::state::EMPTY)
    {
        table[pos].slotState = slot::state::DELETED;
        numOfElments--;
    }
}

int hash_table::get(int key) const
{
    size_t pos = exists(key);
    if(table[pos].slotState == slot::state::EMPTY)
        throw "key not found!";
        
    return table[pos].data;
}

size_t hash_table::exists(int key) const
{
    size_t pos = hash(key, numOfSlots);
    while(table[pos].slotState != slot::state::EMPTY)
    {
        if(table[pos].slotState == slot::state::OCCUPIED) 
            if(key == table[pos].key)
                return pos;
        pos = (++pos) % numOfSlots;
    }
    return pos;//this position is a empty slot position
}

void hash_table::add(int key, int value)
{
    size_t pos = hash(key, numOfSlots);
    while(table[pos].slotState == slot::state::OCCUPIED)
    {
        if(key = table[pos].key)
            break;
        pos = (++pos) % numOfSlots;
    }
    if(key != table[pos].key) numOfElments--;
    table[pos].data = value;
    table[pos].key  = key;
    table[pos].slotState = slot::state::OCCUPIED;
}

size_t hash_table::hash(int key, size_t size) const
{
    return key - floor(float(key)/size) * size;
}

hash_table::~hash_table()
{
    delete [] table;
}

hash_table::hash_table()
    :
    table(nullptr),
    numOfElments(0),
    numOfSlots(DEFULT_SIZE)
{
    table = new slot[numOfSlots];
}
#endif
