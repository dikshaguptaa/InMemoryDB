#include "InMemoryDB.h"
#include <iostream>
#include <stdexcept>

InMemoryDB::InMemoryDB() : transactionInProgress(false) {}

void InMemoryDB::begin_transaction() {
    if (transactionInProgress) {
        std::cout << "Error: A transaction is already in progress." << std::endl;
        return;
    }
    transactionInProgress = true;
    transactionState.clear();
}

void InMemoryDB::put(const std::string& key, int value) {
    if (!transactionInProgress) {
        std::cout << "Error: Cannot use put() without an active transaction." << std::endl;
        return;
    }
    transactionState[key] = value;
}

int InMemoryDB::get(const std::string& key) {
    // Check if the key exists in the main state (committed state)
    if (mainState.find(key) != mainState.end()) {
        std::cout << "Value of " << key << ": " << mainState[key] << std::endl;
        return mainState[key];
    }

    // Check if the key exists in the transaction state
    if (transactionInProgress && transactionState.find(key) != transactionState.end()) {
        // Uncommitted keys should return null
        std::cout << "Value of " << key << ": null" << std::endl;
        return -1; // Returning -1 to indicate "null"
    }

    // Key does not exist in either state
    std::cout << "Value of " << key << ": null" << std::endl;
    return -1; // Returning -1 to indicate "null"
}


void InMemoryDB::commit() {
    if (!transactionInProgress) {
        std::cout << "Error: No transaction to commit." << std::endl;
        return;
    }
    for (const auto& pair : transactionState) {
        mainState[pair.first] = pair.second;
    }
    transactionInProgress = false;
    transactionState.clear();
}

void InMemoryDB::rollback() {
    if (!transactionInProgress) {
        std::cout << "Error: No transaction to rollback." << std::endl;
        return;
    }
    transactionInProgress = false;
    transactionState.clear();
}
