#ifndef HASH_TABLE_H
#define HASH_TABLE_H
class hash_table
{
 public:
    hash_table();
    ~hash_table();
    size_t hash(int key, size_t size) const;
    void add(int key, int value);
    bool exists(int key) const;
    int get(key) const;
    void remove(key);
 private:
    struct slot
    {
        enum class state
        {
            EMPTY, OCCUPIED, DELETED
        };
        int key;
        int data;
    };
    slot* table;
    size_t numOfElments;
};
#endif
