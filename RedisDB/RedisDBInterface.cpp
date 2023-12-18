#include "RedisDBInterface.h"

void RedisDBInterface::drop(){
    conn->scan
}

void RedisDBInterface::create(const sw::redis::StringView& key, const sw::redis::StringView& val) {
    conn->set(key, val);
}

sw::redis::OptionalString RedisDBInterface::read(const sw::redis::StringView& key) const {
    conn->get(key);
}

void RedisDBInterface::update(const sw::redis::StringView& key, const sw::redis::StringView& val) { 
    conn->set(key, val);
}

void RedisDBInterface::delete(const sw::redis::StringView& key) {
    conn->del(key);
}