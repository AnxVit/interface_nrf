#include "MongoDB/MongoDBInterface.h"
#include "RedisDB/RedisDBInterface.h"

int main(){
    MongoDBInterface mongo("mongodb://localhost:27017");
    RedisDBInterface redis("tcp://127.0.0.1:6379");
    return 0;
}