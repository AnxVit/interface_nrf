#pragma once

#include <iostream> 

#include <redis_conn.h>
#include <../include/DBInterface.h>
#include <vector>
 

class RedisDBInterface: public DBInterface<std::pair<sw::redis::StringView,sw::redis::StringView>, 
                        sw::redis::OptionalString, 
                        sw::redis::StringView, 
                        sw::redis::StringView>{
private:
    RedisConn redis;
    std::shared_ptr<sw::redis::Redis> conn;

public:
    RedisDBInterface(const char* uri): redis(uri), conn(redis.connection()){};

//    void drop();
    
    std::vector<sw::redis::OptionalString> find(const std::string nfTypeSearch);
    
public:
    void create(const std::pair<sw::redis::StringView, sw::redis::StringView>& key_val);

    sw::redis::OptionalString read(const sw::redis::StringView& key);
    
    void update(const sw::redis::StringView& filter, const sw::redis::StringView& update);

    void del(const sw::redis::StringView& key);

};
