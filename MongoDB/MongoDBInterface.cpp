#include <MongoDBInterface.h>

void MongoDBInterface::set_db(const char* database){
    db = client.connection()->database(database);
}

void MongoDBInterface::set_collection(const char* collection){
    collect = db[collection];
}

void MongoDBInterface::drop(){
    db.drop();
}

void MongoDBInterface::create(const bsoncxx::document::view_or_value& document) {
    collect.insert_one(document.view());
}

mongocxx::cursor MongoDBInterface::read(const bsoncxx::document::view_or_value& read){
    return collect.find(read);
}

void MongoDBInterface::update(const bsoncxx::document::view_or_value& filter, const bsoncxx::document::view_or_value& update) {        
    collect.update_one(filter, update);
}

void MongoDBInterface::del(const bsoncxx::document::view_or_value& filter) {
    collect.delete_one(filter);

    bsoncxx::stdx::optional<bsoncxx::document::value> result = collect.find_one(filter);

    if (result) {
        std::cout << "The document has not been deleted." << std::endl;
    }
    else {
        std::cout << "The document  deleted." << std::endl;
    }
}

mongocxx::cursor MongoDBInterface::find_d(const bsoncxx::document::view_or_value& filter){
    mongocxx::cursor result = collect.find(filter);
    if(result.begin() == result.end()){
        std::cout << "There are no matches";
    }
    return result;
}