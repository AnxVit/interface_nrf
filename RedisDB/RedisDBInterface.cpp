#include "RedisDBInterface.h"
/*
void RedisDBInterface::drop(){
    conn->scan
}*/

void RedisDBInterface::create(const std::pair<sw::redis::StringView, sw::redis::StringView>& key_val) {
    conn->set(key_val.first, key_val.second);
}

sw::redis::OptionalString RedisDBInterface::read(const sw::redis::StringView& key) {
    return conn->get(key);
}

void RedisDBInterface::update(const sw::redis::StringView& key, const sw::redis::StringView& val) { 
    bool flag = conn->set(key, val);
    if(!flag){
        std::cout << "No matches";
    }
}

void RedisDBInterface::del(const sw::redis::StringView& key) {
    conn->del(key);
}

std::vector<sw::redis::OptionalString> RedisDBInterface::find(const std::string nfTypeSearch){
    std::vector<sw::redis::OptionalString> match_keys;
    std::vector<sw::redis::OptionalString> keys;

    conn->keys("*", std::back_inserter(keys));
    for (const auto& key : keys) {        
        if (conn->hget(*key, "nfType") == nfTypeSearch)
            match_keys.push_back(key);
    }

    return match_keys;
}