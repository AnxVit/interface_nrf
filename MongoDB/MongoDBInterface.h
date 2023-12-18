#pragma once

#include <iostream> 
#include <bsoncxx/builder/basic/document.hpp> 
#include <bsoncxx/json.hpp> 
#include <bsoncxx/stdx/optional.hpp>
#include <bsoncxx/document/view_or_value.hpp>

#include <mongod_conn.h>
#include <../DBInterface.h>
 

class MongoDBInterface: public DBInterface<bsoncxx::document::view_or_value, mongocxx::cursor>{
public:
    MongoDBInterface(const char* uri): client(uri){};

    void set_db(const char* database);

    void set_collection(const char* collection);

    void drop();
    
public:
    void create(const bsoncxx::document::view_or_value& document);

    mongocxx::cursor read(const bsoncxx::document::view_or_value& read) const;
    
    void update(const bsoncxx::document::view_or_value& filter, const bsoncxx::document::view_or_value& update);

    void delete(const bsoncxx::document::view_or_value& filter);

private:
    MongoConn client;
    mongocxx::database db;
    mongocxx::collection collect;
};
