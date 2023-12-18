#pragma once

template<typename Value, typename Read>
class DBInterface {
public:
    virtual void create(const Value& document) = 0;

    virtual Read read(const Value& val) const = 0;

    virtual void update(const Value& filter, const Value& update) = 0;

    virtual void delete(const Value& filter) = 0;
};


