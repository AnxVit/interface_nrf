#pragma once

template<typename Create, typename Read, typename Update, typename Del_Read>
class DBInterface {
public:
    virtual void create(const Create& document) = 0;

    virtual Read read(const Del_Read& val) = 0;

    virtual void update(const Update& filter, const Update& update) = 0;

    virtual void del(const Del_Read& filter) = 0;

};


