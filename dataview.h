#ifndef DATAVIEW_H
#define DATAVIEW_H

class DataModel;

class DataView
{
public:
    virtual ~DataView() = default;
    DataModel *model() const;
    void setModel(DataModel *model);

private:
    DataModel *mModel = nullptr;
};

#endif // DATAVIEW_H




