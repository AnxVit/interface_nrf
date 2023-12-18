#include <MongoDBInterface.h>

void MongoDBInterface::set_db(const char* database){
    db = *(client->connection())[database];
}

void MongoDBInterface::set_collection(const char* collection){
    collect = db[collection];
}

void MongoDBInterface::drop(){
    db.drop();
}

void MongoDBInterface::create(const bsoncxx::document::view_or_value& document) {
    collection.insert_one(document.view());
}

mongocxx::cursor MongoDBInterface::read(const bsoncxx::document::view_or_value& read) const {
    return collect.find(read);
}

void MongoDBInterface::update(const bsoncxx::document::view_or_value& filter, const bsoncxx::document::view_or_value& update) {        
    collect.update_one(filter, update);
}

void MongoDBInterface::delete(const bsoncxx::document::view_or_value& filter) {
    collect.delete_one(filter);

    bsoncxx::stdx::optional<bsoncxx::document::value> result = collect.find_one(filter);

    if (result) {
        std::cout << "The document has not been deleted." << std::endl;
    }
    else {
        std::cout << "The document  deleted." << std::endl;
    }
}