#pragma once

#include <iostream> 

#include <redis_conn.h>
#include <../DBInterface.h>
 

class RedisDBInterface: public DBInterface<sw::redis::StringView, sw::redis::OptionalString>{
public:
    RedisDBInterface(const char* uri): redis(uri){
        conn.reset(redis->connection());
    };

    void drop();
    
public:
    void create(const sw::redis::StringView& key, const sw::redis::StringView& val);

    sw::redis::OptionalString read(const sw::redis::StringView& key) const;
    
    void update(const sw::redis::StringView& filter, sw::redis::StringView& update);

    void delete(const sw::redis::StringView& key);

private:
    RedisConn redis;
    std::shared_ptr<sw::redis::Redis> conn;
};
