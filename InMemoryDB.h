#ifndef INMEMORYDB_H
#define INMEMORYDB_H

#include <string>
#include <unordered_map>

class InMemoryDB {
private:
    std::unordered_map<std::string, int> mainState;
    std::unordered_map<std::string, int> transactionState;
    bool transactionInProgress;

public:
    InMemoryDB();
    void begin_transaction();
    void put(const std::string& key, int value);
    int get(const std::string& key);
    void commit();
    void rollback();
};

#endif
