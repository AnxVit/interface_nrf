#include "redis_conn.h"

RedisConn::RedisConn(const char* m_uri){
    m_connection.reset(new sw::redis::Redis(m_uri));
}

std::shared_ptr<sw::redis::Redis> RedisConn::connection() const {
    return m_connection;
}